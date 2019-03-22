

#include "audio_player.h"
#include <jni.h>

JNIEnv*  app_env;
jclass audio_player_class;
jmethodID jni_callback_with_frame_id;
jbyte* frame_data;
jbyteArray frame_data_arr;


// 回掉接口 如果这里不回掉java可以直接拿java层的对象 直接使用jni的方式 操作AudioTrack调用AudioTrack的write函数
void playByAudioTrack(uint8_t* out_buffer,int fram_buffer_size){
    memcpy(frame_data,out_buffer,fram_buffer_size);
    app_env->CallStaticVoidMethod(audio_player_class,jni_callback_with_frame_id,frame_data_arr,fram_buffer_size);
}


extern "C"
JNIEXPORT void JNICALL
Java_com_sample_player_ffmpegp_AudioPlayer_playWithAudioTrack(JNIEnv *env, jclass type,
                                                              jstring path_) {
    const char *path = env->GetStringUTFChars(path_, 0);

    app_env = env;
    audio_player_class = type;
    jni_callback_with_frame_id = env->GetStaticMethodID(type,"jniCallBackWithFrame","([BI)V");
    frame_data_arr = env->NewByteArray(BUFFER_SIZE);
    frame_data = env->GetByteArrayElements(frame_data_arr,NULL);
    // 解码并回掉帧
    audio_decode_frame(path,playByAudioTrack);

    // 结束后释放arr资源
    env->ReleaseByteArrayElements(frame_data_arr,frame_data,NULL);
    env->DeleteLocalRef(frame_data_arr);

    env->ReleaseStringUTFChars(path_, path);
}