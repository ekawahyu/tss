/*
 * tss.c
 *
 * Created on: Jan 1, 2017
 *     Author: Ekawahyu Susilo
 *
 * Copyright (c) 2017, Chongqing Aisenke Electronic Technology Co., Ltd.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of the copyright holder.
 *
 */
 
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

int main(void) {

    struct timeval now;
    struct tm *tmp;
    char timestr[20], buffer[256], ch;
    int rc;

    while(fgets(buffer, 255, stdin)) {

        rc = gettimeofday(&now, 0);

        if (rc != 0) {
            perror("gettimeofday");
            return 1;
        }

        tmp = localtime(&now.tv_sec);

        if (tmp == 0) {
            perror("localtime");
            return 1;
        }

        rc = strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", tmp);
        if (rc == 0) {
            fprintf(stderr, "strftime call failed.\n");
            return 1;
        }

        printf("[%s.%06ld] ", timestr, now.tv_usec);

        fputs(buffer, stdout);
    }

    return 0;
}
