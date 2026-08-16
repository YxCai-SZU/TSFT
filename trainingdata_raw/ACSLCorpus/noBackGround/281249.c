#include <limits.h>

/*@
    requires a >= INT_MIN && a <= INT_MAX;
    requires b >= INT_MIN && b <= INT_MAX;
    requires c >= INT_MIN && c <= INT_MAX;
    ensures \result <= a && \result <= b && \result <= c;
    ensures \result == a || \result == b || \result == c;
    ensures \result >= INT_MIN && \result <= INT_MAX;
    assigns \nothing;
*/
int min_numbers(int a, int b, int c)
{
    int min_val = a;
    
    if (b < min_val)
    {
        min_val = b;
        //@ assert min_val <= a && min_val <= b;
    }
    
    if (c < min_val)
    {
        min_val = c;
        //@ assert min_val <= a && min_val <= b && min_val <= c;
    }
    
    //@ assert min_val <= a && min_val <= b && min_val <= c;
    //@ assert min_val == a || min_val == b || min_val == c;
    //@ assert min_val >= INT_MIN && min_val <= INT_MAX;
    
    return min_val;
}
