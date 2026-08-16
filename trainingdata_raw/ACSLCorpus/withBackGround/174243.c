#include <stdbool.h>

/*@
    predicate ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
*/

/*@
    requires a < 0x80000000 && b < 0x80000000 && c < 0x80000000 && 
             d < 0x80000000 && e < 0x80000000 && k < 0x80000000;
    requires ordered(a, b, c, d, e);
    ensures \result == (e - a <= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    //@ assert a < b && b < c && c < d && d < e;
    return (e - a) <= k;
}
