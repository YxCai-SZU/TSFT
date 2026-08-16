#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
*/
int func(int a, int b) {
    int max_val;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (a - b * 2 > 0) {
        max_val = a - b * 2;
    } else {
        max_val = 0;
    }
    
    //@ assert max_val >= 0;
    //@ assert max_val == a - b * 2 || max_val == 0;
    
    return max_val;
}
