package com.example.finalproject;

import androidx.appcompat.app.AppCompatActivity;

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
import android.widget.TextView;

import com.example.finalproject.databinding.ActivityItem1Binding;
import com.example.finalproject.databinding.ActivityItem5Binding;

import java.util.ArrayList;
import java.util.List;

public class item5 extends AppCompatActivity {

    private ActivityItem5Binding binding;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityItem5Binding.inflate(getLayoutInflater());
        View view= binding.getRoot();
        setContentView(view);
        setTitle("과자코너");

        Bundle extras = getIntent().getExtras();
        if(extras==null){
            return ;
        }

        String jangbaguni = extras.getString("jangbaguni");
        binding.editTextitem5.setText(jangbaguni);

        insertDB(view);
    }

    public void gobackjangbaguni(View view){
        Intent data = new Intent();

        String returnString = binding.editTextitem5.getText().toString();
        data.putExtra("jangbaguni",returnString);
        setResult(RESULT_OK,data);
        super.finish();
    }

    public class myDBHelper extends SQLiteOpenHelper {
        public myDBHelper(Context context){
            super(context,"item5",null,1);
        }

        @Override
        public void onCreate(SQLiteDatabase sqLiteDatabase) {
            sqLiteDatabase.execSQL("create table item5 (gName char(20));");
        }

        @Override
        public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
            sqLiteDatabase.execSQL("drop table if exists item5");;
            onCreate(sqLiteDatabase);
        }
    }

    public void insertDB(View view){
        String items = binding.editTextitem5.getText().toString();
        String[] array = items.split("\n");
        myDBHelper myHelper = new myDBHelper(this);
        SQLiteDatabase sqlDB = myHelper.getWritableDatabase();
        myHelper.onUpgrade(sqlDB,1,2);
        //sqlDB.execSQL("insert into groupTBL values('" + binding.editText1.getText().toString() +"'," + binding.editText2.getText().toString()+");");
        sqlDB.execSQL("insert into item5 values('사브레');");
        sqlDB.execSQL("insert into item5 values('바나나킥');");
        sqlDB.execSQL("insert into item5 values('썬칲');");
        sqlDB.execSQL("insert into item5 values('콘칲');");
        sqlDB.execSQL("insert into item5 values('쵸코비');");
        binding.textView5.setText("");
        SQLiteDatabase sqlDB2 = myHelper.getReadableDatabase();
        Cursor cursor;
        cursor = sqlDB2.rawQuery("select * from item5",null);
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
        binding.textView5.setText(string);
        TextView textView = (TextView) findViewById(R.id.textView5);
        String content = textView.getText().toString();
        SpannableString spannableString = new SpannableString(content);

        //Toast.makeText(getApplicationContext(),array[0],Toast.LENGTH_LONG).show();
        for( int i = 0 ; i < start.size() ; i++){
            spannableString.setSpan(new ForegroundColorSpan(Color.parseColor("#ff0000")),start.get(i),end.get(i), Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
        }
        binding.textView5.setText(spannableString);
        cursor.close();
        sqlDB.close();
    }
}