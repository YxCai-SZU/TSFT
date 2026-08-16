#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/*@
    predicate is_even(integer k) = k % 2 == 0;
    predicate is_between_inclusive(integer a, integer b, integer c) = a <= b && b <= c;
*/

/*@
    lemma test_is_even:
        is_even(4) && !is_even(7);
    
    lemma test_is_between_inclusive:
        is_between_inclusive(4, 7, 9) && !is_between_inclusive(9, 7, 4);
*/

/*@
    requires 1 <= k <= 100;
    requires 0 <= x <= 100;
    ensures \result != \null;
    ensures \valid(\result + (0..(2*k-2)));
    ensures \forall integer i; 0 <= i < 2*k-1 ==> \result[i] == i + x - k + 1;
    assigns \nothing;
*/
long long* func(long long k, long long x) {
    long long* ans;
    long long i;
    long long* tmp;
    size_t ans_len;
    
    ans = (long long*)malloc((2*k-1) * sizeof(long long));
    if (ans == NULL) {
        return NULL;
    }
    
    i = x - k + 1;
    ans_len = 0;
    
    /*@
        loop invariant x - k + 1 <= i <= x + k;
        loop invariant ans_len == (size_t)(i - (x - k + 1));
        loop invariant \forall integer j; 0 <= j < ans_len ==> ans[j] == j + x - k + 1;
        loop invariant 1 <= k <= 100;
        loop invariant 0 <= x <= 100;
        loop invariant ans_len <= 2*k - 1;
        loop assigns i, ans[0..(2*k-2)], ans_len;
        loop variant x + k - i;
    */
    while (i < x + k) {
        //@ assert ans_len < 2*k - 1;
        ans[ans_len] = i;
        ans_len++;
        i++;
        //@ assert ans_len == (size_t)(i - (x - k + 1));
    }
    
    //@ assert ans_len == 2*k - 1;
    return ans;
}

/*@
    requires 1 <= k <= 100;
    requires 0 <= x <= 100;
    requires ans != \null;
    requires \valid(ans + (0..(2*k-2)));
    requires \forall integer i; 0 <= i < 2*k-1 ==> ans[i] == i + x - k + 1;
    assigns \nothing;
*/
void proof_func(long long k, long long x, long long* ans) {
    // Add any necessary proofs here
}

int main() {
    return 0;
}
