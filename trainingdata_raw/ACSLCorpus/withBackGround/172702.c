#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer x) = 1 <= x <= 3; */

/*@
  requires valid_range(a) && valid_range(b);
  requires a != b;
  ensures \result == 6 - a - b;
  ensures 1 <= \result <= 3;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at top
    size_t result;
    
    //@ assert 6 - a - b >= 1;
    //@ assert 6 - a - b <= 3;
    
    result = 6 - a - b;
    return result;
}
