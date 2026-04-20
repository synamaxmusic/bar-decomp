// SPDX-License-Identifier: AGPL-3.0-or-later
#ifndef BAR_MODULE_H
#define BAR_MODULE_H
/* Module exports */
#include "uvstring_rom.h"
#include "uvsort_rom.h"
#include "uvufileld_rom.h"
#include "uvtseqld_rom.h"
#include "uvvolumeld_rom.h"
#include "uvmath_rom.h"
#include "uvfvec_rom.h"
#include "uvimtx_rom.h"
#include "uvfmtx_rom.h"
#include "uvgfxmgr_rom.h"
#include "uvdbg_rom.h"
#include "uvsprt_rom.h"
#include "uvtexture_rom.h"
#include "uvdgeom_rom.h"
#include "uvcback_rom.h"
#include "ripple.h"
#include "intro.h"
#include "track7.h"
#define MODULE_ENTRY_POINT(func) __entrypoint_##func
#include "global_exports.h"

#endif /* BAR_MODULE_H */
