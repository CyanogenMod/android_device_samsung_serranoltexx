/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "I257M")) {
        /* serranoltebmc */
        property_set("ro.build.fingerprint", "samsung/serranoltebmc/serranoltebmc:4.4.2/KOT49H/I257MVLUBNE6:user/release-keys");
        property_set("ro.build.description", "serranoltebmc-user 4.4.2 KOT49H I257MVLUBNE6 release-keys");
        property_set("ro.product.model", "SGH-I257M");
        property_set("ro.product.device", "serranoltebmc");
    } else if (strstr(bootloader, "I9195")) {
        /* serranoltexx */
        property_set("ro.build.fingerprint", "samsung/serranoltexx/serranolte:4.4.2/KOT49H/I9195XXUCNE6:user/release-keys");
        property_set("ro.build.description", "serranoltexx-user 4.4.2 KOT49H I9195XXUCNE6 release-keys");
        property_set("ro.product.model", "GT-I9195");
        property_set("ro.product.device", "serranoltexx");
    } else if (strstr(bootloader, "E370K")) {
        /* serranoltektt */
        property_set("ro.build.fingerprint", "samsung/serranoltektt/serranoltektt:4.4.4/KTU84P/E370KKTU2BNK5:user/release-keys");
        property_set("ro.build.description", "serranoltektt-user 4.4.4 KTU84P E370KKTU2BNK5 release-keys");
        property_set("ro.product.model", "SHV-E370K");
        property_set("ro.product.device", "serranoltektt");
    }

    property_get("ro.product.device", device);
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, device);
}
