#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < 124 &&
        0 <= (b) && (b) < 124 &&
        0 <= (c) && (c) < 124 &&
        0 <= (d) && (d) < 124 &&
        0 <= (e) && (e) < 124 &&
        0 <= (k) && (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> e - a <= k;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    unsigned long long min;
    bool result;

    //@ assert a < e;
    min = e - a;

    if (min > k) {
        //@ assert e - a > k;
        result = false;
    } else {
        //@ assert e - a <= k;
        result = true;
    }

    return result;
}
