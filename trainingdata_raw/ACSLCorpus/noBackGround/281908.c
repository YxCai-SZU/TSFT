#include <stdint.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == ((n) / 3) * ((n) / 3) * ((n) / 3);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t e;
    int64_t temp_n;
    
    e = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= e;
        loop invariant 0 <= temp_n;
        loop invariant n == temp_n + e * 3;
        loop assigns e, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        temp_n = temp_n - 3;
        e = e + 1;
    }
    
    //@ assert 0 <= e <= 3333;
    
    //@ assert 0 <= e * e <= 3333 * 3333;
    
    //@ assert 0 <= e * e * e <= 3333 * 3333 * 3333;
    
    return e * e * e;
}
