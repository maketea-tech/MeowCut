#pragma once


#include "meowi_audio_layer_group.h"
#include "meowi_canvas_layer.h"
#include "meowi_editor_layer.h"
#include "meowi_effect_layer_group.h"
#include "meowi_engine_controller.h"
#include "meowi_pip_layer_group.h"
#include "meowi_unit_factory.h"

namespace Meow {

struct MeowEngine;

struct MeowiEngine {
  /**
   * @brief 整个Engine作用前首先调用此接口进行配置，然后才能得到相应的图层
   *
   * @return MeowiStatusCode
   */
  MeowiStatusCode Configure(MeowiVideoConfig video_config, MeowiAudioConfig audio_config);

  /**
   * @brief 获取画布图层
   *
   * @return MeowiCanvasLayer
   */
  MeowiCanvasLayer GetCanvasLayer();

  /**
   * @brief 获取编辑图层
   *
   * @return MeowiEditorLayer
   */
  MeowiEditorLayer GetEditorLayer();

  /**
   * @brief 获取音频图层组
   *
   * @return MeowiAudioLayerGroup
   */
  MeowiAudioLayerGroup GetAudioLayerGroup();

  /**
   * @brief 获取画中画图层组
   *
   * @return MeowiPipLayerGroup
   */
  MeowiPipLayerGroup GetPipLayerGroup();

  /**
   * @brief 获取特效图层组
   *
   * @return MeowiEffectLayerGroup
   */
  MeowiEffectLayerGroup GetEffectLayerGroup();

  /**
   * @brief 获取Unit工厂，具体见MeowiUnitFactory
   *
   * @return MeowiUnitFactory
   */
  MeowiUnitFactory GetUnitFactory();

  /**
   * @brief 获取Engine的控制器
   *
   * @return MeowiEngineController
   */
  MeowiEngineController GetController();

 private:
  friend class MeowiConverter;
  MeowiEngine(MeowEngine*);

  MeowEngine* impl_;
};

}  // namespace Meow
