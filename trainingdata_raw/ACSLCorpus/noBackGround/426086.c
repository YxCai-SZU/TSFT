#include <stdint.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t plus;
    int64_t minus;
    int64_t multi;
    int64_t result;

    plus = a + b;
    minus = a - b;
    //@ assert -10000 <= a * b <= 10000;
    multi = a * b;

    if (plus > minus && plus > multi)
    {
        result = plus;
    }
    else if (minus > multi)
    {
        result = minus;
    }
    else
    {
        result = multi;
    }

    //@ assert result >= plus && result >= minus && result >= multi;
    return result;
}
