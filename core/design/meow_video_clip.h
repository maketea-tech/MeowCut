#pragma once

#include "meow_audio_clip.h"
#include "meow_common.h"

namespace Meow {

struct MeowVideoClip {
    enum class VideoType {
        kImage,  ///< 图片
        kVideo   ///< 视频
    };

    /**
     * @brief 设置不透明度
     *
     * @param opacity [0-100]
     * @return true
     * @return false
     */
    bool SetOpacity(MeowTracingContext*, int32_t opacity);

    ///< **************
    ///< 移动的能力
    ///< **************

    /**
     * @brief 设置具体位置
     *
     * @param position
     * @return true
     * @return false
     */
    bool SetPosition(MeowTracingContext*, MeowPoint position);

    /**
     * @brief 设置缩放比例
     *
     * @param scale_x
     * @param scale_y
     * @param scale_z
     * @return true
     * @return false
     */
    bool SetScale(MeowTracingContext*, float scale_x, float scale_y, float scale_z);

    /**
     * @brief 设置旋转信息
     *
     * @param rotation_x 0-360
     * @param rotation_y
     * @param rotation_z
     * @return true
     * @return false
     */
    bool SetRotation(MeowTracingContext*, float rotation_x, float rotation_y, float rotation_z);

    ///< **************
    ///< 与音频的共有能力
    ///< **************

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

    struct MeowVideoClipImpl;
    MeowVideoClipImpl* impl;
};

}  // namespace Meow
