#include <stdbool.h>

/*@ requires 1 <= x <= 9;
    ensures \result == (x == 3 || x == 5 || x == 7);
    assigns \nothing;
 */
bool func(int x)
{
    int a;
    int b;
    int c;
    bool result;

    a = 3;
    b = 5;
    c = 7;
    result = false;

    if (x == a || x == b || x == c)
    {
        result = true;
    }

    //@ assert result == (x == 3 || x == 5 || x == 7);
    return result;
}
