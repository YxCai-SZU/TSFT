#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((a == b + 1 && c == b) || 
                       (b == c + 1 && a == c) || 
                       (c == a + 1 && b == a) || 
                       (c == b && b == a + 1) || 
                       (a == c && c == b + 1) || 
                       (b == a && a == c + 1));
*/
bool func(int a, int b, int c) {
    bool ans;
    
    if ((a == b + 1 && c == b) ||  
        (b == c + 1 && a == c) ||  
        (c == a + 1 && b == a) ||  
        (c == b && b == a + 1) ||  
        (a == c && c == b + 1) ||  
        (b == a && a == c + 1)) {
        ans = true;
    } else {
        ans = false;
    }
    
    //@ assert ans == ((a == b + 1 && c == b) || (b == c + 1 && a == c) || (c == a + 1 && b == a) || (c == b && b == a + 1) || (a == c && c == b + 1) || (b == a && a == c + 1));
    
    return ans;
}
