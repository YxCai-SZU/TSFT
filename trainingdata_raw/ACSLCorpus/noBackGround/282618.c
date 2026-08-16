#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == (1000 * ((n) / 1000) +
        500 * (((n) % 1000) / 500) +
        100 * (((n) % 1000) % 500 / 100) +
        50 * (((n) % 1000) % 500 % 100 / 50) +
        10 * (((n) % 1000) % 500 % 100 % 50 / 10) +
        ((n) % 1000) % 500 % 100 % 50 % 10);
    assigns \nothing;
*/
size_t func(size_t n)
{
    // Variable declarations at top of scope
    size_t res;
    size_t t1, t2, t3, t4, t5, t6;
    size_t tmp1, tmp2, tmp3, tmp4, tmp5;

    //@ assert n / 1000 <= 10;
    t1 = n / 1000;
    
    tmp1 = n % 1000;
    //@ assert tmp1 / 500 <= 2;
    t2 = tmp1 / 500;
    
    tmp2 = tmp1 % 500;
    //@ assert tmp2 / 100 <= 5;
    t3 = tmp2 / 100;
    
    tmp3 = tmp2 % 100;
    //@ assert tmp3 / 50 <= 2;
    t4 = tmp3 / 50;
    
    tmp4 = tmp3 % 50;
    //@ assert tmp4 / 10 <= 5;
    t5 = tmp4 / 10;
    
    tmp5 = tmp4 % 10;
    //@ assert tmp5 <= 10;
    t6 = tmp5;

    res = 1000 * t1 + 500 * t2 + 100 * t3 + 50 * t4 + 10 * t5 + t6;

    //@ assert res == (1000 * ((n) / 1000) +         500 * (((n) % 1000) / 500) +         100 * (((n) % 1000) % 500 / 100) +         50 * (((n) % 1000) % 500 % 100 / 50) +         10 * (((n) % 1000) % 500 % 100 % 50 / 10) +         ((n) % 1000) % 500 % 100 % 50 % 10);
    return res;
}
