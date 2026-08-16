#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/*@
    requires (2 <= (n) <= 200000 &&
        \valid((a) + (0 .. (n)-2)) &&
        \forall integer j; 0 <= j < (n)-1 ==> 1 <= (a)[j] < j+1);
    ensures \valid(\result + (0 .. n-1));
    ensures \forall integer i; 0 <= i < n ==> 0 <= \result[i] <= n-1;
    assigns \nothing;
*/
uint64_t *func(size_t n, const uint64_t *a) {
    uint64_t *ans;
    size_t i;
    size_t k_index;
    uint64_t current_value;

    //@ assert 2 <= n <= 200000;
    //@ assert \valid(a + (0 .. n-2));
    //@ assert \forall integer j; 0 <= j < n-1 ==> 1 <= a[j] < j+1;

    ans = (uint64_t *)malloc(n * sizeof(uint64_t));
    if (ans == NULL) {
        return NULL;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \valid(ans + (0 .. n-1));
        loop invariant \forall integer k; 0 <= k < i ==> ans[k] == 0;
        loop assigns i, ans[0 .. n-1];
        loop variant n - i;
    */
    while (i < n) {
        ans[i] = 0;
        i = i + 1;
    }

    //@ assert \forall integer k; 0 <= k < n ==> ans[k] == 0;

    i = 0;
    /*@
        loop invariant 0 <= i <= n-1;
        loop invariant \valid(ans + (0 .. n-1));
        loop invariant \forall integer k; 0 <= k < n ==> 0 <= ans[k] <= i;
        loop assigns i, ans[0 .. n-1];
        loop variant (n-1) - i;
    */
    while (i < n - 1) {
        //@ assert 1 <= a[i] < i+1;
        
        k_index = (size_t)(a[i] - 1);
        //@ assert k_index < n;
        
        current_value = ans[k_index];
        ans[k_index] = current_value + 1;
        
        i = i + 1;
    }

    //@ assert \forall integer i; 0 <= i < n ==> 0 <= ans[i] <= n-1;
    return ans;
}
