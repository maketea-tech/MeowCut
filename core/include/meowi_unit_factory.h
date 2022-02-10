#pragma once

#include "meowi_audio_clip.h"
#include "meowi_caption_effect.h"
#include "meowi_sticker_effect.h"
#include "meowi_video_clip.h"

namespace Meow {

struct MeowUnitFactory;

struct MeowiUnitFactory {
  /**
   * @brief 添加一个音频片段
   *
   * @param path
   * @return MeowiAudioClip
   */
  MeowiAudioClip AddAudioClip(std::string path);

  /**
   * @brief 删除某个音频片段
   *
   * @param audio_clip
   * @return MeowiStatusCode
   */
  MeowiStatusCode DelAudioClip(MeowiAudioClip audio_clip);

  /**
   * @brief 添加一个视频片段
   *
   * @param path
   * @return MeowiVideoClip
   */
  MeowiVideoClip AddVideoClip(std::string path);

  /**
   * @brief 删除某个视频片段
   *
   * @param video_clip
   * @return MeowiStatusCode
   */
  MeowiStatusCode DelVideoClip(MeowiVideoClip video_clip);

  /**
   * @brief 添加一个贴纸特效实例
   *
   * @return MeowiStickerEffect
   */
  MeowiStickerEffect AddStickerEffect();

  /**
   * @brief 删除贴纸实例
   *
   * @param sticker
   * @return MeowiStatusCode
   */
  MeowiStatusCode DelStickerEffect(MeowiStickerEffect sticker);

  /**
   * @brief 添加一个字幕特效实例
   *
   * @return MeowiCaptionEffect
   */
  MeowiCaptionEffect AddCaptionEffect();

  /**
   * @brief 删除字幕特效实例
   *
   * @param caption
   * @return MeowiStatusCode
   */
  MeowiStatusCode DelCaptionEffect(MeowiCaptionEffect caption);

 private:
  friend class MeowiConverter;
  MeowiUnitFactory(MeowUnitFactory*);
  MeowUnitFactory* impl_;
};

}  // namespace Meow
