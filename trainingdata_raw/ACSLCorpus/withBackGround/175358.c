#include <stdbool.h>

/*@ predicate is_even(integer val) = val % 2 == 0; */

/*@
  requires 1 <= x <= 100;
  requires 1 <= y <= 100;
  ensures \result == true <==> (y % 2 == 0 && y <= 4 * x);
*/
bool func(int x, int y)
{
    bool even = false;
    int temp_y = y;
    
    /*@
      loop invariant 1 <= x <= 100;
      loop invariant 1 <= y <= 100;
      loop invariant 0 <= temp_y <= y;
      loop invariant temp_y % 2 == y % 2;
      loop assigns temp_y;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
    }
    
    if (temp_y == 0)
    {
        even = true;
    }
    
    //@ assert even == (y % 2 == 0);
    
    if (even && y <= 4 * x)
    {
        return true;
    }
    else
    {
        return false;
    }
}
