#include <limits.h>

/*@
  requires (1 <= (a) && (a) <= 100 &&
      1 <= (b) && (b) <= 100 &&
      1 <= (c) && (c) <= 100 &&
      1 <= (k) && (k) <= 3);
  ensures \result >= -c;
  ensures \result <= a + b;
*/
int max_sum(int a, int b, int c, int k)
{
    int result = 0;
    int k_remaining = k;

    //@ assert (1 <= (a) && (a) <= 100 &&       1 <= (b) && (b) <= 100 &&       1 <= (c) && (c) <= 100 &&       1 <= (k) && (k) <= 3);
    
    if (a >= k_remaining) {
        result += k_remaining;
        k_remaining = 0;
    } else {
        result += a;
        k_remaining -= a;
    }

    if (b >= k_remaining) {
        k_remaining = 0;
    } else {
        k_remaining -= b;
    }

    result -= k_remaining;

    //@ assert result >= -c;
    //@ assert result <= a + b;
    
    return result;
}
