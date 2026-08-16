#include <limits.h>

/*@
    predicate in_range(integer a) = -100 <= a <= 100;
    predicate product_in_range(integer a, integer b) = -10000 <= a * b <= 10000;
*/


int func(int A, int B)
{
    // Variable declarations at top of scope
    int result;

    //@ assert product_in_range(A, B);
    
    result = A * B;
    return result;
}
