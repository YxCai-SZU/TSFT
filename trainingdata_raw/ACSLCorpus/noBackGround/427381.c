#include <stddef.h>

/*@
    requires (2 <= (N) <= 100 &&
        \valid((B) + (0 .. (N)-2)) &&
        \forall integer j; 0 <= j < (N)-1 ==> 0 <= (B)[j] <= 100000);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(size_t N, const int *B) {
    int ans;
    size_t i;
    int B_i;
    
    ans = B[0] + B[N-2];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= N-1;
        loop invariant ans >= 0;
        loop invariant ans <= (100000 * ((i) + 1));
        loop assigns ans, i, B_i;
        loop variant N - i;
    */
    while (i < N-1) {
        B_i = B[i];
        
        //@ assert B_i >= 0 && B_i <= 100000;
        
        if (B_i < B[i-1]) {
            ans += B_i;
        } else {
            ans += B[i-1];
        }
        
        i += 1;
    }
    
    //@ assert ans >= 0;
    return ans;
}
