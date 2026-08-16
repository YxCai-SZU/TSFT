#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(int a, int b)
{
    bool a_is_multiple_of_3;
    bool b_is_multiple_of_3;
    bool sum_is_multiple_of_3;
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;

    a_is_multiple_of_3 = (a / 3 * 3 == a);
    b_is_multiple_of_3 = (b / 3 * 3 == b);
    sum_is_multiple_of_3 = ((a + b) / 3 * 3 == a + b);

    result = a_is_multiple_of_3 || b_is_multiple_of_3 || sum_is_multiple_of_3;
    return result;
}
