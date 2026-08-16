#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_index(size_t i, size_t len) = 0 <= i < len;
    predicate is_odd_or_even(integer n) = n % 2 == 0 || n % 2 == 1;
    predicate loop_invariant(size_t i, size_t len, unsigned int *arr) =
        0 <= i <= len &&
        len > 0 &&
        (\forall integer j; 0 <= j < i ==> is_odd_or_even(arr[j]));
*/

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    ensures \result == true ==> (\forall integer i; 0 <= i < len ==> is_odd_or_even(arr[i]));
    assigns \nothing;
*/
bool check_odd_even(const unsigned int *arr, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant loop_invariant(i, len, arr);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        unsigned int num = arr[i];
        //@ assert is_odd_or_even(num);
        i++;
    }
    return true;
}
