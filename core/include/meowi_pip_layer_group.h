#pragma once

#include "meowi_pip_layer.h"

namespace Meow {

struct MeowPipLayerGroup;

/**
 * @brief LayerGroup：layer的group，内部存储多个layer，下一层的layer会覆盖上一层layer的画面
 */
struct MeowiPipLayerGroup {
  /**
   * @brief 添加一个画中画图层
   *
   * @return MeowiPipLayer
   */
  MeowiPipLayer AddPipLayer();

  /**
   * @brief 删除画中画图层
   *
   * @param layer
   * @return MeowiStatusCode
   */
  MeowiStatusCode DelPipLayer(MeowiPipLayer layer);

 private:
  friend class MeowiConverter;
  MeowiPipLayerGroup(MeowPipLayerGroup*);
  MeowPipLayerGroup* impl_;
};

}  // namespace Meow
