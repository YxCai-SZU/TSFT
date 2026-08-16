#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == 1 || \result == 2 || \result == 5 || \result == 14 || \result == 15 || \result == 4 || \result == 51;
    assigns \nothing;
*/
int func(int n) {
    int res;
    
    if (n == 1) {
        res = 1;
    } else if (n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12) {
        res = 2;
    } else if (n == 4 || n == 6 || n == 9 || n == 11) {
        res = 5;
    } else {
        res = 14;
    }
    
    //@ assert res == 1 || res == 2 || res == 5 || res == 14 || res == 15 || res == 4 || res == 51;
    return res;
}
