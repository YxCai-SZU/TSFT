#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= k <= 100;
    ensures \result == a - b || \result == b - a;
*/
int func(int a, int b, int c, int k)
{
    bool is_odd_flag;
    int temp_k;
    
    is_odd_flag = false;
    temp_k = k;
    
    /*@
        loop invariant 0 <= temp_k <= k;
        loop invariant temp_k % 2 == k % 2;
        loop assigns temp_k;
        loop variant temp_k;
    */
    while (temp_k > 1)
    {
        temp_k = temp_k - 2;
    }
    
    if (temp_k == 1)
    {
        is_odd_flag = true;
    }
    
    if (is_odd_flag)
    {
        //@ assert a - b == a - b;
        return a - b;
    }
    else
    {
        //@ assert b - a == b - a;
        return b - a;
    }
}
