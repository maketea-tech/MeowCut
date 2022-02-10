#pragma once

#include "meow_effect_layer.h"

namespace Meow {

/**
 * @brief LayerGroup：layer的group，内部存储多个layer，下一层的layer会覆盖上一层layer的画面
 */
struct MeowEffectLayerGroup {
  /**
   * @brief 添加一个特效图层
   *
   * @return MeowEffectLayer*
   */
  MeowEffectLayer* AddEffectLayer();

  /**
   * @brief 删除特效图层
   *
   * @param layer
   * @return MeowStatusCode
   */
  MeowStatusCode DelEffectLayer(MeowEffectLayer* layer);

  struct MeowEffectLayerGroupImpl;
  MeowEffectLayerGroupImpl* impl;
};

}  // namespace Meow
