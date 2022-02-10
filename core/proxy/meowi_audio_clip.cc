#include "include/meowi_audio_clip.h"

#include "meowi_converter.h"
#include "proxy_include/meow_audio_clip.h"

using namespace Meow;

MeowiStatusCode MeowiAudioClip::ReplaceStreamPath(std::string path) {
  return MeowiConverter::convert(impl_->ReplaceStreamPath(std::move(path)));
}

std::string MeowiAudioClip::GetStreamPath() { return std::move(impl_->GetStreamPath()); }

int64_t MeowiAudioClip::GetInPoint() { return impl_->GetInPoint(); }

int64_t MeowiAudioClip::GetOutPoint() { return impl_->GetOutPoint(); }

MeowiStatusCode MeowiAudioClip::SetTrimIn(int64_t trim_in) {
  return MeowiConverter::convert(impl_->SetTrimIn(trim_in));
}

int64_t MeowiAudioClip::GetTrimIn() { return impl_->GetTrimIn(); }

MeowiStatusCode MeowiAudioClip::SetTrimOut(int64_t trim_out) {
  return MeowiConverter::convert(impl_->SetTrimOut(trim_out));
}

int64_t MeowiAudioClip::GetTrimOut() { return impl_->GetTrimOut(); }

int64_t MeowiAudioClip::GetDuration() { return impl_->GetDuration(); }

MeowiStatusCode MeowiAudioClip::SetSpeed(float speed) { return MeowiConverter::convert(impl_->SetSpeed(speed)); }

MeowiStatusCode MeowiAudioClip::SetVolume(int32_t volume) { return MeowiConverter::convert(impl_->SetVolume(volume)); }

MeowiStatusCode MeowiAudioClip::SetFade(int64_t fade_in, int64_t fade_out) {
  return MeowiConverter::convert(impl_->SetFade(fade_in, fade_out));
}

MeowiStatusCode MeowiAudioClip::SetAudioEffect(std::string effect_json) {
  return MeowiConverter::convert(impl_->SetAudioEffect(std::move(effect_json)));
}

MeowiStatusCode MeowiAudioClip::ClearAudioEffect() { return MeowiConverter::convert(impl_->ClearAudioEffect()); }

int64_t MeowiAudioClip::GetStreamDuration() { return impl_->GetStreamDuration(); }

MeowiAudioClip::MeowiAudioClip(MeowAudioClip* ptr) : impl_{ptr} {}
