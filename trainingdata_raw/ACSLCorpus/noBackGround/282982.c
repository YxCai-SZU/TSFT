#include <stdint.h>
#include <stdbool.h>

/*@
    requires ((N) > 0 && (N) <= 100000 &&
    \valid((Hs) + (0 .. (N)-1)) &&
    \forall integer i; 0 <= i < (N) ==> (Hs)[i] > 0 && (Hs)[i] <= 1000000000);
    ensures \result >= 0 && \result <= N;
    assigns \nothing;
*/
uint32_t func(uint32_t N, const uint64_t *Hs) {
    uint64_t max_h = 0;
    uint32_t res = 0;
    uint32_t index = 0;
    
    /*@
        loop invariant 0 <= index <= N;
        loop invariant 0 <= res <= index;
        loop invariant \forall integer i; 0 <= i < index ==> Hs[i] > 0 && Hs[i] <= 1000000000;
        loop invariant max_h >= 0;
        loop assigns max_h, res, index;
        loop variant N - index;
    */
    while (index < N) {
        uint64_t H = Hs[index];
        
        //@ assert H > 0 && H <= 1000000000;
        
        if (max_h <= H) {
            max_h = H;
            res += 1;
        }
        
        //@ assert res <= index + 1;
        index += 1;
    }
    
    //@ assert res <= N;
    return res;
}

int main() {
    return 0;
}
