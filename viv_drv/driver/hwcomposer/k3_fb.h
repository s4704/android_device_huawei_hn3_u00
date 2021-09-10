/* Copyright (c) 2008-2011, Hisilicon Tech. Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *	 * Redistributions of source code must retain the above copyright
 *	   notice, this list of conditions and the following disclaimer.
 *	 * Redistributions in binary form must reproduce the above
 *	   copyright notice, this list of conditions and the following
 *	   disclaimer in the documentation and/or other materials provided
 *	   with the distribution.
 *	 * Neither the name of Code Aurora Forum, Inc. nor the names of its
 *	   contributors may be used to endorse or promote products derived
 *	   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef K3_FB_H
#define K3_FB_H
#include <linux/fb.h>

#define K3_FB_OVERLAY_USE_BUF 1

/*G2D clk rate*/
#define G2D_CLK_60MHz	(60 * 1000 * 1000)
#define G2D_CLK_120MHz	(120 * 1000 * 1000)
#define G2D_CLK_240MHz	(240 * 1000 * 1000)
#define G2D_CLK_360MHz	(360 * 1000 * 1000)
#define G2D_CLK_480MHz	(480 * 1000 * 1000)

/* FRC */
#ifdef CONFIG_LCD_PANASONIC_VVX10F002A00
#define K3_FB_FRC_BENCHMARK_FPS	60
#define K3_FB_FRC_NORMAL_FPS	60
#define K3_FB_FRC_VIDEO_FPS	60
#define K3_FB_FRC_WEBKIT_FPS	40
#define K3_FB_FRC_GAME_FPS	40
#define K3_FB_FRC_IDLE_FPS	50
#else
#define K3_FB_FRC_NORMAL_FPS	60
#define K3_FB_FRC_IDLE_FPS	30
#define K3_FB_FRC_VIDEO_FPS	60
#define K3_FB_FRC_WEBKIT_FPS	30
#define K3_FB_FRC_BENCHMARK_FPS	67
#define K3_FB_FRC_GAME_FPS	30
#endif
#define K3_FB_FRC_SPECIAL_GAME_FPS  60

/* FRC for Command Panel */
#define K3_FB_FRC_GAME_FPS_CMD	40

#define K3_FB_FRC_THRESHOLD	6

/* ESD */
#define K3_FB_ESD_THRESHOLD	45

/* SBL */
#define SBL_BKL_STEP	5
#define SBL_REDUCE_VALUE(x)	((x) * 70 / 100)

/* display resolution limited */
#define K3_FB_MIN_WIDTH	32
#define K3_FB_MIN_HEIGHT	32
#define K3_FB_MAX_WIDTH	1200
#define K3_FB_MAX_HEIGHT	1920

/* frame buffer physical addr */
#define K3_FB_PA	HISI_FRAME_BUFFER_BASE
#define K3_NUM_FRAMEBUFFERS	4

/* EDC */
#define EDC_CH_SECU_LINE	11
#define EDC_CLK_RATE_GET(x)	((x) * 12 / 10)

#define K3FB_DEFAULT_BGR_FORMAT	EDC_RGB

/* for MIPI Command LCD */
#define CLK_SWITCH	1

/* for Vsync*/
#define VSYNC_TIMEOUT_MSEC 50

/* FB width must be 16 pixels aligned in Vivante GPU */
#define USE_VIVANTE_GPU	1

#if defined(CONFIG_OVERLAY_COMPOSE)
//channel change flow
//#define EDC_CH_CHG_SUPPORT
#endif //CONFIG_OVERLAY_COMPOSE

enum {
	LCD_LANDSCAPE = 0,
	LCD_PORTRAIT,
};

/* set backlight by pwm or mipi ... */
enum {
	BL_SET_BY_NONE = 0,
	BL_SET_BY_PWM = 0x1,
	BL_SET_BY_MIPI = 0x2,
};

enum {
	IMG_PIXEL_FORMAT_RGB_565 = 1,
	IMG_PIXEL_FORMAT_RGBA_5551,
	IMG_PIXEL_FORMAT_RGBX_5551,
	IMG_PIXEL_FORMAT_RGBA_8888,
	IMG_PIXEL_FORMAT_RGBX_8888,
};

enum {
	FB_64BYTES_ODD_ALIGN_NONE = 0,
	FB_64BYTES_ODD_ALIGN_UI,
	FB_64BYTES_ODD_ALIGN_VIDEO,
};

enum {
	FB_LDI_INT_TYPE_NONE = 0x0,
	FB_LDI_INT_TYPE_FRC = 0x1,
	FB_LDI_INT_TYPE_ESD = 0x2,
};

/* frc state definition */
enum {
	K3_FB_FRC_NONE_PLAYING = 0x0,
	K3_FB_FRC_VIDEO_PLAYING = 0x2,
	K3_FB_FRC_GAME_PLAYING = 0x4,
	K3_FB_FRC_VIDEO_IN_GAME = 0x6,
	K3_FB_FRC_BENCHMARK_PLAYING = 0x8,
	K3_FB_FRC_WEBKIT_PLAYING =0x10,
	K3_FB_FRC_SPECIAL_GAME_PLAYING = 0x20,
	K3_FB_FRC_IDLE_PLAYING = 0x40,
};





enum {
    OVC_NONE,
    OVC_PARTIAL,
    OVC_FULL,
};

struct k3_fb_data_type {

	char edc_irq_name[64];
	char ldi_irq_name[64];

	bool panel_power_on;

	struct workqueue_struct *frame_end_wq;

	bool cmd_mode_refresh;
	bool is_first_frame_end;

	struct platform_device *pdev;
	struct clk *edc_clk;
	struct clk *edc_clk_rst;
	struct clk *ldi_clk;
	struct clk *mipi_dphy_clk;
	struct clk *g2d_clk;
	struct regulator *edc_vcc;


	/* for sbl */
	struct workqueue_struct *sbl_wq;

	/* for frc */
	unsigned long frc_timestamp;

	/* for esd */
	unsigned long esd_timestamp;

	bool esd_hrtimer_enable;

#ifdef CONFIG_HAS_EARLYSUSPEND
	struct early_suspend early_suspend;
#endif

#if defined(CONFIG_OVERLAY_COMPOSE)
	/* type: full/partial/none */
	u32 ovc_type;
	u32 ovc_ch_count;
	//ch chg state
#if defined(EDC_CH_CHG_SUPPORT)
	bool ch_chg_flag;
	bool ch_chg_power_off;
#endif //EDC_CH_CHG_SUPPORT
	//idle switch to g2d
	bool ovc_idle_flag;
	//ovc buffer sync: ch1,ch2,crs
	bool ovc_wait_state[MAX_EDC_CHANNEL];
	bool ovc_wait_flag[MAX_EDC_CHANNEL];
	u32 ovc_lock_addr[MAX_EDC_CHANNEL];
	u32 ovc_lock_size[MAX_EDC_CHANNEL];
	u32 ovc_ch_gonna_display_addr[MAX_EDC_CHANNEL];
	u32 ovc_ch_display_addr[MAX_EDC_CHANNEL];
	//overlay play cfg_ok once
	struct overlay_data ovc_req[MAX_EDC_CHANNEL];
#if defined(CONFIG_CPU_FREQ_GOV_K3HOTPLUG)
	u32 ddr_min_freq;
	u32 ddr_min_freq_saved;
	u32 ddr_curr_freq;
	u32 ovc_ddr_failed;
	struct pm_qos_request_list ovc_ddrminprofile;
	struct work_struct ovc_ddr_work;
	struct workqueue_struct *ovc_ddr_wq;
#endif
#endif /* CONFIG_OVERLAY_COMPOSE */

};


/******************************************************************************
** FUNCTIONS PROTOTYPES
*/

void k3_fb_set_backlight(struct k3_fb_data_type *k3fd);
struct platform_device *k3_fb_add_device(struct platform_device *pdev);

int k3_fb1_blank(int blank_mode);
int k3fb_buf_isfree(int phys);
void k3fb_set_hdmi_state(bool is_connected);
struct fb_var_screeninfo * k3fb_get_fb_var(int index);

#if defined(CONFIG_OVERLAY_COMPOSE)
void k3_fb_gralloc_overlay_save_display_addr(struct k3_fb_data_type *k3fd, int ch, u32 addr);
void k3_fb_gralloc_overlay_restore_display_addr(struct k3_fb_data_type *k3fd);
#if defined(EDC_CH_CHG_SUPPORT)
struct fb_info* k3_fb1_get_info(void);
#endif //EDC_CH_CHG_SUPPORT
void k3_fb_overlay_compose_data_clear(struct k3_fb_data_type *k3fd);

#endif //CONFIG_OVERLAY_COMPOSE

#endif /* K3_FB_H */
