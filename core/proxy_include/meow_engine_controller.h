#pragma once

#include <cstdint>

#include "meow_common.h"
#include "meow_tracing_context.h"

namespace Meow {

struct MeowEngineController {
  /**
   * @brief 连接用于显示的view，内部会将渲染后的画面显示在此view上
   *
   * @param view QT中的View
   * @return MeowStatusCode
   */
  MeowStatusCode ConnectView(void* view);

  /**
   * @brief 开启预览
   *
   * @return MeowStatusCode
   */
  MeowStatusCode StartPreview();

  /**
   * @brief 设置从固定时间点开始预览
   *
   * @return MeowStatusCode
   */
  MeowStatusCode StartPreview(int64_t start_point);

  /**
   * @brief 设置预览某个时间段
   *
   * @return MeowStatusCode
   */
  MeowStatusCode StartPreview(int64_t start_point, int64_t end_point);

  /**
   * @brief 暂停预览
   *
   * @return MeowStatusCode
   */
  MeowStatusCode PausePreview();

  /**
   * @brief 恢复预览
   *
   * @return MeowStatusCode
   */
  MeowStatusCode ResumePreview();

  /**
   * @brief 获取当前显示的时间点位置，是指画面播放的具体时间点，单位是us
   *
   * @return int64_t
   */
  int64_t GetCurrentTimePoint();

  /**
   * @brief 跳转显示某个时间点的画面，单位是us
   *
   * @param time_point
   * @return MeowStatusCode
   */
  MeowStatusCode SeekToTimePoint(int64_t time_point);

  /**
   * @brief 获取流时长，单位us，不受特效影响
   *
   * @return int64_t
   */
  int64_t GetStreamDuration();

  /**
   * @brief 获取播放总时长，单位us，受特效影响
   *
   * @return int64_t
   */
  int64_t GetDuration();

  /**
   * @brief 刷新当前画面，当更新特效后，调用此接口刷新
   *
   * @return MeowStatusCode
   */
  MeowStatusCode Refresh();

  ///< 导出相关功能

  /**
   * @brief 开始导出，导出为mp4，导出进度以回调的形式给出
   *
   * @param export_config
   * @return MeowStatusCode
   */
  MeowStatusCode StartExport(MeowExportConfig export_config);

  /**
   * @brief 从某个时间点开始导出
   *
   * @param export_config
   * @return MeowStatusCode
   */
  MeowStatusCode StartExport(MeowExportConfig export_config, int64_t start_point);

  /**
   * @brief 导出某个时间段
   *
   * @param export_config
   * @return MeowStatusCode
   */
  MeowStatusCode StartExport(MeowExportConfig export_config, int64_t start_point, int64_t end_point);

  /**
   * @brief 暂停导出
   *
   * @param export_config
   * @return MeowStatusCode
   */
  MeowStatusCode PauseExport();

  /**
   * @brief 恢复导出
   *
   * @param export_config
   * @return MeowStatusCode
   */
  MeowStatusCode ResumeExport();

  /**
   * @brief 停止导出，无法恢复
   *
   * @param export_config
   * @return MeowStatusCode
   */
  MeowStatusCode StopExport();
};

}  // namespace Meow
