/**********************************************************************
  Copyright(c) 2011-2014 Intel Corporation All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions 
  are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of Intel Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********************************************************************/
#include <limits.h>
#include <stdio.h>
#include "erasure_code.h"
#include "types.h"

void ec_init_tables(int k, int rows, unsigned char *a, unsigned char *g_tbls)
{
  printf("k %d rows %d\n", k, rows);
  printf("A: ");
  for(int i = 0; i < k * rows; i++) {
    printf("%x", a[i]);
  }
  printf("\n");
	int i, j;
  unsigned char *b;
  b = g_tbls;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < k; j++) {
			gf_vect_mul_init(*a++, g_tbls);
			g_tbls += 32;
		}
	}
  
  printf("G Tables: ");
  for(int i = 0; i < k * rows * 32; i++) {
    printf("%x", b[i]);
  }
  printf("\n");
}

struct slver {
	UINT16 snum;
	UINT8 ver;
	UINT8 core;
};

// Version info
struct slver ec_init_tables_slver_00010068;
struct slver ec_init_tables_slver = { 0x0068, 0x01, 0x00 };

struct slver ec_encode_data_sse_slver_00020069;
struct slver ec_encode_data_sse_slver = { 0x0069, 0x02, 0x00 };
