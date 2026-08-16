#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 100);
    ensures \result == ((((((a)) - 1)) * ((((b)) - 1))));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t a_minus_one;
    uint32_t b_minus_one;
    uint32_t result;

    //@ assert a >= 2 && a <= 100;
    //@ assert b >= 2 && b <= 100;

    a_minus_one = a - 1;
    //@ assert a_minus_one == ((a) - 1);
    //@ assert a_minus_one >= 1;

    b_minus_one = b - 1;
    //@ assert b_minus_one == ((b) - 1);
    //@ assert b_minus_one >= 1;

    //@ assert a_minus_one <= 99;
    //@ assert b_minus_one <= 99;

    //@ assert a_minus_one * b_minus_one <= 99 * 99;
    result = a_minus_one * b_minus_one;
    //@ assert result == ((((a) - 1)) * (((b) - 1)));

    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    uint32_t a = 5;
    uint32_t b = 7;
    uint32_t result = func(a, b);
    //@ assert result == (a - 1) * (b - 1);
    assert(result == (a - 1) * (b - 1));
    return 0;
}
#endif
