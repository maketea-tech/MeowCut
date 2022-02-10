#include "include/meowi_video_clip.h"

#include "meowi_converter.h"
#include "proxy_include/meow_video_clip.h"

using namespace Meow;

MeowiStatusCode MeowiVideoClip::SetOpacity(int32_t opacity) {
  return MeowiConverter::convert(impl_->SetOpacity(opacity));
}

MeowiStatusCode MeowiVideoClip::SetPosition(MeowiPoint position) {
  return MeowiConverter::convert(impl_->SetPosition(MeowiConverter::convert(position)));
}

MeowiStatusCode MeowiVideoClip::SetScale(float scale_x, float scale_y, float scale_z) {
  return MeowiConverter::convert(impl_->SetScale(scale_x, scale_y, scale_z));
}

MeowiStatusCode MeowiVideoClip::SetRotation(float rotation_x, float rotation_y, float rotation_z) {
  return MeowiConverter::convert(impl_->SetRotation(rotation_x, rotation_y, rotation_z));
}

MeowiStatusCode MeowiVideoClip::ReplaceStreamPath(std::string path) {
  return MeowiConverter::convert(impl_->ReplaceStreamPath(std::move(path)));
}

std::string MeowiVideoClip::GetStreamPath() { return impl_->GetStreamPath(); }

int64_t MeowiVideoClip::GetInPoint() { return impl_->GetInPoint(); }

int64_t MeowiVideoClip::GetOutPoint() { return impl_->GetOutPoint(); }

MeowiStatusCode MeowiVideoClip::SetTrimIn(int64_t trim_in) {
  return MeowiConverter::convert(impl_->SetTrimIn(trim_in));
}

int64_t MeowiVideoClip::GetTrimIn() { return impl_->GetTrimIn(); }

MeowiStatusCode MeowiVideoClip::SetTrimOut(int64_t trim_out) {
  return MeowiConverter::convert(impl_->SetTrimOut(trim_out));
}

int64_t MeowiVideoClip::GetTrimOut() { return impl_->GetTrimOut(); }

int64_t MeowiVideoClip::GetDuration() { return impl_->GetDuration(); }

MeowiStatusCode MeowiVideoClip::SetSpeed(float speed) { return MeowiConverter::convert(impl_->SetSpeed(speed)); }

MeowiStatusCode MeowiVideoClip::SetVolume(int32_t volume) { return MeowiConverter::convert(impl_->SetVolume(volume)); }

MeowiStatusCode MeowiVideoClip::SetFade(int64_t fade_in, int64_t fade_out) {
  return MeowiConverter::convert(impl_->SetFade(fade_in, fade_out));
}

MeowiStatusCode MeowiVideoClip::SetAudioEffect(std::string effect_json) {
  return MeowiConverter::convert(impl_->SetAudioEffect(std::move(effect_json)));
}

MeowiStatusCode MeowiVideoClip::ClearAudioEffect() { return MeowiConverter::convert(impl_->ClearAudioEffect()); }

int64_t MeowiVideoClip::GetStreamDuration() { return impl_->GetStreamDuration(); }

MeowiVideoClip::MeowiVideoClip(MeowVideoClip* ptr) : impl_{ptr} {}
