#pragma once

#include <vector>

#include "meowi_caption_effect.h"
#include "meowi_sticker_effect.h"

namespace Meow {

struct MeowEffectLayer;

struct MeowiEffectLayer {
  /**
   * @brief 更新贴纸特效位置
   *
   * @param effect
   * @param in_point
   * @return MeowiStatusCode
   */
  MeowiStatusCode UpdateSticker(MeowiStickerEffect effect, int64_t in_point);

  /**
   * @brief 绑定贴纸
   *
   * @param effect
   * @param in_point
   * @return MeowiStatusCode
   */
  MeowiStatusCode BindSticker(MeowiStickerEffect effect, int64_t in_point);

  /**
   * @brief 解绑贴纸
   *
   * @param effect
   * @return MeowiStatusCode
   */
  MeowiStatusCode UnBindSticker(MeowiStickerEffect effect);

  /**
   * @brief 获取当前layer已经绑定的贴纸
   *
   * @return std::vector<MeowiStickerEffect>
   */
  std::vector<MeowiStickerEffect> GetBindedSticker();

  ///< 字幕

  /**
   * @brief 更新字幕特效位置
   *
   * @param effect
   * @param in_point
   * @return MeowiStatusCode
   */
  MeowiStatusCode UpdateCaption(MeowiCaptionEffect effect, int64_t in_point);

  /**
   * @brief 绑定字幕
   *
   * @param effect
   * @param in_point
   * @return MeowiStatusCode
   */
  MeowiStatusCode BindCaption(MeowiCaptionEffect effect, int64_t in_point);

  /**
   * @brief 解绑字幕
   *
   * @param effect
   * @return MeowiStatusCode
   */
  MeowiStatusCode UnBindCaption(MeowiCaptionEffect effect);

  /**
   * @brief 获取当前layer已经绑定的字幕
   *
   * @return std::vector<MeowiCaptionEffect>
   */
  std::vector<MeowiCaptionEffect> GetBindedCaption();

  ///< other

  /**
   * @brief 入点in_point，出点为out_point的effect是否允许绑定到当前layer上
   *
   * @param in_point
   * @param out_point
   * @return MeowiStatusCode
   */
  MeowiStatusCode IsAllowedBind(int64_t in_point, int64_t out_point);

  /**
   * @brief 更新layer中所有effect的in_point和out_point
   *
   * @return MeowiStatusCode
   */
  MeowiStatusCode Refresh();

 private:
  friend class MeowiConverter;
  MeowiEffectLayer(MeowEffectLayer*);
  MeowEffectLayer* impl_;
};

}  // namespace Meow
