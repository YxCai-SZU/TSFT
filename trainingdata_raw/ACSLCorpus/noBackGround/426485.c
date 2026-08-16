#include <stdbool.h>

/*@
    requires \valid_read(a + (0 .. 2));
    requires ((3) == 3 &&
        1 <= (a)[0] && (a)[0] <= 100 &&
        1 <= (a)[1] && (a)[1] <= 100 &&
        1 <= (a)[2] && (a)[2] <= 100);
    ensures \result == ((((a)[1] - (a)[0] == (a)[2] - (a)[1]) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int *a)
{
    //@ assert ((3) == 3 &&         1 <= (a)[0] && (a)[0] <= 100 &&         1 <= (a)[1] && (a)[1] <= 100 &&         1 <= (a)[2] && (a)[2] <= 100);
    return a[1] - a[0] == a[2] - a[1];
}
