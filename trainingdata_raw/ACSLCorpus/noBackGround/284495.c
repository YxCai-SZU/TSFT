#include <stdbool.h>
#include <stddef.h>

/*@
    requires (\valid((a) + (0..2)) &&
        1 <= (a)[0] <= 100 &&
        1 <= (a)[1] <= 100 &&
        1 <= (a)[2] <= 100);
    ensures \result == ((a[0]) - ((a[1]) - (a[2])));
    assigns \nothing;
*/
int func(int* a)
{
    int result;
    //@ assert (0 <= (0) && (0) < 3);
    //@ assert (0 <= (1) && (1) < 3);
    //@ assert (0 <= (2) && (2) < 3);
    result = a[0] - (a[1] - a[2]);
    //@ assert result == ((a[0]) - ((a[1]) - (a[2])));
    return result;
}
