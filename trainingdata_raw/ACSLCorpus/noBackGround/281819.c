#include <stdbool.h>

/*@
    requires (1 <= (a) <= 5000 &&
        1 <= (b) <= 5000 &&
        1 <= (c) <= 10000);
    ensures \result == (c - a >= 0 && c - a <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int x;

    //@ assert (1 <= (a) <= 5000 &&         1 <= (b) <= 5000 &&         1 <= (c) <= 10000);
    x = c - a;
    
    //@ assert x == ((c) - (a));
    
    if (x >= 0 && x <= b) {
        //@ assert ((x) >= 0 && (x) <= (b));
        return true;
    } else {
        //@ assert !((x) >= 0 && (x) <= (b));
        return false;
    }
}
