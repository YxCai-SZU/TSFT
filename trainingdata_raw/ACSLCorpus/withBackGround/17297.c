#include <stdbool.h>

/*@
    predicate valid_params(integer n, int *h) =
        2 <= n <= 100000 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= h[i] <= 1000000000;

    predicate loop_invariant(integer n, int *h, integer idx, integer cnt, integer max) =
        0 <= idx <= n-1 &&
        0 <= cnt <= idx &&
        0 <= max <= idx &&
        idx - cnt <= n - 1 &&
        valid_params(n, h);
*/

/*@
    requires valid_params(n, h);
    ensures 0 <= \result <= n-1;
    assigns \nothing;
*/
int func(int n, int *h) {
    int dist = 0;
    int cur = 0;
    int cnt = 0;
    int max = 0;
    int index = 0;

    //@ assert valid_params(n, h);
    
    /*@
        loop invariant loop_invariant(n, h, index, cnt, max);
        loop assigns index, cnt, max;
        loop variant n-1 - index;
    */
    while (index < n - 1) {
        int next_index = index + 1;
        
        if (h[index] < h[next_index]) {
            cnt = 0;
        } else {
            cnt = cnt + 1;
            if (cnt > max) {
                max = cnt;
            }
        }
        
        //@ assert 0 <= cnt <= index+1;
        //@ assert 0 <= max <= index+1;
        
        index = index + 1;
    }
    
    //@ assert 0 <= max <= n-1;
    return max;
}
