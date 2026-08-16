#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == true <==> a < c && (c <= b || (b < c && d >= a && d <= b));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    bool result = false;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    if (a < c) {
        if (c <= b) {
            result = true;
        } else if (b < c && d >= a && d <= b) {
            result = true;
        } else {
            //@ assert a < c && !(c <= b || (b < c && d >= a && d <= b));
            result = false;
        }
    } else {
        //@ assert !(a < c && (c <= b || (b < c && d >= a && d <= b)));
        result = false;
    }

    return result;
}
