#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int n, int k) {
    int remainder = n;
    
    /*@
        loop invariant 0 <= remainder <= n;
        loop invariant (1 <= (n) <= 100 && 1 <= (k) <= 100);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= k) {
        remainder -= k;
    }
    
    //@ assert remainder == 0 || remainder != 0;
    
    if (remainder == 0) {
        return 0;
    } else {
        return 1;
    }
}
