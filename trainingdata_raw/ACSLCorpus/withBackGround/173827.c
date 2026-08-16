#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(unsigned long long *arr, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < len ==> (arr[i] == i + 1 || arr[i] == 0) &&
    \exists integer i; 0 <= i < len && arr[i] == 0;
*/

/*@ predicate zero_in_range(unsigned long long *arr, integer len, integer start) =
    \exists integer j; start <= j < len && arr[j] == 0;
*/

/*@ predicate no_zero_before(unsigned long long *arr, integer end) =
    \forall integer j; 0 <= j < end ==> arr[j] != 0;
*/

/*@
    requires \valid_read(arr + (0 .. 4));
    requires valid_array(arr, 5);
    ensures \result > 0 && \result <= 5;
    ensures zero_in_range(arr, 5, 0);
*/
unsigned long long func(unsigned long long *arr) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant valid_array(arr, 5);
        loop invariant no_zero_before(arr, i);
        loop invariant zero_in_range(arr, 5, i);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (arr[i] == 0) {
            //@ assert arr[i] == 0;
            //@ assert zero_in_range(arr, 5, i);
            return (unsigned long long)(i + 1);
        }
        //@ assert arr[i] != 0;
        i++;
    }
    return 0;
}
