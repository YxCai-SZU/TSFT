#include <stdbool.h>

/*@
    requires \valid(v + (0..3));
    requires (1 <= (v[0]) <= 10000) && (1 <= (v[1]) <= 10000) && (1 <= (v[2]) <= 10000) && (1 <= (v[3]) <= 10000);
    ensures \result >= 0;
    ensures \result == v[0] + v[1] || \result == v[2] + v[3];
*/
int func(int v[4]) {
    int ans;
    
    //@ assert (1 <= (v[0]) <= 10000);
    //@ assert (1 <= (v[1]) <= 10000);
    //@ assert (1 <= (v[2]) <= 10000);
    //@ assert (1 <= (v[3]) <= 10000);
    
    if (v[0] + v[1] > v[2] + v[3]) {
        ans = v[0] + v[1];
    } else {
        ans = v[2] + v[3];
    }
    
    //@ assert ans >= 0;
    return ans;
}
