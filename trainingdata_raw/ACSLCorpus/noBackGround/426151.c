#include <stdint.h>

/*@
    requires 0 <= n <= 1000000000000;
    requires 0 <= m <= 1000000000000;
    requires n + m >= 1;
    ensures \result >= 0;
    ensures \result <= n + m / 2;
    ensures n > m / 2 ==> \result == n - m / 2;
    ensures n <= m / 2 ==> \result == 0;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t res;

    //@ assert ((n) >= 0 && (m) >= 0 && (n) + (m) >= 1);
    
    if (n > m / 2)
    {
        //@ assert n > m / 2;
        res = n - m / 2;
        //@ assert res == n - m / 2;
    }
    else
    {
        //@ assert n <= m / 2;
        res = 0;
        //@ assert res == 0;
    }

    //@ assert res == ((n) > (((m)) / 2) ? (n) - (((m)) / 2) : 0);
    return res;
}
