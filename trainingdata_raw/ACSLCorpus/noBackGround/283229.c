#include <stdbool.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        1 <= (a) && (a) < (b) && (b) <= (n));
    ensures \result == ((((b) - (a) == 1) || ((a) == 1) || ((b) == (n)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int n, int a, int b) {
    bool result;
    
    //@ assert 2 <= n && n <= 100;
    //@ assert 1 <= a && a < b && b <= n;
    
    result = (b - a == 1) || (a == 1) || (b == n);
    
    //@ assert result == ((((b) - (a) == 1) || ((a) == 1) || ((b) == (n)) ? 1 : 0) == 1);
    return result;
}
