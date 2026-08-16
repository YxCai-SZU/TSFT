#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_length(integer len) = 1 <= len <= 200000; */

/*@ predicate element_matches(long *arr, integer len, integer idx) =
    \valid(arr + (0..len-1)) &&
    0 <= idx < len &&
    (arr[idx] == idx + 1 || arr[idx] == idx - 1); */

/*@ predicate all_elements_match(long *arr, integer len) =
    \forall integer j; 0 <= j < len ==> element_matches(arr, len, j); */

/*@ lemma count_bound: \forall long *arr, integer len, integer i, integer cnt;
    is_valid_length(len) &&
    all_elements_match(arr, len) &&
    0 <= i <= len &&
    0 <= cnt <= i &&
    (\forall integer k; 0 <= k < i ==> (k + 1 == arr[k] ==> cnt >= 1)) ==>
    cnt >= 0 && cnt <= len; */

/*@
    requires \valid(x + (0..len-1));
    requires is_valid_length(len);
    requires all_elements_match(x, len);
    assigns \nothing;
    ensures 0 <= \result <= len;
*/
long func(long *x, size_t len) {
    long count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant is_valid_length(len);
        loop invariant all_elements_match(x, len);
        loop invariant \forall integer k; 0 <= k < i ==> (k + 1 == x[k] ==> count >= 1);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        long val = x[i];
        if ((long)i + 1 == val) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
