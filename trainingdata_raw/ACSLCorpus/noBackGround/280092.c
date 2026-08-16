#include <limits.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result >= 0;
    ensures \result <= 10000;
    ensures \result == ((((n)) / 3) + (((((n)) % 3)) / 2));
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
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n >= 0;
        loop invariant count >= 0;
        loop invariant temp_n == n - 3 * count;
        loop invariant count <= ((n) / 3);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        temp_n -= 3;
        count += 1;
    }
    
    result += count;
    
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n >= 0;
        loop invariant count >= 0;
        loop invariant temp_n == n - 3 * result - 2 * count;
        loop invariant count <= ((n - 3 * result) / 2);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        temp_n -= 2;
        count += 1;
    }
    
    result += count;
    
    //@ assert result == ((((n)) / 3) + (((((n)) % 3)) / 2));
    return result;
}
