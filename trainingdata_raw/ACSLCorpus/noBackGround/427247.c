#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    requires (0 <= (c) <= 100);
    requires a != b;
    ensures \result == ((a < c && b < c) || (a > c && b > c));
*/
bool func(int a, int b, int c) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert (0 <= (c) <= 100);
    //@ assert a != b;
    
    result = (a < c && b < c) || (a > c && b > c);
    
    return result;
}
