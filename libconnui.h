/**
  @file libconnui.h

  Copyright (C) 2011 Jonathan Wilson

  @author Jonathan wilson <jfwfreo@tpgi.com.au>

  This library is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License version 2.1 as
  published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include <glib.h>
#include <dbus/dbus.h>
#include <gtk/gtk.h>
#include <libosso.h>

//libconnui
struct pixbuf_cache
{
	GHashTable *table1;
	GHashTable *table2;
	GtkIconTheme *icon_theme;
};
typedef void (*cellular_data_suspended_cb) (gboolean suspended,guint32 suspendcode,gpointer user_data);
typedef void (*devlock_cb) (gboolean locked, gpointer user_data);
typedef void (*display_event_cb) (gchar *state, gpointer user_data);
typedef void (*flightmode_cb) (gboolean offline, gpointer user_data);

//connui_box_view_get_model
GType connui_box_view_get_type();
//connui_box_view_new_with_model
GType connui_cell_renderer_operator_get_type();
//connui_cell_renderer_operator_new
void connui_cellular_data_suspended_close(cellular_data_suspended_cb callback);
gboolean connui_cellular_data_suspended_status(cellular_data_suspended_cb callback,gpointer user_data);
osso_return_t connui_dbus_activate_app(osso_context_t *osso, const gchar *application);
dbus_bool_t connui_dbus_application_activation(const char *path,const char *name,DBusObjectPathMessageFunction function,void *user_data);
void connui_dbus_close();
dbus_bool_t connui_dbus_connect_session_bcast_signal(const char *interface, DBusHandleMessageFunction function, void *user_data, const char *signal);
dbus_bool_t connui_dbus_connect_session_path(const char *path, DBusObjectPathMessageFunction function, void *user_data);
dbus_bool_t connui_dbus_connect_system_bcast_signal(const char *interface, DBusHandleMessageFunction function, void *user_data, const char *signal);
dbus_bool_t connui_dbus_connect_system_path(const char *path, DBusObjectPathMessageFunction function, void *user_data);
DBusMessage *connui_dbus_create_method_call(const char *bus_name, const char *path, const char *interface, const char *method, int first_arg_type, ...);
dbus_bool_t connui_dbus_disconnect_session_bcast_signal(const char *interface, DBusHandleMessageFunction function, void *user_data, const char *signal);
dbus_bool_t connui_dbus_disconnect_session_path(DBusConnection *connection);
dbus_bool_t connui_dbus_disconnect_system_bcast_signal(const char *interface, DBusHandleMessageFunction function, void *user_data, const char *signal);
dbus_bool_t connui_dbus_disconnect_system_path(DBusConnection *connection);
dbus_bool_t connui_dbus_get_value_and_iterate(DBusMessageIter *iter, int type,void *value);
dbus_bool_t connui_dbus_libosso_application_activation(const char *path, const char *name, DBusObjectPathMessageFunction function, void *user_data);
DBusMessage *connui_dbus_recv_reply_session_mcall(DBusMessage *message);
DBusMessage *connui_dbus_recv_reply_system_mcall(DBusMessage *message);
dbus_bool_t connui_dbus_register_session_service(const char *path, const char *name, unsigned int flags, DBusObjectPathMessageFunction function, void *user_data);
dbus_bool_t connui_dbus_register_system_service(const char *path, const char *name, unsigned int flags, DBusObjectPathMessageFunction function, void *user_data);
//connui_dbus_register_watcher
dbus_bool_t connui_dbus_send_session_mcall(DBusMessage *mcall, int timeout_milliseconds, DBusPendingCallNotifyFunction notify, void *user_data, DBusPendingCall **call);
dbus_bool_t connui_dbus_send_session_msg(DBusMessage *message);
dbus_bool_t connui_dbus_send_system_mcall(DBusMessage *mcall, int timeout_milliseconds, DBusPendingCallNotifyFunction notify, void *user_data, DBusPendingCall **call);
dbus_bool_t connui_dbus_send_system_msg(DBusMessage *message);
//connui_dbus_unregister_watcher
void connui_devicelock_close(devlock_cb callback);
gboolean connui_devicelock_status(devlock_cb callback,gpointer user_data);
void connui_display_event_close(display_event_cb callback);
gboolean connui_display_event_status(display_event_cb callback,gpointer user_data);
void connui_flightmode_close(flightmode_cb callback);
void connui_flightmode_off();
void connui_flightmode_off_confirm();
void connui_flightmode_on();
gboolean connui_flightmode_status(flightmode_cb callback,gpointer user_data);
//connui_inetstate_close
//connui_inetstate_statistics_start
//connui_inetstate_statistics_stop
//connui_inetstate_status
//connui_pixbuf_anim_destroy
//connui_pixbuf_anim_new
//connui_pixbuf_anim_new_from_icons
//connui_pixbuf_anim_start
//connui_pixbuf_anim_stop
void connui_pixbuf_cache_destroy(struct pixbuf_cache *cache);
GdkPixbuf *connui_pixbuf_cache_get(struct pixbuf_cache *cache,guchar *icon,gint size);
GdkPixbuf *connui_pixbuf_cache_get_with_flags(struct pixbuf_cache *cache,guchar *icon,gint size,guint flags);
struct pixbuf_cache *connui_pixbuf_cache_new();
GdkPixbuf *connui_pixbuf_load(gchar *name,gint size);
void connui_pixbuf_unref(GdkPixbuf *);
GType connui_scan_box_view_get_type();
GtkWidget *connui_scan_box_view_new_with_model(GtkTreeModel *model);
//connui_utils_callback_compare
//connui_utils_find_callback
osso_context_t *connui_utils_inherit_osso_context(osso_context_t *context, gchar *name, gchar *version);
//connui_utils_notify_add
//connui_utils_notify_notify
//connui_utils_notify_remove
void connui_utils_reload_theme();
void connui_utils_unblank_display();
//iap_common_activate_iap
//iap_common_get_last_used_network
//iap_common_get_preferred_service
//iap_common_get_service_gconf_path
//iap_common_get_service_properties
//iap_common_get_signal_by_nw_level
//iap_common_make_connection_entry
//iap_common_make_connection_entry_for_network
//iap_common_make_connection_entry_with_type
//iap_common_make_connection_entry_with_type_for_network
//iap_common_pack_to_hildon_button
//iap_common_set_close_response
//iap_common_set_last_used_network
//iap_common_set_service_properties
//iap_common_set_service_properties_for_iap
//iap_common_set_service_properties_for_network
//iap_common_show_saved_not_found_banner
//iap_network_entry_clear
//iap_network_entry_compare
//iap_network_entry_connect
//iap_network_entry_disconnect
//iap_network_entry_dup
//iap_network_entry_equal
//iap_network_entry_from_dbus_iter
//iap_network_entry_hash
//iap_network_entry_is_saved
//iap_network_entry_network_compare
//iap_network_entry_service_compare
//iap_network_entry_to_dbus_iter
//iap_scan_add_scan_entry
//iap_scan_close
//iap_scan_default_sort_func
//iap_scan_free_scan_entry
//iap_scan_start
//iap_scan_start_for_network_types
//iap_scan_stop
//iap_scan_store_create
//iap_scan_tree_create
//iap_scan_view_create
//iap_settings_create_iap_id
//iap_settings_enum_to_gconf_type
//iap_settings_gconf_type_to_enum
//iap_settings_get_auto_connect
//iap_settings_get_gconf_value
//iap_settings_get_iap_icon_name_by_id
//iap_settings_get_iap_icon_name_by_network
//iap_settings_get_iap_icon_name_by_network_and_signal
//iap_settings_get_iap_list
//iap_settings_get_name
//iap_settings_get_name_by_network
//iap_settings_get_search_interval
//iap_settings_get_wlan_ssid
//iap_settings_iap_exists
//iap_settings_iap_is_easywlan
//iap_settings_is_empty
//iap_settings_is_iap_visible
//iap_settings_is_iaptype_supported
//iap_settings_remove_iap
//iap_settings_set_gconf_value
//iap_settings_wlan_txpower_get
//wlan_common_gconf_wlan_security_to_capability
//wlan_common_get_iaptype_icon_name_by_capability
//wlan_common_get_icon_name_by_saved
//wlan_common_get_icon_name_by_strength
//wlan_common_get_saved_icon_name_by_network
//wlan_common_get_security_icon_name_by_network_attrs
//wlan_common_get_signal_by_rssi
//wlan_common_mangle_ssid


//libconnui_cell
struct network_info
{
	char network_service_status;
	gchar *country_code;
	gchar *operator_code;
	gchar *operator_name;
	char umts_avail;
	char network_type;
};
struct network_state
{
	int network_reg_status;
	unsigned int lac;
	unsigned int cell_id;
	struct network_info *network;
	char supported_services;
	char network_signals_bar;
	char rat_name;
	char network_radio_state;
	int operator_name_type;
	gchar *operator_name;
	gchar *alternative_operator_name;
};
typedef void (*call_status_cb) (gboolean calls, gpointer user_data);
typedef void (*cs_status_cb) (gchar state, gpointer user_data);
typedef void (*net_status_cb) (struct network_state *state, gpointer user_data);
typedef void (*sim_status_cb) (guint status, gpointer user_data);
typedef void (*ssc_state_cb) (gchar *state, gpointer user_data);

void connui_cell_call_status_close(call_status_cb callback);
gboolean connui_cell_call_status_register(call_status_cb callback,gpointer user_data);
gboolean connui_cell_code_ui_cancel_dialog();
//connui_cell_code_ui_change_code
//connui_cell_code_ui_create_dialog
//connui_cell_code_ui_deactivate_simlock
//connui_cell_code_ui_destroy
//connui_cell_code_ui_error_note_type_to_text
//connui_cell_code_ui_init
//connui_cell_code_ui_is_sim_locked_with_error
//connui_cell_code_ui_set_current_code_active
//connui_cell_code_ui_update_sim_status
void connui_cell_cs_status_close(cs_status_cb callback);
gboolean connui_cell_cs_status_register(cs_status_cb callback,gpointer user_data);
//connui_cell_datacounter_close
//connui_cell_datacounter_register
//connui_cell_datacounter_reset
//connui_cell_datacounter_save
gboolean connui_cell_emergency_call();
GStrv connui_cell_emergency_get_numbers();
//connui_cell_net_cancel_list
//connui_cell_net_cancel_select
//connui_cell_net_cancel_service_call
//connui_cell_net_get_call_forwarding_enabled
//connui_cell_net_get_call_waiting_enabled
//connui_cell_net_get_caller_id_presentation
//connui_cell_net_get_current
guchar connui_cell_net_get_network_selection_mode(gint32 *error);
gchar *connui_cell_net_get_operator_name(struct network_info *network,gboolean longname,gint32 *error);
guchar connui_cell_net_get_radio_access_mode(gint32 *error);
gboolean connui_cell_net_is_activated(gint32 *error);
//connui_cell_net_list
//connui_cell_net_select
//connui_cell_net_set_call_forwarding_enabled
//connui_cell_net_set_call_waiting_enabled
//connui_cell_net_set_caller_id_presentation
//connui_cell_net_set_caller_id_presentation_bluez
gboolean connui_cell_net_set_radio_access_mode(guchar mode,gint32 *error);
void connui_cell_net_status_close(net_status_cb callback);
gboolean connui_cell_net_status_register(net_status_cb callback,gpointer user_data);
struct network_info *connui_cell_network_dup(struct network_info *info);
void connui_cell_network_free(struct network_info *info);
GType connui_cell_note_get_type();
//connui_cell_note_new_information
void connui_cell_reset_network();
//connui_cell_security_code_change
//connui_cell_security_code_close
//connui_cell_security_code_get_active
//connui_cell_security_code_get_enabled
//connui_cell_security_code_register
//connui_cell_security_code_set_active
//connui_cell_security_code_set_enabled
//connui_cell_security_code_set_enabled_internal
gboolean connui_cell_sim_deactivate_lock(gchar *code,gint32 *error);
gchar *connui_cell_sim_get_service_provider(guint32 *unknown,gint32 *error);
gboolean connui_cell_sim_is_locked(gint32 *error);
gboolean connui_cell_sim_is_network_in_service_provider_info(gint32 *error,guchar *provider);
void connui_cell_sim_status_close(sim_status_cb callback);
gboolean connui_cell_sim_status_register(sim_status_cb callback,gpointer user_data);
guint32 connui_cell_sim_verify_attempts_left(guint32 level,gint32 *error);
void connui_cell_ssc_state_close(ssc_state_cb callback);
gboolean connui_cell_ssc_state_register(ssc_state_cb callback,gpointer user_data);
