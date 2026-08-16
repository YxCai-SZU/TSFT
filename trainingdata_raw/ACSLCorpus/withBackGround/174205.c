#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(int* arr, integer n) =
    n >= 1 && n <= 200000 &&
    \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000000000;
*/

/*@ predicate count_invariant(int* arr, integer n, integer index, integer count) =
    index >= 0 && index <= n &&
    count >= 0 && count <= index &&
    count <= n &&
    (index > 0 ==> \forall integer i; 0 <= i < index ==> arr[i] >= 1 && arr[i] <= 1000000000);
*/

/*@ lemma count_bound: \forall integer n, integer count;
    count >= 0 && count <= n ==> count <= n;
*/

/*@ requires n >= 1 && n <= 200000;
    requires \valid(a + (0 .. n-1));
    requires is_valid_array(a, n);
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
size_t func(size_t n, int* a) {
    size_t count = 0;
    size_t index = 0;
    
    /*@ loop invariant count_invariant(a, n, index, count);
        loop invariant n >= 1 && n <= 200000;
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert index >= 0 && index < n;
        if (a[index] & 1) {
            //@ assert count >= 0 && count < n;
            count++;
            //@ assert count >= 1 && count <= n;
        }
        index++;
        //@ assert count_invariant(a, n, index, count);
    }
    //@ assert count_invariant(a, n, index, count);
    //@ assert count >= 0 && count <= n;
    return count;
}
