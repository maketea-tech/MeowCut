#pragma once

#include "meow_pip_layer.h"

namespace Meow {

/**
 * @brief LayerGroup：layer的group，内部存储多个layer，下一层的layer会覆盖上一层layer的画面
 */
struct MeowPipLayerGroup {
  /**
   * @brief 添加一个画中画图层
   *
   * @return MeowPipLayer*
   */
  MeowPipLayer* AddPipLayer();

  /**
   * @brief 删除画中画图层
   *
   * @param layer
   * @return MeowStatusCode
   */
  MeowStatusCode DelPipLayer(MeowPipLayer* layer);
};

}  // namespace Meow
