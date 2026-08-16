#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@
  requires 1 <= n <= 100;
  ensures is_even(n) ==> \result == 0;
  ensures !is_even(n) ==> \result == 1;
  assigns \nothing;
*/
size_t func(size_t n)
{
    size_t change;
    
    if (n % 2 == 0)
    {
        change = 0;
    }
    else
    {
        //@ assert n % 2 != 0;
        change = 1;
    }
    
    return change;
}
