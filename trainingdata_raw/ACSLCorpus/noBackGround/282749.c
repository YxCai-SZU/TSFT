#include <limits.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == (1000 * (((n) / 1000) + 1) - (n));
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int count;
    
    result = 1000;
    temp_n = n;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n == n - 1000 * count;
        loop invariant 0 <= count <= n / 1000;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 1000)
    {
        //@ assert temp_n >= 1000;
        temp_n -= 1000;
        count += 1;
    }
    
    //@ assert temp_n == n - 1000 * count;
    result *= (count + 1);
    
    //@ assert result == 1000 * (count + 1);
    return result - n;
}
