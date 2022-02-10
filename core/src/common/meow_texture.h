#pragma once

#include <cstdint>

namespace Meow {

struct MeowTexture {
  MeowTexture(uint32_t texture_id, uint32_t width, uint32_t height)
      : texture_id_{texture_id}, width_{width}, height_{height} {}

  uint32_t GetId() const noexcept { return texture_id_; }

  uint32_t GetWidth() const noexcept { return width_; }

  uint32_t GetHeight() const noexcept { return height_; }

  ///< GL线程析构
  ~MeowTexture() {}

 private:
  uint32_t width_{0};
  uint32_t height_{0};
  uint32_t texture_id_{0};
};

}  // namespace Meow
