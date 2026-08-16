#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (x) <= 100);
    ensures \result == 1 <==> ((a) <= (x) && ((x) - (a)) <= (b));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 0 <= a <= 100;
    //@ assert 0 <= b <= 100;
    //@ assert 0 <= x <= 100;

    if (a <= x && (x - a) <= b) {
        //@ assert ((a) <= (x) && ((x) - (a)) <= (b));
        result = true;
    } else {
        result = false;
    }

    return result;
}
