#include <stdbool.h>
#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000 && 1 <= (k) <= 500);
    requires \valid(h + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] <= 500);
    assigns \nothing;
    ensures 0 <= \result <= n;
    ensures (\forall integer i; 0 <= i < (n) ==> ((h)[i] >= (k) ==> (\result) >= 1));
*/
uint64_t func(uint64_t n, uint64_t k, uint64_t *h) {
    uint64_t count = 0;
    uint64_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (h[j] >= k ==> count >= 1);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] <= 500);
        loop invariant (1 <= (n) <= 100000 && 1 <= (k) <= 500);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= k) {
            count = count + 1;
        }
        i = i + 1;
    }
    
    //@ assert 0 <= count <= n;
    //@ assert (\forall integer i; 0 <= i < (n) ==> ((h)[i] >= (k) ==> (count) >= 1));
    return count;
}
