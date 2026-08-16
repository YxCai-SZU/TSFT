#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == true <==> ((a == b && a != c) || (b == c && b != a) || (a == c && a != b));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int state = 0;
    //@ assert state == 0;
    
    if (a == b) {
        state += 1;
    }
    if (b == c) {
        state += 1;
    }
    if (a == c) {
        state += 1;
    }
    
    //@ assert state == 1 <==> ((a == b && a != c) || (b == c && b != a) || (a == c && a != b));
    
    if (state == 1) {
        return true;
    } else {
        return false;
    }
}
