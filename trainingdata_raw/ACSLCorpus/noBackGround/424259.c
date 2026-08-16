#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b) {
    // Variable declarations at top of scope
    int result;

    //@ assert (-1000 <= (a) <= 1000);
    //@ assert (-1000 <= (b) <= 1000);
    //@ assert ((a) * (b)) >= -1000000 && ((a) * (b)) <= 1000000;

    result = a * b;
    //@ assert result == ((a) * (b));
    return result;
}
