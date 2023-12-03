package com.example.finalproject;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.motion.widget.MotionHelperInterface;

import android.content.Intent;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.ScaleGestureDetector;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import com.example.finalproject.databinding.ActivityMainBinding;
import com.example.finalproject.databinding.ActivityMap3Binding;

public class Map3 extends AppCompatActivity {

    private ActivityMap3Binding binding;
    ScaleGestureDetector scaleGestureDetector;
    private ActivityResultLauncher<Intent> resultLauncher;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMap3Binding.inflate(getLayoutInflater());
        View view = binding.getRoot();
        setContentView(view);

        Bundle extras = getIntent().getExtras();
        if(extras==null){
            return ;
        }

        String jangbaguni = extras.getString("jangbaguni");
        binding.editText2.setText(jangbaguni);

        scaleGestureDetector = new ScaleGestureDetector(this,new MyonScaleGestureListener());

        resultLauncher = registerForActivityResult(
                new ActivityResultContracts.StartActivityForResult(),
                new ActivityResultCallback<ActivityResult>() {
                    @Override
                    public void onActivityResult(ActivityResult result) {
                        if(result.getResultCode() == RESULT_OK){
                            Intent data = result.getData();
                            String returnString = data.getExtras().getString("jangbaguni");
                            binding.editText2.setText(returnString);
                        }
                    }
                }
        );
    }

    public boolean onTouchEvent(MotionEvent event){
        scaleGestureDetector.onTouchEvent(event);
        return true;
    }
    public class MyonScaleGestureListener extends ScaleGestureDetector.SimpleOnScaleGestureListener{
        @Override
        public boolean onScale(ScaleGestureDetector detector) {
            float scaleFactor = detector.getScaleFactor();

            if(scaleFactor > 1){
                //zoom in
            }
            else{

            }
            return true;
        }

        @Override
        public boolean onScaleBegin(ScaleGestureDetector detector) {
            return true;
        }

        @Override
        public void onScaleEnd(ScaleGestureDetector detector) {

        }
    }

    public void gobackjangbaguni(View view){
        Intent data = new Intent();
        String returnString = binding.editText2.getText().toString();
        data.putExtra("jangbaguni",returnString);
        setResult(RESULT_OK,data);
        super.finish();
    }

    public void gotoitem1(View view){
        Intent intent = new Intent(this, item1.class);
        String myString = binding.editText2.getText().toString();
        intent.putExtra("jangbaguni",myString);
        resultLauncher.launch(intent);
    }

    public void gotoitem2(View view){
        Intent intent = new Intent(this, item2.class);
        String myString = binding.editText2.getText().toString();
        intent.putExtra("jangbaguni",myString);
        resultLauncher.launch(intent);
    }

    public void gotoitem3(View view){
        Intent intent = new Intent(this, item3.class);
        String myString = binding.editText2.getText().toString();
        intent.putExtra("jangbaguni",myString);
        resultLauncher.launch(intent);
    }

    public void gotoitem4(View view){
        Intent intent = new Intent(this, item4.class);
        String myString = binding.editText2.getText().toString();
        intent.putExtra("jangbaguni",myString);
        resultLauncher.launch(intent);
    }

    public void gotoitem5(View view){
        Intent intent = new Intent(this, item5.class);
        String myString = binding.editText2.getText().toString();
        intent.putExtra("jangbaguni",myString);
        resultLauncher.launch(intent);
    }
}