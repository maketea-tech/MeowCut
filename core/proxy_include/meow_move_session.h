#pragma once

#include "meow_common.h"
#include "meow_tracing_context.h"

/**
 * @brief 此头文件暂时没用，如果考虑用继承方式，可以用到此结构
 *
 */
namespace Meow {

struct MeowMoveSession {
  /**
   * @brief 设置具体位置
   *
   * @param position
   * @return MeowStatusCode
   */
  MeowStatusCode SetPosition(MeowPoint position);

  /**
   * @brief 设置缩放比例
   *
   * @param scale_x
   * @param scale_y
   * @param scale_z
   * @return MeowStatusCode
   */
  MeowStatusCode SetScale(float scale_x, float scale_y, float scale_z);

  /**
   * @brief 设置旋转信息
   *
   * @param rotation_x 0-360
   * @param rotation_y
   * @param rotation_z
   * @return MeowStatusCode
   */
  MeowStatusCode SetRotation(float rotation_x, float rotation_y, float rotation_z);

  struct MeowMoveSessionImpl;
  MeowMoveSessionImpl* impl;
};

}  // namespace Meow
