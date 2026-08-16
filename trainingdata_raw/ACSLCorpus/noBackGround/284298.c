#include <stdint.h>

/*@
  requires (1 <= (k) && (k) <= (n) && (n) <= 50);
  ensures \result == ((n) - (k) + 1);
*/
int64_t func(int64_t n, int64_t k)
{
    //@ assert n - k >= 0;
    return n - k + 1;
}

/*@
  requires (1 <= (k) && (k) <= (n) && (n) <= 50);
  ensures \result == ((n) - (k) + 1);
*/
int64_t func2(int64_t n, int64_t k)
{
    //@ assert n - k >= 0;
    //@ assert n - k + 1 <= 51;
    return n - k + 1;
}
