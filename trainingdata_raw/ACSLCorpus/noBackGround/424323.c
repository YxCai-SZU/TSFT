#include <stdint.h>

/*@ requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * ((n) + 1) / 2); */
uint64_t func(uint64_t n)
{
  uint64_t ans = 0;
  uint64_t i = 1;
  
  /*@ loop invariant 1 <= i && i <= n+1;
      loop invariant ans == ((i-1) * ((i-1) + 1) / 2);
      loop invariant i <= 101;
      loop assigns ans, i;
      loop variant n - i + 1; */
  while (i <= n) {
    //@ assert ans + i == ((i) * ((i) + 1) / 2);
    
    ans += i;
    i += 1;
  }
  
  return ans;
}
