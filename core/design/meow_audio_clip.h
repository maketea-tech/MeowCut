#pragma once

#include <string>

#include "meow_tracing_context.h"

namespace Meow {

struct MeowAudioClip {
    /**
     * @brief 替换音视频文件路径
     *
     * @param path
     * @return true
     * @return false
     */
    bool ReplaceStreamPath(MeowTracingContext*, std::string path);

    /**
     * @brief 获取当前音视频路径
     *
     * @return std::string
     */
    std::string GetStreamPath(MeowTracingContext*);

    /**
     * @brief 获取片段在整个时间线上的入点
     *
     * @return int64_t 单位us
     */
    int64_t GetInPoint(MeowTracingContext*);

    /**
     * @brief 获取片段在整个时间线上的出点
     *
     * @return int64_t 单位us
     */
    int64_t GetOutPoint(MeowTracingContext*);

    /**
     * @brief 设置片段在整个音视频文件中的裁剪入点，默认是0
     *
     * @param trim_in 单位us
     * @return true
     * @return false
     */
    bool SetTrimIn(MeowTracingContext*, int64_t trim_in);

    /**
     * @brief 获取片段在整个音视频文件中的裁剪入点
     *
     * @return int64_t
     */
    int64_t GetTrimIn(MeowTracingContext*);

    /**
     * @brief 设置片段在整个音视频文件中的裁剪出点
     *
     * @param duration 单位us
     * @return true
     * @return false
     */
    bool SetTrimOut(MeowTracingContext*, int64_t trim_out);

    /**
     * @brief 获取片段在整个音视频文件中的裁剪出点
     *
     * @return int64_t
     */
    int64_t GetTrimOut(MeowTracingContext*);

    /**
     * @brief 获取整个片段时长，trim_out - trim_in
     *
     * @return int64_t
     */
    int64_t GetDuration(MeowTracingContext*);

    /**
     * @brief 设置倍速
     *
     * @param speed
     * @return true
     * @return false
     */
    bool SetSpeed(MeowTracingContext*, float speed);

    /**
     * @brief 设置音量大小
     *
     * @param volume [0-100]
     * @return true
     * @return false
     */
    bool SetVolume(MeowTracingContext*, int32_t volume);

    /**
     * @brief 设置淡入淡出时长
     *
     * @param fade_in
     * @param fade_out
     * @return true
     * @return false
     */
    bool SetFade(MeowTracingContext*, int64_t fade_in, int64_t fade_out);

    /**
     * @brief 设置音频特效
     *
     * @param effect_json 音效的描述字符串
     * @return true
     * @return false
     */
    bool SetAudioEffect(MeowTracingContext*, std::string effect_json);

    /**
     * @brief 清空音频特效
     *
     * @return true
     * @return false
     */
    bool ClearAudioEffect(MeowTracingContext*);

    /**
     * @brief 获取整个文件时长，该接口返回值 >= GetDuration()
     *
     * @return int64_t
     */
    int64_t GetStreamDuration(MeowTracingContext*);

    struct MeowAudioClipImpl;
    MeowAudioClipImpl* impl;
};

}  // namespace Meow
