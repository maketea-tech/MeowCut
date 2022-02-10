#pragma once

#include <cstdint>
#include <string>

#include "meowi_common.h"
#include "meowi_tracing_context.h"

namespace Meow {

struct MeowCanvasLayer;

struct MeowiCanvasLayer {
  /**
   * @brief 设置画布比例，比如9:16、1:1、16:9等
   *
   * @param numerator
   * @param denominator
   * @return MeowiStatusCode
   */
  MeowiStatusCode SetCanvasRatio(int32_t numerator, int32_t denominator);

  /**
   * @brief 设置背景颜色
   *
   * @param color
   * @return MeowiStatusCode
   */
  MeowiStatusCode SetBackGroundColor(MeowiColor color);

  /**
   * @brief 设置背景图片
   *
   * @param image_path
   * @return MeowiStatusCode
   */
  MeowiStatusCode SetBackGroundImage(std::string image_path);

  /**
   * @brief 设置背景模糊强度
   *
   * @param intensity
   * @return MeowiStatusCode
   */
  MeowiStatusCode SetBackGroundBlur(float intensity);

 private:
  friend class MeowiConverter;
  MeowiCanvasLayer(MeowCanvasLayer*);
  MeowCanvasLayer* impl_;
};

}  // namespace Meow
