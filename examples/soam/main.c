/**
 * @section License
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014-2016, Erik Moqvist
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

#include "simba.h"

static struct slip_t slip;
static uint8_t slip_buf[128];

static struct soam_t soam;
static uint8_t soam_buf[128];

static THRD_STACK(input_stack, 2048);

/**
 * This thread executes file system commands.
 */
static void *input_main(void *arg_p)
{
    uint8_t byte;
    ssize_t size;

    while (1) {
        chan_read(sys_get_stdin(), &byte, sizeof(byte));

        size = slip_input(&slip, byte);

        if (size > 0) {
            soam_input(&soam, &slip_buf[0], size);
        }
    }

    return (NULL);
}

int main()
{
    int i;

    sys_start();

    if (slip_init(&slip,
                  &slip_buf[0],
                  sizeof(slip_buf),
                  sys_get_stdout()) != 0) {
        return (-1);
    }

    if (soam_init(&soam,
                  &soam_buf[0],
                  sizeof(soam_buf),
                  slip_get_output_channel(&slip)) != 0) {
        return (-1);
    }

    log_set_default_handler_output_channel(soam_get_log_input_channel(&soam));

    thrd_spawn(input_main,
               NULL,
               0,
               input_stack,
               sizeof(input_stack));

    i = 0;

    while (1) {
        log_object_print(NULL,
                         LOG_INFO,
                         FSTR("i: %d\r\n"),
                         i);

        i++;
        thrd_sleep(3);
    }

    return (0);
}
