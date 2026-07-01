#include "ti_msp_dl_config.h"

// 如果 CPUCLK_FREQ 未定义，请根据实际主频手动定义（单位：Hz）
// 例如： #define CPUCLK_FREQ  32000000UL

/**
  * @brief  微秒级延时（优化版）
  * @param  xus  延时的微秒数（最大约 1.34e8，即 134 秒，若超出会自动分段）
  */
void Delay_us(uint32_t xus)
{
    // 每微秒对应的 CPU 周期数
    const uint32_t cycles_per_us = CPUCLK_FREQ / 1000000UL;

    while (xus > 0) {
        // 计算本次可延时的最大微秒数（避免 uint32 溢出）
        uint32_t chunk = (0xFFFFFFFFUL / cycles_per_us);
        if (chunk > xus) {
            chunk = xus;
        }
        // 一次性延时 chunk 微秒
        delay_cycles((uint64_t)cycles_per_us * chunk);
        xus -= chunk;
    }
}

/**
  * @brief  毫秒级延时（优化版）
  * @param  xms  延时的毫秒数
  */
void Delay_ms(uint32_t xms)
{
    const uint32_t cycles_per_ms = CPUCLK_FREQ / 1000UL;

    while (xms > 0) {
        uint32_t chunk = (0xFFFFFFFFUL / cycles_per_ms);
        if (chunk > xms) {
            chunk = xms;
        }
        delay_cycles((uint64_t)cycles_per_ms * chunk);
        xms -= chunk;
    }
}

/**
  * @brief  秒级延时
  * @param  xs  延时的秒数
  */
void Delay_s(uint32_t xs)
{
    while (xs--) {
        delay_cycles(CPUCLK_FREQ);   // 1秒 = CPUCLK_FREQ 个周期
    }
}
