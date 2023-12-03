package com.example.finalproject;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Application;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.graphics.Color;
import android.os.Bundle;
import android.text.Spannable;
import android.text.SpannableString;
import android.text.style.ForegroundColorSpan;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import com.example.finalproject.databinding.ActivityItem1Binding;
import com.example.finalproject.databinding.ActivitySecondBinding;

import java.util.ArrayList;
import java.util.List;

public class item1 extends AppCompatActivity {

    private ActivityItem1Binding binding;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityItem1Binding.inflate(getLayoutInflater());
        View view= binding.getRoot();
        setContentView(view);
        setTitle("과일코너");
        Bundle extras = getIntent().getExtras();
        if(extras==null){
            return ;
        }
        
        String jangbaguni = extras.getString("jangbaguni");
        binding.editTextitem1.setText(jangbaguni);

        insertDB(view);
    }

    public void gobackjangbaguni(View view){
        Intent data = new Intent();
        String returnString = binding.editTextitem1.getText().toString();
        data.putExtra("jangbaguni",returnString);
        setResult(RESULT_OK,data);
        super.finish();
    }

    public class myDBHelper extends SQLiteOpenHelper {
        public myDBHelper(Context context){
            super(context,"item1",null,1);
        }

        @Override
        public void onCreate(SQLiteDatabase sqLiteDatabase) {
            sqLiteDatabase.execSQL("create table item1 (gName char(20));");
        }

        @Override
        public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
            sqLiteDatabase.execSQL("drop table if exists item1");;
            onCreate(sqLiteDatabase);
        }
    }

    public void insertDB(View view){
        String items = binding.editTextitem1.getText().toString();
        String[] array = items.split("\n");
        myDBHelper myHelper = new myDBHelper(this);
        SQLiteDatabase sqlDB = myHelper.getWritableDatabase();
        myHelper.onUpgrade(sqlDB,1,2);
        //sqlDB.execSQL("insert into groupTBL values('" + binding.editText1.getText().toString() +"'," + binding.editText2.getText().toString()+");");
        sqlDB.execSQL("insert into item1 values('사과');");
        sqlDB.execSQL("insert into item1 values('바나나');");
        sqlDB.execSQL("insert into item1 values('키위');");
        sqlDB.execSQL("insert into item1 values('망고');");
        sqlDB.execSQL("insert into item1 values('딸기');");
        binding.textView.setText("");
        SQLiteDatabase sqlDB2 = myHelper.getReadableDatabase();
        Cursor cursor;
        cursor = sqlDB2.rawQuery("select * from item1",null);
        String string = "";
        String item ="";
        List<Integer> start = new ArrayList<>();
        List<Integer> end = new ArrayList<>();
        int index = 0;
        while(cursor.moveToNext()){
            item = cursor.getString(0);

            for(int i = 0 ; i < array.length ; i++){
                if(item.equals(array[i])){
                    start.add(index);
                    end.add(index+item.length()+1);
                }
            }
            index += item.length()+1;
            string += cursor.getString(0)+System.lineSeparator();
        }
        //string += array[0];
        binding.textView.setText(string);
        TextView textView = (TextView) findViewById(R.id.textView);
        String content = textView.getText().toString();
        SpannableString spannableString = new SpannableString(content);

        for( int i = 0 ; i < start.size() ; i++){
            spannableString.setSpan(new ForegroundColorSpan(Color.parseColor("#ff0000")),start.get(i),end.get(i),Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
        }
        binding.textView.setText(spannableString);
        cursor.close();
        sqlDB.close();



    }


}
