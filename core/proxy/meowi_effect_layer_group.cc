#include "include/meowi_effect_layer_group.h"

#include "meowi_converter.h"
#include "proxy_include/meow_effect_layer_group.h"

using namespace Meow;

MeowiEffectLayer MeowiEffectLayerGroup::AddEffectLayer() { return MeowiConverter::convert(impl_->AddEffectLayer()); }

MeowiStatusCode MeowiEffectLayerGroup::DelEffectLayer(MeowiEffectLayer layer) {
  return MeowiConverter::convert(impl_->DelEffectLayer(MeowiConverter::convert(layer)));
}

MeowiEffectLayerGroup::MeowiEffectLayerGroup(MeowEffectLayerGroup* ptr) : impl_{ptr} {}
