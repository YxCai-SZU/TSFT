#include <stdbool.h>
#include <limits.h>

/*@ predicate is_min_or_max(integer x) = x == INT_MIN || x == INT_MAX; */

/*@ predicate element_in_range{L}(int *arr, integer len, integer low, integer high, integer val) =
    \exists integer i; low <= i < high && \at(arr[i], L) == val; */

/*@ lemma exists_in_full_array:
    \forall int *arr, integer len, integer val;
      element_in_range(arr, len, 0, len, val) ==> element_in_range(arr, len, 0, len, val); */

/*@ requires \valid(v+(0..2));
    requires \forall integer i; 0 <= i < 3 ==> is_min_or_max(v[i]);
    ensures is_min_or_max(\result);
    ensures element_in_range(v, 3, 0, 3, \result);
    assigns \nothing;
 */
int func(int v[3]) {
    int vec[3];
    int len;
    int max;
    int i;
    
    // Copy input array
    vec[0] = v[0];
    vec[1] = v[1];
    vec[2] = v[2];
    len = 3;
    max = vec[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant len == 3;
        loop invariant \forall integer j; 0 <= j < i ==> is_min_or_max(vec[j]);
        loop invariant \forall integer j; 0 <= j < len ==> is_min_or_max(vec[j]);
        loop invariant element_in_range{Here}(&vec[0], len, 0, i, max);
        loop invariant is_min_or_max(max);
        loop invariant i > 0;
        loop assigns i, max;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (vec[i] > max) {
            max = vec[i];
        }
        i = i + 1;
    }
    
    //@ assert element_in_range{Here}(&vec[0], len, 0, len, max);
    return max;
}

int main() {
    return 0;
}
