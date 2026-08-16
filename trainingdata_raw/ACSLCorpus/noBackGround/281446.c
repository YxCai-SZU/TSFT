#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == a * 2 - 1 || \result == b * 2 - 1 || 
            \result == a + b || \result == b * 2;
    assigns \nothing;
*/
int func(int a, int b) {
    int result;
    
    if (a > b + 1) {
        result = a * 2 - 1;
    } else if (b > a + 1) {
        result = b * 2 - 1;
    } else if (b == a) {
        result = b * 2;
    } else {
        //@ assert a + b == a + b;
        result = b + a;
    }
    
    return result;
}
