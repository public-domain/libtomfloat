/* LibTomFloat, multiple-precision floating-point library
 *
 * LibTomFloat is a library that provides multiple-precision
 * floating-point artihmetic as well as trigonometric functionality.
 *
 * This library requires the public domain LibTomMath to be installed.
 * 
 * This library is free for all purposes without any express
 * gurantee it works
 *
 * Tom St Denis, tomstdenis@iahu.ca, http://float.libtomcrypt.org
 */
#include <tomfloat.h>

int  mpf_cmp_d(mp_float *a, long b, int *res)
{
   int      err;
   mp_float tmp;

   if ((err = mpf_init(&tmp, a->radix)) != MP_OKAY) {
      return err;
   }

   if ((err = mpf_const_d(&tmp, b)) != MP_OKAY)              { goto __ERR; }
   *res = mpf_cmp(a, &tmp);

__ERR:
   mpf_clear(&tmp);
   return err;
}
