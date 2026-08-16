#include <stdint.h>


int64_t func(int64_t a)
{
    int64_t a2;
    int64_t a3;
    int64_t ans;

    //@ assert (1 <= (a) <= 10);
    //@ assert 1 <= a * a <= 100;
    //@ assert 1 <= a * a * a <= 1000;
    //@ assert 1 <= a + a * a <= 110;
    //@ assert 1 <= a + a * a + a * a * a <= 1110;

    a2 = a * a;
    a3 = a * a * a;
    ans = a + a2 + a3;

    //@ assert ans == a + a * a + a * a * a;
    return ans;
}
