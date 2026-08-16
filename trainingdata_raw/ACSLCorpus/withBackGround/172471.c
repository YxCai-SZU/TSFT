#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    
    predicate vec_even_range(unsigned int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> is_even(arr[i]);
*/

/*@
    requires \valid_read(vec + (0..len-1));
    requires len >= 0;
    requires \valid(result_arr + (0..len-1));
    assigns result_arr[0..len-1];
    ensures \result <= len;
    ensures vec_even_range(result_arr, \result);
*/
unsigned int filter_evens(const unsigned int *vec, unsigned int len, unsigned int *result_arr) {
    unsigned int result_len = 0;
    unsigned int index = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant 0 <= result_len <= index;
        loop invariant vec_even_range(result_arr, result_len);
        loop assigns index, result_len, result_arr[0..len-1];
        loop variant len - index;
    */
    while (index < len) {
        unsigned int x = vec[index];
        if (x % 2 == 0) {
            //@ assert is_even(x);
            result_arr[result_len] = x;
            result_len++;
        }
        index++;
    }
    return result_len;
}
