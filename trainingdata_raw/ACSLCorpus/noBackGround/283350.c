#include <stdbool.h>

/*@
    requires 1 <= s <= 100;
    requires 1 <= w <= 100;
    ensures \result == (s <= w);
*/
bool func(int s, int w) {
    int diff;
    int max_val;
    
    diff = s - w;
    
    //@ assert diff == s - w;
    
    if (diff < 0) {
        max_val = 0;
    } else {
        max_val = diff;
    }
    
    //@ assert diff == s - w;
    
    return s <= w;
}
