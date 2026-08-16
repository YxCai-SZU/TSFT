#include <limits.h>

/*@
    requires (2 <= (x) <= 100) && (2 <= (y) <= 100);
    ensures \result == ((x) * (y) - (x) - (y) + 1);
    assigns \nothing;
*/
int func(int x, int y) {
    int result;
    //@ assert x * y >= 2 * 2;
    //@ assert x * y <= 100 * 100;
    //@ assert x + y >= 2 + 2;
    //@ assert x + y <= 100 + 100;
    //@ assert x * y - x - y + 1 >= INT_MIN;
    //@ assert x * y - x - y + 1 <= INT_MAX;
    
    result = x * y - x - y + 1;
    return result;
}
