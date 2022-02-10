#include "include/meowi_engine_factory.h"

#include "meowi_converter.h"
#include "proxy_include/meow_engine_factory.h"

using namespace Meow;

MeowiEngineFactory::MeowiEngineFactory() : impl_{std::make_unique<MeowEngineFactory>()} {}

MeowiTracingContext MeowiEngineFactory::GetTracingContext() {
  return MeowiConverter::convert(impl_->GetTracingContext());
}

MeowiEngine MeowiEngineFactory::GetEngine() { return MeowiConverter::convert(impl_->GetEngine()); }
