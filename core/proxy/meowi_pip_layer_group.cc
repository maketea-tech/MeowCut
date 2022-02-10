#include "include/meowi_pip_layer_group.h"

#include "meowi_converter.h"
#include "proxy_include/meow_pip_layer_group.h"

using namespace Meow;

MeowiPipLayer MeowiPipLayerGroup::AddPipLayer() { return MeowiConverter::convert(impl_->AddPipLayer()); }

MeowiStatusCode MeowiPipLayerGroup::DelPipLayer(MeowiPipLayer layer) {
  return MeowiConverter::convert(impl_->DelPipLayer(MeowiConverter::convert(layer)));
}

MeowiPipLayerGroup::MeowiPipLayerGroup(MeowPipLayerGroup* ptr) : impl_{ptr} {}
