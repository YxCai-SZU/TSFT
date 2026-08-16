#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == ((n + 1) / 2 >= 6);
*/
bool func(unsigned long n)
{
    unsigned long half_n;
    bool result;
    unsigned long count;
    
    half_n = n + 1;
    result = false;
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant half_n <= n + 1;
        loop invariant count <= (n + 1) / 2;
        loop invariant half_n == n + 1 - 2 * count;
        loop assigns half_n, count;
        loop variant half_n;
    */
    while (half_n > 1)
    {
        //@ assert half_n == n + 1 - 2 * count;
        half_n -= 2;
        count += 1;
        //@ assert half_n == n + 1 - 2 * count;
    }
    
    //@ assert count == (n + 1) / 2;
    if (count >= 6)
    {
        result = true;
    }
    
    //@ assert result == ((n + 1) / 2 >= 6);
    return result;
}
