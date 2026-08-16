#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_params(integer n, integer k, int* h) =
    n >= 1 && n <= 100000 &&
    k >= 1 && k <= 500 &&
    \valid(h + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@ predicate ans_invariant(integer index, integer ans, integer n, integer k, int* h) =
    index <= n &&
    ans >= 0 &&
    ans <= index &&
    \forall integer i; 0 <= i < index ==> (h[i] >= k ==> ans >= 1);
*/

/*@ lemma loop_maintains_invariant:
    \forall integer n, integer k, int* h, integer index, integer ans;
    is_valid_params(n, k, h) && ans_invariant(index, ans, n, k, h) && index < n ==>
    (h[index] >= k ==> ans_invariant(index+1, ans+1, n, k, h)) &&
    (h[index] < k ==> ans_invariant(index+1, ans, n, k, h));
*/

/*@ requires is_valid_params(n, k, h);
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result >= 1);
    assigns \nothing;
*/
int func(int n, int k, int* h) {
    int ans = 0;
    int index = 0;
    
    /*@ loop invariant ans_invariant(index, ans, n, k, h);
        loop invariant is_valid_params(n, k, h);
        loop assigns ans, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert index < n;
        if (h[index] >= k) {
            ans += 1;
        }
        index += 1;
        //@ assert ans_invariant(index, ans, n, k, h);
    }
    return ans;
}
