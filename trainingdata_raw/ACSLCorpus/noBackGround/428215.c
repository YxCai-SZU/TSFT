#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 16 &&
        1 <= (b) && (b) <= 16 &&
        (a) + (b) <= 16);
    ensures \result == ((((a) <= 8 && (b) <= 8) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    bool result;
    //@ assert (1 <= (a) && (a) <= 16 &&         1 <= (b) && (b) <= 16 &&         (a) + (b) <= 16);
    result = (a <= 8) && (b <= 8);
    //@ assert result == ((((a) <= 8 && (b) <= 8) ? 1 : 0) == 1);
    return result;
}

/*@
    requires (0 <= (x) && (x) <= 8 && 0 <= (y) && (y) <= 8);
    ensures \result == x * y;
    assigns \nothing;
*/
unsigned int test_nonlinear_arith(unsigned int x, unsigned int y)
{
    unsigned int ret;
    //@ assert (0 <= (x) && (x) <= 8 && 0 <= (y) && (y) <= 8);
    ret = x * y;
    //@ assert ret == x * y;
    return ret;
}
