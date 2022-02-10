#include "include/meowi_audio_layer.h"

#include "meowi_converter.h"
#include "proxy_include/meow_audio_layer.h"

using namespace Meow;


MeowiStatusCode MeowiAudioLayer::UpdateAudioClip(MeowiAudioClip clip, int64_t in_point) {
  return MeowiConverter::convert(impl_->UpdateAudioClip(MeowiConverter::convert(clip), in_point));
}

MeowiStatusCode MeowiAudioLayer::BindAudioClip(MeowiAudioClip clip, int64_t in_point) {
  return MeowiConverter::convert(impl_->BindAudioClip(MeowiConverter::convert(clip), in_point));
}

MeowiStatusCode MeowiAudioLayer::UnBindAudioClip(MeowiAudioClip clip) {
  return MeowiConverter::convert(impl_->UnBindAudioClip(MeowiConverter::convert(clip)));
}

std::vector<MeowiAudioClip> MeowiAudioLayer::GetBindedClips() {
  return MeowiConverter::convert(impl_->GetBindedClips());
}

MeowiStatusCode MeowiAudioLayer::IsAllowedBind(int64_t in_point, int64_t out_point) {
  return MeowiConverter::convert(impl_->IsAllowedBind(in_point, out_point));
}

MeowiStatusCode MeowiAudioLayer::Refresh() { return MeowiConverter::convert(impl_->Refresh()); }

MeowiAudioLayer::MeowiAudioLayer(MeowAudioLayer* ptr) : impl_{ptr} {}
