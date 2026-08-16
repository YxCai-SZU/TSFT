#include <stdbool.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        1 <= (a) && (a) < (b) && (b) <= (n));
    ensures \result == true <==> (((b) - (a)) % 2) == 0;
    assigns \nothing;
*/
bool func(int n, int a, int b) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant (2 <= (n) && (n) <= 100 &&
        1 <= (a) && (a) < (b) && (b) <= (n));
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        i += 1;
    }
    
    //@ assert (2 <= (n) && (n) <= 100 &&         1 <= (a) && (a) < (b) && (b) <= (n));
    return (b - a) % 2 == 0;
}
