#include "include/meowi_editor_layer.h"

#include "meowi_converter.h"
#include "proxy_include/meow_editor_layer.h"

using namespace Meow;

MeowiVideoClip MeowiEditorLayer::AppendVideoClip(std::string video_path) {
  return MeowiConverter::convert(impl_->AppendVideoClip(std::move(video_path)));
}

MeowiVideoClip MeowiEditorLayer::InsertVideoClip(int32_t index, std::string video_path) {
  return MeowiConverter::convert(impl_->InsertVideoClip(index, std::move(video_path)));
}

MeowiStatusCode MeowiEditorLayer::ApplyTransition(int32_t index, TransitionInfo transition) {
  return MeowiConverter::convert(impl_->ApplyTransition(index, MeowiConverter::convert(transition)));
}

MeowiStatusCode MeowiEditorLayer::CancelTransition(int32_t index) {
  return MeowiConverter::convert(impl_->CancelTransition(index));
}

MeowiEditorLayer::MeowiEditorLayer(MeowEditorLayer* ptr) : impl_{ptr} {}
