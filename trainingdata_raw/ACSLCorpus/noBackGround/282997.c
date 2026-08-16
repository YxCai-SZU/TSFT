#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) * ((b) + 1) / 2) - ((b) / 2));
    assigns \nothing;
*/
int64_t func(uint64_t a, uint64_t b)
{
    uint64_t b_div_2;
    uint64_t a_times_b_plus_1;
    uint64_t a_times_b_plus_1_div_2;
    int64_t result;

    b_div_2 = b / 2;
    //@ assert 1 <= a && a <= 100 && 1 <= b && b <= 100;
    //@ assert 1 <= a * (b + 1) <= 100 * 101;
    a_times_b_plus_1 = a * (b + 1);
    a_times_b_plus_1_div_2 = a_times_b_plus_1 / 2;
    //@ assert a_times_b_plus_1_div_2 == (a * (b + 1) / 2);
    //@ assert b_div_2 == (b / 2);
    result = (int64_t)a_times_b_plus_1_div_2 - (int64_t)b_div_2;
    return result;
}
