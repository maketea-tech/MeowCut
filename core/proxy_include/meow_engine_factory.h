#pragma once

#include "meow_engine.h"
#include "meow_tracing_context.h"

namespace Meow {

struct MeowEngineFactory {
  /**
   * @brief 获取链路追踪上下文
   *
   * @return MeowTracingContext*
   */
  MeowTracingContext* GetTracingContext();

  MeowEngine* GetEngine();
};

}  // namespace Meow
