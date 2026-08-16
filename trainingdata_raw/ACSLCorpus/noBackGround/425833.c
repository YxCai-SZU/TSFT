#include <limits.h>

/*@
    requires (-46340 <= (n) && (n) <= 46340);
    ensures \result == n * n;
    assigns \nothing;
*/
int square(int n) {
    // Variable declarations at top of scope
    int res;
    
    //@ assert (-46340 <= (n) && (n) <= 46340);
    
    //@ assert -46340 * 46340 <= n * n && n * n <= 46340 * 46340;
    
    res = n * n;
    return res;
}

int main() {
    return 0;
}
