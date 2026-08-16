#include <stdbool.h>

/*@
    requires \true;
    ensures (((\result) == (a) || (\result) == (b)) &&
        (\result) <= (a) &&
        (\result) <= (b));
    assigns \nothing;
*/
int minimum(int a, int b)
{
    int ret;

    if (a < b) {
        //@ assert a <= a && a <= b;
        ret = a;
    } else {
        //@ assert b <= a && b <= b;
        ret = b;
    }

    //@ assert (((ret) == (a) || (ret) == (b)) &&         (ret) <= (a) &&         (ret) <= (b));
    return ret;
}
