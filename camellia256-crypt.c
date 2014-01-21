/* camellia256-crypt.c
 *
 * Crypt function for the camellia block cipher.
 */

/* nettle, low-level cryptographics library
 *
 * Copyright (C) 2010, 2013 Niels Möller
 *  
 * The nettle library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 * 
 * The nettle library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with the nettle library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02111-1301, USA.
 */

#if HAVE_CONFIG_H
# include "config.h"
#endif

#include <assert.h>

#include "camellia-internal.h"

/* The main point on this function is to help the assembler
   implementations of _nettle_camellia_crypt to get the table pointer.
   For PIC code, the details can be complex and system dependent. */
void
camellia256_crypt(const struct camellia256_ctx *ctx,
		  size_t length, uint8_t *dst,
		  const uint8_t *src)
{
  assert(!(length % CAMELLIA_BLOCK_SIZE) );
  _camellia_crypt(_CAMELLIA256_NKEYS, ctx->keys,
		  &_camellia_table,
		  length, dst, src);
}
