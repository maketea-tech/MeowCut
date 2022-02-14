#pragma once

#include "meow_audio_layer.h"

namespace Meow {

/**
 * @brief LayerGroup：layer的group，内部存储多个layer，下一层的layer会覆盖上一层layer的画面
 */
struct MeowAudioLayerGroup {
  /**
   * @brief 添加一个音频层
   *
   * @return MeowAudioLayer*
   */
  MeowAudioLayer* AddAudioLayer();

  /**
   * @brief 删除音频层，删除layer时，需要先获取layer中所有binded clip，逐个删除
   *
   * @param layer
   * @return MeowStatusCode
   */
  MeowStatusCode DelAudioLayer(MeowAudioLayer* layer);
};

}  // namespace Meow
