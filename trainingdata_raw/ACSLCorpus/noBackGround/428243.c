#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= k <= 100;
    ensures \result == a - b || \result == b - a;
*/
int func(int a, int b, int c, long k)
{
    bool is_even;
    long temp_k;
    
    is_even = true;
    temp_k = k;
    
    /*@
        loop invariant 0 <= temp_k <= k;
        loop invariant ((temp_k) % 2 == 0) <==> ((k) % 2 == 0);
        loop assigns temp_k, is_even;
    */
    while (temp_k > 0)
    {
        if (temp_k == 1)
        {
            is_even = false;
            break;
        }
        temp_k -= 2;
    }
    
    if (is_even)
    {
        //@ assert a - b == a - b || a - b == b - a;
        return a - b;
    }
    else
    {
        //@ assert b - a == a - b || b - a == b - a;
        return b - a;
    }
}
