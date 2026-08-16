#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int x;
    int y;

    if (a < b) {
        x = a;
        y = b;
    } else {
        x = b;
        y = a;
    }

    //@ assert x <= y;

    if (x < c && c < y) {
        //@ assert ((x) < (c) && (c) < (y));
        //@ assert (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
        return true;
    }

    //@ assert !(((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
    return false;
}
