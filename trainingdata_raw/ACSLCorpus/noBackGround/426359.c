#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == ((n) / 2 + ((n) % 2));
    ensures \result <= n;
*/
size_t func(size_t n)
{
    size_t res;
    size_t temp_n;
    size_t count;
    size_t remainder;
    
    res = 0;
    temp_n = n;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant count <= n / 2;
        loop invariant n == temp_n + 2 * count;
        loop invariant count > 0 ==> res == 0;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        count += 1;
    }
    
    res = count;
    remainder = n;
    
    /*@
        loop invariant 0 <= remainder <= n;
        loop invariant remainder < 2 + n;
        loop invariant remainder == n - 2 * ((n - remainder) / 2);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder >= 2;
        remainder -= 2;
    }
    
    if (remainder == 1)
    {
        res += 1;
    }
    
    //@ assert res <= n;
    return res;
}
