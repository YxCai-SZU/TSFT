#include <stddef.h>

/*@
    requires (2 <= (a) && (a) <= 100 && 2 <= (b) && (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at top of scope
    size_t tmp_a;
    size_t tmp_b;
    size_t result;

    //@ assert 2 <= a && a <= 100;
    //@ assert 2 <= b && b <= 100;

    // Ensure (a - 1) >= 1
    //@ assert a - 1 >= 1;
    tmp_a = a - 1;

    // Ensure (b - 1) >= 1
    //@ assert b - 1 >= 1;
    tmp_b = b - 1;

    // Ensure (a - 1) <= 99
    //@ assert tmp_a <= 99;
    // Ensure (b - 1) <= 99
    //@ assert tmp_b <= 99;

    // Ensure product bounds
    //@ assert tmp_a * tmp_b <= 99 * 99;
    //@ assert tmp_a * tmp_b >= 1 * 1;

    result = tmp_a * tmp_b;
    //@ assert result == (((a) - 1) * ((b) - 1));
    return result;
}
