#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> (uint64_t)\result * 8 / 100 == a && (uint64_t)\result * 10 / 100 == b;
*/
int64_t func(uint64_t a, uint64_t b)
{
    uint64_t sum;
    uint64_t x;
    uint64_t aa;
    uint64_t bb;
    int64_t result;

    sum = a + b;

    //@ assert sum == ((a) + (b));

    if (sum < 8)
    {
        result = -1;
        //@ assert result >= 0 || result == -1;
        return result;
    }

    x = sum / 10;
    if (sum % 10 != 0)
    {
        x = x + 1;
    }

    //@ assert x == ((sum) % 10 == 0 ? (sum) / 10 : (sum) / 10 + 1);

    aa = x * 8 / 100;
    bb = x * 10 / 100;

    //@ assert aa == ((x) * 8 / 100);
    //@ assert bb == ((x) * 10 / 100);

    if (aa == a && bb == b)
    {
        result = (int64_t)x;
        //@ assert result >= 0;
        //@ assert (uint64_t)result * 8 / 100 == a;
        //@ assert (uint64_t)result * 10 / 100 == b;
        return result;
    }
    else
    {
        result = -1;
        //@ assert result >= 0 || result == -1;
        return result;
    }
}
