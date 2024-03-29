# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        ffmpegp_audio_player

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        audio_player.cpp
        ffmpegp_audio_player.cpp)

#引入头文件
include_directories(${CMAKE_SOURCE_DIR}/include)

#引入第三方so
link_directories(${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/)




find_library(
        log-lib

        log )

# 编解码库
add_library( avcodec-56
        SHARED
        IMPORTED )
set_target_properties( avcodec-56
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libavcodec-56.so)

#输出输入设备的支持
add_library( avdevice-56
        SHARED
        IMPORTED )
set_target_properties( avdevice-56
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libavdevice-56.so)

#滤镜
add_library( avfilter-5
        SHARED
        IMPORTED )
set_target_properties( avfilter-5
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libavfilter-5.so)


#数据封装格式的库
add_library( avformat-56
        SHARED
        IMPORTED )
set_target_properties( avformat-56
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libavformat-56.so)


# 工具包
add_library( avutil-54
        SHARED
        IMPORTED )
set_target_properties( avutil-54
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libavutil-54.so)


add_library( postproc-53
        SHARED
        IMPORTED )
set_target_properties( postproc-53
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libpostproc-53.so)


add_library( swresample-1
        SHARED
        IMPORTED )
set_target_properties( swresample-1
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libswresample-1.so)


#像素格式转换 缩放
add_library( swscale-3
        SHARED
        IMPORTED )
set_target_properties( swscale-3
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libswscale-3.so)



target_link_libraries( # Specifies the target library.
        ffmpegp_audio_player

        #链接第三方库
        avcodec-56
        avdevice-56
        avfilter-5
        avformat-56
        avutil-54
        postproc-53
        swresample-1
        swscale-3

        ${log-lib})