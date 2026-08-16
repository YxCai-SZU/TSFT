#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 1000000;
        loop assigns i;
        loop variant 1000000 - i;
    */
    while (i < 1000000) {
        i = i + 1;
    }
    
    bool result = (n == m);
    //@ assert result == (n == m);
    return result;
}
