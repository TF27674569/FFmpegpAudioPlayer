package com.sample.player;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;

import com.sample.player.ffmpegp.AudioPlayer;

import java.io.File;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void playWithAudioTrack(View view) {
        final File file = new File(Environment.getExternalStorageDirectory().getPath(),"input.mp4");
        Log.e("TAG", file.getAbsolutePath() + "   exists = " + file.exists() );
        new Thread(){
            @Override
            public void run() {
                AudioPlayer.play1(file.getAbsolutePath());
            }
        }.start();

    }
}
