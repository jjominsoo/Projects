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
import android.widget.Toast;

import com.example.finalproject.databinding.ActivityItem1Binding;
import com.example.finalproject.databinding.ActivityItem2Binding;

import java.util.ArrayList;
import java.util.List;

public class item2 extends AppCompatActivity {

    private ActivityItem2Binding binding;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityItem2Binding.inflate(getLayoutInflater());
        View view= binding.getRoot();
        setContentView(view);
        setTitle("미용코너");
        Bundle extras = getIntent().getExtras();
        if(extras==null){
            return ;
        }

        String jangbaguni = extras.getString("jangbaguni");
        binding.editTextitem2.setText(jangbaguni);

        insertDB(view);
    }

    public void gobackjangbaguni(View view){
        Intent data = new Intent();
        String returnString = binding.editTextitem2.getText().toString();
        data.putExtra("jangbaguni",returnString);
        setResult(RESULT_OK,data);
        super.finish();
    }

    public class myDBHelper extends SQLiteOpenHelper {
        public myDBHelper(Context context){
            super(context,"item2",null,1);
        }

        @Override
        public void onCreate(SQLiteDatabase sqLiteDatabase) {
            sqLiteDatabase.execSQL("create table item2 (gName char(20));");
        }

        @Override
        public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
            sqLiteDatabase.execSQL("drop table if exists item2");;
            onCreate(sqLiteDatabase);
        }
    }

    public void insertDB(View view){
        String items = binding.editTextitem2.getText().toString();
        String[] array = items.split("\n");
        myDBHelper myHelper = new myDBHelper(this);
        SQLiteDatabase sqlDB = myHelper.getWritableDatabase();
        myHelper.onUpgrade(sqlDB,1,2);
        //sqlDB.execSQL("insert into groupTBL values('" + binding.editText1.getText().toString() +"'," + binding.editText2.getText().toString()+");");
        sqlDB.execSQL("insert into item2 values('치약');");
        sqlDB.execSQL("insert into item2 values('칫솔');");
        sqlDB.execSQL("insert into item2 values('면도기');");
        sqlDB.execSQL("insert into item2 values('면도크림');");
        sqlDB.execSQL("insert into item2 values('치간칫솔');");
        binding.textView2.setText("");
        SQLiteDatabase sqlDB2 = myHelper.getReadableDatabase();
        Cursor cursor;
        cursor = sqlDB2.rawQuery("select * from item2",null);
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
        binding.textView2.setText(string);
        TextView textView = (TextView) findViewById(R.id.textView2);
        String content = textView.getText().toString();
        SpannableString spannableString = new SpannableString(content);

        //Toast.makeText(getApplicationContext(),array[0],Toast.LENGTH_LONG).show();
        for( int i = 0 ; i < start.size() ; i++){
            spannableString.setSpan(new ForegroundColorSpan(Color.parseColor("#ff0000")),start.get(i),end.get(i), Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
        }
        binding.textView2.setText(spannableString);
        cursor.close();
        sqlDB.close();
    }
}