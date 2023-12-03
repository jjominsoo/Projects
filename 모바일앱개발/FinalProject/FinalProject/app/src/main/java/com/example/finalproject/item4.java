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
import com.example.finalproject.databinding.ActivityItem4Binding;

import java.util.ArrayList;
import java.util.List;

public class item4 extends AppCompatActivity {

    private ActivityItem4Binding binding;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityItem4Binding.inflate(getLayoutInflater());
        View view= binding.getRoot();
        setContentView(view);
        setTitle("고기코너");

        Bundle extras = getIntent().getExtras();
        if(extras==null){
            return ;
        }

        String jangbaguni = extras.getString("jangbaguni");
        binding.editTextitem4.setText(jangbaguni);

        insertDB(view);
    }

    public void gobackjangbaguni(View view){
        Intent data = new Intent();

        String returnString = binding.editTextitem4.getText().toString();
        data.putExtra("jangbaguni",returnString);
        setResult(RESULT_OK,data);
        super.finish();
    }

    public class myDBHelper extends SQLiteOpenHelper {
        public myDBHelper(Context context){
            super(context,"item4",null,1);
        }

        @Override
        public void onCreate(SQLiteDatabase sqLiteDatabase) {
            sqLiteDatabase.execSQL("create table item4 (gName char(20));");
        }

        @Override
        public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
            sqLiteDatabase.execSQL("drop table if exists item4");;
            onCreate(sqLiteDatabase);
        }
    }

    public void insertDB(View view){
        String items = binding.editTextitem4.getText().toString();
        String[] array = items.split("\n");
        myDBHelper myHelper = new myDBHelper(this);
        SQLiteDatabase sqlDB = myHelper.getWritableDatabase();
        myHelper.onUpgrade(sqlDB,1,2);
        //sqlDB.execSQL("insert into groupTBL values('" + binding.editText1.getText().toString() +"'," + binding.editText2.getText().toString()+");");
        sqlDB.execSQL("insert into item4 values('닭가슴살');");
        sqlDB.execSQL("insert into item4 values('소등심');");
        sqlDB.execSQL("insert into item4 values('돼지목살');");
        binding.textView4.setText("");
        SQLiteDatabase sqlDB2 = myHelper.getReadableDatabase();
        Cursor cursor;
        cursor = sqlDB2.rawQuery("select * from item4",null);
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
        binding.textView4.setText(string);
        TextView textView = (TextView) findViewById(R.id.textView4);
        String content = textView.getText().toString();
        SpannableString spannableString = new SpannableString(content);

        //Toast.makeText(getApplicationContext(),array[0],Toast.LENGTH_LONG).show();
        for( int i = 0 ; i < start.size() ; i++){
            spannableString.setSpan(new ForegroundColorSpan(Color.parseColor("#ff0000")),start.get(i),end.get(i), Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
        }
        binding.textView4.setText(spannableString);
        cursor.close();
        sqlDB.close();
    }
}