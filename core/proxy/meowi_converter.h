#pragma once

#include "include/meowi_core.h"
#include "proxy_include/meow_core.h"

namespace Meow {

struct MeowiConverter {
  static MeowiStatusCode convert(MeowStatusCode code) { return static_cast<MeowiStatusCode>(code); }

  static MeowStatusCode convert(MeowiStatusCode code) { return static_cast<MeowStatusCode>(code); }

  static MeowiVideoConfig convert(MeowVideoConfig param) {
    MeowiVideoConfig ret;
    ret.width = param.width;
    ret.height = param.height;
    ret.timebase_num = param.timebase_num;
    ret.timebase_den = param.timebase_den;
    return ret;
  }

  static MeowVideoConfig convert(MeowiVideoConfig param) {
    MeowVideoConfig ret;
    ret.width = param.width;
    ret.height = param.height;
    ret.timebase_num = param.timebase_num;
    ret.timebase_den = param.timebase_den;
    return ret;
  }

  static MeowiAudioConfig convert(MeowAudioConfig param) {
    MeowiAudioConfig ret;
    ret.sample_rate = param.sample_rate;
    ret.channel_count = param.channel_count;
    return ret;
  }

  static MeowAudioConfig convert(MeowiAudioConfig param) {
    MeowAudioConfig ret;
    ret.sample_rate = param.sample_rate;
    ret.channel_count = param.channel_count;
    return ret;
  }

  static MeowiExportConfig convert(MeowExportConfig param) {
    MeowiExportConfig ret;
    ret.width = param.width;
    ret.height = param.height;
    ret.frame_rate = param.frame_rate;
    ret.bit_rate = param.bit_rate;
    ret.sample_rate = param.sample_rate;
    ret.file_path = param.file_path;
    ret.temp_dir = param.temp_dir;
    return ret;
  }

  static MeowExportConfig convert(MeowiExportConfig param) {
    MeowExportConfig ret;
    ret.width = param.width;
    ret.height = param.height;
    ret.frame_rate = param.frame_rate;
    ret.bit_rate = param.bit_rate;
    ret.sample_rate = param.sample_rate;
    ret.file_path = param.file_path;
    ret.temp_dir = param.temp_dir;
    return ret;
  }

  static MeowiPoint convert(MeowPoint param) {
    MeowiPoint ret;
    ret.x = param.x;
    ret.y = param.y;
    ret.z = param.z;
    return ret;
  }

  static MeowPoint convert(MeowiPoint param) {
    MeowPoint ret;
    ret.x = param.x;
    ret.y = param.y;
    ret.z = param.z;
    return ret;
  }

  static MeowiColor convert(MeowColor param) {
    MeowiColor ret;
    ret.r = param.r;
    ret.g = param.g;
    ret.b = param.b;
    ret.a = param.a;
    return ret;
  }

  static MeowColor convert(MeowiColor param) {
    MeowColor ret;
    ret.r = param.r;
    ret.g = param.g;
    ret.b = param.b;
    ret.a = param.a;
    return ret;
  }

  static MeowAudioClip* convert(MeowiAudioClip param) { return param.impl_; }

  static MeowiAudioClip convert(MeowAudioClip* param) { return MeowiAudioClip(param); }

  std::vector<MeowAudioClip*> convert(std::vector<MeowiAudioClip> param) {
    std::vector<MeowAudioClip*> ret;
    for (MeowiAudioClip& p : param) {
      ret.emplace_back(p.impl_);
    }
    return ret;
  }

  static std::vector<MeowiAudioClip> convert(std::vector<MeowAudioClip*> param) {
    std::vector<MeowiAudioClip> ret;
    for (MeowAudioClip* p : param) {
      ret.emplace_back(p);
    }
    return ret;
  }

  static MeowAudioLayerGroup* convert(MeowiAudioLayerGroup param) { return param.impl_; }

  static MeowiAudioLayerGroup convert(MeowAudioLayerGroup* param) { return MeowiAudioLayerGroup(param); }

  static MeowAudioLayer* convert(MeowiAudioLayer param) { return param.impl_; }

  static MeowiAudioLayer convert(MeowAudioLayer* param) { return MeowiAudioLayer(param); }

  static MeowCanvasLayer* convert(MeowiCanvasLayer param) { return param.impl_; }

  static MeowiCanvasLayer convert(MeowCanvasLayer* param) { return MeowiCanvasLayer(param); }

  static MeowCaptionEffect* convert(MeowiCaptionEffect param) { return param.impl_; }

  static MeowiCaptionEffect convert(MeowCaptionEffect* param) { return MeowiCaptionEffect(param); }

  std::vector<MeowCaptionEffect*> convert(std::vector<MeowiCaptionEffect> param) {
    std::vector<MeowCaptionEffect*> ret;
    for (MeowiCaptionEffect& p : param) {
      ret.emplace_back(p.impl_);
    }
    return ret;
  }

  static std::vector<MeowiCaptionEffect> convert(std::vector<MeowCaptionEffect*> param) {
    std::vector<MeowiCaptionEffect> ret;
    for (MeowCaptionEffect* p : param) {
      ret.emplace_back(p);
    }
    return ret;
  }

  static MeowEditorLayer* convert(MeowiEditorLayer param) { return param.impl_; }

  static MeowiEditorLayer convert(MeowEditorLayer* param) { return MeowiEditorLayer(param); }

  static MeowiEditorLayer::TransitionInfo convert(MeowEditorLayer::TransitionInfo param) {
    MeowiEditorLayer::TransitionInfo ret;
    ret.json_path = param.json_path;
    ret.total_time = param.total_time;
    ret.first_time = param.first_time;
    ret.second_time = param.second_time;
    ret.overlap_time = param.overlap_time;
    return ret;
  }

  static MeowEditorLayer::TransitionInfo convert(MeowiEditorLayer::TransitionInfo param) {
    MeowEditorLayer::TransitionInfo ret;
    ret.json_path = param.json_path;
    ret.total_time = param.total_time;
    ret.first_time = param.first_time;
    ret.second_time = param.second_time;
    ret.overlap_time = param.overlap_time;
    return ret;
  }

  static MeowEffectLayerGroup* convert(MeowiEffectLayerGroup param) { return param.impl_; }

  static MeowiEffectLayerGroup convert(MeowEffectLayerGroup* param) { return MeowiEffectLayerGroup(param); }

  static MeowEffectLayer* convert(MeowiEffectLayer param) { return param.impl_; }

  static MeowiEffectLayer convert(MeowEffectLayer* param) { return MeowiEffectLayer(param); }

  static MeowEngineController* convert(MeowiEngineController param) { return param.impl_; }

  static MeowiEngineController convert(MeowEngineController* param) { return MeowiEngineController(param); }

  static MeowEngine* convert(MeowiEngine param) { return param.impl_; }

  static MeowiEngine convert(MeowEngine* param) { return MeowiEngine(param); }

  static MeowMoveSession* convert(MeowiMoveSession param) { return param.impl_; }

  static MeowiMoveSession convert(MeowMoveSession* param) { return MeowiMoveSession(param); }

  static MeowPipLayerGroup* convert(MeowiPipLayerGroup param) { return param.impl_; }

  static MeowiPipLayerGroup convert(MeowPipLayerGroup* param) { return MeowiPipLayerGroup(param); }

  static MeowPipLayer* convert(MeowiPipLayer param) { return param.impl_; }

  static MeowiPipLayer convert(MeowPipLayer* param) { return MeowiPipLayer(param); }

  static MeowStickerEffect* convert(MeowiStickerEffect param) { return param.impl_; }

  static MeowiStickerEffect convert(MeowStickerEffect* param) { return MeowiStickerEffect(param); }

  std::vector<MeowStickerEffect*> convert(std::vector<MeowiStickerEffect> param) {
    std::vector<MeowStickerEffect*> ret;
    for (MeowiStickerEffect& p : param) {
      ret.emplace_back(p.impl_);
    }
    return ret;
  }

  static std::vector<MeowiStickerEffect> convert(std::vector<MeowStickerEffect*> param) {
    std::vector<MeowiStickerEffect> ret;
    for (MeowStickerEffect* p : param) {
      ret.emplace_back(p);
    }
    return ret;
  }

  static MeowTracingContext* convert(MeowiTracingContext param) { return param.impl_; }

  static MeowiTracingContext convert(MeowTracingContext* param) { return MeowiTracingContext(param); }

  static MeowUnitFactory* convert(MeowiUnitFactory param) { return param.impl_; }

  static MeowiUnitFactory convert(MeowUnitFactory* param) { return MeowiUnitFactory(param); }

  static MeowVideoClip* convert(MeowiVideoClip param) { return param.impl_; }

  static MeowiVideoClip convert(MeowVideoClip* param) { return MeowiVideoClip(param); }

  std::vector<MeowVideoClip*> convert(std::vector<MeowiVideoClip> param) {
    std::vector<MeowVideoClip*> ret;
    for (MeowiVideoClip& p : param) {
      ret.emplace_back(p.impl_);
    }
    return ret;
  }

  static std::vector<MeowiVideoClip> convert(std::vector<MeowVideoClip*> param) {
    std::vector<MeowiVideoClip> ret;
    for (MeowVideoClip* p : param) {
      ret.emplace_back(p);
    }
    return ret;
  }
};

}  // namespace Meow
