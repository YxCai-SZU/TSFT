#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result = 0;

    if (c > 0)
    {
        if (b < c)
        {
            //@ assert 0 <= b && b <= 100;
            //@ assert b * 2 + 1 <= 201;
            //@ assert b * 2 + 1 >= 1;
            result += b * 2 + 1;
        }
        else
        {
            //@ assert 0 <= c && c <= 100;
            //@ assert c * 2 <= 200;
            //@ assert c * 2 >= 0;
            result += c * 2;
        }
    }

    return result;
}
