#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (m == n);
    assigns \nothing;
*/
bool func(int n, int m) {
    // Variable declarations at top of scope
    int start;
    int i;
    
    start = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 1000;
        loop assigns i;
    */
    while (i < 1000) {
        i = i + 1;
    }
    
    //@ assert 0 <= i <= 1000;
    
    return m == n;
}

int main() {
    return 0;
}
