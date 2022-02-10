#pragma once

#include <string>

#include "meowi_common.h"
#include "meowi_tracing_context.h"

namespace Meow {

struct MeowStickerEffect;

struct MeowiStickerEffect {
  /**
   * @brief 设置贴纸路径
   *
   * @param sticker_path
   * @return MeowiStatusCode
   */
  MeowiStatusCode SetStickerPath(std::string sticker_path);

  ///< **************
  ///< 移动的能力
  ///< **************

  /**
   * @brief 设置具体位置
   *
   * @param position
   * @return MeowiStatusCode
   */
  MeowiStatusCode SetPosition(MeowiPoint position);

  /**
   * @brief 设置缩放比例
   *
   * @param scale_x
   * @param scale_y
   * @param scale_z
   * @return MeowiStatusCode
   */
  MeowiStatusCode SetScale(float scale_x, float scale_y, float scale_z);

  /**
   * @brief 设置旋转信息
   *
   * @param rotation_x 0-360
   * @param rotation_y
   * @param rotation_z
   * @return MeowiStatusCode
   */
  MeowiStatusCode SetRotation(float rotation_x, float rotation_y, float rotation_z);

 private:
  friend class MeowiConverter;
  MeowiStickerEffect(MeowStickerEffect*);
  MeowStickerEffect* impl_;
};


}  // namespace Meow
