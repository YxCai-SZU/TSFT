#include <limits.h>

/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    assigns \nothing;
*/
int func(int a, int b)
{
    // Declare all variables at the top
    int result;

    //@ assert a > 1;
    //@ assert b > 1;
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a * b <= 100 * 100;
    //@ assert a * b >= 2 * 2;
    //@ assert a * b - a <= 100 * 100 - 2;
    //@ assert a * b - a >= 2 * 2 - 100;
    //@ assert a * b - a - b <= 100 * 100 - 2 - 2;
    //@ assert a * b - a - b >= 2 * 2 - 100 - 100;
    //@ assert a * b - a - b + 1 <= 100 * 100 - 2 - 2 + 1;
    //@ assert a * b - a - b + 1 >= 2 * 2 - 100 - 100 + 1;
    //@ assert a * b - a - b + 1 >= INT_MIN;

    result = a * b - a - b + 1;
    return result;
}
