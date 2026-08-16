#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000);
    ensures \result == ((n) / 3) * ((n) / 3) * ((n) / 3);
*/
int64_t func(int64_t n)
{
    int64_t m;
    int64_t temp_n;
    int64_t count;
    
    m = 0;
    temp_n = n;
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 1000000;
        loop invariant 0 <= temp_n;
        loop invariant n == temp_n + 3 * count;
        loop invariant 0 <= count;
        loop invariant count <= ((n) / 3);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        temp_n = temp_n - 3;
        count = count + 1;
    }
    m = count;
    
    //@ assert n / 3 >= 0;
    //@ assert m >= 0 && m <= n / 3;
    //@ assert n / 3 <= 333333;
    //@ assert (n / 3) * (n / 3) <= 333333 * 333333;
    //@ assert (n / 3) * (n / 3) * (n / 3) <= 333333 * 333333 * 333333;
    
    return m * m * m;
}

int main()
{
    return 0;
}
