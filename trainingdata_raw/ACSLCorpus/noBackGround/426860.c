#include <stdbool.h>
/*@
    requires ((2) == 2 &&
        \valid((a) + (0 .. (2)-1)) &&
        1 <= (a)[0] <= 100 &&
        0 <= (a)[1] <= 4111);
    ensures \result >= 0;
    ensures \result == ((a[0]) * 100 + (a[1])) || \result == a[1];
*/
int func(int *a) {
    // Variable declarations at scope top
    int sum;
    int ans;
    
    //@ assert a[0] >= 1 && a[0] <= 100;
    //@ assert a[1] >= 0 && a[1] <= 4111;
    
    sum = a[0] * 100 + a[1];
    
    //@ assert sum == ((a[0]) * 100 + (a[1]));
    //@ assert sum >= 0;
    
    if (sum < a[1]) {
        ans = sum;
    } else {
        ans = a[1];
    }
    
    //@ assert ans >= 0;
    //@ assert ans == ((a[0]) * 100 + (a[1])) || ans == a[1];
    
    return ans;
}
