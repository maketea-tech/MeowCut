#pragma once

#include "meow_audio_clip.h"
#include "meow_caption_effect.h"
#include "meow_sticker_effect.h"
#include "meow_video_clip.h"

namespace Meow {

struct MeowUnitFactory {
    /**
     * @brief 添加一个音频片段
     *
     * @param path
     * @return MeowAudioClip*
     */
    MeowAudioClip* AddAudioClip(MeowTracingContext*, std::string path);

    /**
     * @brief 删除某个音频片段
     *
     * @param audio_clip
     * @return true
     * @return false
     */
    bool DelAudioClip(MeowTracingContext*, MeowAudioClip* audio_clip);

    /**
     * @brief 添加一个视频片段
     *
     * @param path
     * @return MeowVideoClip*
     */
    MeowVideoClip* AddVideoClip(MeowTracingContext*, std::string path);

    /**
     * @brief 删除某个视频片段
     *
     * @param video_clip
     * @return true
     * @return false
     */
    bool DelVideoClip(MeowTracingContext*, MeowVideoClip* video_clip);

    /**
     * @brief 添加一个贴纸特效实例
     *
     * @return MeowStickerEffect*
     */
    MeowStickerEffect* AddStickerEffect(MeowTracingContext*);

    /**
     * @brief 删除贴纸实例
     *
     * @param sticker
     * @return true
     * @return false
     */
    bool DelStickerEffect(MeowTracingContext*, MeowStickerEffect* sticker);

    /**
     * @brief 添加一个字幕特效实例
     *
     * @return MeowCaptionEffect*
     */
    MeowCaptionEffect* AddCaptionEffect(MeowTracingContext*);

    /**
     * @brief 删除字幕特效实例
     *
     * @param caption
     * @return true
     * @return false
     */
    bool DelCaptionEffect(MeowTracingContext*, MeowCaptionEffect* caption);

    struct MeowUnitFactoryImpl;
    MeowUnitFactoryImpl* impl;
};

}  // namespace Meow
