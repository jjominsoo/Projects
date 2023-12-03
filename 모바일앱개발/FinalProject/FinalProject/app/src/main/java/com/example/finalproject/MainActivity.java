package com.example.finalproject;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.RecyclerView;

import android.app.Application;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.ScaleGestureDetector;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.Switch;
import android.widget.Toast;

import com.example.finalproject.databinding.ActivityMainBinding;
import com.kyleduo.switchbutton.SwitchButton;

import java.util.ArrayList;
import java.util.Dictionary;

public class MainActivity extends AppCompatActivity {

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        View view = binding.getRoot();
        setContentView(view);

    }
    public class myDBHelper extends SQLiteOpenHelper{
        public myDBHelper(Context context){
            super(context,"groupDB",null,1);
        }

        @Override
        public void onCreate(SQLiteDatabase sqLiteDatabase) {
            sqLiteDatabase.execSQL("create table groupTBL (gName char(20));");
        }

        @Override
        public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
            sqLiteDatabase.execSQL("drop table if exists groupTBL");;
            onCreate(sqLiteDatabase);
        }
    }

    public void initializeDB(View view){
        myDBHelper myHelper = new myDBHelper(this);
        SQLiteDatabase sqlDB = myHelper.getWritableDatabase();
        myHelper.onUpgrade(sqlDB,1,2);
        SQLiteDatabase sqlDB2 = myHelper.getReadableDatabase();
        Cursor cursor;
        cursor = sqlDB2.rawQuery("select * from groupTBL",null);
        String string = "";
        while(cursor.moveToNext()){
            string += cursor.getString(0)+System.lineSeparator();
        }
        binding.jangbaguni.setText(string);
        cursor.close();
        sqlDB.close();
    }

    public void insertDB(View view){
        myDBHelper myHelper = new myDBHelper(this);
        SQLiteDatabase sqlDB = myHelper.getWritableDatabase();
        //sqlDB.execSQL("insert into groupTBL values('" + binding.editText1.getText().toString() +"'," + binding.editText2.getText().toString()+");");
        sqlDB.execSQL("insert into groupTBL values('"+binding.editText.getText().toString()+"');");
        binding.editText.setText("");
        SQLiteDatabase sqlDB2 = myHelper.getReadableDatabase();
        Cursor cursor;
        cursor = sqlDB2.rawQuery("select * from groupTBL",null);
        String string = "";
        while(cursor.moveToNext()){
            string += cursor.getString(0)+System.lineSeparator();
        }
        binding.jangbaguni.setText(string);
        cursor.close();
        sqlDB.close();
    }


    public void gotomap(View view){
        Intent intent = new Intent(this, Map3.class);
        String myString = binding.jangbaguni.getText().toString();
        intent.putExtra("jangbaguni",myString);
        startActivity(intent);
    }



}