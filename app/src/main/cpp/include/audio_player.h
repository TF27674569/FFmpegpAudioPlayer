//
// Created by TIAN FENG on 2019/3/22.
//

#ifndef FFMPEGPAUDIOPLAYER_AUDIO_PLAYER_H
#define FFMPEGPAUDIOPLAYER_AUDIO_PLAYER_H

#include <string>
#include <android/log.h>
#include <stdio.h>


#define OUT_SAMPLE_RATE 44100
#define BUFFER_SIZE (OUT_SAMPLE_RATE<<1) // 16bit 44100hz 8bit = 1byte

#define TAG "FFmpegp"

#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,TAG,FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR,TAG,FORMAT,##__VA_ARGS__);



extern "C"{

//封装视频格式
#include "libavformat/avformat.h"
// 解码库
#include "libavcodec/avcodec.h"
// 缩放
#include "libswscale/swscale.h"

#include "libswresample/swresample.h"

}

extern "C" {

void audio_decode_frame(const  char* path ,void (*frame_call_back)(uint8_t* out_buffer,int fram_buffer_size));
}


#endif //FFMPEGPAUDIOPLAYER_AUDIO_PLAYER_H
