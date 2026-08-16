#include <stdbool.h>

/*@ predicate is_valid_range(integer a) = 1 <= a && a <= 100; */

/*@
    requires is_valid_range(A) && is_valid_range(B);
    ensures \result == (A - B * 2) || \result == 0;
    ensures \result >= 0;
*/
int func(int A, int B)
{
    int C;
    C = A - B * 2;
    
    if (C < 0)
    {
        //@ assert C < 0;
        return 0;
    }
    else
    {
        //@ assert C >= 0;
        return C;
    }
}
