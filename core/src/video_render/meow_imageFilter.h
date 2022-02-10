#pragma once

#include <cstdint>
#include <string>

#include "common/meow_ret_code.h"
#include "common/meow_texture.h"

namespace Meow {

/**
 * @brief 滤镜、转场、普通特效的头文件
 *
 */

struct ImageFilter {
  /**
   * @brief 滤镜的类型：水墨 灰阶 漫画 等等
   */
  enum class Type {};

  /**
   * @brief 滤镜的一些参数：比如水墨强度 漫画强度等等
   *
   */
  enum class Param {

  };

  /**
   * @brief 旋转角度：0 90 180 270
   *
   */
  enum class Rotation {

  };

  /**
   * @brief 滤镜链条中滤镜的个数
   *
   * @return int32_t
   */
  int32_t GetChainSize();

  /**
   * @brief 向整个滤镜链条末尾添加某一个类型的滤镜
   *
   * @param filter_type
   * @return MeowRetCode
   */
  MeowRetCode PushBack(Type filter_type);

  /**
   * @brief 向整个滤镜链条头部添加某一个类型的滤镜
   *
   * @param filter_type
   * @return MeowRetCode
   */
  MeowRetCode PushFront(Type filter_type);

  /**
   * @brief 移除尾部滤镜
   *
   * @return MeowRetCode
   */
  MeowRetCode PopBack();

  /**
   * @brief 移除头部滤镜
   *
   * @return MeowRetCode
   */
  MeowRetCode PopFront();

  /**
   * @brief 在某个位置插入某种类型的滤镜
   *
   * @param index
   * @param filter_type
   * @return MeowRetCode
   */
  MeowRetCode Insert(int32_t index, Type filter_type);

  /**
   * @brief 清空链条
   *
   * @return MeowRetCode
   */
  MeowRetCode Clear();

  /**
   * @brief 移除某种类型的滤镜
   *
   * @param filter_type
   * @return MeowRetCode
   */
  MeowRetCode Remove(Type filter_type);

  /**
   * @brief 设置float类型的参数
   *
   * @param param
   * @param value
   * @return MeowRetCode
   */
  MeowRetCode SetParam(Param param, float value);

  /**
   * @brief 设置string类型的参数
   *
   * @param param
   * @param value
   * @return MeowRetCode
   */
  MeowRetCode SetParam(Param param, std::string value);

  /**
   * @brief 获取float类型的参数值
   *
   * @param param
   * @return float
   */
  float getFloatParam(Param param);

  /**
   * @brief 获取string类型的参数值
   *
   * @param param
   * @return std::string
   */
  std::string getStringParam(Param param);

  struct RenderParam {
    MeowTexture texture_first_in;
    MeowTexture texture_second_in;
    MeowTexture texture_out;
    Rotation rotation;
  };

  /**
   * @brief 渲染的接口
   *
   * @param param
   * @return MeowRetCode
   */
  MeowRetCode RenderFilter(RenderParam param);

  /**
   * @brief
   * 常用的接口，通过json文件配置渲染链，该操作会清空内部所有链条，应用json内容
   *
   * @param json_file_path
   * @return MeowRetCode
   */
  MeowRetCode SetFilterWithJsonFile(std::string json_file_path);

  /**
   * @brief
   * 常用的接口，通过jsonstring配置渲染链，该操作会清空内部所有链条，应用json内容
   *
   * @param json_file_path
   * @return MeowRetCode
   */
  MeowRetCode SetFilterWithJsonString(std::string json_string);

  //***********************上面是针对于滤镜的接口，下面是针对于转场的接口************************************

  /**
   * @brief 时长信息结构体
   *
   */
  struct TransitionTimeInfo {
    float first_video_time;   ///< 参与转场的第一个视频的时长
    float second_video_time;  ///< 第二个
    float blend_time;         ///< 参与转场的两个视频重合部分的时长
    float total_time;         ///< 整个转场的总时长 total = first + second - blend
  };

  /**
   * @brief 输入转场总时长和两个视频的时长比，计算具体时长信息
   *
   * @param total_time
   * @param ab_ratio
   * @return TransitionTimeInfo
   */
  TransitionTimeInfo GetTransitionTimeInfo(float total_time, float ab_ratio);

  enum class VideoInputType {
    kFirstVideo,   ///< 只输入第一个视频帧
    kSecondVideo,  ///< 只输入第二个视频帧
    kBothVideo,    ///< 同时输入两个视频帧
    kInvalid
  };

  struct VideoInputInfo {
    VideoInputType input_type;    ///< 输入视频帧的种类
    float first_video_progress;   ///< 所需的第一个视频相对于自身的进度值，范围是0-1
    float second_video_progress;  ///< 所需的第二个视频相对于自身的进度值，范围是0-1
    float blend_progress;         ///< 所需的两个视频重合的部分，相对于自身的进度值，范围是0-1
  };

  /**
   * @brief 获取当前转场、特效的视频输入信息，在整个转场特效每一帧都要执行此方法，ab_ratio>0是转场，=0则是普通特效
   * 特效时，返回的input_type为kFirstVideo
   *
   * @param ab_ratio
   * @param progress
   * @return VideoInputInfo
   */
  VideoInputInfo GetVideoInputInfo(float ab_ratio, float progress);

  /**
   * @brief 转场特效的渲染接口，在整个转场特效过程中每一帧都执行此方法做渲染
   * 每一次调用前线调用GetVideoInputInfo获取VideoInputInfo，然后传递到此函数中
   * 另外在转场前，根据需求可能需要调用GetTransitionTimeInfo获取时长信息
   *
   * @param param
   * @return MeowRetCode
   */
  MeowRetCode RenderEffect(RenderParam param, VideoInputInfo info);

  /**
   * @brief 通过json格式配置转场或者特效的效果
   *
   * @param json_string
   * @return MeowRetCode
   */
  MeowRetCode SetEffectWithJsonString(std::string json_string);

  ///< 其实还有通过枚举类型来配置转场效果，这里不再列举，都是类似的接口
};

}  // namespace Meow
