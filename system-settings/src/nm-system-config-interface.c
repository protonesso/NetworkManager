/* -*- Mode: C; tab-width: 5; indent-tabs-mode: t; c-basic-offset: 5 -*- */
/* NetworkManager -- Network link manager
 *
 * Dan Williams <dcbw@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * (C) Copyright 2007 Red Hat, Inc.
 */

#include "nm-system-config-interface.h"

static void
nm_system_config_interface_init (gpointer g_iface)
{
	GType iface_type = G_TYPE_FROM_INTERFACE (g_iface);
	static gboolean initialized = FALSE;

	if (initialized)
		return;

	/* Properties */
	g_object_interface_install_property
		(g_iface,
		 g_param_spec_string (NM_SYSTEM_CONFIG_INTERFACE_NAME,
							  "Name",
							  "Plugin name",
							  NULL,
							  G_PARAM_READABLE));

	g_object_interface_install_property
		(g_iface,
		 g_param_spec_string (NM_SYSTEM_CONFIG_INTERFACE_INFO,
							  "Info",
							  "Plugin information",
							  NULL,
							  G_PARAM_READABLE));

	/* Signals */
	g_signal_new ("connection-added",
				  iface_type,
				  G_SIGNAL_RUN_FIRST,
				  G_STRUCT_OFFSET (NMSystemConfigInterface, connection_added),
				  NULL, NULL,
				  g_cclosure_marshal_VOID__OBJECT,
				  G_TYPE_NONE, 1,
				  G_TYPE_OBJECT);

	g_signal_new ("connection-removed",
				  iface_type,
				  G_SIGNAL_RUN_FIRST,
				  G_STRUCT_OFFSET (NMSystemConfigInterface, connection_removed),
				  NULL, NULL,
				  g_cclosure_marshal_VOID__OBJECT,
				  G_TYPE_NONE, 1,
				  G_TYPE_OBJECT);

	g_signal_new ("connection-updated",
				  iface_type,
				  G_SIGNAL_RUN_FIRST,
				  G_STRUCT_OFFSET (NMSystemConfigInterface, connection_updated),
				  NULL, NULL,
				  g_cclosure_marshal_VOID__OBJECT,
				  G_TYPE_NONE, 1,
				  G_TYPE_OBJECT);

	initialized = TRUE;
}


GType
nm_system_config_interface_get_type (void)
{
	static GType system_config_interface_type = 0;

	if (!system_config_interface_type) {
		const GTypeInfo system_config_interface_info = {
			sizeof (NMSystemConfigInterface), /* class_size */
			nm_system_config_interface_init,   /* base_init */
			NULL,		/* base_finalize */
			NULL,
			NULL,		/* class_finalize */
			NULL,		/* class_data */
			0,
			0,              /* n_preallocs */
			NULL
		};

		system_config_interface_type = g_type_register_static (G_TYPE_INTERFACE,
														       "NMSystemConfigInterface",
														       &system_config_interface_info,
														       0);

		g_type_interface_add_prerequisite (system_config_interface_type, G_TYPE_OBJECT);
	}

	return system_config_interface_type;
}

