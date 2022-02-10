#include "include/meowi_sticker_effect.h"

#include "meowi_converter.h"
#include "proxy_include/meow_sticker_effect.h"

using namespace Meow;


MeowiStatusCode MeowiStickerEffect::SetStickerPath(std::string sticker_path) {
  return MeowiConverter::convert(impl_->SetStickerPath(std::move(sticker_path)));
}

MeowiStatusCode MeowiStickerEffect::SetPosition(MeowiPoint position) {
  return MeowiConverter::convert(impl_->SetPosition(MeowiConverter::convert(position)));
}

MeowiStatusCode MeowiStickerEffect::SetScale(float scale_x, float scale_y, float scale_z) {
  return MeowiConverter::convert(impl_->SetScale(scale_x, scale_y, scale_z));
}

MeowiStatusCode MeowiStickerEffect::SetRotation(float rotation_x, float rotation_y, float rotation_z) {
  return MeowiConverter::convert(impl_->SetRotation(rotation_x, rotation_y, rotation_z));
}

MeowiStickerEffect::MeowiStickerEffect(MeowStickerEffect* ptr) : impl_{ptr} {}
