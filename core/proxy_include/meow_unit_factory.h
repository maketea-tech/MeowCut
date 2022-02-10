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
  MeowAudioClip* AddAudioClip(std::string path);

  /**
   * @brief 删除某个音频片段
   *
   * @param audio_clip
   * @return MeowStatusCode
   */
  MeowStatusCode DelAudioClip(MeowAudioClip* audio_clip);

  /**
   * @brief 添加一个视频片段
   *
   * @param path
   * @return MeowVideoClip*
   */
  MeowVideoClip* AddVideoClip(std::string path);

  /**
   * @brief 删除某个视频片段
   *
   * @param video_clip
   * @return MeowStatusCode
   */
  MeowStatusCode DelVideoClip(MeowVideoClip* video_clip);

  /**
   * @brief 添加一个贴纸特效实例
   *
   * @return MeowStickerEffect*
   */
  MeowStickerEffect* AddStickerEffect();

  /**
   * @brief 删除贴纸实例
   *
   * @param sticker
   * @return MeowStatusCode
   */
  MeowStatusCode DelStickerEffect(MeowStickerEffect* sticker);

  /**
   * @brief 添加一个字幕特效实例
   *
   * @return MeowCaptionEffect*
   */
  MeowCaptionEffect* AddCaptionEffect();

  /**
   * @brief 删除字幕特效实例
   *
   * @param caption
   * @return MeowStatusCode
   */
  MeowStatusCode DelCaptionEffect(MeowCaptionEffect* caption);

  struct MeowUnitFactoryImpl;
  MeowUnitFactoryImpl* impl;
};

}  // namespace Meow
