#include "include/meowi_tracing_context.h"

#include "meowi_converter.h"
#include "proxy_include/meow_tracing_context.h"

using namespace Meow;


void MeowiTracingContext::Dump() { impl_->Dump(); }

MeowiTracingContext::MeowiTracingContext(MeowTracingContext* ptr) : impl_{ptr} {}
