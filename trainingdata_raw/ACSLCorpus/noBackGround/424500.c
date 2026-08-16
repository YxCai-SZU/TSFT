#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    requires ((a) + (b) + (c) == 100);
    ensures \result == true <==> ((a) >= (c) && (c) <= 50 && (a) < 50 + (b));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert ((a) + (b) + (c) == 100);
    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert (0 <= (c) <= 100);
    //@ assert 50 <= (50 + (b)) <= 150;
    
    if (a >= c && c <= 50 && a < 50 + b) {
        return true;
    } else {
        return false;
    }
}
