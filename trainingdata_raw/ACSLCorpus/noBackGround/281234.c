#include <stdint.h>
#include <stdbool.h>

/*@
    requires (1 <= (N) <= 20 &&
        \valid((Hs) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> 1 <= (Hs)[i] <= 100);
    ensures \result <= N;
    ensures \forall integer i; 0 <= i < N ==> Hs[i] == \at(Hs[i], Pre);
    assigns \nothing;
*/
uint64_t func(uint64_t N, const uint64_t *Hs) {
    uint64_t ans = 0;
    uint64_t acc = 0;
    uint64_t idx = 0;
    
    /*@
        loop invariant 0 <= idx <= N;
        loop invariant 0 <= acc <= idx * 100;
        loop invariant 0 <= ans <= idx;
        loop assigns ans, acc, idx;
        loop variant N - idx;
    */
    while (idx < N) {
        uint64_t H = Hs[idx];
        acc += H;
        
        //@ assert 0 <= acc <= (idx + 1) * 100;
        
        if (acc >= idx) {
            ans = idx + 1;
        } else {
            ans = acc;
        }
        
        //@ assert 0 <= ans <= idx + 1;
        idx += 1;
    }
    
    //@ assert ans <= N;
    return ans;
}
