#include <stdbool.h>

/*@
  requires (0 <= (a) <= 123 &&
      0 <= (b) <= 123 &&
      0 <= (c) <= 123 &&
      0 <= (d) <= 123 &&
      0 <= (e) <= 123 &&
      (a) < (b) < (c) < (d) < (e));
  requires 0 <= k <= 123;
  ensures ((\result) == true <==> 
      ((b) - (a) <= (k) || (c) - (a) <= (k) || (d) - (a) <= (k) || (e) - (a) <= (k)));
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    bool good = false;
    
    if (b - a <= k)
    {
        good = true;
    }
    else if (c - a <= k)
    {
        good = true;
    }
    else if (d - a <= k)
    {
        good = true;
    }
    else if (e - a <= k)
    {
        good = true;
    }
    
    //@ assert good == true <==> (b - a <= k || c - a <= k || d - a <= k || e - a <= k);
    
    return good;
}
