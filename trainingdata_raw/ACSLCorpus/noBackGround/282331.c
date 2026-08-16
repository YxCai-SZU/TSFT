#include <stdbool.h>

/*@
    requires 10 <= a <= 99;
    ensures \result == (a / 10 == 9 || a % 10 == 9);
    assigns \nothing;
*/
bool func(int a)
{
    bool res = false;

    //@ assert 10 <= a <= 99;

    if (a / 10 == 9) {
        res = true;
    }
    //@ assert res == (a / 10 == 9);

    if (a % 10 == 9) {
        res = true;
    }
    //@ assert res == (a / 10 == 9 || a % 10 == 9);

    return res;
}
