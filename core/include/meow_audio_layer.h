#pragma once

#include <vector>

#include "meow_audio_clip.h"

namespace Meow {

struct MeowAudioLayer {
    /**
     * @brief 更新某一片段在时间线上的入点，仅用于当前layer上已绑定的clip
     *
     * @param clip
     * @param in_point
     * @return MeowStatusCode
     */
    MeowStatusCode UpdateAudioClip(MeowAudioClip* clip, int64_t in_point);

    /**
     * @brief 绑定某个音频片段到此layer上
     *
     * @param clip
     * @param in_point
     * @return MeowStatusCode
     */
    MeowStatusCode BindAudioClip(MeowAudioClip* clip, int64_t in_point);

    /**
     * @brief 片段和layer解绑
     *
     * @param clip
     * @return MeowStatusCode
     */
    MeowStatusCode UnBindAudioClip(MeowAudioClip* clip);

    /**
     * @brief 获取当前已经绑定的音频片段
     *
     * @return std::vector<MeowAudioClip*>
     */
    std::vector<MeowAudioClip*> GetBindedClips();

    /**
     * @brief 入点in_point，出点为out_point的片段是否允许绑定到当前layer上
     *
     * @param in_point
     * @param out_point
     * @return MeowStatusCode
     */
    MeowStatusCode IsAllowedBind(int64_t in_point, int64_t out_point);

    /**
     * @brief 更新layer中所有片段的in_point和out_point，配置完该layer中clip的trim_in等属性后，需要调用此接口
     *
     * @return MeowStatusCode
     */
    MeowStatusCode Refresh();

    struct MeowAudioLayerImpl;
    MeowAudioLayerImpl* impl;
};

}  // namespace Meow
