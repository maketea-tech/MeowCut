#pragma once

#include <memory>

#include "common/meow_ret_code.h"
#include "common/meow_texture.h"

namespace Meow {

struct MeowTexturePool {
  /**
   * @brief GL线程调用
   *
   * @param width
   * @param height
   * @return MeowTexture
   */
  MeowTexture Get(uint32_t width, uint32_t height);

  /**
   * @brief GL线程调用
   *
   * @param texture
   * @return MeowRetCode
   */
  MeowRetCode GiveBack(MeowTexture texture);

 private:
  struct MeowTexturePoolImpl;
  std::unique_ptr<MeowTexturePoolImpl> impl_{nullptr};
};

}  // namespace Meow
