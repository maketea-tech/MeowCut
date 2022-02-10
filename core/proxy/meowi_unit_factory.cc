#include "include/meowi_unit_factory.h"

#include "meowi_converter.h"
#include "proxy_include/meow_unit_factory.h"

using namespace Meow;

MeowiAudioClip MeowiUnitFactory::AddAudioClip(std::string path) {
  return MeowiConverter::convert(impl_->AddAudioClip(std::move(path)));
}

MeowiStatusCode MeowiUnitFactory::DelAudioClip(MeowiAudioClip audio_clip) {
  return MeowiConverter::convert(impl_->DelAudioClip(MeowiConverter::convert(audio_clip)));
}

MeowiVideoClip MeowiUnitFactory::AddVideoClip(std::string path) {
  return MeowiConverter::convert(impl_->AddVideoClip(std::move(path)));
}

MeowiStatusCode MeowiUnitFactory::DelVideoClip(MeowiVideoClip video_clip) {
  return MeowiConverter::convert(impl_->DelVideoClip(MeowiConverter::convert(video_clip)));
}

MeowiStickerEffect MeowiUnitFactory::AddStickerEffect() { return MeowiConverter::convert(impl_->AddStickerEffect()); }

MeowiStatusCode MeowiUnitFactory::DelStickerEffect(MeowiStickerEffect sticker) {
  return MeowiConverter::convert(impl_->DelStickerEffect(MeowiConverter::convert(sticker)));
}

MeowiCaptionEffect MeowiUnitFactory::AddCaptionEffect() { return MeowiConverter::convert(impl_->AddCaptionEffect()); }

MeowiStatusCode MeowiUnitFactory::DelCaptionEffect(MeowiCaptionEffect caption) {
  return MeowiConverter::convert(impl_->DelCaptionEffect(MeowiConverter::convert(caption)));
}

MeowiUnitFactory::MeowiUnitFactory(MeowUnitFactory* ptr) : impl_{ptr} {}
