#include <stdbool.h>

/*@
    requires a > -2147483648 && a < 2147483647;
    requires b > -2147483648 && b < 2147483647;
    requires c > -2147483648 && c < 2147483647;
    ensures \result == true <==> ((a) < (b) && (b) < (c));
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert \true;
    if (a < b && b < c) {
        //@ assert ((a) < (b) && (b) < (c));
        result = true;
    } else {
        //@ assert !((a) < (b) && (b) < (c));
        result = false;
    }

    return result;
}
