#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (x) && (x) <= 200 &&
        (a) + (b) <= 200);
    ensures \result == 1 <==> ((b) <= (x) && (x) <= (a) + (b));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= x && x <= 200;
    //@ assert a + b <= 200;
    
    if (b <= x && x <= (a + b)) {
        return true;
    } else {
        return false;
    }
}
