#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == true <==> (a < b && b < c);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c) {
    unsigned long cnt = 0;
    
    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    
    if (a == b || a == c) {
        cnt += 1;
    }
    if (b == c) {
        cnt += 1;
    }
    
    //@ assert cnt <= 2;
    
    if (cnt == 0 && a < b && b < c) {
        return true;
    } else {
        return false;
    }
}
