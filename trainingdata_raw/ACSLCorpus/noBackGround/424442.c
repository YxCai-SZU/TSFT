#include <stdbool.h>
#include <stdint.h>

/*@
  requires ((x) <= 0xFFFFFFFFU / 0xFFFFFFFFU &&
      (y) <= 0xFFFFFFFFU / 0xFFFFFFFFU);
  ensures \result == ((unsigned long long)x * y <= 0xFFFFFFFFU);
  assigns \nothing;
*/
bool check_nonlinear_arith(uint32_t x, uint32_t y) {
    //@ assert ((x) <= 0xFFFFFFFFU / 0xFFFFFFFFU &&       (y) <= 0xFFFFFFFFU / 0xFFFFFFFFU);
    //@ assert (unsigned long long)x * y <= 0xFFFFFFFFU;
    return (unsigned long long)x * y <= 0xFFFFFFFFU;
}
