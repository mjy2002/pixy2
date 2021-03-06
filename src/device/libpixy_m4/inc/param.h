//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//

#ifndef _PARAM_H
#define _PARAM_H

#include <stdarg.h>
#include "chirp.hpp"

#define PROG_MASK                         0xfe000000
#define PROG_BIT(prog)                    (1<<(prog + 25))
#define PROG_FLAGS(prog)                  (PROG_MASK & ~PROG_BIT(prog))
#define PROG_FLAGS_TEST(prog, flags)      (~flags & PROG_BIT(prog))
#define PROG_FLAGS_EQUAL(flags0, flags1)  ((flags0&PROG_MASK)==(flags1&PROG_MASK))

#define PRM_PRIORITY_DEFAULT              0
#define PRM_PRIORITY_5                    5000
#define PRM_PRIORITY_4                    4000
#define PRM_PRIORITY_3                    3000
#define PRM_PRIORITY_2                    2000
#define PRM_PRIORITY_1                    1000

typedef void (*ShadowCallback)(const char *id, const void *arg0);

int prm_init(Chirp *chirp);

int32_t prm_set(const char *id, ...);
int32_t prm_setDirty();
int32_t prm_setChirp(const char *id, const uint32_t &valLen, const uint8_t *val);
int32_t prm_setShadowChirp(const char *id, const uint32_t &valLen, const uint8_t *val);
int32_t prm_eraseShadows();
int32_t prm_get(const char *id, ...);
int32_t prm_getChirp(const char *id, Chirp *chirp);
int32_t prm_getInfo(const char *id, Chirp *chirp);
int32_t prm_getAll(const uint8_t &contextual, const uint16_t &index, Chirp *chirp);

int prm_setShadowCallback(const char *id, ShadowCallback callback);
int32_t prm_resetShadows();

int prm_add(const char *id, uint32_t flags, uint32_t priority, const char *desc, ...);
bool prm_verifyAll();
int prm_format();
bool prm_dirty();


#endif
