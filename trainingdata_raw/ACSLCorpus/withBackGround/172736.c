#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 100; */

/*@
  requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
  ensures \result == true <==> (a < c && b > c) || (a > c && b < c);
  assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at the top
    bool result;

    //@ assert (a < c && b > c) || (a > c && b < c) <==> (a < c && b > c) || (a > c && b < c);
    
    result = (a < c && b > c) || (a > c && b < c);
    return result;
}
