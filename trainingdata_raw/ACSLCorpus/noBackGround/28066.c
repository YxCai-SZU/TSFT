#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == true <==> (n % 2 == 0);
*/
bool func(unsigned long n) {
    bool ans;
    
    if (n % 2 == 0) {
        ans = true;
    } else {
        ans = false;
    }
    
    //@ assert ans == true <==> (n % 2 == 0);
    
    return ans;
}
