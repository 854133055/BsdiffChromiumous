/* Copyright 2015 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef _BSDIFF_BSDIFF_H_
#define _BSDIFF_BSDIFF_H_

#ifdef __cplusplus
extern "C" {
#endif

int bsdiff(const char* old_filename, const char* new_filename,
           const char* patch_filename);

#ifdef __cplusplus
}
#endif

#endif  /* _BSDIFF_BSDIFF_H_ */
