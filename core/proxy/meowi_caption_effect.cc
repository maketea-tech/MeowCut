#include "include/meowi_caption_effect.h"

#include "meowi_converter.h"
#include "proxy_include/meow_caption_effect.h"

using namespace Meow;

MeowiStatusCode MeowiCaptionEffect::SetCaptionPath(std::string caption_path) {
  return MeowiConverter::convert(impl_->SetCaptionPath(std::move(caption_path)));
}

MeowiStatusCode MeowiCaptionEffect::SetPosition(MeowiPoint position) {
  return MeowiConverter::convert(impl_->SetPosition(MeowiConverter::convert(position)));
}

MeowiStatusCode MeowiCaptionEffect::SetScale(float scale_x, float scale_y, float scale_z) {
  return MeowiConverter::convert(impl_->SetScale(scale_x, scale_y, scale_z));
}

MeowiStatusCode MeowiCaptionEffect::SetRotation(float rotation_x, float rotation_y, float rotation_z) {
  return MeowiConverter::convert(impl_->SetScale(rotation_x, rotation_y, rotation_z));
}

MeowiCaptionEffect::MeowiCaptionEffect(MeowCaptionEffect* ptr) : impl_{ptr} {}
