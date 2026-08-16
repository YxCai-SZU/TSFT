#include <stddef.h>
#include <stdbool.h>

/*@ requires n >= 1 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n;
    requires \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
    assigns \nothing;
    ensures \result >= 1 && \result <= n;
*/
size_t func(size_t n, int *p) {
    size_t ans = 1;
    int min_bound = p[0];
    size_t i = 1;
    
    /*@ loop invariant 1 <= i <= n;
        loop invariant 1 <= ans <= i;
        loop invariant min_bound <= p[0];
        loop invariant \forall integer k; 0 <= k < i ==> p[k] >= 1 && p[k] <= n;
        loop invariant \forall integer k, j; 0 <= k < j < i ==> p[k] != p[j];
        loop invariant \forall integer k; 0 <= k < n ==> p[k] >= 1 && p[k] <= n;
        loop invariant \forall integer k, j; 0 <= k < j < n ==> p[k] != p[j];
        loop invariant ans <= i + 1;
        loop assigns i, ans, min_bound;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert (1 <= (i) && (i) <= (n) &&     1 <= (ans) && (ans) <= (i) &&     (min_bound) <= (p)[0] &&     \forall integer k; 0 <= k < (i) ==> (p)[k] >= 1 && (p)[k] <= (n) &&     \forall integer k, j; 0 <= k < j < (i) ==> (p)[k] != (p)[j] &&     \forall integer k; 0 <= k < (n) ==> (p)[k] >= 1 && (p)[k] <= (n) &&     \forall integer k, j; 0 <= k < j < (n) ==> (p)[k] != (p)[j] &&     (ans) <= (i) + 1);
        
        if (p[i] <= min_bound) {
            min_bound = p[i];
            ans += 1;
        }
        i += 1;
        
        //@ assert (1 <= (i) && (i) <= (n) &&     1 <= (ans) && (ans) <= (i) &&     (min_bound) <= (p)[0] &&     \forall integer k; 0 <= k < (i) ==> (p)[k] >= 1 && (p)[k] <= (n) &&     \forall integer k, j; 0 <= k < j < (i) ==> (p)[k] != (p)[j] &&     \forall integer k; 0 <= k < (n) ==> (p)[k] >= 1 && (p)[k] <= (n) &&     \forall integer k, j; 0 <= k < j < (n) ==> (p)[k] != (p)[j] &&     (ans) <= (i) + 1);
    }
    
    //@ assert ans >= 1 && ans <= n;
    return ans;
}
