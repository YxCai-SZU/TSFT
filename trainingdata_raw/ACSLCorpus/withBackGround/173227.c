#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(int64_t* arr, size_t n) =
        n >= 2 && n <= 100000 &&
        \forall size_t j; 0 <= j < n ==> 1 <= arr[j] && arr[j] <= n;

    logic integer array_length{L}(int64_t* arr, size_t n) = n;

    lemma index_bounds:
        \forall int64_t* arr, size_t n, size_t i;
        valid_array(arr, n) && 0 <= i < n ==> 1 <= arr[i] && arr[i] <= n;
*/

/*@
    requires n >= 2 && n <= 100000;
    requires \valid(aa + (0 .. n-1));
    requires valid_array(aa, n);
    assigns \nothing;
    ensures \result >= -1;
    ensures \result <= (long)n - 1;
*/
int64_t func(size_t n, int64_t* aa) {
    int64_t counter = 0;
    size_t i = 1;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 1 <= i <= index + 1;
        loop invariant 0 <= counter <= (long)index;
        loop invariant valid_array(aa, n);
        loop assigns counter, i, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (i != aa[index]) {
            counter += 1;
        } else {
            i += 1;
        }
        index += 1;
    }
    
    if (counter == (int64_t)n) {
        return -1;
    } else {
        return counter;
    }
}
