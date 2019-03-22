package com.sample.player.ffmpegp;

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;

/**
 * Description :
 * <p>
 * Created : TIAN FENG
 * Date : 2019/3/22
 * Email : 27674569@qq.com
 * Version : 1.0
 */
public class AudioPlayer {

    static {
        System.loadLibrary("avcodec-56");
        System.loadLibrary("avdevice-56");
        System.loadLibrary("avfilter-5");
        System.loadLibrary("avformat-56");
        System.loadLibrary("avutil-54");
        System.loadLibrary("postproc-53");
        System.loadLibrary("swresample-1");
        System.loadLibrary("swscale-3");
        System.loadLibrary("ffmpegp_audio_player");
    }

    private static final int SAMPLE_RATEIN_HZ = 44100;

    private final static  AudioTrack S_AUDIO_TRACK = new AudioTrack(
            AudioManager.STREAM_MUSIC,
            SAMPLE_RATEIN_HZ,
            AudioFormat.CHANNEL_OUT_STEREO,
            AudioFormat.ENCODING_PCM_16BIT,
            AudioTrack.getMinBufferSize(SAMPLE_RATEIN_HZ,AudioFormat.CHANNEL_OUT_STEREO,AudioFormat.ENCODING_PCM_16BIT),
            AudioTrack.MODE_STREAM
            );



    public static void play1(String path){
        S_AUDIO_TRACK.play();
        // 这个函数里面解码帧 回掉jniCallBackWithFrame 这一步可以放在jni调用
        playWithAudioTrack(path);
    }

    private static void jniCallBackWithFrame(byte[] audioData,int sizeInBytes){
        S_AUDIO_TRACK.write(audioData,0,sizeInBytes);
    }


    private native static void playWithAudioTrack(String path);

}
