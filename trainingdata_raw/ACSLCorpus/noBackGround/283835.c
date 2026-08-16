#include <stdint.h>

/*@
  requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
  requires a == (int64_t)a && b == (int64_t)b;
  ensures \result >= 0;
  ensures \result == a - b * 2 || \result == 0;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;
    
    ans = a - b * 2;
    
    if (ans < 0)
    {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    //@ assert ans == a - b * 2 || ans == 0;
    
    return ans;
}
