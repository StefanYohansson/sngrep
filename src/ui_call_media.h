/**************************************************************************
 **
 ** sngrep - SIP Messages flow viewer
 **
 ** Copyright (C) 2013-2015 Ivan Alonso (Kaian)
 ** Copyright (C) 2013-2015 Irontec SL. All rights reserved.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program. If not, see <http://www.gnu.org/licenses/>.
 **
 ****************************************************************************/
/**
 * @file ui_call_media.h
 * @author Ivan Alonso [aka Kaian] <kaian@irontec.com>
 *
 * @brief Functions to manage Call SDP medias
 *
 * This file contains the functions and structures to manage call medias defined
 * in SIP sdp content.
 *
 */
#ifndef __UI_CALL_MEDIA_H
#define __UI_CALL_MEDIA_H

#include "config.h"
#include "ui_manager.h"
#include "group.h"

//! Sorter declaration of struct call_media_info
typedef struct call_media_info call_media_info_t;

/**
 * @brief Call flow Extended status information
 *
 * This data stores the actual status of the panel. It's stored in the
 * PANEL user pointer.
 */
struct call_media_info {
    sip_call_group_t *group;
};

/**
 * @brief Create Call Flow extended panel
 *
 * This function will allocate the ncurses pointer and draw the static
 * stuff of the screen (which usually won't be redrawn)
 * It will also create an information structure of the panel status and
 * store it in the panel's userpointer
 *
 * @return the allocated ncurses panel
 */
PANEL *
call_media_create();

/**
 * @brief Destroy panel
 *
 * This function will hide the panel and free all allocated memory.
 *
 * @return panel Ncurses panel pointer
 */
void
call_media_destroy(PANEL *panel);

/**
 * @brief Draw the Call media panel
 *
 * This function will drawn the panel into the screen based on its stored
 * status
 *
 * @param panel Ncurses panel pointer
 * @return 0 if the panel has been drawn, -1 otherwise
 */
int
call_media_draw(PANEL *panel);

/**
 * @brief Handle Call media key strokes
 *
 * This function will manage the custom keybindings of the panel. If this
 * function returns -1, the ui manager will check if the pressed key
 * is one of the common ones (like toggle colors and so).
 *
 * @param panel Ncurses panel pointer
 * @param key Pressed keycode
 * @return 0 if the function can handle the key, key otherwise
 */
int
call_media_handle_key(PANEL *panel, int key);

/**
 * @brief Request the panel to show its help
 *
 * This function will request to panel to show its help (if any) by
 * invoking its help function.
 *
 * @param panel Ncurses panel pointer
 * @return 0 if the screen has help, -1 otherwise
 */
int
call_media_help(PANEL *panel);

/**
 * @brief Set the group call of the panel
 *
 * This function will access the panel information and will set the
 * group call pointer to the processed calls.
 *
 * @param group Call group pointer to be set in the internal info struct
 */
int
call_media_set_group(sip_call_group_t *group);

#endif /* __UI_CALL_MEDIA_H */
