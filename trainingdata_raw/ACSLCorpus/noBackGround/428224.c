#include <stdint.h>

/*@
  requires (1 <= (k) && (k) <= (n) && (n) <= 50);
  ensures \result == n - k + 1;
*/
uint32_t func(uint32_t n, uint32_t k)
{
    uint32_t ans;
    //@ assert (1 <= (k) && (k) <= (n) && (n) <= 50);
    ans = n - k + 1;
    //@ assert ans == n - k + 1;
    return ans;
}

/*@
  requires (1 <= (k) && (k) <= (n) && (n) <= 50);
  ensures \result == n - k + 1;
*/
uint32_t func2(uint32_t n, uint32_t k)
{
    uint32_t ans;
    //@ assert (1 <= (k) && (k) <= (n) && (n) <= 50);
    ans = n - k + 1;
    //@ assert ans == n - k + 1;
    return ans;
}
