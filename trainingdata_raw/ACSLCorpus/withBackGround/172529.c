#include <stdbool.h>

/*@
    predicate remainder_correct(integer h, integer r) =
        r == h % 500;
*/

/*@
    requires 1 <= h && h <= 10000;
    requires 1 <= n && n <= 10000;
    ensures \result == (h % 500 <= n);
    assigns \nothing;
*/
bool func(unsigned int h, unsigned int n)
{
    unsigned int remainder;
    
    remainder = h % 500;
    
    //@ assert remainder == h % 500;
    
    return remainder <= n;
}
