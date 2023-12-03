#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
  
    1. getc�� �о� ��� ���ڸ� 1���� �޴� ����� �������� �Ѵ�.
    2. �־��� ���ǵ�(integer, operator...)���� �Ľ��� ����(��ū)�� ������ 
       ���� ���鹮�ڸ� �߰��Ͽ� ���� syntax analyzer ������ �����ϰ� �Ѵ�.
    3. if���� else���� �������� �̿��Ͽ� �����ϱ� ������ �Ѵ�.

*/

//�ִ�� ���� �� �ִ� ���� �� �̴�.
//if = 2���� else = 4����
#define SIZE 1000

//���ڿ� ���ڹ迭��
char digit[] = { '0','1','2','3','4','5','6','7','8','9' };
char letter[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };


//����� �Լ���
//1. �ش繮�ڰ� �������� Ȯ���ϴ� �Լ�
int CheckLetter(char a) {

    for (int i = 0; i < sizeof(letter); i++) {
        if (a == letter[i]) {          
            return 1;
        }
        else {

            continue;
        }
    }

    return 0;
}
//2. �ش繮�ڰ� �������� Ȯ���ϴ� �Լ�
int CheckDigit(char a) {
    for (int i = 0; i < sizeof(digit); i++) {
        if (a == digit[i]) {
            return 1;
        }
        else {

            continue;
        }
    }
    return 0;
}

//�����Լ�
int main(void)
{
    
    char Table[SIZE] = { 0 };                           //Table�迭�̴�
                                                        //��� ��ū���� �����ϴ� �迭�̴�
                                                        //��ū�� ���̿��� ���鹮�ڰ� ����־� �����ϱ� ������ �Ѵ�
    
    
    char p[SIZE] = { 0 };                               //p�迭�̴�
                                                        //INPUT ������ �ϳ��� �޾� ������ �迭�̴�
                                                        //p�迭�� ���ڰ����� �ϳ��� ���ϸ� ��ūȭ ��ų ���̴�.

    FILE* fp = NULL;                                    //FILE���
    fp = fopen("test.txt", "r");                        //test.txt�� ����ϱ� ���� r�������� ����
                                                        //���� fclose���ش�
   
    
    while (!feof(fp)) {                                 //������ ���� �ٴٸ��� �����Ѵ�,


        int index = 0;                                  //Table�迭�� index��ȣ
        int num = 0;

        for (int i = 0; i < SIZE; i++) {                //getc�� �Ͽ� p�迭�� �ѹ��ھ� �ִ´�
            p[i] = getc(fp);
        }

        /*for (int i = 0; i < SIZE; i++) {                //(�ӽ�)test.txt�� �����̴�
            printf("%c", p[i]);
        }*/
        printf("\n");
        for (int i = 0; i < SIZE; i++) {                            //��ūȭ�� ���� �Լ����̴�.
            char temp[SIZE] = { 0 };                                //��������� �ӽù迭
                                                                    //�Ź� �ʱ�ȭ�� �ؾ��Ѵ�.

            //Whitespace                                            //Whitespace ~ Arithmetic operater >> �켱������ ����
                                                                    //���� ���͵� ��ūȭ�� ������ ���� �͵��� ���� ���������.
            if (p[i] == ' ' || p[i] == '\n' || p[i] == '\t') {
                
            }

            //Comma                                                 //�⺻���� ������
            else if (p[i] == ',') {                                 //1.���ڰ� ��ū�� ���ٸ�
                printf("<COMMA>");
                for (int j = 0; j < sizeof(p[i]); j++) {            //2.Table�迭�� ���̸�ŭ �����ϰ�
                    Table[index + j] = p[i];
                }
                index += sizeof(p[i]);                              //3.index�� ��������
                Table[index] = ' ';                                 //4.������ �־ �����ϱ� ������ �س���
                index += 1;                                         //5.���������� �ѹ��� ������Ų��
            }                                                       //6.�̷ν� Ȯ���ϰ� ���鹮�ڸ� �������� ù��° ��ū�� �ι�° ��ū�� ������ �ȴ�.

            //Array
            else if (p[i] == '[' || p[i] == ']') {                  //��ȣ�� ���� ���
                if (p[i] == '[') {                                  //���ʰ� �������� ���� �������ش�.
                    printf("LBRACKET");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];
                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }
                else if (p[i] == ']') {
                    printf("RBRACKET");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];
                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }
            }

            //Function Statement
            else if (p[i] == '(' || p[i] == ')') {
                if (p[i] == '(') {
                    printf("<LPAREN>");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];


                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }
                else if (p[i] == ')') {
                    printf("<RPAREN>");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];
                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }

            }

            //Definition Area
            else if (p[i] == '{' || p[i] == '}') {
                if (p[i] == '{') {
                    printf("<LBRACE>");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];
                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }
                if (p[i] == '}') {
                    printf("<RBRACE>");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];
                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }
            }

            //Semicolon
            else if (p[i] == ';') {
                printf("<SEMI>");
                for (int j = 0; j < sizeof(p[i]); j++) {
                    Table[index + j] = p[i];
                }
                index += sizeof(p[i]);
                Table[index] = ' ';
                index += 1;
            }

            //Comparison(1)
            else if (p[i] == '>' || p[i] == '<') {
                if (p[i] == '>') {
                    if (p[i + 1] == '=') {
                        printf("<COMPARISON,>= >");
                        for (int j = 0; j < 2; j++) {
                            Table[index + j] = p[i + j];
                        }
                        index += 2;
                        Table[index] = ' ';
                        index += 1;
                        i = i + 1;
                    }
                    else {
                        printf("<COMPARISON,> >)");
                        for (int j = 0; j < sizeof(p[i]); j++) {
                            Table[index + j] = p[i];
                        }
                        index += sizeof(p[i]);
                        Table[index] = ' ';
                        index += 1;
                    }
                }
                if (p[i] == '<') {
                    if (p[i + 1] == '=') {
                        printf("<COMPARISON,<= >");
                        for (int j = 0; j < 2; j++) {
                            Table[index + j] = p[i + j];
                        }
                        index += 2;
                        Table[index] = ' ';
                        index += 1;
                        i = i + 1;
                    }
                    else {
                        printf("<COMPARISON,> >");
                        for (int j = 0; j < sizeof(p[i]); j++) {
                            Table[index + j] = p[i];
                        }
                        index += sizeof(p[i]);
                        Table[index] = ' ';
                        index += 1;
                    }
                }

            }

            //Comparison(2) + Assignment
            else if (p[i] == '!' && p[i + 1] == '=') {
                printf("<COMPARISON,!=>");
                for (int j = 0; j < 2; j++) {
                    Table[index + j] = p[i + j];
                }
                index += 2;
                Table[index] = ' ';
                index += 1;
                i = i + 1;
            }
            else if (p[i] == '=') {
                if (p[i + 1] == '=') {
                    printf("<COMPARISON,==>");
                    for (int j = 0; j < 2; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 2;
                    Table[index] = ' ';
                    index += 1;
                    i = i + 1;
                }
                else {
                    printf("<ASSIGN>");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];
                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }

            }

            //Arithmetic operater                                                   
            else if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/') {    //������ operater���� �ϵ��� �ϰڴ�.
                if (p[i] == '+') {                                                  //integer���� �������� ���� ���� �ʾҴ�.
                    printf("<OP,+>");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];
                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }
                if (p[i] == '-') {
                    printf("<OP,->");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];
                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }
                if (p[i] == '*') {
                    printf("<OP,*>");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];
                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }
                if (p[i] == '/') {
                    printf("<OP,/>");
                    for (int j = 0; j < sizeof(p[i]); j++) {
                        Table[index + j] = p[i];
                    }
                    index += sizeof(p[i]);
                    Table[index] = ' ';
                    index += 1;
                }
            }

            //Variable type                                                                             

            else if (p[i] == 'i' && p[i + 1] == 'n' && p[i + 2] == 't') {
                int x = 0;                                                                              //���� ����ϰ� ���ڵ�� ��ū�� ������ Ȯ���ϴ� ���������
                for (x = 3;; x++) {                                                                     //�ڿ� �߰��� ����/����/_ �� �´ٸ� identifier�� �����ϴ� ����̴�
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {   //
                        continue;                                                                       //int�� 3�����̱� ������ p[k]���� ������ ��� p[k+3]�� Ȯ���ϸ� �ȴ�.
                    }                                                                                   //�ڷ� ��� ���� �� �����Ƿ� continue���� ���� �ݺ��Ͽ� x�� ������Ű�� 
                    if (x == 3) {                                                                       //x���� ���� �ڿ� � ���ڵ��� ��� �ִ��� Ȯ�� �����ϴ� (x-3)��
                        num = 0;                                                                        //x�� 3�̸� variable type �� int�̰�
                        break;                                                                          //x>3�̸� 'int'�� �����ϴ� identifier���� �� �� �ִ�.
                    }
                    num = 1;
                    break;
                }
                switch (num) {
                case 0:
                    printf("<VTYPE,int>");
                    for (int j = 0; j < 3; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 3;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                case 1:

                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') { //���� check~���� ������ Ȯ���ϴ� ���̰�, �̰��� �迭�� ����/����ϱ� ���� if���̴�.
                            continue;
                        }
                        break;
                    }

                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<ID, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                }


            }
            else if (p[i] == 'c' && p[i + 1] == 'h' && p[i + 2] == 'a' && p[i + 3] == 'r') {
                int x = 0;
                for (x = 4;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    if (x == 4) {
                        num = 0;
                        break;
                    }
                    num = 1;
                    break;
                }
                switch (num) {
                case 0:
                    printf("<VTYPE,char>");
                    for (int j = 0; j < 4; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 4;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;

                case 1:
                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                            continue;
                        }
                        break;
                    }

                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }

                    printf("<ID, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                }

            }
            else if (p[i] == 'b' && p[i + 1] == 'o' && p[i + 2] == 'o' && p[i + 3] == 'l' && p[i + 4] == 'e' && p[i + 5] == 'a' && p[i + 6] == 'n') {
                int x = 0;
                for (x = 7;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    if (x == 7) {
                        num = 0;
                        break;
                    }
                    num = 1;
                    break;
                }
                switch (num) {
                case 0:
                    printf("<VTYPE,bool>");
                    for (int j = 0; j < 7; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 7;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                case 1:
                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                            continue;
                        }
                        break;
                    }

                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<ID, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                }

            }
            else if (p[i] == 's' && p[i + 1] == 't' && p[i + 2] == 'r' && p[i + 3] == 'i' && p[i + 4] == 'n' && p[i + 5] == 'g') {
                int x = 0;
                for (x = 6;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    if (x == 6) {
                        num = 0;
                        break;
                    }
                    num = 1;
                    break;
                }
                switch (num) {
                case 0:
                    printf("<VTYPE,string>");
                    for (int j = 0; j < 6; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 6;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                case 1:
                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                            continue;
                        }
                        break;
                    }
                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<ID, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                }

            }

            else if (p[i] == 't' && p[i + 1] == 'r' && p[i + 2] == 'u' && p[i + 3] == 'e') {                //Boolean�� ���� ���������� ������ ��ģ��
                int x = 0;
                for (x = 4;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    if (x == 4) {
                        num = 0;
                        break;
                    }
                    num = 1;
                    break;
                }
                switch (num) {
                case 0:
                    printf("TRUE");
                    for (int j = 0; j < 4; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 4;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                case 1:
                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                            continue;
                        }
                        break;
                    }
                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<ID, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                }
            }

            else if (p[i] == 'f' && p[i + 1] == 'a' && p[i + 2] == 'l' && p[i + 3] == 's' && p[i + 4] == 'e') {


                int x = 0;
                for (x = 5;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    if (x == 5) {
                        num = 0;
                        break;
                    }
                    num = 1;
                    break;
                }
                switch (num) {
                case 0:
                    printf("FALSE");
                    for (int j = 0; j < 5; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 5;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                case 1:
                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                            continue;
                        }
                        break;
                    }
                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<ID, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                }
            }



            else if (p[i] == 'i' && p[i + 1] == 'f') {                                                          //Keyword�� ��������
                int x = 0;
                for (x = 2;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    if (x == 2) {
                        num = 0;
                        break;
                    }
                    num = 1;
                    break;
                }

                switch (num) {
                case 0:
                    printf("<IF>");
                    for (int j = 0; j < 2; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 2;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                case 1:
                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                            continue;
                        }
                        break;
                    }

                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<ID, %s>", temp);

                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;


                    break;
                }

            }
            else if (p[i] == 'e' && p[i + 1] == 'l' && p[i + 2] == 's' && p[i + 3] == 'e') {
                int x = 0;
                for (x = 4;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    if (x == 4) {
                        num = 0;
                        break;
                    }
                    num = 1;
                    break;
                }
                switch (num) {
                case 0:
                    printf("<ELSE>");
                    for (int j = 0; j < 4; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 4;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                case 1:
                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                            continue;
                        }
                        break;
                    }
                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<ID, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                }

            }
            else if (p[i] == 'w' && p[i + 1] == 'h' && p[i + 2] == 'i' && p[i + 3] == 'l' && p[i + 4] == 'e') {
                int x = 0;
                for (x = 5;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    if (x == 5) {
                        num = 0;
                        break;
                    }
                    num = 1;
                    break;
                }
                switch (num) {
                case 0:
                    printf("<WHILE>");
                    for (int j = 0; j < 5; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 5;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                case 1:
                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                            continue;
                        }
                        break;
                    }
                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<ID, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                }

            }
            else if (p[i] == 'c' && p[i + 1] == 'l' && p[i + 2] == 'a' && p[i + 3] == 's' && p[i + 4] == 's') {
                int x = 0;
                for (x = 5;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    if (x == 5) {
                        num = 0;
                        break;
                    }
                    num = 1;
                    break;
                }
                switch (num) {
                case 0:
                    printf("<CLASS>");
                    for (int j = 0; j < 5; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 5;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                case 1:
                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                            continue;
                        }
                        break;
                    }
                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<ID, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                }
            }
            else if (p[i] == 'r' && p[i + 1] == 'e' && p[i + 2] == 't' && p[i + 3] == 'u' && p[i + 4] == 'r' && p[i + 5] == 'n') {
                int x = 0;
                for (x = 6;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    if (x == 6) {
                        num = 0;
                        break;
                    }
                    num = 1;
                    break;
                }
                switch (num) {
                case 0:
                    printf("<RETURN>");
                    for (int j = 0; j < 6; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 6;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                case 1:
                    int x = 0;
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                            continue;
                        }
                        break;
                    }
                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<ID, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;
                    break;
                }

            }

            //Identifier                                                                                       //while���� ���������� �Ʒ��� �������鼭 �д� ����̱� ������
            else if (CheckLetter(p[i]) == 1 || p[i] == '_') {                                                  //keyword�� variableó�� �켱���� (int��� ���ڸ� ���� Ȯ���ؾ���)
                int x = 0;                                                                                     //�� �ִ� ��쿡�� ���� ���� �������־���.
                for (x = 1;; x++) {
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {
                        continue;
                    }
                    break;
                }
                for (int j = 0; j < x; j++) {
                    Table[index + j] = p[i + j];
                    temp[j] = p[i + j];
                }
                printf("<ID, %s>", temp);
                index += x;
                Table[index] = ' ';
                index += 1;
                i = i + x - 1;

            }


            //Literal string                                                                                    //Literalstring�̳� singlecharacter���� ��쿡�� 
            else if (p[i] == '\"') {                                                                            // " �� ' �� ����
                int x = 0;
                for (x = 1;; x++) {
                    if (p[i + x] == '\"') {
                        for (int j = 0; j < x - 1; j++) {
                            Table[index + j] = p[i + j + 1];
                            temp[j] = p[i + j + 1];
                        }
                        printf("<string, %s>", temp);
                        index += x - 1;
                        Table[index] = ' ';
                        index += 1;
                        i = i + x;
                        break;
                    }

                }
            }

            //Single Character                                                                                  
            else if (p[i] == '\'') {
                if (p[i + 1] == '\'') {
                    Table[index] = p[i];
                    Table[index + 1] = p[i + 1];
                    index += 3;
                    Table[index] = ' ';
                    index += 1;
                    i = i + 1;
                    printf("<char,>");
                }
                else if (p[i + 2] == '\'') {
                    temp[0] = p[i + 1];
                    Table[index] = p[i];
                    Table[index + 1] = p[i + 1];
                    Table[index + 2] = p[i + 2];
                    index += 3;
                    Table[index] = ' ';
                    index += 1;
                    //content = p[i+1]
                    i = i + 2;

                    printf("<char,%s>", temp);

                }

            }

            //Signed Integer
            else if (CheckDigit(p[i]) == 1) {                                                       //Integer�̴�.
                int x = 0;                                                                          //������ ���ߵ�, ������ Arithmetic operater���� ���ϰ�
                if (p[i] == '0') {                                                                  //���� 0�� ������ ���յ��� ����.
                    printf("<INTEGER, 0>");
                    for (int j = 0; j < 1; j++) {
                        Table[index + j] = p[i + j];
                    }
                    index += 1;
                    Table[index] = ' ';
                    index += 1;
                }
                else {
                    for (x = 1;; x++) {
                        if (CheckDigit(p[i + x]) == 1) {
                            continue;
                        }
                        break;
                    }
                    for (int j = 0; j < x; j++) {
                        Table[index + j] = p[i + j];
                        temp[j] = p[i + j];
                    }
                    printf("<INTEGER, %s>", temp);
                    index += x;
                    Table[index] = ' ';
                    index += 1;
                    i = i + x - 1;

                }


            }

        }
    }

    
    
    fclose(fp);                                                                                         //������ �ݾ� �����Ѵ�.
    return 0;
}
