#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(unsigned int *arr, size_t len) =
        len >= 1 && len <= 100 &&
        \forall size_t i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= 100;

    logic integer array_length(unsigned int *arr, size_t len) = (integer)len;

    lemma max_bounds:
        \forall unsigned int *arr, size_t len, unsigned int max;
        valid_array(arr, len) && max >= 0 && max <= 100 ==>
        (max >= 0 && max <= 100);

    lemma count_bounds:
        \forall unsigned int *arr, size_t len, unsigned int count, size_t idx;
        valid_array(arr, len) && 0 <= idx <= len && count >= 0 && count <= idx ==>
        (count >= 0 && count <= len);
*/

/*@
    requires \valid_read(numbers + (0 .. len-1));
    requires valid_array(numbers, len);
    ensures \result >= 0 && \result <= 100;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
unsigned int func(unsigned int *numbers, size_t len) {
    unsigned int max = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant valid_array(numbers, len);
        loop invariant max >= 0 && max <= 100;
        loop invariant \forall size_t k; 0 <= k < len ==> numbers[k] >= 1 && numbers[k] <= 100;
        loop assigns max, index;
        loop variant len - index;
    */
    while (index < len) {
        unsigned int a = numbers[index];
        //@ assert a >= 1 && a <= 100;
        max = (a > max) ? a : max;
        index++;
    }
    
    unsigned int count = 0;
    index = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant valid_array(numbers, len);
        loop invariant count >= 0 && count <= index;
        loop invariant max >= 0 && max <= 100;
        loop invariant \forall size_t k; 0 <= k < len ==> numbers[k] >= 1 && numbers[k] <= 100;
        loop assigns count, index;
        loop variant len - index;
    */
    while (index < len) {
        unsigned int a = numbers[index];
        //@ assert a >= 1 && a <= 100;
        if (max == a) {
            count++;
        }
        index++;
    }
    
    //@ assert count >= 0 && count <= len;
    if (count == 1) {
        return 1;
    } else {
        return 0;
    }
}
