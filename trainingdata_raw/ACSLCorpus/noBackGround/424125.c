#include <stdbool.h>

/*@
  requires (1 <= (k) && (k) <= 100 &&
      1 <= (x) && (x) <= 100000);
  ensures \result == (((k) * 500) >= x);
  assigns \nothing;
*/
bool func(int k, int x)
{
    // Variable declarations at scope top
    bool ans;
    
    //@ assert (1 <= (k) && (k) <= 100 &&       1 <= (x) && (x) <= 100000);
    
    ans = (k * 500) >= x;
    
    //@ assert ans == (((k) * 500) >= x);
    
    return ans;
}
