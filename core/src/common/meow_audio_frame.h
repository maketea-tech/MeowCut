#pragma once

#include <cstdint>

namespace Meow {

enum class MeowAudioChannelLayout { kMono = 1, kStereo = 2 };

enum class MeowAudioSampleFormat { kInt16 = 16, kFloat32 = 32 };

struct MeowAudioConfig {
  MeowAudioChannelLayout layout{MeowAudioChannelLayout::kStereo};
  MeowAudioSampleFormat format{MeowAudioSampleFormat::kInt16};
  int32_t sample_rate{44100};
};

struct MeowAudioFrame {
  int64_t pts{0};
  int64_t duration{0};  ///< us

  MeowAudioConfig config;

  uint8_t* data{nullptr};  ///< PCM裸数据
  int32_t data_size{0};
};

}  // namespace Meow
