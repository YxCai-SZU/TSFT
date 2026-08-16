#include <stdint.h>

/*@
  requires (1 <= (a) <= 10) && (1 <= (b) <= 10);
  ensures \result == ((a) * (b));
*/
uint32_t func(uint32_t a, uint32_t b)
{
  // Variable declarations at top of scope
  uint32_t ans;

  // Precondition assertions
  //@ assert a >= 1;
  //@ assert b >= 1;
  //@ assert a <= 10;
  //@ assert b <= 10;
  //@ assert a * b <= 100;

  ans = a * b;
  
  // Postcondition verification
  //@ assert ans >= 1;
  //@ assert ans == a * b;
  
  return ans;
}
