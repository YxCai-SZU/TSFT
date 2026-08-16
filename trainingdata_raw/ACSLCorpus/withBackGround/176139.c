#include <stdbool.h>
#include <stdint.h>

/*@
    predicate heights_in_range(unsigned int *heights, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= heights[i] <= 500;

    predicate ans_property(unsigned int ans, unsigned int *heights, integer n, unsigned int k) =
        \forall integer i; 0 <= i < n ==> (heights[i] >= k ==> ans > 0);
*/

/*@
    requires n >= 1 && n <= 100000;
    requires k >= 1 && k <= 500;
    requires \valid(heights + (0 .. n-1));
    requires heights_in_range(heights, n);
    assigns \nothing;
    ensures \result <= n;
    ensures ans_property(\result, heights, n, k);
*/
unsigned int func(unsigned int n, unsigned int k, unsigned int *heights) {
    unsigned int ans = 0;
    unsigned int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (heights[j] >= k ==> ans > 0);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (heights[i] >= k) {
            ans = ans + 1;
        }
        i = i + 1;
    }
    return ans;
}
