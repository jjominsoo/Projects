#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
  
    1. getc로 읽어 모든 문자를 1개씩 받는 방법을 바탕으로 한다.
    2. 주어진 조건들(integer, operator...)으로 파싱한 문자(토큰)를 받으면 
       끝에 공백문자를 추가하여 추후 syntax analyzer 구현을 용이하게 한다.
    3. if문과 else문을 다중으로 이용하여 이해하기 쉽도록 한다.

*/

//최대로 받을 수 있는 글자 수 이다.
//if = 2글자 else = 4글자
#define SIZE 1000

//숫자와 문자배열들
char digit[] = { '0','1','2','3','4','5','6','7','8','9' };
char letter[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };


//사용할 함수들
//1. 해당문자가 문자인지 확인하는 함수
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
//2. 해당문자가 숫자인지 확인하는 함수
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

//메인함수
int main(void)
{
    
    char Table[SIZE] = { 0 };                           //Table배열이다
                                                        //모든 토큰들을 저장하는 배열이다
                                                        //토큰들 사이에는 공백문자가 들어있어 구분하기 쉽도록 한다
    
    
    char p[SIZE] = { 0 };                               //p배열이다
                                                        //INPUT 값들을 하나씩 받아 저장한 배열이다
                                                        //p배열의 인자값들을 하나씩 비교하며 토큰화 시킬 것이다.

    FILE* fp = NULL;                                    //FILE출력
    fp = fopen("test.txt", "r");                        //test.txt를 사용하기 위해 r권한으로 연다
                                                        //이후 fclose해준다
   
    
    while (!feof(fp)) {                                 //파일이 끝에 다다르면 종료한다,


        int index = 0;                                  //Table배열의 index번호
        int num = 0;

        for (int i = 0; i < SIZE; i++) {                //getc를 하여 p배열에 한문자씩 넣는다
            p[i] = getc(fp);
        }

        /*for (int i = 0; i < SIZE; i++) {                //(임시)test.txt의 내용이다
            printf("%c", p[i]);
        }*/
        printf("\n");
        for (int i = 0; i < SIZE; i++) {                            //토큰화를 위한 함수들이다.
            char temp[SIZE] = { 0 };                                //출력을위한 임시배열
                                                                    //매번 초기화를 해야한다.

            //Whitespace                                            //Whitespace ~ Arithmetic operater >> 우선순위가 없다
                                                                    //언제 나와도 토큰화에 문제가 없는 것들은 먼저 선언해줬다.
            if (p[i] == ' ' || p[i] == '\n' || p[i] == '\t') {
                
            }

            //Comma                                                 //기본적인 구성은
            else if (p[i] == ',') {                                 //1.문자가 토큰과 같다면
                printf("<COMMA>");
                for (int j = 0; j < sizeof(p[i]); j++) {            //2.Table배열에 길이만큼 저장하고
                    Table[index + j] = p[i];
                }
                index += sizeof(p[i]);                              //3.index를 증가시켜
                Table[index] = ' ';                                 //4.공백을 넣어서 구분하기 쉽도록 해놓고
                index += 1;                                         //5.마지막으로 한번더 증가시킨다
            }                                                       //6.이로써 확실하게 공백문자를 기준으로 첫번째 토큰과 두번째 토큰이 나뉘게 된다.

            //Array
            else if (p[i] == '[' || p[i] == ']') {                  //괄호들 같은 경우
                if (p[i] == '[') {                                  //왼쪽과 오른쪽을 따로 저장해준다.
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
            else if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/') {    //음수는 operater에서 하도록 하겠다.
                if (p[i] == '+') {                                                  //integer에서 음의정수 따로 하지 않았다.
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
                int x = 0;                                                                              //위와 비슷하게 문자들과 토큰이 같은지 확인하는 방법이지만
                for (x = 3;; x++) {                                                                     //뒤에 추가로 숫자/문자/_ 가 온다면 identifier로 구분하는 방식이다
                    if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') {   //
                        continue;                                                                       //int는 3글자이기 때문에 p[k]부터 시작한 경우 p[k+3]을 확인하면 된다.
                    }                                                                                   //뒤로 계속 있을 수 있으므로 continue문을 통해 반복하여 x를 증가시키고 
                    if (x == 3) {                                                                       //x값을 통해 뒤에 어떤 문자들이 계속 있는지 확인 가능하다 (x-3)개
                        num = 0;                                                                        //x가 3이면 variable type 의 int이고
                        break;                                                                          //x>3이면 'int'로 시작하는 identifier임을 알 수 있다.
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
                        if (CheckDigit(p[i + x]) == 1 || CheckLetter(p[i + x]) == 1 || p[i + x] == '_') { //위의 check~들은 갯수만 확인하는 것이고, 이것은 배열에 저장/출력하기 위한 if문이다.
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

            else if (p[i] == 't' && p[i + 1] == 'r' && p[i + 2] == 'u' && p[i + 3] == 'e') {                //Boolean도 위와 마찬가지의 과정을 거친다
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



            else if (p[i] == 'i' && p[i + 1] == 'f') {                                                          //Keyword도 마찬가지
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

            //Identifier                                                                                       //while문은 위에서부터 아래로 내려오면서 읽는 방식이기 때문에
            else if (CheckLetter(p[i]) == 1 || p[i] == '_') {                                                  //keyword나 variable처럼 우선순위 (int라는 글자를 먼저 확인해야함)
                int x = 0;                                                                                     //가 있는 경우에는 위에 먼저 정의해주었다.
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


            //Literal string                                                                                    //Literalstring이나 singlecharacter같은 경우에는 
            else if (p[i] == '\"') {                                                                            // " 와 ' 를 기준
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
            else if (CheckDigit(p[i]) == 1) {                                                       //Integer이다.
                int x = 0;                                                                          //위에서 정했듯, 음수는 Arithmetic operater에서 정하고
                if (p[i] == '0') {                                                                  //숫자 0과 나머지 조합들을 본다.
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

    
    
    fclose(fp);                                                                                         //파일을 닫아 종료한다.
    return 0;
}
