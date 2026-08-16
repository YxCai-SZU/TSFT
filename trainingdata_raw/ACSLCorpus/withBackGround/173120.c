#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(int *arr, integer n) =
    n >= 2 && n <= 100 &&
    \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 100;
*/

/*@ predicate count_invariant(int *arr, integer n, integer i, integer count) =
    i >= 0 && i <= n &&
    count >= 0 && count <= i &&
    is_valid_array(arr, n);
*/

/*@ lemma count_non_negative:
    \forall int *arr, integer n, i, count;
    count_invariant(arr, n, i, count) ==> count >= 0;
*/

/*@ lemma count_bounded:
    \forall int *arr, integer n, i, count;
    count_invariant(arr, n, i, count) ==> count <= n;
*/

/*@ requires 2 <= n && n <= 100;
    requires \valid(aa + (0 .. n-1));
    requires is_valid_array(aa, n);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *aa) {
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant count_invariant(aa, n, i, count);
        loop invariant i <= n;
        loop assigns count, i;
        loop variant n - i;
    */
    while (i < (size_t)n) {
        int a = aa[i];
        
        //@ assert a >= 1 && a <= 100;
        
        if (a & 1) {
            count = count + 1;
        }
        
        i = i + 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    
    return count;
}
