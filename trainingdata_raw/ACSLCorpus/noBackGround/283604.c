#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures ((1 <= (a) <= 9) && (1 <= (b) <= 9)) ==> \result == a * b;
    ensures (!(1 <= (a) <= 9) || !(1 <= (b) <= 9)) ==> \result == -1;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t max_value;
    int64_t min_value;
    int64_t result;

    max_value = (a > b) ? a : b;
    min_value = (a + b - max_value == a) ? a : b;

    if (max_value > 9)
    {
        //@ assert !(1 <= (a) <= 9) || !(1 <= (b) <= 9);
        result = -1;
    }
    else
    {
        //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9);
        //@ assert 1 <= a * b <= 81;
        result = a * b;
    }

    return result;
}
