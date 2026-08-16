#include <stdbool.h>

/*@
  requires (1 <= (k) <= 100);
  requires (1 <= (x) <= 100000);
  ensures ((\result) == (500 * (k) >= (x)));
*/
bool func(int k, int x)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= k && k <= 100;
    //@ assert 500 * 1 <= 500 * k && 500 * k <= 500 * 100;
    
    result = (500 * k >= x);
    return result;
}
