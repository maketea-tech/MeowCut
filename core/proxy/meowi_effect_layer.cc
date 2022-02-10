#include "include/meowi_effect_layer.h"

#include "meowi_converter.h"
#include "proxy_include/meow_effect_layer.h"

using namespace Meow;


MeowiStatusCode MeowiEffectLayer::UpdateSticker(MeowiStickerEffect effect, int64_t in_point) {
  return MeowiConverter::convert(impl_->UpdateSticker(MeowiConverter::convert(effect), in_point));
}

MeowiStatusCode MeowiEffectLayer::BindSticker(MeowiStickerEffect effect, int64_t in_point) {
  return MeowiConverter::convert(impl_->BindSticker(MeowiConverter::convert(effect), in_point));
}

MeowiStatusCode MeowiEffectLayer::UnBindSticker(MeowiStickerEffect effect) {
  return MeowiConverter::convert(impl_->UnBindSticker(MeowiConverter::convert(effect)));
}

std::vector<MeowiStickerEffect> MeowiEffectLayer::GetBindedSticker() {
  return MeowiConverter::convert(impl_->GetBindedSticker());
}

MeowiStatusCode MeowiEffectLayer::UpdateCaption(MeowiCaptionEffect effect, int64_t in_point) {
  return MeowiConverter::convert(impl_->UpdateCaption(MeowiConverter::convert(effect), in_point));
}

MeowiStatusCode MeowiEffectLayer::BindCaption(MeowiCaptionEffect effect, int64_t in_point) {
  return MeowiConverter::convert(impl_->BindCaption(MeowiConverter::convert(effect), in_point));
}

MeowiStatusCode MeowiEffectLayer::UnBindCaption(MeowiCaptionEffect effect) {
  return MeowiConverter::convert(impl_->UnBindCaption(MeowiConverter::convert(effect)));
}

std::vector<MeowiCaptionEffect> MeowiEffectLayer::GetBindedCaption() {
  return MeowiConverter::convert(impl_->GetBindedCaption());
}

MeowiStatusCode MeowiEffectLayer::IsAllowedBind(int64_t in_point, int64_t out_point) {
  return MeowiConverter::convert(impl_->IsAllowedBind(in_point, out_point));
}

MeowiStatusCode MeowiEffectLayer::Refresh() { return MeowiConverter::convert(impl_->Refresh()); }

MeowiEffectLayer::MeowiEffectLayer(MeowEffectLayer* ptr) : impl_{ptr} {}
