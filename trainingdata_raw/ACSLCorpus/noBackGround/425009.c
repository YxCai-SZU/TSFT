#include <stdint.h>

/*@ requires (2 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1)); */
int32_t func(int32_t a, int32_t b)
{
  int32_t a_local;
  int32_t b_local;
  int32_t result;

  a_local = a - 1;
  b_local = b - 1;

  //@ assert 1 <= a_local && a_local <= 99;
  //@ assert 1 <= b_local && b_local <= 99;
  //@ assert 1 <= a_local * b_local && a_local * b_local <= 99 * 99;

  result = a_local * b_local;
  return result;
}
