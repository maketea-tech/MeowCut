#pragma once

#include "meowi_audio_layer.h"

namespace Meow {

struct MeowAudioLayerGroup;

/**
 * @brief LayerGroup：layer的group，内部存储多个layer，下一层的layer会覆盖上一层layer的画面
 */
struct MeowiAudioLayerGroup {
  /**
   * @brief 添加一个音频层
   *
   * @return MeowiAudioLayer
   */
  MeowiAudioLayer AddAudioLayer();

  /**
   * @brief 删除音频层，删除layer时，需要先获取layer中所有binded clip，逐个删除
   *
   * @param layer
   * @return MeowiStatusCode
   */
  MeowiStatusCode DelAudioLayer(MeowiAudioLayer layer);

 private:
  friend class MeowiConverter;
  MeowiAudioLayerGroup(MeowAudioLayerGroup*);
  MeowAudioLayerGroup* impl_;
};

}  // namespace Meow
