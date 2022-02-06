#pragma once

#include <cstdint>
#include <string>

#include "meow_status_code.h"

namespace Meow {

/**
 * @brief 坐标信息
 * TODO 具体单位待定
 */
struct MeowPoint {
    float x;
    float y;
    float z;
};

/**
 * @brief 颜色结构体
 *
 */
struct MeowColor {
    float r;
    float g;
    float b;
    float a;
};

struct MeowVideoConfig {
    int32_t width;
    int32_t height;
    int32_t timebase_num;  ///< timebase的分子
    int32_t timebase_den;  ///< timebase的分母
};

struct MeowAudioConfig {
    int32_t sample_rate;    ///< 采样率，一般为44100
    int32_t channel_count;  ///< 通道数，一般为2
};

struct MeowExportConfig {
    int32_t width;          ///< 导出的分辨率宽
    int32_t height;         ///< 导出的分辨率高
    int32_t frame_rate;     ///< 视频帧率
    int32_t bit_rate;       ///< 比特率
    int32_t sample_rate;    ///< 采样率
    std::string file_path;  ///< 目标文件路径
    std::string temp_dir;   ///< 临时目录，用于写临时文件，必须配置
    ///< 还需添加一些状态回调
};

}  // namespace Meow
