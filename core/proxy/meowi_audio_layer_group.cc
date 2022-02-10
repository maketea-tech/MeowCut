#include "include/meowi_audio_layer_group.h"

#include "meowi_converter.h"
#include "proxy_include/meow_audio_layer_group.h"

using namespace Meow;

MeowiAudioLayer MeowiAudioLayerGroup::AddAudioLayer() { return MeowiConverter::convert(impl_->AddAudioLayer()); }

MeowiStatusCode MeowiAudioLayerGroup::DelAudioLayer(MeowiAudioLayer layer) {
  return MeowiConverter::convert(impl_->DelAudioLayer(MeowiConverter::convert(layer)));
}

MeowiAudioLayerGroup::MeowiAudioLayerGroup(MeowAudioLayerGroup* ptr) : impl_{ptr} {}
