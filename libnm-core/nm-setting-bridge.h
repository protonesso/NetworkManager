// SPDX-License-Identifier: LGPL-2.1+
/*
 * Copyright (C) 2011 - 2015 Red Hat, Inc.
 */

#ifndef __NM_SETTING_BRIDGE_H__
#define __NM_SETTING_BRIDGE_H__

#if !defined (__NETWORKMANAGER_H_INSIDE__) && !defined (NETWORKMANAGER_COMPILATION)
#error "Only <NetworkManager.h> can be included directly."
#endif

#include "nm-setting.h"

G_BEGIN_DECLS

#define NM_TYPE_SETTING_BRIDGE            (nm_setting_bridge_get_type ())
#define NM_SETTING_BRIDGE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), NM_TYPE_SETTING_BRIDGE, NMSettingBridge))
#define NM_SETTING_BRIDGE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), NM_TYPE_SETTING_BRIDGE, NMSettingBridgeClass))
#define NM_IS_SETTING_BRIDGE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NM_TYPE_SETTING_BRIDGE))
#define NM_IS_SETTING_BRIDGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NM_TYPE_SETTING_BRIDGE))
#define NM_SETTING_BRIDGE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), NM_TYPE_SETTING_BRIDGE, NMSettingBridgeClass))

#define NM_SETTING_BRIDGE_SETTING_NAME "bridge"

#define NM_SETTING_BRIDGE_MAC_ADDRESS                       "mac-address"
#define NM_SETTING_BRIDGE_STP                               "stp"
#define NM_SETTING_BRIDGE_PRIORITY                          "priority"
#define NM_SETTING_BRIDGE_FORWARD_DELAY                     "forward-delay"
#define NM_SETTING_BRIDGE_HELLO_TIME                        "hello-time"
#define NM_SETTING_BRIDGE_MAX_AGE                           "max-age"
#define NM_SETTING_BRIDGE_AGEING_TIME                       "ageing-time"
#define NM_SETTING_BRIDGE_GROUP_FORWARD_MASK                "group-forward-mask"
#define NM_SETTING_BRIDGE_MULTICAST_HASH_MAX                "multicast-hash-max"
#define NM_SETTING_BRIDGE_MULTICAST_LAST_MEMBER_COUNT       "multicast-last-member-count"
#define NM_SETTING_BRIDGE_MULTICAST_LAST_MEMBER_INTERVAL    "multicast-last-member-interval"
#define NM_SETTING_BRIDGE_MULTICAST_MEMBERSHIP_INTERVAL     "multicast-membership-interval"
#define NM_SETTING_BRIDGE_MULTICAST_SNOOPING                "multicast-snooping"
#define NM_SETTING_BRIDGE_MULTICAST_ROUTER                  "multicast-router"
#define NM_SETTING_BRIDGE_MULTICAST_QUERIER                 "multicast-querier"
#define NM_SETTING_BRIDGE_MULTICAST_QUERIER_INTERVAL        "multicast-querier-interval"
#define NM_SETTING_BRIDGE_MULTICAST_QUERY_INTERVAL          "multicast-query-interval"
#define NM_SETTING_BRIDGE_MULTICAST_QUERY_RESPONSE_INTERVAL "multicast-query-response-interval"
#define NM_SETTING_BRIDGE_MULTICAST_QUERY_USE_IFADDR        "multicast-query-use-ifaddr"
#define NM_SETTING_BRIDGE_MULTICAST_STARTUP_QUERY_COUNT     "multicast-startup-query-count"
#define NM_SETTING_BRIDGE_MULTICAST_STARTUP_QUERY_INTERVAL  "multicast-startup-query-interval"
#define NM_SETTING_BRIDGE_VLAN_FILTERING                    "vlan-filtering"
#define NM_SETTING_BRIDGE_VLAN_DEFAULT_PVID                 "vlan-default-pvid"
#define NM_SETTING_BRIDGE_VLANS                             "vlans"
#define NM_SETTING_BRIDGE_GROUP_ADDRESS                     "group-address"
#define NM_SETTING_BRIDGE_VLAN_PROTOCOL                     "vlan-protocol"
#define NM_SETTING_BRIDGE_VLAN_STATS_ENABLED                "vlan-stats-enabled"

#define NM_BRIDGE_VLAN_VID_MIN            1
#define NM_BRIDGE_VLAN_VID_MAX            4094

typedef struct _NMSettingBridgeClass NMSettingBridgeClass;

typedef struct _NMBridgeVlan NMBridgeVlan;

GType nm_setting_bridge_get_type (void);

NMSetting *  nm_setting_bridge_new                (void);

const char * nm_setting_bridge_get_mac_address    (NMSettingBridge *setting);

gboolean     nm_setting_bridge_get_stp            (NMSettingBridge *setting);

guint16      nm_setting_bridge_get_priority       (NMSettingBridge *setting);

guint16      nm_setting_bridge_get_forward_delay  (NMSettingBridge *setting);

guint16      nm_setting_bridge_get_hello_time     (NMSettingBridge *setting);

guint16      nm_setting_bridge_get_max_age        (NMSettingBridge *setting);

guint32      nm_setting_bridge_get_ageing_time    (NMSettingBridge *setting);
NM_AVAILABLE_IN_1_10
guint16      nm_setting_bridge_get_group_forward_mask (NMSettingBridge *setting);

gboolean     nm_setting_bridge_get_multicast_snooping (NMSettingBridge *setting);
NM_AVAILABLE_IN_1_18
gboolean     nm_setting_bridge_get_vlan_filtering (NMSettingBridge *setting);
NM_AVAILABLE_IN_1_18
guint16      nm_setting_bridge_get_vlan_default_pvid (NMSettingBridge *setting);
NM_AVAILABLE_IN_1_18
void          nm_setting_bridge_add_vlan (NMSettingBridge *setting,
                                          NMBridgeVlan *vlan);
NM_AVAILABLE_IN_1_18
guint         nm_setting_bridge_get_num_vlans (NMSettingBridge *setting);
NM_AVAILABLE_IN_1_18
NMBridgeVlan *nm_setting_bridge_get_vlan (NMSettingBridge *setting, guint idx);
NM_AVAILABLE_IN_1_18
void          nm_setting_bridge_remove_vlan (NMSettingBridge *setting, guint idx);
NM_AVAILABLE_IN_1_18
gboolean      nm_setting_bridge_remove_vlan_by_vid (NMSettingBridge *setting,
                                                    guint16 vid_start,
                                                    guint16 vid_end);
NM_AVAILABLE_IN_1_18
void          nm_setting_bridge_clear_vlans (NMSettingBridge *setting);

NM_AVAILABLE_IN_1_18
GType          nm_bridge_vlan_get_type (void);
NM_AVAILABLE_IN_1_18
NMBridgeVlan * nm_bridge_vlan_new (guint16 vid_start, guint16 vid_end);
NM_AVAILABLE_IN_1_18
NMBridgeVlan * nm_bridge_vlan_ref (NMBridgeVlan *vlan);
NM_AVAILABLE_IN_1_18
void           nm_bridge_vlan_unref (NMBridgeVlan *vlan);
NM_AVAILABLE_IN_1_18
NMBridgeVlan * nm_bridge_vlan_new_clone (const NMBridgeVlan *vlan);
NM_AVAILABLE_IN_1_18
int            nm_bridge_vlan_cmp (const NMBridgeVlan *a, const NMBridgeVlan *b);
NM_AVAILABLE_IN_1_18
void           nm_bridge_vlan_seal (NMBridgeVlan *vlan);
NM_AVAILABLE_IN_1_18
gboolean       nm_bridge_vlan_is_sealed (const NMBridgeVlan *vlan);
NM_AVAILABLE_IN_1_18
void           nm_bridge_vlan_set_untagged (NMBridgeVlan *vlan, gboolean value);
NM_AVAILABLE_IN_1_18
void           nm_bridge_vlan_set_pvid (NMBridgeVlan *vlan, gboolean value);
NM_AVAILABLE_IN_1_18
gboolean       nm_bridge_vlan_get_vid_range (const NMBridgeVlan *vlan, guint16 *vid_start, guint16 *vid_end);
NM_AVAILABLE_IN_1_18
gboolean       nm_bridge_vlan_is_untagged (const NMBridgeVlan *vlan);
NM_AVAILABLE_IN_1_18
gboolean       nm_bridge_vlan_is_pvid (const NMBridgeVlan *vlan);

NM_AVAILABLE_IN_1_18
char         * nm_bridge_vlan_to_str (const NMBridgeVlan *vlan, GError **error);
NM_AVAILABLE_IN_1_18
NMBridgeVlan * nm_bridge_vlan_from_str (const char *str, GError **error);

NM_AVAILABLE_IN_1_24
const char *   nm_setting_bridge_get_group_address (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_24
const char *   nm_setting_bridge_get_vlan_protocol (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_24
gboolean nm_setting_bridge_get_vlan_stats_enabled (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_24
const char *   nm_setting_bridge_get_multicast_router (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_24
gboolean nm_setting_bridge_get_multicast_query_use_ifaddr (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_24
gboolean nm_setting_bridge_get_multicast_querier (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_26
guint32 nm_setting_bridge_get_multicast_hash_max (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_26
guint32 nm_setting_bridge_get_multicast_last_member_count (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_26
guint64 nm_setting_bridge_get_multicast_last_member_interval (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_26
guint64 nm_setting_bridge_get_multicast_membership_interval (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_26
guint64 nm_setting_bridge_get_multicast_querier_interval (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_26
guint64 nm_setting_bridge_get_multicast_query_interval (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_26
guint64 nm_setting_bridge_get_multicast_query_response_interval (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_26
guint32 nm_setting_bridge_get_multicast_startup_query_count (const NMSettingBridge *setting);

NM_AVAILABLE_IN_1_26
guint64 nm_setting_bridge_get_multicast_startup_query_interval (const NMSettingBridge *setting);

G_END_DECLS

#endif /* __NM_SETTING_BRIDGE_H__ */
