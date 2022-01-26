#pragma once

#include "meow_tracing_context.h"
#include "meow_video_clip.h"


namespace Meow {

struct MeowEditorLayer {
    struct TransitionInfo {
        std::string json_path;  ///< 转场的类型，通过json表示
        int64_t total_time;     ///< 转场时间
        int64_t first_time;     ///< 第一个视频参与转场的时间
        int64_t second_time;    ///< 第二个视频参与转场的时间
        int64_t overlap_time;   ///< 两个视频的重叠时间，total = first + second - overlap
    };

    /**
     * @brief 追加视频片段
     *
     * @param video_path
     * @return MeowVideoClip*
     */
    MeowVideoClip* AppendVideoClip(MeowTracingContext*, std::string video_path);

    /**
     * @brief 在某个位置插入视频片段
     *
     * @param index
     * @param video_path
     * @return MeowVideoClip*
     */
    MeowVideoClip* InsertVideoClip(MeowTracingContext*, int32_t index, std::string video_path);

    /**
     * @brief 对某两个片段之间应用转场效果，index为前一个片段的索引
     *
     * @param index
     * @param transition
     * @return true
     * @return false
     */
    bool ApplyTransition(MeowTracingContext*, int32_t index, TransitionInfo transition);

    /**
     * @brief 取消转场效果
     *
     * @param index
     * @return true
     * @return false
     */
    bool CancelTransition(MeowTracingContext*, int32_t index);

    // 定格

    struct MeowEditorLayerImpl;
    MeowEditorLayerImpl* impl;
};

}  // namespace Meow
