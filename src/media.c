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
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **
 ****************************************************************************/
/**
 * @file media.c
 * @author Ivan Alonso [aka Kaian] <kaian@irontec.com>
 *
 * @brief Source of functions defined in media.h
 */

#include "config.h"
#include <string.h>
#include <stdlib.h>
#include "media.h"

void
media_init()
{

}

sdp_media_t *
media_create(const char *addr, int port)
{
    sdp_media_t *media = malloc(sizeof(sdp_media_t));

    if (!media)
        return 0;

    memset(media, 0, sizeof(sdp_media_t));

    media->address = strdup(addr);
    media->port = port;
    return media;

}

sdp_media_t *
media_find(sdp_media_t *media, const char *address, int port)
{
    sdp_media_t *m;

    if (!media)
        return 0;

    for (m = media; m; m = m->next)
        if (!strcmp(m->address, address) && m->port == port)
            return m;

    return 0;
}




