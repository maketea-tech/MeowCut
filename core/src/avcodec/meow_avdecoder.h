#pragma once

#include <memory>
#include <string>

#include "common/meow_audio_frame.h"
#include "common/meow_ret_code.h"
#include "common/meow_video_frame.h"
#include "gl_manager/meow_gl_context.h"

namespace Meow {

struct MeowDecoder {
  enum class Type { kVideo, kImage, kAudio, kInvalid };

  struct VideoConfig {
    int32_t width{0};
    int32_t height{0};
    int32_t fps{30};
    float speed{1.0f};
  };

  struct AudioConfig {
    MeowAudioChannelLayout layout{MeowAudioChannelLayout::kStereo};
    MeowAudioSampleFormat format{MeowAudioSampleFormat::kInt16};
    int32_t sample_rate{44100};
    float speed{1.0f};
    float volume{1.0f};
  };

  struct DecoderParam {
    std::string path;
    Type type;
    VideoConfig video_config;
    AudioConfig audio_config;
  };

  struct DecoderFrame {
    Type type;
    MeowVideoFrame video_frame;
    MeowAudioFrame audio_frame;
  };

  MeowDecoder(MeowGLContext* context);

  ~MeowDecoder();

  MeowRetCode Config(DecoderParam config);

  MeowRetCode prepare();

  Type GetDecoderType() const;

  MeowRetCode SetSpeed(float speed);

  float GetSpeed() const;

  int64_t GetVStreamDuration();  ///< us

  int64_t GetAStreamDuration();  ///< us

  float GetVStreamFrameRate();

  int32_t GetVWidth();

  int32_t GetVHeight();

  MeowRetCode SetResolution(int32_t width, int32_t height);

  MeowRetCode Stop();

  std::shared_ptr<DecoderFrame> GetFrameAtTime(int64_t time, Type type);
};


}  // namespace Meow
