/**
 * @section License
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014-2018, Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This file is part of the Simba project.
 */

#ifndef __LOG_MOCK_H__
#define __LOG_MOCK_H__

#include "simba.h"

int mock_write_log_module_init(int res);

int mock_write_log_object_init(const char *name_p,
                               char mask,
                               int res);

int mock_write_log_object_set_log_mask(char mask,
                                       int res);

int mock_write_log_object_get_log_mask(char res);

int mock_write_log_object_is_enabled_for(int level,
                                         int res);

int mock_write_log_object_print(int level,
                                const char *fmt_p,
                                int res);

int mock_write_log_handler_init(void *chout_p,
                                int res);

int mock_write_log_add_handler(struct log_handler_t *handler_p,
                               int res);

int mock_write_log_remove_handler(struct log_handler_t *handler_p,
                                  int res);

int mock_write_log_add_object(struct log_object_t *object_p,
                              int res);

int mock_write_log_remove_object(struct log_object_t *object_p,
                                 int res);

int mock_write_log_set_default_handler_output_channel(void *chout_p,
                                                      int res);

#endif
