#pragma once

#include <vector>

#include "meow_caption_effect.h"
#include "meow_sticker_effect.h"

namespace Meow {

struct MeowEffectLayer {
    /**
     * @brief 更新贴纸特效位置
     *
     * @param effect
     * @param in_point
     * @return true
     * @return false
     */
    bool UpdateSticker(MeowTracingContext*, MeowStickerEffect* effect, int64_t in_point);

    /**
     * @brief 绑定贴纸
     *
     * @param effect
     * @param in_point
     * @return true
     * @return false
     */
    bool BindSticker(MeowTracingContext*, MeowStickerEffect* effect, int64_t in_point);

    /**
     * @brief 解绑贴纸
     *
     * @param effect
     * @return true
     * @return false
     */
    bool UnBindSticker(MeowTracingContext*, MeowStickerEffect* effect);

    /**
     * @brief 获取当前layer已经绑定的贴纸
     *
     * @return std::vector<MeowStickerEffect*>
     */
    std::vector<MeowStickerEffect*> GetBindedSticker(MeowTracingContext*);

    ///< 字幕

    /**
     * @brief 更新字幕特效位置
     *
     * @param effect
     * @param in_point
     * @return true
     * @return false
     */
    bool UpdateCaption(MeowTracingContext*, MeowCaptionEffect* effect, int64_t in_point);

    /**
     * @brief 绑定字幕
     *
     * @param effect
     * @param in_point
     * @return true
     * @return false
     */
    bool BindCaption(MeowTracingContext*, MeowCaptionEffect* effect, int64_t in_point);

    /**
     * @brief 解绑字幕
     *
     * @param effect
     * @return true
     * @return false
     */
    bool UnBindCaption(MeowTracingContext*, MeowCaptionEffect* effect);

    /**
     * @brief 获取当前layer已经绑定的字幕
     *
     * @return std::vector<MeowCaptionEffect*>
     */
    std::vector<MeowCaptionEffect*> GetBindedCaption(MeowTracingContext*);

    ///< other

    /**
     * @brief 入点in_point，出点为out_point的effect是否允许绑定到当前layer上
     *
     * @param in_point
     * @param out_point
     * @return true
     * @return false
     */
    bool IsAllowedBind(MeowTracingContext*, int64_t in_point, int64_t out_point);

    /**
     * @brief 更新layer中所有effect的in_point和out_point
     *
     * @return true
     * @return false
     */
    bool Refresh(MeowTracingContext*);

    struct MeowEffectLayerImpl;
    MeowEffectLayerImpl* impl;
};

}  // namespace Meow
