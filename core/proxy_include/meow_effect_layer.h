#pragma once

#include <vector>

#include "meow_caption_effect.h"
#include "meow_sticker_effect.h"

namespace Meow {

struct MeowEffectLayer {
  /**
   * @brief 更新贴纸特效位置
   *
   * @param effect
   * @param in_point
   * @return MeowStatusCode
   */
  MeowStatusCode UpdateSticker(MeowStickerEffect* effect, int64_t in_point);

  /**
   * @brief 绑定贴纸
   *
   * @param effect
   * @param in_point
   * @return MeowStatusCode
   */
  MeowStatusCode BindSticker(MeowStickerEffect* effect, int64_t in_point);

  /**
   * @brief 解绑贴纸
   *
   * @param effect
   * @return MeowStatusCode
   */
  MeowStatusCode UnBindSticker(MeowStickerEffect* effect);

  /**
   * @brief 获取当前layer已经绑定的贴纸
   *
   * @return std::vector<MeowStickerEffect*>
   */
  std::vector<MeowStickerEffect*> GetBindedSticker();

  ///< 字幕

  /**
   * @brief 更新字幕特效位置
   *
   * @param effect
   * @param in_point
   * @return MeowStatusCode
   */
  MeowStatusCode UpdateCaption(MeowCaptionEffect* effect, int64_t in_point);

  /**
   * @brief 绑定字幕
   *
   * @param effect
   * @param in_point
   * @return MeowStatusCode
   */
  MeowStatusCode BindCaption(MeowCaptionEffect* effect, int64_t in_point);

  /**
   * @brief 解绑字幕
   *
   * @param effect
   * @return MeowStatusCode
   */
  MeowStatusCode UnBindCaption(MeowCaptionEffect* effect);

  /**
   * @brief 获取当前layer已经绑定的字幕
   *
   * @return std::vector<MeowCaptionEffect*>
   */
  std::vector<MeowCaptionEffect*> GetBindedCaption();

  ///< other

  /**
   * @brief 入点in_point，出点为out_point的effect是否允许绑定到当前layer上
   *
   * @param in_point
   * @param out_point
   * @return MeowStatusCode
   */
  MeowStatusCode IsAllowedBind(int64_t in_point, int64_t out_point);

  /**
   * @brief 更新layer中所有effect的in_point和out_point
   *
   * @return MeowStatusCode
   */
  MeowStatusCode Refresh();

  struct MeowEffectLayerImpl;
  MeowEffectLayerImpl* impl;
};

}  // namespace Meow
