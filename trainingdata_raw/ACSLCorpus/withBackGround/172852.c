#include <stdbool.h>

/*@ predicate are_close(integer n, integer m) =
      n == m || n == m - 1 || n + 1 == m;
*/

/*@
  requires 1 <= n <= 100;
  requires 1 <= m <= 100;
  ensures \result == true <==> are_close(n, m);
  assigns \nothing;
*/
bool func(int n, int m)
{
    bool result;
    // Variable declarations at top of scope
    result = false;
    
    if (n == m)
    {
        result = true;
        //@ assert are_close(n, m);
        return result;
    }
    else if (n == m - 1 || n + 1 == m)
    {
        result = true;
        //@ assert are_close(n, m);
        return result;
    }
    else
    {
        result = false;
        //@ assert !are_close(n, m);
        return result;
    }
}
