#pragma once

#include "meowi_effect_layer.h"

namespace Meow {

struct MeowEffectLayerGroup;

/**
 * @brief LayerGroup：layer的group，内部存储多个layer，下一层的layer会覆盖上一层layer的画面
 */
struct MeowiEffectLayerGroup {
  /**
   * @brief 添加一个特效图层
   *
   * @return MeowiEffectLayer
   */
  MeowiEffectLayer AddEffectLayer();

  /**
   * @brief 删除特效图层
   *
   * @param layer
   * @return MeowiStatusCode
   */
  MeowiStatusCode DelEffectLayer(MeowiEffectLayer layer);

 private:
  friend class MeowiConverter;
  MeowiEffectLayerGroup(MeowEffectLayerGroup*);
  MeowEffectLayerGroup* impl_;
};

}  // namespace Meow
