#pragma once

#include <cstdint>
#include <string>

#include "common/meow_ret_code.h"
#include "common/meow_texture.h"

namespace Meow {

/**
 * @brief 贴纸、字幕的头文件
 *
 */
struct Animator {
  /**
   * @brief 设置json素材包路径，素材包资源路径
   *
   * @param json_path
   * @param resource_path
   * @return MeowRetCode
   */
  MeowRetCode ChangeEffect(std::string json_path, std::string resource_path);

  struct Point {
    int32_t x;
    int32_t y;
  };

  struct RenderParam {
    MeowTexture texture_in;
    MeowTexture texture_out;
    Point position;
    float scale;
    float rotation;
    float progress;
  };

  /**
   * @brief 绘制接口
   *
   * @param param
   * @return MeowRetCode
   */
  MeowRetCode Render(RenderParam param);

  /**
   * @brief 获取素材的宽高
   *
   * @return std::pair<float, float>
   */
  std::pair<float, float> GetSize();

  /**
   * @brief 获取素材的时长
   *
   * @return float
   */
  float GetDuration();

  /**
   * @brief 设置字体资源路径
   *
   * @param font_path
   * @return MeowRetCode
   */
  MeowRetCode SetFontPath(std::string font_path);

  struct TextStyle {
    std::string content;  ///< 点击输入文字
    int32_t text_spacing;
    int32_t line_spacint;
    int32_t text_align;
    int32_t background_color[4];  ///< RGBA
    int32_t opacity;              ///< 0-100
  };

  struct FontStyle {
    std::string font_name;
    int32_t font_size;
    int32_t fill_color[4];    ///< RGBA
    int32_t stroke_color[4];  ///< RGBA
    int32_t shadow_color[4];  ///< RGBA
    int32_t shadow_degree;
    int32_t stroke_width;
    bool is_bold;
    bool is_italic;
  };

  /**
   * @brief 设置文本样式
   *
   * @param style
   * @return MeowRetCode
   */
  MeowRetCode SetTextStyle(TextStyle style);

  /**
   * @brief 字符样式
   *
   * @param font
   * @return MeowRetCode
   */
  MeowRetCode SetFontStyle(FontStyle font);
};


}  // namespace Meow
