#include <stddef.h>

/*@
    requires (1 <= (n) <= 100000);
    ensures \result == ((((n)) / 2) + (((n)) % 2));
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t half;
    size_t temp_n;
    size_t count;
    
    half = 0;
    temp_n = n;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n == n - 2 * count;
        loop invariant 0 <= count <= ((n) / 2);
        loop invariant half == 0;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        count += 1;
    }
    half = count;
    
    size_t remainder;
    if (temp_n == 1)
    {
        remainder = 1;
    }
    else
    {
        remainder = 0;
    }
    
    //@ assert half <= 50000;
    //@ assert remainder <= 1;
    
    return half + remainder;
}

int main(void)
{
    return 0;
}
