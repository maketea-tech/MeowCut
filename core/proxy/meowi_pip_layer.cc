#include "include/meowi_pip_layer.h"

#include "meowi_converter.h"
#include "proxy_include/meow_pip_layer.h"

using namespace Meow;


MeowiStatusCode MeowiPipLayer::UpdateVideoClip(MeowiVideoClip clip, int64_t in_point) {
  return MeowiConverter::convert(impl_->UpdateVideoClip(MeowiConverter::convert(clip), in_point));
}

MeowiStatusCode MeowiPipLayer::BindVideoClip(MeowiVideoClip clip, int64_t in_point) {
  return MeowiConverter::convert(impl_->BindVideoClip(MeowiConverter::convert(clip), in_point));
}

MeowiStatusCode MeowiPipLayer::UnBindVideoClip(MeowiVideoClip clip) {
  return MeowiConverter::convert(impl_->UnBindVideoClip(MeowiConverter::convert(clip)));
}

std::vector<MeowiVideoClip> MeowiPipLayer::GetBindedClips() { return MeowiConverter::convert(impl_->GetBindedClips()); }

MeowiStatusCode MeowiPipLayer::IsAllowedBind(int64_t in_point, int64_t out_point) {
  return MeowiConverter::convert(impl_->IsAllowedBind(in_point, out_point));
}

MeowiStatusCode MeowiPipLayer::Refresh() { return MeowiConverter::convert(impl_->Refresh()); }

MeowiPipLayer::MeowiPipLayer(MeowPipLayer* ptr) : impl_{ptr} {}
