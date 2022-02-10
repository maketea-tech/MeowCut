#pragma once

#include <cstdint>
#include <string>

#include "meow_common.h"
#include "meow_tracing_context.h"

namespace Meow {

struct MeowCanvasLayer {
  /**
   * @brief 设置画布比例，比如9:16、1:1、16:9等
   *
   * @param numerator
   * @param denominator
   * @return MeowStatusCode
   */
  MeowStatusCode SetCanvasRatio(int32_t numerator, int32_t denominator);

  /**
   * @brief 设置背景颜色
   *
   * @param color
   * @return MeowStatusCode
   */
  MeowStatusCode SetBackGroundColor(MeowColor color);

  /**
   * @brief 设置背景图片
   *
   * @param image_path
   * @return MeowStatusCode
   */
  MeowStatusCode SetBackGroundImage(std::string image_path);

  /**
   * @brief 设置背景模糊强度
   *
   * @param intensity
   * @return MeowStatusCode
   */
  MeowStatusCode SetBackGroundBlur(float intensity);

  struct MeowCanvasLayerImpl;
  MeowCanvasLayerImpl* impl;
};

}  // namespace Meow
