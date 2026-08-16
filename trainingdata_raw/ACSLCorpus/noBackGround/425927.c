#include <stdbool.h>
#include <stddef.h>

/*@ requires N >= 1 && N <= 20;
    requires \valid(H + (0 .. N-1));
    requires \forall integer i; 0 <= i < N ==> H[i] >= 1 && H[i] <= 100;
    ensures \result >= 0 && \result <= N;
*/
long func(size_t N, const long *H) {
    long result = 0;
    long acc = 0;
    bool flag = true;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= N;
        loop invariant result >= 0;
        loop invariant result <= i;
        loop invariant \valid(H + (0 .. N-1));
        loop invariant \forall integer j; 0 <= j < N ==> H[j] >= 1 && H[j] <= 100;
        loop assigns i, result, acc, flag;
        loop variant N - i;
    */
    while (i < N) {
        long elem = H[i];
        
        if (flag) {
            acc = elem;
            result += 1;
            flag = false;
        } else if (acc <= elem) {
            acc = elem;
            result += 1;
        }
        
        //@ assert ((result) >= 0 && (result) <= (i+1));
        i += 1;
    }
    
    //@ assert ((result) >= 0 && (result) <= (N));
    return result;
}
