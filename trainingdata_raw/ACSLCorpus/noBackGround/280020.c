#include <limits.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result >= 0;
    ensures \result == n / 3 || \result == n / 3 + 1;
    ensures \result <= n / 3 + 1;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int count;
    
    result = 0;
    temp_n = n;
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant temp_n >= 0;
        loop invariant count >= 0;
        loop invariant n == temp_n + 3 * count;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        //@ assert temp_n >= 3;
        temp_n -= 3;
        count += 1;
    }
    
    if (temp_n != 0)
    {
        //@ assert temp_n > 0 && temp_n < 3;
        count += 1;
    }
    
    result = count;
    
    //@ assert result >= 0;
    //@ assert result == n / 3 || result == n / 3 + 1;
    //@ assert result <= n / 3 + 1;
    
    return result;
}
