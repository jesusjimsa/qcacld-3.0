/*
 * Copyright (c) 2020-2021, The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * DOC: This file contains definitions for MLME roaming offload.
 */

#ifndef CM_ROAM_PUBLIC_STRUCT_H__
#define CM_ROAM_PUBLIC_STRUCT_H__

#include "wlan_objmgr_cmn.h"
#include "reg_services_public_struct.h"
#include "wlan_cm_bss_score_param.h"
#include "wlan_blm_public_struct.h"
#include "wmi_unified_param.h"
#include "wmi_unified_sta_param.h"
#include "wlan_cm_public_struct.h"

#define ROAM_SCAN_OFFLOAD_START                     1
#define ROAM_SCAN_OFFLOAD_STOP                      2
#define ROAM_SCAN_OFFLOAD_RESTART                   3
#define ROAM_SCAN_OFFLOAD_UPDATE_CFG                4
#define ROAM_SCAN_OFFLOAD_ABORT_SCAN                5

#define REASON_CONNECT                              1
#define REASON_CHANNEL_LIST_CHANGED                 2
#define REASON_LOOKUP_THRESH_CHANGED                3
#define REASON_DISCONNECTED                         4
#define REASON_RSSI_DIFF_CHANGED                    5
#define REASON_ESE_INI_CFG_CHANGED                  6
#define REASON_NEIGHBOR_SCAN_REFRESH_PERIOD_CHANGED 7
#define REASON_VALID_CHANNEL_LIST_CHANGED           8
#define REASON_FLUSH_CHANNEL_LIST                   9
#define REASON_EMPTY_SCAN_REF_PERIOD_CHANGED        10
#define REASON_PREAUTH_FAILED_FOR_ALL               11
#define REASON_NO_CAND_FOUND_OR_NOT_ROAMING_NOW     12
#define REASON_NPROBES_CHANGED                      13
#define REASON_HOME_AWAY_TIME_CHANGED               14
#define REASON_OS_REQUESTED_ROAMING_NOW             15
#define REASON_SCAN_CH_TIME_CHANGED                 16
#define REASON_SCAN_HOME_TIME_CHANGED               17
#define REASON_OPPORTUNISTIC_THRESH_DIFF_CHANGED    18
#define REASON_ROAM_RESCAN_RSSI_DIFF_CHANGED        19
#define REASON_ROAM_BMISS_FIRST_BCNT_CHANGED        20
#define REASON_ROAM_BMISS_FINAL_BCNT_CHANGED        21
#define REASON_ROAM_DFS_SCAN_MODE_CHANGED           23
#define REASON_ROAM_ABORT_ROAM_SCAN                 24
#define REASON_ROAM_EXT_SCAN_PARAMS_CHANGED         25
#define REASON_ROAM_SET_SSID_ALLOWED                26
#define REASON_ROAM_SET_FAVORED_BSSID               27
#define REASON_ROAM_GOOD_RSSI_CHANGED               28
#define REASON_ROAM_SET_BLACKLIST_BSSID             29
#define REASON_ROAM_SCAN_HI_RSSI_MAXCOUNT_CHANGED   30
#define REASON_ROAM_SCAN_HI_RSSI_DELTA_CHANGED      31
#define REASON_ROAM_SCAN_HI_RSSI_DELAY_CHANGED      32
#define REASON_ROAM_SCAN_HI_RSSI_UB_CHANGED         33
#define REASON_CONNECT_IES_CHANGED                  34
#define REASON_ROAM_SCAN_STA_ROAM_POLICY_CHANGED    35
#define REASON_ROAM_SYNCH_FAILED                    36
#define REASON_ROAM_PSK_PMK_CHANGED                 37
#define REASON_ROAM_STOP_ALL                        38
#define REASON_SUPPLICANT_DISABLED_ROAMING          39
#define REASON_CTX_INIT                             40
#define REASON_FILS_PARAMS_CHANGED                  41
#define REASON_SME_ISSUED                           42
#define REASON_DRIVER_ENABLED                       43
#define REASON_ROAM_FULL_SCAN_PERIOD_CHANGED        44
#define REASON_SCORING_CRITERIA_CHANGED             45
#define REASON_SUPPLICANT_INIT_ROAMING              46
#define REASON_SUPPLICANT_DE_INIT_ROAMING           47
#define REASON_DRIVER_DISABLED                      48
#define REASON_ROAM_CONTROL_CONFIG_CHANGED          49
#define REASON_ROAM_CONTROL_CONFIG_ENABLED          50
#define REASON_ROAM_CANDIDATE_FOUND                 51
#define REASON_ROAM_HANDOFF_DONE                    52
#define REASON_ROAM_ABORT                           53
#define REASON_ROAM_SET_PRIMARY                     54

#ifdef FEATURE_CM_ENABLE
#define FILS_MAX_KEYNAME_NAI_LENGTH WLAN_CM_FILS_MAX_KEYNAME_NAI_LENGTH
#define WLAN_FILS_MAX_REALM_LEN WLAN_CM_FILS_MAX_REALM_LEN
#define WLAN_FILS_MAX_RRK_LENGTH WLAN_CM_FILS_MAX_RRK_LENGTH
#else
#define FILS_MAX_KEYNAME_NAI_LENGTH 253
#define WLAN_FILS_MAX_REALM_LEN 255
#define WLAN_FILS_MAX_RRK_LENGTH 64
#endif

#define FILS_MAX_HLP_DATA_LEN 2048

#define WLAN_FILS_MAX_RIK_LENGTH WLAN_FILS_MAX_RRK_LENGTH
#define WLAN_FILS_FT_MAX_LEN          48

#define WLAN_MAX_PMK_DUMP_BYTES 6
#define DEFAULT_ROAM_SCAN_SCHEME_BITMAP 0
#define ROAM_MAX_CFG_VALUE 0xffffffff

#define CFG_VALID_CHANNEL_LIST_LEN 100
#define MAX_SSID_ALLOWED_LIST    8
#define MAX_BSSID_AVOID_LIST     16
#define MAX_BSSID_FAVORED      16

#define MAX_FTIE_SIZE 384
#define ESE_MAX_TSPEC_IES 4

/*
 * To get 4 LSB of roam reason of roam_synch_data
 * received from firmware
 */
#define ROAM_REASON_MASK 0x0F

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
#define ROAM_SCAN_PSK_SIZE    48
#define ROAM_R0KH_ID_MAX_LEN  48
/* connected but not authenticated */
#define ROAM_AUTH_STATUS_CONNECTED      0x1
/* connected and authenticated */
#define ROAM_AUTH_STATUS_AUTHENTICATED  0x2

#define IS_ROAM_REASON_STA_KICKOUT(reason) ((reason & 0xF) == \
	WMI_ROAM_TRIGGER_REASON_STA_KICKOUT)
#define IS_ROAM_REASON_DISCONNECTION(reason) ((reason & 0xF) == \
	WMI_ROAM_TRIGGER_REASON_DEAUTH)
#endif

/*
 * Neighbor Report Params Bitmask
 */
#define NEIGHBOR_REPORT_PARAMS_TIME_OFFSET            0x01
#define NEIGHBOR_REPORT_PARAMS_LOW_RSSI_OFFSET        0x02
#define NEIGHBOR_REPORT_PARAMS_BMISS_COUNT_TRIGGER    0x04
#define NEIGHBOR_REPORT_PARAMS_PER_THRESHOLD_OFFSET   0x08
#define NEIGHBOR_REPORT_PARAMS_CACHE_TIMEOUT          0x10
#define NEIGHBOR_REPORT_PARAMS_MAX_REQ_CAP            0x20
#define NEIGHBOR_REPORT_PARAMS_ALL                    0x3F

/*
 * Neighbor report offload needs to send 0xFFFFFFFF if a particular
 * parameter is disabled from the ini
 */
#define NEIGHBOR_REPORT_PARAM_INVALID (0xFFFFFFFFU)

/*
 * Currently roam score delta value is sent for 2 triggers and min rssi
 * values are sent for 3 triggers
 */
#define NUM_OF_ROAM_TRIGGERS 2
#define IDLE_ROAM_TRIGGER 0
#define BTM_ROAM_TRIGGER  1

#define NUM_OF_ROAM_MIN_RSSI 3
#define DEAUTH_MIN_RSSI 0
#define BMISS_MIN_RSSI  1
#define MIN_RSSI_2G_TO_5G_ROAM 2

/**
 * struct cm_roam_neighbor_report_offload_params - neighbor report offload
 *                                                 parameters
 * @offload_11k_enable_bitmask: neighbor report offload bitmask control
 * @params_bitmask: bitmask to specify which of the below are enabled
 * @time_offset: time offset after 11k offload command to trigger a neighbor
 *              report request (in seconds)
 * @low_rssi_offset: Offset from rssi threshold to trigger neighbor
 *      report request (in dBm)
 * @bmiss_count_trigger: Number of beacon miss events to trigger neighbor
 *              report request
 * @per_threshold_offset: offset from PER threshold to trigger neighbor
 *              report request (in %)
 * @neighbor_report_cache_timeout: timeout after which new trigger can enable
 *              sending of a neighbor report request (in seconds)
 * @max_neighbor_report_req_cap: max number of neighbor report requests that
 *              can be sent to the peer in the current session
 */
struct cm_roam_neighbor_report_offload_params {
	uint32_t offload_11k_enable_bitmask;
	uint8_t params_bitmask;
	uint32_t time_offset;
	uint32_t low_rssi_offset;
	uint32_t bmiss_count_trigger;
	uint32_t per_threshold_offset;
	uint32_t neighbor_report_cache_timeout;
	uint32_t max_neighbor_report_req_cap;
};

/**
 * struct rso_chan_info - chan info
 * @num_chan: number of channels
 * @freq_list: freq list
 */
struct rso_chan_info {
	uint8_t num_chan;
	qdf_freq_t *freq_list;
};

/**
 * struct rso_cfg_params - per vdev rso cfg
 */
struct rso_cfg_params {
	uint32_t neighbor_scan_period;
	uint32_t neighbor_scan_min_period;
	struct rso_chan_info specific_chan_info;
	uint8_t neighbor_lookup_threshold;
	int8_t rssi_thresh_offset_5g;
	uint32_t min_chan_scan_time;
	uint32_t max_chan_scan_time;
	uint16_t neighbor_results_refresh_period;
	uint16_t empty_scan_refresh_period;
	uint8_t opportunistic_threshold_diff;
	uint8_t roam_rescan_rssi_diff;
	uint8_t roam_bmiss_first_bcn_cnt;
	uint8_t roam_bmiss_final_cnt;
	uint32_t hi_rssi_scan_max_count;
	uint32_t hi_rssi_scan_rssi_delta;
	uint32_t hi_rssi_scan_delay;
	int32_t hi_rssi_scan_rssi_ub;
	struct rso_chan_info pref_chan_info;
	uint32_t full_roam_scan_period;
	bool enable_scoring_for_roam;
	uint8_t roam_rssi_diff;
	uint8_t bg_rssi_threshold;
	uint16_t roam_scan_home_away_time;
	uint8_t roam_scan_n_probes;
	uint32_t roam_scan_inactivity_time;
	uint32_t roam_inactive_data_packet_count;
	uint32_t roam_scan_period_after_inactivity;
};

/**
 * struct wlan_chan_list - channel list
 * @num_chan: number of channels
 * @freq_list: freq list
 */
struct wlan_chan_list {
	uint8_t num_chan;
	qdf_freq_t freq_list[CFG_VALID_CHANNEL_LIST_LEN];
};

/*
 * roam_fail_params: different types of params to set or get roam fail states
 * for the vdev
 * @ROAM_TRIGGER_REASON: Roam trigger reason(enum WMI_ROAM_TRIGGER_REASON_ID)
 * @ROAM_INVOKE_FAIL_REASON: One of WMI_ROAM_FAIL_REASON_ID for roam failure
 * in case of forced roam
 * @ROAM_FAIL_REASON: One of WMI_ROAM_FAIL_REASON_ID for roam failure
 */
enum roam_fail_params {
	ROAM_TRIGGER_REASON,
	ROAM_INVOKE_FAIL_REASON,
	ROAM_FAIL_REASON,
};

/**
 * struct rso_config - connect config to be used to send info in
 * RSO. This is the info we dont have in VDEV or CM ctx
 * @cm_rso_lock: RSO lock
 * @rsn_cap: original rsn caps from the connect req from supplicant
 * @disable_hi_rssi: disable high rssi
 * @roam_control_enable: Flag used to cache the status of roam control
 *			 configuration. This will be set only if the
 *			 corresponding vendor command data is configured to
 *			 driver/firmware successfully. The same shall be
 *			 returned to userspace whenever queried for roam
 *			 control config status.
 * @rescan_rssi_delta: Roam scan rssi delta. Start new rssi triggered scan only
 * if it changes by rescan_rssi_delta value.
 * @beacon_rssi_weight: Number of beacons to be used to calculate the average
 * rssi of the AP.
 * @hi_rssi_scan_delay: Roam scan delay in ms for High RSSI roam trigger.
 * @roam_scan_scheme_bitmap: Bitmap of roam triggers for which partial channel
 * map scan scheme needs to be enabled. Each bit in the bitmap corresponds to
 * the bit position in the order provided by the enum roam_trigger_reason
 * Ex: roam_scan_scheme_bitmap - 0x00110 will enable partial scan for below
 * triggers:
 * ROAM_TRIGGER_REASON_PER, ROAM_TRIGGER_REASON_BMISS
 * @cfg_param: per vdev config params
 * @assoc_ie: assoc IE
 * @prev_ap_bcn_ie: last connetced AP ie
 * @occupied_chan_lst: occupied channel list
 * @roam_candidate_count: candidate count
 * @is_ese_assoc: is ese assoc
 * @krk: krk data
 * @btk: btk data
 * @psk_pmk: pmk
 * @pmk_len: length of pmk
 * @mdid: mdid info
 * @is_11r_assoc: is 11r assoc
 * @is_adaptive_11r_connection: is adaptive 11r connection
 * @hs_20_ap: Hotspot 2.0 AP
 * @mbo_oce_enabled_ap: MBO/OCE enabled network
 * @is_single_pmk: is single pmk
 * @roam_scan_freq_lst: roam freq list
 * @roam_fail_reason: One of WMI_ROAM_FAIL_REASON_ID
 * @roam_trigger_reason: Roam trigger reason(enum WMI_ROAM_TRIGGER_REASON_ID)
 * @roam_invoke_fail_reason: One of reason id from enum
 * wmi_roam_invoke_status_error in case of forced roam
 * @lost_link_rssi: lost link RSSI
 */
struct rso_config {
	qdf_mutex_t cm_rso_lock;
	uint8_t rsn_cap;
	bool disable_hi_rssi;
	bool roam_control_enable;
	uint8_t rescan_rssi_delta;
	uint8_t beacon_rssi_weight;
	uint32_t hi_rssi_scan_delay;
	uint32_t roam_scan_scheme_bitmap;
	struct rso_cfg_params cfg_param;
	struct element_info assoc_ie;
	struct element_info prev_ap_bcn_ie;
	struct wlan_chan_list occupied_chan_lst;
	int8_t roam_candidate_count;
	uint8_t uapsd_mask;
#ifdef FEATURE_WLAN_ESE
	bool is_ese_assoc;
	uint8_t krk[WMI_KRK_KEY_LEN];
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
	uint8_t btk[WMI_BTK_KEY_LEN];
#endif
#endif
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
	uint8_t psk_pmk[ROAM_SCAN_PSK_SIZE];
	uint8_t pmk_len;
#endif
	struct mobility_domain_info mdid;
	bool is_11r_assoc;
	bool is_adaptive_11r_connection;
	bool hs_20_ap;
	bool is_single_pmk;
	uint32_t mbo_oce_enabled_ap;
	struct rso_chan_info roam_scan_freq_lst;
	uint32_t roam_fail_reason;
	uint32_t roam_trigger_reason;
	uint32_t roam_invoke_fail_reason;
	int32_t lost_link_rssi;
};

/**
 * enum sta_roam_policy_dfs_mode - state of DFS mode for STA ROME policy
 * @STA_ROAM_POLICY_NONE: DFS mode attribute is not valid
 * @STA_ROAM_POLICY_DFS_ENABLED:  DFS mode is enabled
 * @STA_ROAM_POLICY_DFS_DISABLED: DFS mode is disabled
 * @STA_ROAM_POLICY_DFS_DEPRIORITIZE: Deprioritize DFS channels in scanning
 */
enum sta_roam_policy_dfs_mode {
	STA_ROAM_POLICY_NONE,
	STA_ROAM_POLICY_DFS_ENABLED,
	STA_ROAM_POLICY_DFS_DISABLED,
	STA_ROAM_POLICY_DFS_DEPRIORITIZE
};

/**
 * struct rso_roam_policy_params - sta roam policy params for station
 * @dfs_mode: tell is DFS channels needs to be skipped while scanning
 * @skip_unsafe_channels: tells if unsafe channels needs to be skip in scanning
 * @sap_operating_band: Opearting band for SAP
 */
struct rso_roam_policy_params {
	enum sta_roam_policy_dfs_mode dfs_mode;
	bool skip_unsafe_channels;
	uint8_t sap_operating_band;
};

#define DEFAULT_RSSI_DB_GAP     30  /* every 30 dbm for one category */

/**
 * struct rso_params - global RSO params
 * @num_ssid_allowed_list: The number of SSID profiles that are
 *                         in the Whitelist. When roaming, we
 *                         consider the BSSID's with this SSID
 *                         also for roaming apart from the connected one's
 * @ssid_allowed_list: Whitelist SSID's
 * @num_bssid_favored: Number of BSSID's which have a preference over others
 * @bssid_favored: Favorable BSSID's
 * @bssid_favored_factor: RSSI to be added to this BSSID to prefer it
 * @good_rssi_roam: Lazy Roam
 * @alert_rssi_threshold: Alert RSSI
 * @rssi: rssi diff
 * @raise_rssi_thresh_5g: The RSSI threshold below which the
 *                        raise_factor_5g (boost factor) should be applied.
 * @drop_rssi_thresh_5g: The RSSI threshold beyond which the
 *                       drop_factor_5g (penalty factor) should be applied
 * @raise_factor_5g: Boost factor
 * @drop_factor_5g: Penalty factor
 * @max_raise_rssi_5g: Maximum amount of Boost that can added
 * @is_fils_roaming_supported: fils roaming supported
 * @roam_scan_control: roam scan control
 * @policy_params: roam policy params
 * @neighbor_report_offload: neighbor report offload params
 */
struct rso_config_params {
	uint8_t num_ssid_allowed_list;
	struct wlan_ssid ssid_allowed_list[MAX_SSID_ALLOWED_LIST];
	uint8_t num_bssid_favored;
	struct qdf_mac_addr bssid_favored[MAX_BSSID_FAVORED];
	uint8_t bssid_favored_factor[MAX_BSSID_FAVORED];
	int good_rssi_roam;
	int alert_rssi_threshold;
	int rssi_diff;
	int raise_rssi_thresh_5g;
	int drop_rssi_thresh_5g;
	uint8_t raise_factor_5g;
	uint8_t drop_factor_5g;
	int max_raise_rssi_5g;
	uint8_t cat_rssi_offset;
	bool is_fils_roaming_supported;
	bool roam_scan_control;
	struct rso_roam_policy_params policy_params;
	struct cm_roam_neighbor_report_offload_params neighbor_report_offload;
};

/**
 * enum roam_cfg_param  - Type values for roaming parameters used as index
 * for get/set of roaming config values(pNeighborRoamInfo in legacy)
 * @RSSI_CHANGE_THRESHOLD: Rssi change threshold
 * @BEACON_RSSI_WEIGHT: Beacon Rssi weight parameter
 * @HI_RSSI_DELAY_BTW_SCANS: High Rssi delay between scans
 * @EMPTY_SCAN_REFRESH_PERIOD: empty scan refresh period
 * @FULL_ROAM_SCAN_PERIOD: Full roam scan period
 * @ENABLE_SCORING_FOR_ROAM: enable scoring
 * @SCAN_MIN_CHAN_TIME: scan min chan time
 * @SCAN_MAX_CHAN_TIME: scan max chan time
 * @NEIGHBOR_SCAN_PERIOD: neighbour scan period
 * @ROAM_CONFIG_ENABLE: Roam config enable
 * @ROAM_PREFERRED_CHAN: preferred channel list
 * @ROAM_SPECIFIC_CHAN: spedific channel list
 * @ROAM_RSSI_DIFF: rssi diff
 * @NEIGHBOUR_LOOKUP_THRESHOLD: lookup threshold
 * @SCAN_N_PROBE: scan n probe
 * @SCAN_HOME_AWAY: scan and away
 * @NEIGHBOUR_SCAN_REFRESH_PERIOD: scan refresh
 * @ROAM_CONTROL_ENABLE: roam control enable
 * @UAPSD_MASK: uapsd mask
 * @MOBILITY_DOMAIN: mobility domain
 * @IS_11R_CONNECTION: is 11r connection
 * @ADAPTIVE_11R_CONNECTION: adaptive 11r
 * @HS_20_AP: Hotspot 2.0 AP
 * @MBO_OCE_ENABLED_AP: MBO/OCE enabled network
 * @LOST_LINK_RSSI: lost link RSSI
 */
enum roam_cfg_param {
	RSSI_CHANGE_THRESHOLD,
	BEACON_RSSI_WEIGHT,
	HI_RSSI_DELAY_BTW_SCANS,
	EMPTY_SCAN_REFRESH_PERIOD,
	FULL_ROAM_SCAN_PERIOD,
	ENABLE_SCORING_FOR_ROAM,
	SCAN_MIN_CHAN_TIME,
	SCAN_MAX_CHAN_TIME,
	NEIGHBOR_SCAN_PERIOD,
	ROAM_CONFIG_ENABLE,
	ROAM_PREFERRED_CHAN,
	ROAM_SPECIFIC_CHAN,
	ROAM_RSSI_DIFF,
	NEIGHBOUR_LOOKUP_THRESHOLD,
	SCAN_N_PROBE,
	SCAN_HOME_AWAY,
	NEIGHBOUR_SCAN_REFRESH_PERIOD,
	ROAM_CONTROL_ENABLE,
	UAPSD_MASK,
	MOBILITY_DOMAIN,
	IS_11R_CONNECTION,
	ADAPTIVE_11R_CONNECTION,
	HS_20_AP,
	MBO_OCE_ENABLED_AP,
	IS_SINGLE_PMK,
	LOST_LINK_RSSI,
};

/**
 * enum roam_offload_init_flags  - Flags sent in Roam offload initialization.
 * @WLAN_ROAM_FW_OFFLOAD_ENABLE: Init roaming module at firwmare
 * @WLAN_ROAM_BMISS_FINAL_SCAN_ENABLE: Enable partial scan after final beacon
 * miss event at firmware
 * @WLAN_ROAM_SKIP_EAPOL_4WAY_HANDSHAKE: Disable 4 Way-HS offload to firmware
 * Setting this flag will make the eapol packets reach to host every time
 * and can cause frequent APPS wake-ups.
 * @WLAN_ROAM_BMISS_FINAL_SCAN_TYPE: Set this flag to skip full scan on final
 * bmiss and use the channel map to do the partial scan alone
 */
enum roam_offload_init_flags {
	WLAN_ROAM_FW_OFFLOAD_ENABLE = BIT(1),
	WLAN_ROAM_BMISS_FINAL_SCAN_ENABLE = BIT(2),
	WLAN_ROAM_SKIP_EAPOL_4WAY_HANDSHAKE = BIT(3),
	WLAN_ROAM_BMISS_FINAL_SCAN_TYPE = BIT(4)
};

/**
 * struct wlan_roam_offload_init_params - Firmware roam module initialization
 * parameters. Used to fill
 * @vdev_id: vdev for which the roaming has to be enabled/disabled
 * @roam_offload_flag:  flag to init/deinit roam module
 */
struct wlan_roam_offload_init_params {
	uint8_t vdev_id;
	uint32_t roam_offload_flag;
};

/**
 * struct wlan_cm_roam_vendor_btm_params - vendor config roam control param
 * @scan_freq_scheme: scan frequency scheme from enum
 * qca_roam_scan_freq_scheme
 * @connected_rssi_threshold: RSSI threshold of the current
 * connected AP
 * @candidate_rssi_threshold: RSSI threshold of the
 * candidate AP
 * @user_roam_reason: Roam triggered reason code, value zero is for enable
 * and non zero value is disable
 */
struct wlan_cm_roam_vendor_btm_params {
	uint32_t scan_freq_scheme;
	uint32_t connected_rssi_threshold;
	uint32_t candidate_rssi_threshold;
	uint32_t user_roam_reason;
};

/**
 * struct ap_profile - Structure ap profile to match candidate
 * @flags: flags
 * @rssi_threshold: the value of the the candidate AP should higher by this
 *                  threshold than the rssi of the currrently associated AP
 * @ssid: ssid vlaue to be matched
 * @rsn_authmode: security params to be matched
 * @rsn_ucastcipherset: unicast cipher set
 * @rsn_mcastcipherset: mcast/group cipher set
 * @rsn_mcastmgmtcipherset: mcast/group management frames cipher set
 * @rssi_abs_thresh: the value of the candidate AP should higher than this
 *                   absolute RSSI threshold. Zero means no absolute minimum
 *                   RSSI is required. units are the offset from the noise
 *                   floor in dB
 * @bg_rssi_threshold: Value of rssi threshold to trigger roaming
 *                     after background scan.
 */
struct ap_profile {
	uint32_t flags;
	uint32_t rssi_threshold;
	struct wlan_ssid  ssid;
	uint32_t rsn_authmode;
	uint32_t rsn_ucastcipherset;
	uint32_t rsn_mcastcipherset;
	uint32_t rsn_mcastmgmtcipherset;
	uint32_t rssi_abs_thresh;
	uint8_t bg_rssi_threshold;
};

/**
 * struct scoring_param - scoring param to sortlist selected AP
 * @disable_bitmap: Each bit will be either allow(0)/disallow(1) to
 *                 considered the roam score param.
 * @rssi_weightage: RSSI weightage out of total score in %
 * @ht_weightage: HT weightage out of total score in %.
 * @vht_weightage: VHT weightage out of total score in %.
 * @he_weightaget: 11ax weightage out of total score in %.
 * @bw_weightage: Bandwidth weightage out of total score in %.
 * @band_weightage: Band(2G/5G) weightage out of total score in %.
 * @nss_weightage: NSS(1x1 / 2x2)weightage out of total score in %.
 * @esp_qbss_weightage: ESP/QBSS weightage out of total score in %.
 * @beamforming_weightage: Beamforming weightage out of total score in %.
 * @pcl_weightage: PCL weightage out of total score in %.
 * @oce_wan_weightage OCE WAN metrics weightage out of total score in %.
 * @oce_ap_tx_pwr_weightage: OCE AP TX power score in %
 * @oce_subnet_id_weightage: OCE subnet id score in %
 * @sae_pk_ap_weightage: SAE-PK AP score in %
 * @bw_index_score: channel BW scoring percentage information.
 *                 BITS 0-7   :- It contains scoring percentage of 20MHz   BW
 *                 BITS 8-15  :- It contains scoring percentage of 40MHz   BW
 *                 BITS 16-23 :- It contains scoring percentage of 80MHz   BW
 *                 BITS 24-31 :- It contains scoring percentage of 1600MHz BW
 *                 The value of each index must be 0-100
 * @band_index_score: band scording percentage information.
 *                   BITS 0-7   :- It contains scoring percentage of 2G
 *                   BITS 8-15  :- It contains scoring percentage of 5G
 *                   BITS 16-23 :- reserved
 *                   BITS 24-31 :- reserved
 *                   The value of each index must be 0-100
 * @nss_index_score: NSS scoring percentage information.
 *                  BITS 0-7   :- It contains scoring percentage of 1x1
 *                  BITS 8-15  :- It contains scoring percentage of 2x2
 *                  BITS 16-23 :- It contains scoring percentage of 3x3
 *                  BITS 24-31 :- It contains scoring percentage of 4x4
 *                  The value of each index must be 0-100
 * @roam_score_delta: delta value expected over the roam score of the candidate
 * ap over the roam score of the current ap
 * @roam_trigger_bitmap: bitmap of roam triggers on which roam_score_delta
 * will be applied
 * @vendor_roam_score_algorithm: Preferred algorithm for roam candidate
 * selection
 * @cand_min_roam_score_delta: candidate min roam score delta value
 * @rssi_scoring: RSSI scoring information.
 * @esp_qbss_scoring: ESP/QBSS scoring percentage information
 * @oce_wan_scoring: OCE WAN metrics percentage information
 */
struct scoring_param {
	uint32_t disable_bitmap;
	int32_t rssi_weightage;
	int32_t ht_weightage;
	int32_t vht_weightage;
	int32_t he_weightage;
	int32_t bw_weightage;
	int32_t band_weightage;
	int32_t nss_weightage;
	int32_t esp_qbss_weightage;
	int32_t beamforming_weightage;
	int32_t pcl_weightage;
	int32_t oce_wan_weightage;
	uint32_t oce_ap_tx_pwr_weightage;
	uint32_t oce_subnet_id_weightage;
	uint32_t sae_pk_ap_weightage;
	uint32_t bw_index_score;
	uint32_t band_index_score;
	uint32_t nss_index_score;
	uint32_t roam_score_delta;
	uint32_t roam_trigger_bitmap;
	uint32_t vendor_roam_score_algorithm;
	uint32_t cand_min_roam_score_delta;
	struct rssi_config_score rssi_scoring;
	struct per_slot_score esp_qbss_scoring;
	struct per_slot_score oce_wan_scoring;
};

/**
 * enum roam_trigger_reason - Reason for triggering roam
 * ROAM_TRIGGER_REASON_NONE: Roam trigger reason none
 * ROAM_TRIGGER_REASON_PER:  Roam triggered due to packet error
 * ROAM_TRIGGER_REASON_BMISS: Roam triggered due to beacon miss
 * ROAM_TRIGGER_REASON_LOW_RSSI: Roam triggered due to low RSSI of current
 * connected AP.
 * ROAM_TRIGGER_REASON_HIGH_RSSI: Roam triggered because sta is connected to
 * a AP in 2.4GHz band and a better 5GHz AP is available
 * ROAM_TRIGGER_REASON_PERIODIC: Roam triggered as better AP was found during
 * periodic roam scan.
 * ROAM_TRIGGER_REASON_MAWC: Motion Aided WiFi Connectivity triggered roam.
 * ROAM_TRIGGER_REASON_DENSE: Roaming triggered due to dense environment
 * detected.
 * ROAM_TRIGGER_REASON_BACKGROUND: Roam triggered due to current AP having
 * poor rssi and scan candidate found in scan results provided by other
 * scan clients.
 * ROAM_TRIGGER_REASON_FORCED: Forced roam trigger.
 * ROAM_TRIGGER_REASON_BTM: Roam triggered due to AP sent BTM query with
 * Disassoc imminent bit set.
 * ROAM_TRIGGER_REASON_UNIT_TEST: Roam triggered due to unit test command.
 * ROAM_TRIGGER_REASON_BSS_LOAD: Roam triggered due to high channel utilization
 * in the current connected channel
 * ROAM_TRIGGER_REASON_DEAUTH: Roam triggered due to deauth received from the
 * current connected AP.
 * ROAM_TRIGGER_REASON_IDLE: Roam triggered due to inactivity of the device.
 * ROAM_TRIGGER_REASON_STA_KICKOUT: Roam triggered due to sta kickout event.
 * ROAM_TRIGGER_REASON_ESS_RSSI: Roam triggered due to ess rssi
 * ROAM_TRIGGER_REASON_WTC_BTM: Roam triggered due to WTC BTM
 * ROAM_TRIGGER_REASON_PMK_TIMEOUT: Roam triggered due to PMK expiry
 * ROAM_TRIGGER_REASON_MAX: Maximum number of roam triggers
 */
enum roam_trigger_reason {
	ROAM_TRIGGER_REASON_NONE = 0,
	ROAM_TRIGGER_REASON_PER,
	ROAM_TRIGGER_REASON_BMISS,
	ROAM_TRIGGER_REASON_LOW_RSSI,
	ROAM_TRIGGER_REASON_HIGH_RSSI,
	ROAM_TRIGGER_REASON_PERIODIC,
	ROAM_TRIGGER_REASON_MAWC,
	ROAM_TRIGGER_REASON_DENSE,
	ROAM_TRIGGER_REASON_BACKGROUND,
	ROAM_TRIGGER_REASON_FORCED,
	ROAM_TRIGGER_REASON_BTM,
	ROAM_TRIGGER_REASON_UNIT_TEST,
	ROAM_TRIGGER_REASON_BSS_LOAD,
	ROAM_TRIGGER_REASON_DEAUTH,
	ROAM_TRIGGER_REASON_IDLE,
	ROAM_TRIGGER_REASON_STA_KICKOUT,
	ROAM_TRIGGER_REASON_ESS_RSSI,
	ROAM_TRIGGER_REASON_WTC_BTM,
	ROAM_TRIGGER_REASON_PMK_TIMEOUT,
	ROAM_TRIGGER_REASON_MAX,
};

/**
 * struct roam_trigger_min_rssi - structure to hold minimum rssi value of
 * candidate APs for each roam trigger
 * @min_rssi: minimum RSSI of candidate AP for the trigger reason specified in
 * trigger_id
 * @trigger_reason: Roam trigger reason
 */
struct roam_trigger_min_rssi {
	int32_t  min_rssi;
	enum roam_trigger_reason trigger_reason;
};

/**
 * struct roam_trigger_score_delta - structure to hold roam score delta value of
 * candidate APs for each roam trigger
 * @roam_score_delta: delta value in score of the candidate AP for the roam
 * trigger mentioned in the trigger_id.
 * @trigger_reason: Roam trigger reason
 */
struct roam_trigger_score_delta {
	uint32_t roam_score_delta;
	enum roam_trigger_reason trigger_reason;
};

/**
 * struct wlan_roam_triggers - vendor configured roam triggers
 * @vdev_id: vdev id
 * @trigger_bitmap: vendor configured roam trigger bitmap as
 *		    defined @enum roam_control_trigger_reason
 * @roam_score_delta: Value of roam score delta
 * percentage to trigger roam
 * @roam_scan_scheme_bitmap: Bitmap of roam triggers as defined in
 * enum roam_trigger_reason, for which the roam scan scheme should
 * be partial scan
 * @control_param: roam trigger param
 * @min_rssi_params: Min RSSI values for different roam triggers
 * @score_delta_params: Roam score delta values for different triggers
 */
struct wlan_roam_triggers {
	uint32_t vdev_id;
	uint32_t trigger_bitmap;
	uint32_t roam_score_delta;
	uint32_t roam_scan_scheme_bitmap;
	struct wlan_cm_roam_vendor_btm_params vendor_btm_param;
	struct roam_trigger_min_rssi min_rssi_params[NUM_OF_ROAM_MIN_RSSI];
	struct roam_trigger_score_delta score_delta_param[NUM_OF_ROAM_TRIGGERS];
};

/**
 * struct ap_profile_params - ap profile params
 * @vdev_id: vdev id
 * @profile: ap profile to match candidate
 * @param: scoring params to short candidate
 * @min_rssi_params: Min RSSI values for different roam triggers
 * @score_delta_params: Roam score delta values for different triggers
 */
struct ap_profile_params {
	uint8_t vdev_id;
	struct ap_profile profile;
	struct scoring_param param;
	struct roam_trigger_min_rssi min_rssi_params[NUM_OF_ROAM_MIN_RSSI];
	struct roam_trigger_score_delta score_delta_param[NUM_OF_ROAM_TRIGGERS];
};

/**
 * struct wlan_roam_mawc_params - Motion Aided wireless connectivity params
 * @vdev_id: VDEV on which the parameters should be applied
 * @enable: MAWC roaming feature enable/disable
 * @traffic_load_threshold: Traffic threshold in kBps for MAWC roaming
 * @best_ap_rssi_threshold: AP RSSI Threshold for MAWC roaming
 * @rssi_stationary_high_adjust: High RSSI adjustment value to suppress scan
 * @rssi_stationary_low_adjust: Low RSSI adjustment value to suppress scan
 */
struct wlan_roam_mawc_params {
	uint8_t vdev_id;
	bool enable;
	uint32_t traffic_load_threshold;
	uint32_t best_ap_rssi_threshold;
	uint8_t rssi_stationary_high_adjust;
	uint8_t rssi_stationary_low_adjust;
};

/**
 * struct roam_scan_filter_params - Structure holding roaming scan
 *                                  parameters
 * @op_bitmap: bitmap to determine reason of roaming
 * @vdev_id: vdev id
 * @num_bssid_black_list: The number of BSSID's that we should avoid
 *                        connecting to. It is like a blacklist of BSSID's.
 * @num_ssid_white_list: The number of SSID profiles that are in the
 *                       Whitelist. When roaming, we consider the BSSID's with
 *                       this SSID also for roaming apart from the connected
 *                       one's
 * @num_bssid_preferred_list: Number of BSSID's which have a preference over
 *                            others
 * @bssid_avoid_list: Blacklist SSID's
 * @ssid_allowed_list: Whitelist SSID's
 * @bssid_favored: Favorable BSSID's
 * @bssid_favored_factor: RSSI to be added to this BSSID to prefer it
 * @lca_disallow_config_present: LCA [Last Connected AP] disallow config
 *                               present
 * @disallow_duration: How long LCA AP will be disallowed before it can be a
 *                     roaming candidate again, in seconds
 * @rssi_channel_penalization: How much RSSI will be penalized if candidate(s)
 *                             are found in the same channel as disallowed
 *                             AP's, in units of db
 * @num_disallowed_aps: How many APs the target should maintain in its LCA
 *                      list
 * @delta_rssi: (dB units) when AB in RSSI blacklist improved by at least
 *              delta_rssi,it will be removed from blacklist
 *
 * This structure holds all the key parameters related to
 * initial connection and roaming connections.
 */

struct roam_scan_filter_params {
	uint32_t op_bitmap;
	uint8_t vdev_id;
	uint32_t num_bssid_black_list;
	uint32_t num_ssid_white_list;
	uint32_t num_bssid_preferred_list;
	struct qdf_mac_addr bssid_avoid_list[MAX_BSSID_AVOID_LIST];
	struct wlan_ssid ssid_allowed_list[MAX_SSID_ALLOWED_LIST];
	struct qdf_mac_addr bssid_favored[MAX_BSSID_FAVORED];
	uint8_t bssid_favored_factor[MAX_BSSID_FAVORED];
	uint8_t lca_disallow_config_present;
	uint32_t disallow_duration;
	uint32_t rssi_channel_penalization;
	uint32_t num_disallowed_aps;
	uint32_t num_rssi_rejection_ap;
	struct reject_ap_config_params
				rssi_rejection_ap[MAX_RSSI_AVOID_BSSID_LIST];
	uint32_t delta_rssi;
};

/**
 * struct wlan_roam_scan_filter_params - structure containing parameters for
 * roam scan offload filter
 * @reason: reason for changing roam state for the requested vdev id
 * @filter_params: roam scan filter parameters
 */
struct wlan_roam_scan_filter_params {
	uint8_t reason;
	struct roam_scan_filter_params filter_params;
};

/**
 * struct wlan_roam_btm_config - BSS Transition Management offload params
 * @vdev_id: VDEV on which the parameters should be applied
 * @btm_offload_config: BTM config
 * @btm_solicited_timeout: Timeout value for waiting BTM request
 * @btm_max_attempt_cnt: Maximum attempt for sending BTM query to ESS
 * @btm_sticky_time: Stick time after roaming to new AP by BTM
 * @disassoc_timer_threshold: threshold value till which the firmware can
 * wait before triggering the roam scan after receiving the disassoc iminent
 * @btm_query_bitmask: bitmask to btm query with candidate list
 * @btm_candidate_min_score: Minimum score of the AP to consider it as a
 * candidate if the roam trigger is BTM kickout.
 */
struct wlan_roam_btm_config {
	uint8_t vdev_id;
	uint32_t btm_offload_config;
	uint32_t btm_solicited_timeout;
	uint32_t btm_max_attempt_cnt;
	uint32_t btm_sticky_time;
	uint32_t disassoc_timer_threshold;
	uint32_t btm_query_bitmask;
	uint32_t btm_candidate_min_score;
};

/**
 * struct wlan_roam_neighbor_report_params -neighbour report params
 * @time_offset: time offset after 11k offload command to trigger a neighbor
 *	report request (in seconds)
 * @low_rssi_offset: Offset from rssi threshold to trigger a neighbor
 *	report request (in dBm)
 * @bmiss_count_trigger: Number of beacon miss events to trigger neighbor
 *	report request
 * @per_threshold_offset: offset from PER threshold to trigger neighbor
 *	report request (in %)
 * @neighbor_report_cache_timeout: timeout after which new trigger can enable
 *	sending of a neighbor report request (in seconds)
 * @max_neighbor_report_req_cap: max number of neighbor report requests that
 *	can be sent to the peer in the current session
 * @ssid: Current connect SSID info
 */
struct wlan_roam_neighbor_report_params {
	uint32_t time_offset;
	uint32_t low_rssi_offset;
	uint32_t bmiss_count_trigger;
	uint32_t per_threshold_offset;
	uint32_t neighbor_report_cache_timeout;
	uint32_t max_neighbor_report_req_cap;
	struct wlan_ssid ssid;
};

/**
 * struct wlan_roam_11k_offload_params - offload 11k features to FW
 * @vdev_id: vdev id
 * @offload_11k_bitmask: bitmask to specify offloaded features
 *	B0: Neighbor Report Request offload
 *	B1-B31: Reserved
 * @neighbor_report_params: neighbor report offload params
 */
struct wlan_roam_11k_offload_params {
	uint32_t vdev_id;
	uint32_t offload_11k_bitmask;
	struct wlan_roam_neighbor_report_params neighbor_report_params;
};

/**
 * struct wlan_roam_bss_load_config - BSS load trigger parameters
 * @vdev_id: VDEV on which the parameters should be applied
 * @bss_load_threshold: BSS load threshold after which roam scan should trigger
 * @bss_load_sample_time: Time duration in milliseconds for which the bss load
 * trigger needs to be enabled
 * @rssi_threshold_5ghz: RSSI threshold of the current connected AP below which
 * roam should be triggered if bss load threshold exceeds the configured value.
 * This value is applicable only when we are connected in 5GHz band.
 * @rssi_threshold_24ghz: RSSI threshold of the current connected AP below which
 * roam should be triggered if bss load threshold exceeds the configured value.
 * This value is applicable only when we are connected in 2.4GHz band.
 */
struct wlan_roam_bss_load_config {
	uint32_t vdev_id;
	uint32_t bss_load_threshold;
	uint32_t bss_load_sample_time;
	int32_t rssi_threshold_5ghz;
	int32_t rssi_threshold_24ghz;
};

/**
 * struct roam_disable_cfg - Firmware roam module disable parameters
 * @vdev_id: vdev for which the roaming has to be enabled/disabled
 * @cfg:  Config to enable/disable FW roam module
 */
struct roam_disable_cfg {
	uint8_t vdev_id;
	uint8_t cfg;
};

/**
 * struct wlan_roam_disconnect_params - Emergency deauth/disconnect roam params
 * @vdev_id: VDEV on which the parameters should be applied
 * @enable: Enable or disable disconnect roaming.
 */
struct wlan_roam_disconnect_params {
	uint32_t vdev_id;
	bool enable;
};

/**
 * struct wlan_roam_idle_params - Idle roam trigger parameters
 * @vdev_id: VDEV on which the parameters should be applied
 * @enable: Enable/Disable Idle roaming
 * @band: Connected AP band
 * @conn_ap_rssi_delta: Rssi change of connected AP in dBm
 * @conn_ap_min_rssi: If connected AP rssi is less than min rssi trigger roam
 * @inactive_time: Connected AP idle time
 * @data_pkt_count: Data packet count allowed during idle time
 */
struct wlan_roam_idle_params {
	uint32_t vdev_id;
	bool enable;
	uint32_t band;
	uint32_t conn_ap_rssi_delta;
	int32_t conn_ap_min_rssi;
	uint32_t inactive_time;
	uint32_t data_pkt_count;
};

/**
 * struct wlan_per_roam_config - per based roaming parameters
 * @enable: if PER based roaming is enabled/disabled
 * @tx_high_rate_thresh: high rate threshold at which PER based
 *     roam will stop in tx path
 * @rx_high_rate_thresh: high rate threshold at which PER based
 *     roam will stop in rx path
 * @tx_low_rate_thresh: rate below which traffic will be considered
 *     for PER based roaming in Tx path
 * @rx_low_rate_thresh: rate below which traffic will be considered
 *     for PER based roaming in Tx path
 * @tx_rate_thresh_percnt: % above which when traffic is below low_rate_thresh
 *     will be considered for PER based scan in tx path
 * @rx_rate_thresh_percnt: % above which when traffic is below low_rate_thresh
 *     will be considered for PER based scan in rx path
 * @per_rest_time: time for which PER based roam will wait once it
 *     issues a roam scan.
 * @tx_per_mon_time: Minimum time required to be considered as valid scenario
 *     for PER based roam in tx path
 * @rx_per_mon_time: Minimum time required to be considered as valid scenario
 *     for PER based roam in rx path
 * @min_candidate_rssi: Minimum RSSI threshold for candidate AP to be used for
 *     PER based roaming
 */
struct wlan_per_roam_config {
	uint32_t enable;
	uint32_t tx_high_rate_thresh;
	uint32_t rx_high_rate_thresh;
	uint32_t tx_low_rate_thresh;
	uint32_t rx_low_rate_thresh;
	uint32_t tx_rate_thresh_percnt;
	uint32_t rx_rate_thresh_percnt;
	uint32_t per_rest_time;
	uint32_t tx_per_mon_time;
	uint32_t rx_per_mon_time;
	uint32_t min_candidate_rssi;
};

/**
 * struct wlan_per_roam_config_req: PER based roaming config request
 * @vdev_id: vdev id on which config needs to be set
 * @per_config: PER config
 */
struct wlan_per_roam_config_req {
	uint8_t vdev_id;
	struct wlan_per_roam_config per_config;
};

#define NOISE_FLOOR_DBM_DEFAULT          (-96)
#define RSSI_MIN_VALUE                   (-128)
#define RSSI_MAX_VALUE                   (127)

#ifdef WLAN_FEATURE_FILS_SK
#define WLAN_FILS_MAX_USERNAME_LENGTH 16

/**
 * struct wlan_roam_fils_params - Roaming FILS params
 * @next_erp_seq_num: next ERP sequence number
 * @username: username
 * @username_length: username length
 * @rrk: RRK
 * @rrk_length: length of @rrk
 * @rik: RIK
 * @rik_length: length of @rik
 * @realm: realm
 * @realm_len: length of @realm
 * @fils_ft: xx_key for FT-FILS connection
 * @fils_ft_len: length of FT-FILS
 */
struct wlan_roam_fils_params {
	uint32_t next_erp_seq_num;
	uint8_t username[WLAN_FILS_MAX_USERNAME_LENGTH];
	uint32_t username_length;
	uint8_t rrk[WLAN_FILS_MAX_RRK_LENGTH];
	uint32_t rrk_length;
	uint8_t rik[WLAN_FILS_MAX_RIK_LENGTH];
	uint32_t rik_length;
	uint8_t realm[WLAN_FILS_MAX_REALM_LEN];
	uint32_t realm_len;
	uint8_t fils_ft[WLAN_FILS_FT_MAX_LEN];
	uint8_t fils_ft_len;
};
#endif

/**
 * struct wlan_roam_scan_params  - Roaming scan parameters
 * @vdev_id: vdev id
 * @dwell_time_passive: dwell time in msec on passive channels
 * @dwell_time_active: dwell time in msec on active channels
 * @burst_duration: Burst duration time in msec
 * @min_rest_time: min time in msec on the BSS channel,only valid if atleast
 * one VDEV is active
 * @max_rest_time: max rest time in msec on the BSS channel,only valid if
 * at least one VDEV is active
 * @probe_spacing_time: time in msec between 2 consequetive probe requests with
 * in a set
 * @probe_delay: delay in msec before sending first probe request after
 * switching to a channel
 * @repeat_probe_time: time in msec between 2 consequetive probe requests within
 * a set
 * @max_scan_time: maximum time in msec allowed for scan
 * @idle_time: data inactivity time in msec on bss channel that will be used by
 * scanner for measuring the inactivity
 * @n_probes: Max number of probes to be sent
 * @scan_ctrl_flags: Scan control flags
 * @scan_ctrl_flags_ext: Scan control flags extended
 * @rso_adaptive_dwell_mode: Adaptive dwell mode
 * @num_chan: number of channels
 * @num_bssid: number of bssids in tlv bssid_list[]
 * @ie_len: number of bytes in ie data. In the TLV ie_data[]
 * @dwell_time_active_2g: dwell time in msec on active 2G channels.
 * @dwell_time_active_6ghz: dwell time in msec when 6 GHz channel
 * @dwell_time_passive_6ghz: Passive scan dwell time in msec for 6Ghz channel.
 * @scan_start_offset: Offset time is in milliseconds per channel
 */
struct wlan_roam_scan_params {
	uint32_t vdev_id;
	uint32_t dwell_time_passive;
	uint32_t dwell_time_active;
	uint32_t burst_duration;
	uint32_t min_rest_time;
	uint32_t max_rest_time;
	uint32_t probe_spacing_time;
	uint32_t probe_delay;
	uint32_t repeat_probe_time;
	uint32_t max_scan_time;
	uint32_t idle_time;
	uint32_t n_probes;
	uint32_t scan_ctrl_flags;
	uint32_t scan_ctrl_flags_ext;
	enum scan_dwelltime_adaptive_mode rso_adaptive_dwell_mode;
	uint32_t num_chan;
	uint32_t num_bssid;
	uint32_t ie_len;
	uint32_t dwell_time_active_2g;
	uint32_t dwell_time_active_6ghz;
	uint32_t dwell_time_passive_6ghz;
	uint32_t scan_start_offset;
};

/**
 * struct wlan_roam_scan_mode_params  - WMI_ROAM_SCAN_MODE command fixed_param
 * wmi_roam_scan_mode_fixed_param related params
 * @roam_scan_mode: Roam scan mode flags
 * @min_delay_btw_scans: Minimum duration allowed between two consecutive roam
 * scans in millisecs.
 * @min_delay_roam_trigger_bitmask: Roaming triggers for which the min delay
 * between roam scans is applicable(bitmask of enum WMI_ROAM_TRIGGER_REASON_ID)
 */
struct wlan_roam_scan_mode_params {
	uint32_t roam_scan_mode;
	uint32_t min_delay_btw_scans;
	uint32_t min_delay_roam_trigger_bitmask;
};

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
/**
 * struct wlan_rso_lfr3_params  - LFR-3.0 roam offload params to be filled
 * in the wmi_roam_offload_tlv_param TLV of WMI_ROAM_SCAN_MODE command.
 * @roam_rssi_cat_gap: RSSI category gap
 * @prefer_5ghz: Prefer 5G candidate AP
 * @select_5gz_margin: Prefer connecting to 5G AP even if its RSSI is lower by
 * select_5g_margin dBm
 * @reassoc_failure_timeout: reassociation response failure timeout
 * @ho_delay_for_rx: Time in millisecs to delay hand-off by this duration to
 * receive pending Rx frames from current BSS
 * @roam_retry_count: maximum number of software retries for preauth and
 * reassoc req
 * @roam_preauth_no_ack_timeout: duration in millsecs to wait before another SW
 * retry made if no ack seen for previous frame
 * @diable_self_roam: Disable roaming to current connected BSS.
 * @rct_validity_timer: duration value for which the entries in
 * roam candidate table(rct) are valid
 */
struct wlan_rso_lfr3_params {
	uint8_t roam_rssi_cat_gap;
	uint8_t prefer_5ghz;
	uint8_t select_5ghz_margin;
	uint32_t reassoc_failure_timeout;
	uint32_t ho_delay_for_rx;
	uint32_t roam_retry_count;
	uint32_t roam_preauth_no_ack_timeout;
	bool disable_self_roam;
	uint32_t rct_validity_timer;
};

#define WLAN_ROAM_OFFLOAD_NUM_MCS_SET     (16)
/**
 * struct wlan_lfr3_roam_offload_param  - LFR3 Roaming offload parameters
 * @capability: RSN capabilities
 * @ht_caps_info: HT capabilities information
 * @ampdu_param: AMPDU configs
 * @ht_ext_cap: HT extended capabilities info
 * @ht_txbf: HT Tx Beamform capabilities
 * @asel_cap: Antena selection capabilities
 * @qos_enabled: QoS enabled
 * @qos_caps: QoS capabilities
 * @wmm_caps: WMM capabilities
 * @mcsset: MCS set
 */
struct wlan_rso_lfr3_caps {
	uint32_t capability;
	uint32_t ht_caps_info;
	uint32_t ampdu_param;
	uint32_t ht_ext_cap;
	uint32_t ht_txbf;
	uint32_t asel_cap;
	uint32_t qos_enabled;
	uint32_t qos_caps;
	uint32_t wmm_caps;
	/* since this is 4 byte aligned, we don't declare it as tlv array */
	uint32_t mcsset[WLAN_ROAM_OFFLOAD_NUM_MCS_SET >> 2];
};

/**
 * struct wlan_rso_11i_params  - LFR-3.0 related parameters to be filled in
 * wmi_roam_11i_offload_tlv_param TLV in the WMI_ROAM_SCAN_MODE command.
 * @roam_key_mgmt_offload_enabled: Enable 4-way HS offload to firmware
 * @fw_okc: use OKC in firmware
 * @fw_pmksa_cache: use PMKSA cache in firmware
 * @is_sae_same_pmk: Flag to indicate fw whether WLAN_SAE_SINGLE_PMK feature is
 * enable or not
 * @psk_pmk: pre shared key/pairwise master key
 * @pmk_len: length of PMK
 */
struct wlan_rso_11i_params {
	bool roam_key_mgmt_offload_enabled;
	bool fw_okc;
	bool fw_pmksa_cache;
	bool is_sae_same_pmk;
	uint8_t psk_pmk[WMI_ROAM_SCAN_PSK_SIZE];
	uint8_t pmk_len;
};

/**
 * struct wlan_rso_11r_params  - LFR-3.0 parameters to fill
 * wmi_roam_11r_offload_tlv_param TLV related info in WMI_ROAM_SCAN_MODE command
 * @enable_ft_im_roaming: Flag to enable/disable FT-IM roaming upon receiving
 * deauth
 * @rokh_id_length: r0kh id length
 * @rokh_id: r0kh id
 * @mdid: mobility domain info
 */
struct wlan_rso_11r_params {
	bool is_11r_assoc;
	bool is_adaptive_11r;
	bool enable_ft_im_roaming;
	uint8_t psk_pmk[WMI_ROAM_SCAN_PSK_SIZE];
	uint8_t pmk_len;
	uint32_t r0kh_id_length;
	uint8_t r0kh_id[WMI_ROAM_R0KH_ID_MAX_LEN];
	struct mobility_domain_info mdid;
};

/**
 * struct wlan_rso_ese_params  - LFR-3.0 parameters to fill the
 * wmi_roam_ese_offload_tlv_param TLV related info in WMI_ROAM_SCAN_MODE command
 * @is_ese_assoc: flag to determine ese assoc
 * @krk: KRK
 * @btk: BTK
 */
struct wlan_rso_ese_params {
	bool is_ese_assoc;
	uint8_t krk[WMI_KRK_KEY_LEN];
	uint8_t btk[WMI_BTK_KEY_LEN];
};

/**
 * struct wlan_rso_sae_offload_params - SAE authentication offload related
 * parameters.
 * @spmk_timeout: Single PMK timeout value in seconds.
 */
struct wlan_rso_sae_offload_params {
	uint32_t spmk_timeout;
};
#endif

#define ROAM_SCAN_DWELL_TIME_ACTIVE_DEFAULT   (100)
#define ROAM_SCAN_DWELL_TIME_PASSIVE_DEFAULT  (110)
#define ROAM_SCAN_MIN_REST_TIME_DEFAULT       (50)
#define ROAM_SCAN_MAX_REST_TIME_DEFAULT       (500)
#define ROAM_SCAN_HW_DEF_SCAN_MAX_DURATION    30000 /* 30 secs */
#define ROAM_SCAN_CHANNEL_SWITCH_TIME         (4)

/**
 * struct roam_offload_scan_params - structure containing roaming offload scan
 * parameters to be filled over WMI_ROAM_SCAN_MODE command.
 * @vdev_id: vdev id
 * @is_rso_stop: flag to tell whether roam req is valid or NULL
 * @rso_mode_info: Roam scan mode related parameters
 * @rso_scan_params: Roam scan offload scan start params
 * @scan_params: Roaming scan related parameters
 * @assoc_ie_length: Assoc IE length
 * @assoc_ie: Assoc IE buffer
 * @roam_offload_enabled: flag for offload enable
 * @add_fils_tlv: add FILS TLV boolean
 * @akm: authentication key management mode
 * @rso_lfr3_params: Candidate selection and other lfr-3.0 offload parameters
 * @rso_lfr3_caps: Self capabilities
 * @rso_11i_info: PMK, PMKSA, SAE single PMK related parameters
 * @rso_11r_info: FT related parameters
 * @rso_ese_info: ESE related parameters
 * @fils_roam_config: roam fils params
 * @sae_offload_params: SAE offload/single pmk related parameters
 */
struct wlan_roam_scan_offload_params {
	uint32_t vdev_id;
	uint8_t is_rso_stop;
	/* Parameters common for LFR-3.0 and LFR-2.0 */
	bool roaming_scan_policy;
	struct wlan_roam_scan_mode_params rso_mode_info;
	struct wlan_roam_scan_params rso_scan_params;
	uint32_t assoc_ie_length;
	uint8_t  assoc_ie[MAX_ASSOC_IE_LENGTH];
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
	/* Parameters specific to LFR-3.0 */
	bool roam_offload_enabled;
	bool add_fils_tlv;
	int akm;
	struct wlan_rso_lfr3_params rso_lfr3_params;
	struct wlan_rso_lfr3_caps rso_lfr3_caps;
	struct wlan_rso_11i_params rso_11i_info;
	struct wlan_rso_11r_params rso_11r_info;
	struct wlan_rso_ese_params rso_ese_info;
#ifdef WLAN_FEATURE_FILS_SK
	struct wlan_roam_fils_params fils_roam_config;
#endif
	struct wlan_rso_sae_offload_params sae_offload_params;
#endif
};

/**
 * struct wlan_roam_offload_scan_rssi_params - structure containing
 *              parameters for roam offload scan based on RSSI
 * @rssi_thresh: rssi threshold
 * @rssi_thresh_diff: difference in rssi threshold
 * @hi_rssi_scan_max_count: 5G scan max count
 * @hi_rssi_scan_rssi_delta: 5G scan rssi change threshold value
 * @hi_rssi_scan_rssi_ub: 5G scan upper bound
 * @raise_rssi_thresh_5g: flag to determine penalty and boost thresholds
 * @vdev_id: vdev id
 * @penalty_threshold_5g: RSSI threshold below which 5GHz RSSI is penalized
 * @boost_threshold_5g: RSSI threshold above which 5GHz RSSI is favored
 * @raise_factor_5g: factor by which 5GHz RSSI is boosted
 * @drop_factor_5g: factor by which 5GHz RSSI is penalized
 * @max_raise_rssi_5g: maximum boost that can be applied to a 5GHz RSSI
 * @max_drop_rssi_5g: maximum penalty that can be applied to a 5GHz RSSI
 * @good_rssi_threshold: RSSI below which roam is kicked in by background
 *                       scan although rssi is still good
 * @early_stop_scan_enable: early stop scan enable
 * @roam_earlystop_thres_min: Minimum RSSI threshold value for early stop,
 *                            unit is dB above NF
 * @roam_earlystop_thres_max: Maximum RSSI threshold value for early stop,
 *                            unit is dB above NF
 * @dense_rssi_thresh_offset: dense roam RSSI threshold difference
 * @dense_min_aps_cnt: dense roam minimum APs
 * @initial_dense_status: dense status detected by host
 * @traffic_threshold: dense roam RSSI threshold
 * @bg_scan_bad_rssi_thresh: Bad RSSI threshold to perform bg scan
 * @roam_bad_rssi_thresh_offset_2g: Offset from Bad RSSI threshold for 2G
 *                                  to 5G Roam
 * @bg_scan_client_bitmap: Bitmap used to identify the client scans to snoop
 * @roam_data_rssi_threshold_triggers: triggers of bad data RSSI threshold to
 *                                  roam
 * @roam_data_rssi_threshold: Bad data RSSI threshold to roam
 * @rx_data_inactivity_time: Rx duration to check data RSSI
 */
struct wlan_roam_offload_scan_rssi_params {
	int8_t rssi_thresh;
	uint8_t rssi_thresh_diff;
	uint32_t hi_rssi_scan_max_count;
	uint32_t hi_rssi_scan_rssi_delta;
	int32_t hi_rssi_scan_rssi_ub;
	int raise_rssi_thresh_5g;
	int drop_rssi_thresh_5g;
	uint8_t vdev_id;
	uint32_t penalty_threshold_5g;
	uint32_t boost_threshold_5g;
	uint8_t raise_factor_5g;
	uint8_t drop_factor_5g;
	int max_raise_rssi_5g;
	int max_drop_rssi_5g;
	uint32_t good_rssi_threshold;
	bool early_stop_scan_enable;
	uint32_t roam_earlystop_thres_min;
	uint32_t roam_earlystop_thres_max;
	int dense_rssi_thresh_offset;
	int dense_min_aps_cnt;
	int initial_dense_status;
	int traffic_threshold;
	int32_t rssi_thresh_offset_5g;
	int8_t bg_scan_bad_rssi_thresh;
	uint8_t roam_bad_rssi_thresh_offset_2g;
	uint32_t bg_scan_client_bitmap;
	uint32_t roam_data_rssi_threshold_triggers;
	int32_t roam_data_rssi_threshold;
	uint32_t rx_data_inactivity_time;
};

/**
 * struct wlan_roam_beacon_miss_cnt - roam beacon miss count
 * @vdev_id: vdev id
 * @roam_bmiss_first_bcnt: First beacon miss count
 * @roam_bmiss_final_bcnt: Final beacon miss count
 */
struct wlan_roam_beacon_miss_cnt {
	uint32_t vdev_id;
	uint8_t roam_bmiss_first_bcnt;
	uint8_t roam_bmiss_final_bcnt;
};

/**
 * struct wlan_roam_reason_vsie_enable - roam reason vsie enable parameters
 * @vdev_id: vdev id
 * @enable_roam_reason_vsie: enable/disable inclusion of roam Reason
 * in Re(association) frame
 */
struct wlan_roam_reason_vsie_enable {
	uint32_t vdev_id;
	uint8_t enable_roam_reason_vsie;
};

/**
 * struct wlan_roam_scan_period_params - Roam scan period parameters
 * @vdev_id: Vdev for which the scan period parameters are sent
 * @empty_scan_refresh_period: empty scan refresh period
 * @scan_period: Opportunistic scan runs on a timer for scan_period
 * @scan_age: Duration after which the scan entries are to be aged out
 * @roam_scan_inactivity_time: inactivity monitoring time in ms for which the
 * device is considered to be inactive
 * @roam_inactive_data_packet_count: Maximum allowed data packets count during
 * roam_scan_inactivity_time.
 * @roam_scan_period_after_inactivity: Roam scan period in ms after device is
 * in inactive state.
 * @full_scan_period: Full scan period is the idle period in seconds
 * between two successive full channel roam scans.
 */
struct wlan_roam_scan_period_params {
	uint32_t vdev_id;
	uint32_t empty_scan_refresh_period;
	uint32_t scan_period;
	uint32_t scan_age;
	uint32_t roam_scan_inactivity_time;
	uint32_t roam_inactive_data_packet_count;
	uint32_t roam_scan_period_after_inactivity;
	uint32_t full_scan_period;
};

#define ROAM_MAX_CHANNELS 80
/**
 * wlan_roam_scan_channel_list  - Roam Scan channel list related
 * parameters
 * @vdev_id: Vdev id
 * @chan_count: Channel count
 * @chan_freq_list: Frequency list pointer
 * @chan_cache_type: Static or dynamic channel cache
 */
struct wlan_roam_scan_channel_list {
	uint32_t vdev_id;
	uint8_t chan_count;
	uint32_t chan_freq_list[ROAM_MAX_CHANNELS];
	uint8_t chan_cache_type;
};

/**
 * struct wlan_roam_rssi_change_params  - RSSI change parameters to be sent over
 * WMI_ROAM_SCAN_RSSI_CHANGE_THRESHOLD command
 * @vdev_id: vdev id
 * only if current RSSI changes by rssi_change_thresh value.
 * @bcn_rssi_weight: Beacon RSSI weightage
 * @hirssi_delay_btw_scans: Delay between high RSSI scans
 * @rssi_change_thresh: RSSI change threshold. Start new rssi triggered scan
 */
struct wlan_roam_rssi_change_params {
	uint32_t vdev_id;
	uint32_t bcn_rssi_weight;
	uint32_t hirssi_delay_btw_scans;
	int32_t rssi_change_thresh;
};

/**
 * struct wlan_roam_start_config - structure containing parameters for
 * roam start config
 * @rssi_params: roam scan rssi threshold parameters
 * @beacon_miss_cnt: roam beacon miss count parameters
 * @reason_vsie_enable: roam reason vsie enable parameters
 * @roam_triggers: roam triggers parameters
 * @scan_period_params: roam scan period parameters
 * @rssi_change_params: Roam offload RSSI change parameters
 * @profile_params: ap profile parameters
 * @rso_chan_info: Roam scan channel list parameters
 * @mawc_params: mawc parameters
 * @scan_filter_params: roam scan filter parameters
 * @btm_config: btm configuration
 * @roam_11k_params: 11k params
 * @bss_load_config: bss load config
 * @disconnect_params: disconnect params
 * @idle_params: idle params
 */
struct wlan_roam_start_config {
	struct wlan_roam_offload_scan_rssi_params rssi_params;
	struct wlan_roam_beacon_miss_cnt beacon_miss_cnt;
	struct wlan_roam_reason_vsie_enable reason_vsie_enable;
	struct wlan_roam_triggers roam_triggers;
	struct wlan_roam_scan_period_params scan_period_params;
	struct wlan_roam_scan_offload_params rso_config;
	struct wlan_roam_rssi_change_params rssi_change_params;
	struct ap_profile_params profile_params;
	struct wlan_roam_scan_channel_list rso_chan_info;
	struct wlan_roam_mawc_params mawc_params;
	struct wlan_roam_scan_filter_params scan_filter_params;
	struct wlan_roam_btm_config btm_config;
	struct wlan_roam_11k_offload_params roam_11k_params;
	struct wlan_roam_bss_load_config bss_load_config;
	struct wlan_roam_disconnect_params disconnect_params;
	struct wlan_roam_idle_params idle_params;
	/* other wmi cmd structures */
};

/**
 * struct wlan_roam_stop_config - structure containing parameters for
 * roam stop
 * @reason: roaming reason
 * @middle_of_roaming: in the middle of roaming
 * @rso_config: Roam scan mode config
 * @roam_11k_params: 11k params
 * @btm_config: btm configuration
 * @scan_filter_params: roam scan filter parameters
 * @disconnect_params: disconnect params
 * @idle_params: idle params
 * @roam_triggers: roam triggers parameters
 * @rssi_params: roam scan rssi threshold parameters
 */
struct wlan_roam_stop_config {
	uint8_t reason;
	uint8_t middle_of_roaming;
	struct wlan_roam_scan_offload_params rso_config;
	struct wlan_roam_11k_offload_params roam_11k_params;
	struct wlan_roam_btm_config btm_config;
	struct wlan_roam_scan_filter_params scan_filter_params;
	struct wlan_roam_disconnect_params disconnect_params;
	struct wlan_roam_idle_params idle_params;
	struct wlan_roam_triggers roam_triggers;
	struct wlan_roam_offload_scan_rssi_params rssi_params;
};

/**
 * struct wlan_roam_update_config - structure containing parameters for
 * roam update config
 * @beacon_miss_cnt: roam beacon miss count parameters
 * @scan_filter_params: roam scan filter parameters
 * @scan_period_params: roam scan period parameters
 * @rssi_change_params: roam scan rssi change parameters
 * @rso_config: roam scan mode configurations
 * @profile_params: ap profile parameters
 * @rso_chan_info: Roam scan channel list parameters
 * @rssi_params: roam scan rssi threshold parameters
 * @disconnect_params: disconnect params
 * @idle_params: idle params
 * @roam_triggers: roam triggers parameters
 */
struct wlan_roam_update_config {
	struct wlan_roam_beacon_miss_cnt beacon_miss_cnt;
	struct wlan_roam_scan_filter_params scan_filter_params;
	struct wlan_roam_scan_period_params scan_period_params;
	struct wlan_roam_rssi_change_params rssi_change_params;
	struct wlan_roam_scan_offload_params rso_config;
	struct ap_profile_params profile_params;
	struct wlan_roam_scan_channel_list rso_chan_info;
	struct wlan_roam_offload_scan_rssi_params rssi_params;
	struct wlan_roam_disconnect_params disconnect_params;
	struct wlan_roam_idle_params idle_params;
	struct wlan_roam_triggers roam_triggers;
};

#if defined(WLAN_FEATURE_HOST_ROAM) || defined(WLAN_FEATURE_ROAM_OFFLOAD)
/**
 * enum roam_offload_state - Roaming module state for each STA vdev.
 * @WLAN_ROAM_DEINIT: Roaming module is not initialized at the
 *  firmware.
 * @WLAN_ROAM_INIT: Roaming module initialized at the firmware.
 * @WLAN_ROAM_RSO_ENABLED: RSO enabled, firmware can roam to different AP.
 * @WLAN_ROAM_RSO_STOPPED: RSO stopped - roaming module is initialized at
 * firmware, but firmware cannot do roaming due to supplicant disabled
 * roaming/driver disabled roaming.
 * @WLAN_ROAMING_IN_PROG: Roaming started at firmware. This state is
 * transitioned after candidate selection is done at fw and preauth to
 * the AP is started.
 * @WLAN_ROAM_SYNCH_IN_PROG: Roaming handoff complete
 */
enum roam_offload_state {
	WLAN_ROAM_DEINIT,
	WLAN_ROAM_INIT,
	WLAN_ROAM_RSO_ENABLED,
	WLAN_ROAM_RSO_STOPPED,
	WLAN_ROAMING_IN_PROG,
	WLAN_ROAM_SYNCH_IN_PROG,
};

/**
 *  struct roam_btm_response_data - BTM response related data
 *  @present:       Flag to check if the roam btm_rsp tlv is present
 *  @btm_status:    Btm request status
 *  @target_bssid:  AP MAC address
 *  @vsie_reason:   Vsie_reason value
 *  @timestamp:     This timestamp indicates the time when btm rsp is sent
 */
struct roam_btm_response_data {
	bool present;
	uint32_t btm_status;
	struct qdf_mac_addr target_bssid;
	uint32_t vsie_reason;
	uint32_t timestamp;
};

/**
 *  struct roam_initial_data - Roam initial related data
 *  @present:                Flag to check if the roam btm_rsp tlv is present
 *  @roam_full_scan_count:   Roam full scan count
 *  @rssi_th:                RSSI threhold
 *  @cu_th:                  Channel utilization threhold
 *  @fw_cancel_timer_bitmap: FW timers, which are getting cancelled
 */
struct roam_initial_data {
	bool present;
	uint32_t roam_full_scan_count;
	uint32_t rssi_th;
	uint32_t cu_th;
	uint32_t fw_cancel_timer_bitmap;
};

/**
 * struct roam_msg_info - Roam message related information
 * @present:    Flag to check if the roam msg info tlv is present
 * @timestamp:  Timestamp is the absolute time w.r.t host timer which is
 * synchronized between the host and target
 * @msg_id:     Message ID from WMI_ROAM_MSG_ID
 * @msg_param1: msg_param1, values is based on the host & FW
 * understanding and depend on the msg ID
 * @msg_param2: msg_param2 value is based on the host & FW understanding
 * and depend on the msg ID
 */
struct roam_msg_info {
	bool present;
	uint32_t timestamp;
	uint32_t msg_id;
	uint32_t msg_param1;
	uint32_t msg_param2;
};

/**
 * enum wlan_cm_rso_control_requestor - Driver disabled roaming requestor that
 * will request the roam module to disable roaming based on the mlme operation
 * @RSO_INVALID_REQUESTOR: invalid requestor
 * @RSO_START_BSS: disable roaming temporarily due to start bss
 * @RSO_CHANNEL_SWITCH: disable roaming due to STA channel switch
 * @RSO_CONNECT_START: disable roaming temporarily due to connect
 * @RSO_SAP_CHANNEL_CHANGE: disable roaming due to SAP channel change
 * @RSO_NDP_CON_ON_NDI: disable roaming due to NDP connection on NDI
 * @RSO_SET_PCL: Disable roaming to set pcl to firmware
 */
enum wlan_cm_rso_control_requestor {
	RSO_INVALID_REQUESTOR,
	RSO_START_BSS          = BIT(0),
	RSO_CHANNEL_SWITCH     = BIT(1),
	RSO_CONNECT_START      = BIT(2),
	RSO_SAP_CHANNEL_CHANGE = BIT(3),
	RSO_NDP_CON_ON_NDI     = BIT(4),
	RSO_SET_PCL            = BIT(5),
};
#endif

/**
 * struct set_pcl_req - Request message to set the PCL
 * @vdev_id:   Vdev id
 * @band_mask: Supported band mask
 * @clear_vdev_pcl: Clear the configured vdev pcl channels
 * @chan_weights: PCL channel weights
 */
struct set_pcl_req {
	uint8_t vdev_id;
	uint32_t band_mask;
	bool clear_vdev_pcl;
	struct wmi_pcl_chan_weights chan_weights;
};

/**
 * struct roam_invoke_req - roam invoke request
 * @vdev_id: vdev for which the roaming has to be enabled/disabled
 * @target_bssid: target mac address
 * @ch_freq: channel frequency
 * @frame_len: frame length, includs mac header, fixed params and ies
 * @frame_buf: buffer contaning probe response or beacon
 * @is_same_bssid: flag to indicate if roaming is requested for same bssid
 * @forced_roaming: Roam to any bssid in any ch (here bssid & ch is not given)
 */
struct roam_invoke_req {
	uint8_t vdev_id;
	struct qdf_mac_addr target_bssid;
	uint32_t ch_freq;
	uint32_t frame_len;
	uint8_t *frame_buf;
	uint8_t is_same_bssid;
	bool forced_roaming;
};

/**
 * wlan_cm_roam_tx_ops  - structure of tx function pointers for
 * roaming related commands
 * @send_vdev_set_pcl_cmd: TX ops function pointer to send set vdev PCL
 * command
 * @send_roam_offload_init_req: TX Ops function pointer to send roam offload
 * module initialize request
 * @send_roam_start_req: TX ops function pointer to send roam start related
 * commands
 * @send_roam_abort: send roam abort
 * @send_roam_disable_config: send roam disable config
 */
struct wlan_cm_roam_tx_ops {
	QDF_STATUS (*send_vdev_set_pcl_cmd)(struct wlan_objmgr_vdev *vdev,
					    struct set_pcl_req *req);
	QDF_STATUS (*send_roam_offload_init_req)(
			struct wlan_objmgr_vdev *vdev,
			struct wlan_roam_offload_init_params *params);

	QDF_STATUS (*send_roam_start_req)(struct wlan_objmgr_vdev *vdev,
					  struct wlan_roam_start_config *req);
	QDF_STATUS (*send_roam_stop_offload)(struct wlan_objmgr_vdev *vdev,
					     struct wlan_roam_stop_config *req);
	QDF_STATUS (*send_roam_update_config)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_roam_update_config *req);
	QDF_STATUS (*send_roam_abort)(struct wlan_objmgr_vdev *vdev,
				      uint8_t vdev_id);
	QDF_STATUS (*send_roam_per_config)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_per_roam_config_req *req);
	QDF_STATUS (*send_roam_triggers)(struct wlan_objmgr_vdev *vdev,
					 struct wlan_roam_triggers *req);
	QDF_STATUS (*send_roam_disable_config)(struct wlan_objmgr_vdev *vdev,
				struct roam_disable_cfg *req);
#ifdef FEATURE_CM_ENABLE
	QDF_STATUS (*send_roam_invoke_cmd)(struct wlan_objmgr_vdev *vdev,
					   struct roam_invoke_req *req);
	QDF_STATUS (*send_roam_sync_complete_cmd)(struct wlan_objmgr_vdev *vdev);
#endif
};

/**
 * wlan_cm_roam_rx_ops  - structure of tx function pointers for
 * roaming related commands
 * @roam_sync_event_rx: RX ops function pointer for roam sync event
 */
struct wlan_cm_roam_rx_ops {
	QDF_STATUS (*roam_sync_event_rx)(struct wlan_objmgr_vdev *vdev);
};

/**
 * enum roam_scan_freq_scheme - Scan mode for triggering roam
 * ROAM_SCAN_FREQ_SCHEME_NO_SCAN: Indicates the fw to not scan.
 * ROAM_SCAN_FREQ_SCHEME_PARTIAL_SCAN: Indicates the firmware to
 * trigger partial frequency scans.
 * ROAM_SCAN_FREQ_SCHEME_FULL_SCAN: Indicates the firmware to
 * trigger full frequency scans.
 */
enum roam_scan_freq_scheme {
	ROAM_SCAN_FREQ_SCHEME_NO_SCAN = 0,
	ROAM_SCAN_FREQ_SCHEME_PARTIAL_SCAN = 1,
	ROAM_SCAN_FREQ_SCHEME_FULL_SCAN = 2,
};

/**
 * struct wlan_cm_roam  - Connection manager roam configs, state and roam
 * data related structure
 * @pcl_vdev_cmd_active:  Flag to check if vdev level pcl command needs to be
 * sent or PDEV level PCL command needs to be sent
 * @control_param: vendor configured roam control param
 */
struct wlan_cm_roam {
	bool pcl_vdev_cmd_active;
	struct wlan_cm_roam_vendor_btm_params vendor_btm_param;
};

/**
 * struct cm_roam_values_copy  - Structure for values copy buffer
 * @uint_value: Unsigned integer value to be copied
 * @int_value: Integer value
 * @bool_value: boolean value
 * @chan_info: chan info
 */
struct cm_roam_values_copy {
	uint32_t uint_value;
	int32_t int_value;
	bool bool_value;
	struct rso_chan_info chan_info;
};

#ifdef FEATURE_LFR_SUBNET_DETECTION
/* bit-4 and bit-5 indicate the subnet status */
#define CM_GET_SUBNET_STATUS(roam_reason) (((roam_reason) & 0x30) >> 4)
#else
#define CM_GET_SUBNET_STATUS(roam_reason) (0)
#endif

/* This should not be greater than MAX_NUMBER_OF_CONC_CONNECTIONS */
#define MAX_VDEV_SUPPORTED 4

/**
 * struct cm_ho_fail_ind - ho fail indication to CM
 * @vdev_id: vdev id
 * @psoc: psoc object
 * @bssid: bssid addr
 */
struct cm_ho_fail_ind {
	uint8_t vdev_id;
	struct wlan_objmgr_psoc *psoc;
	struct qdf_mac_addr bssid;
};

/**
 * struct policy_mgr_vdev_mac_map - vdev id-mac id map
 * @vdev_id: VDEV id
 * @mac_id: MAC id
 */
struct policy_mgr_vdev_mac_map {
	uint32_t vdev_id;
	uint32_t mac_id;
};

/**
 * struct cm_hw_mode_trans_ind - HW mode transition indication
 * @old_hw_mode_index: Index of old HW mode
 * @new_hw_mode_index: Index of new HW mode
 * @num_vdev_mac_entries: Number of vdev-mac id entries
 * @vdev_mac_map: vdev id-mac id map
 */
struct cm_hw_mode_trans_ind {
	uint32_t old_hw_mode_index;
	uint32_t new_hw_mode_index;
	uint32_t num_vdev_mac_entries;
	struct policy_mgr_vdev_mac_map vdev_mac_map[MAX_VDEV_SUPPORTED];
};

struct roam_offload_synch_ind {
	uint16_t beaconProbeRespOffset;
	uint16_t beaconProbeRespLength;
	uint16_t reassocRespOffset;
	uint16_t reassocRespLength;
	uint16_t reassoc_req_offset;
	uint16_t reassoc_req_length;
	uint8_t isBeacon;
	uint8_t roamed_vdev_id;
	struct qdf_mac_addr bssid;
	struct qdf_mac_addr self_mac;
	int8_t txMgmtPower;
	uint32_t auth_status;
	uint8_t rssi;
	uint8_t roam_reason;
	uint32_t chan_freq;
	uint8_t kck[MAX_KCK_LEN];
	uint8_t kck_len;
	uint32_t kek_len;
	uint8_t kek[MAX_KEK_LENGTH];
	uint32_t   pmk_len;
	uint8_t    pmk[MAX_PMK_LEN];
	uint8_t    pmkid[PMKID_LEN];
	bool update_erp_next_seq_num;
	uint16_t next_erp_seq_num;
	uint8_t replay_ctr[REPLAY_CTR_LEN];
	void *add_bss_params;
	enum phy_ch_width chan_width;
	uint32_t max_rate_flags;
	uint32_t ric_data_len;
#ifdef FEATURE_WLAN_ESE
	uint32_t tspec_len;
#endif
	uint8_t *ric_tspec_data;
	uint16_t aid;
	struct cm_hw_mode_trans_ind hw_mode_trans_ind;
	uint8_t nss;
	struct qdf_mac_addr dst_mac;
	struct qdf_mac_addr src_mac;
	uint16_t hlp_data_len;
	uint8_t hlp_data[FILS_MAX_HLP_DATA_LEN];
	bool is_ft_im_roam;
	enum wlan_phymode phy_mode; /*phy mode sent by fw */
};
#endif
