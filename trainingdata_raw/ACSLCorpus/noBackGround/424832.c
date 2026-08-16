#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (((a) * 100 / 2) >= b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int s;
    unsigned int res;
    //@ assert a * 100 <= 10000;
    s = a * 100 / 2;
    //@ assert s == ((a) * 100 / 2);
    if (s >= b) {
        res = 1;
    } else {
        res = 0;
    }
    //@ assert res == 1 ==> s >= b;
    return res == 1;
}
