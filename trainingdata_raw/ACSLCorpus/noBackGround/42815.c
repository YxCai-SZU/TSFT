#include <stdbool.h>
#include <stddef.h>

/*@ requires N >= 1 && N <= 100000;
    requires \valid(Hs + (0 .. N-1));
    requires ((N) >= 1 && (N) <= 100000 &&
        \forall size_t i; 0 <= i < (N) ==> (Hs)[i] >= 1 && (Hs)[i] <= 1000000000);
    ensures \result >= 0 && \result <= N - 1;
    assigns \nothing;
*/
unsigned int func(size_t N, unsigned int *Hs) {
    unsigned int cur_h;
    unsigned int res;
    size_t i;
    
    cur_h = Hs[0];
    res = 0;
    i = 1;
    
    /*@ loop invariant (1 <= (i) && (i) <= (N) &&
        (((N)) >= 1 && ((N)) <= 100000 &&
        \forall size_t i; 0 <= i < ((N)) ==> ((Hs))[i] >= 1 && ((Hs))[i] <= 1000000000) &&
        (res) >= 0 && (res) <= (i) - 1);
        loop invariant cur_h >= 1 && cur_h <= 1000000000;
        loop invariant \forall size_t j; 0 <= j < i ==> Hs[j] <= cur_h;
        loop assigns i, res, cur_h;
        loop variant N - i;
    */
    while (i < N) {
        //@ assert i >= 1 && i <= N;
        
        if (Hs[i] >= cur_h) {
            //@ assert Hs[i] >= cur_h;
            res = res + 1;
        }
        
        //@ assert Hs[i] >= 1 && Hs[i] <= 1000000000;
        if (Hs[i] > cur_h) {
            cur_h = Hs[i];
        }
        
        i = i + 1;
    }
    
    //@ assert i == N;
    //@ assert res <= N - 1;
    return res;
}
