#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= a <= 100;
    ensures \result == (n % 2 == 0 || (n % 2 == 1 && a >= 6));
*/
bool func(int n, int a) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= a <= 100;
    
    result = (n % 2 == 0 || (n % 2 == 1 && a >= 6));
    return result;
}
