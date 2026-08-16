#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100000 &&
        1 <= (k) && (k) <= 500 &&
        \valid((hs) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (hs)[i] && (hs)[i] <= 500);
    assigns \nothing;
    ensures 0 <= \result && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (k <= hs[i] ==> \result > 0);
*/
size_t func(size_t n, size_t k, const size_t *hs) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i && i <= n;
        loop invariant 0 <= count && count <= i;
        loop invariant \forall integer j; 0 <= j < n ==> 1 <= hs[j] && hs[j] <= 500;
        loop invariant \forall integer j; 0 <= j < i ==> (k <= hs[j] ==> count > 0);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i && i < n;
        if (hs[i] >= k) {
            //@ assert k <= hs[i];
            count += 1;
            //@ assert count > 0;
        }
        i += 1;
        //@ assert \forall integer j; 0 <= j < i ==> (k <= hs[j] ==> count > 0);
    }
    return count;
}
