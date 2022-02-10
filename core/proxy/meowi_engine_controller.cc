#include "include/meowi_engine_controller.h"

#include "meowi_converter.h"
#include "proxy_include/meow_engine_controller.h"

using namespace Meow;

MeowiStatusCode MeowiEngineController::ConnectView(void* view) {
  return MeowiConverter::convert(impl_->ConnectView(view));
}

MeowiStatusCode MeowiEngineController::StartPreview() { return MeowiConverter::convert(impl_->StartPreview()); }

MeowiStatusCode MeowiEngineController::StartPreview(int64_t start_point) {
  return MeowiConverter::convert(impl_->StartPreview(start_point));
}

MeowiStatusCode MeowiEngineController::StartPreview(int64_t start_point, int64_t end_point) {
  return MeowiConverter::convert(impl_->StartPreview(start_point, end_point));
}

MeowiStatusCode MeowiEngineController::PausePreview() { return MeowiConverter::convert(impl_->PausePreview()); }

MeowiStatusCode MeowiEngineController::ResumePreview() { return MeowiConverter::convert(impl_->ResumePreview()); }

int64_t MeowiEngineController::GetCurrentTimePoint() { return impl_->GetCurrentTimePoint(); }

MeowiStatusCode MeowiEngineController::SeekToTimePoint(int64_t time_point) {
  return MeowiConverter::convert(impl_->SeekToTimePoint(time_point));
}

int64_t MeowiEngineController::GetStreamDuration() { return impl_->GetStreamDuration(); }

int64_t MeowiEngineController::GetDuration() { return impl_->GetDuration(); }

MeowiStatusCode MeowiEngineController::Refresh() { return MeowiConverter::convert(impl_->Refresh()); }

MeowiStatusCode MeowiEngineController::StartExport(MeowiExportConfig export_config) {
  return MeowiConverter::convert(impl_->StartExport(MeowiConverter::convert(export_config)));
}

MeowiStatusCode MeowiEngineController::StartExport(MeowiExportConfig export_config, int64_t start_point) {
  return MeowiConverter::convert(impl_->StartExport(MeowiConverter::convert(export_config), start_point));
}

MeowiStatusCode MeowiEngineController::StartExport(MeowiExportConfig export_config, int64_t start_point,
                                                   int64_t end_point) {
  return MeowiConverter::convert(impl_->StartExport(MeowiConverter::convert(export_config), start_point, end_point));
}

MeowiStatusCode MeowiEngineController::PauseExport() { return MeowiConverter::convert(impl_->PauseExport()); }

MeowiStatusCode MeowiEngineController::ResumeExport() { return MeowiConverter::convert(impl_->ResumeExport()); }

MeowiStatusCode MeowiEngineController::StopExport() { return MeowiConverter::convert(impl_->StopExport()); }

MeowiEngineController::MeowiEngineController(MeowEngineController* ptr) : impl_{ptr} {}
