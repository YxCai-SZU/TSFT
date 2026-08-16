#include <stdbool.h>

/*@ requires (1 <= (n) && (n) <= 20 &&
      1 <= (a) && (a) <= 100 &&
      1 <= (b) && (b) <= 2000);
    ensures \result <= b;
    ensures \result == a * n || \result == b;
    assigns \nothing;
*/
int func(int n, int a, int b) {
    // Variable declarations at top of scope
    int ans;
    
    //@ assert (1 <= (n) && (n) <= 20 &&       1 <= (a) && (a) <= 100 &&       1 <= (b) && (b) <= 2000);
    //@ assert a * n <= 2000;
    
    ans = a * n;
    
    if (ans < b) {
        //@ assert ans == a * n;
        return ans;
    } else {
        //@ assert b <= ans;
        return b;
    }
}
