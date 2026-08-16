#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    requires (0 <= (x) <= 100);
    ensures \result == (x - a >= 0 && x - a <= b);
*/
bool func(long a, long b, long x)
{
    long rest;

    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert (0 <= (x) <= 100);
    
    rest = x - a;
    
    //@ assert rest == ((x) - (a));
    
    if (rest >= 0 && rest <= b) {
        //@ assert rest >= 0 && rest <= b;
        return true;
    } else {
        //@ assert !(rest >= 0 && rest <= b);
        return false;
    }
}
