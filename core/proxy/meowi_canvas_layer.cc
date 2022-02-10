#include "include/meowi_canvas_layer.h"

#include "meowi_converter.h"
#include "proxy_include/meow_canvas_layer.h"

using namespace Meow;


MeowiStatusCode MeowiCanvasLayer::SetCanvasRatio(int32_t numerator, int32_t denominator) {
  return MeowiConverter::convert(impl_->SetCanvasRatio(numerator, denominator));
}

MeowiStatusCode MeowiCanvasLayer::SetBackGroundColor(MeowiColor color) {
  return MeowiConverter::convert(impl_->SetBackGroundColor(MeowiConverter::convert(color)));
}

MeowiStatusCode MeowiCanvasLayer::SetBackGroundImage(std::string image_path) {
  return MeowiConverter::convert(impl_->SetBackGroundImage(std::move(image_path)));
}

MeowiStatusCode MeowiCanvasLayer::SetBackGroundBlur(float intensity) {
  return MeowiConverter::convert(impl_->SetBackGroundBlur(intensity));
}

MeowiCanvasLayer::MeowiCanvasLayer(MeowCanvasLayer* ptr) : impl_{ptr} {}
