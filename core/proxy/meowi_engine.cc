#include "include/meowi_engine.h"

#include "meowi_converter.h"
#include "proxy_include/meow_engine.h"

using namespace Meow;

MeowiStatusCode MeowiEngine::Configure(MeowiVideoConfig video_config, MeowiAudioConfig audio_config) {
  return MeowiConverter::convert(
      impl_->Configure(MeowiConverter::convert(video_config), MeowiConverter::convert(audio_config)));
}

MeowiCanvasLayer MeowiEngine::GetCanvasLayer() { return MeowiConverter::convert(impl_->GetCanvasLayer()); }

MeowiEditorLayer MeowiEngine::GetEditorLayer() { return MeowiConverter::convert(impl_->GetEditorLayer()); }

MeowiAudioLayerGroup MeowiEngine::GetAudioLayerGroup() { return MeowiConverter::convert(impl_->GetAudioLayerGroup()); }

MeowiPipLayerGroup MeowiEngine::GetPipLayerGroup() { return MeowiConverter::convert(impl_->GetPipLayerGroup()); }

MeowiEffectLayerGroup MeowiEngine::GetEffectLayerGroup() {
  return MeowiConverter::convert(impl_->GetEffectLayerGroup());
}

MeowiUnitFactory MeowiEngine::GetUnitFactory() { return MeowiConverter::convert(impl_->GetUnitFactory()); }

MeowiEngineController MeowiEngine::GetController() { return MeowiConverter::convert(impl_->GetController()); }

MeowiEngine::MeowiEngine(MeowEngine* ptr) : impl_{ptr} {}
