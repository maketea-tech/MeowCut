#pragma once

#include <memory>

#include "meowi_engine.h"
#include "meowi_tracing_context.h"

namespace Meow {

struct MeowEngineFactory;

struct MeowiEngineFactory {
  /**
   * @brief 获取链路追踪上下文
   *
   * @return MeowiTracingContext
   */
  MeowiTracingContext GetTracingContext();

  MeowiEngine GetEngine();

  MeowiEngineFactory();

 private:
  std::unique_ptr<MeowEngineFactory> impl_;
};

}  // namespace Meow
