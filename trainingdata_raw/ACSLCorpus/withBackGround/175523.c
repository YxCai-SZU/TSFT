#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_range(uint32_t* arr, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 100;

    predicate processed_first_n(uint32_t* arr, integer n, uint32_t max_val, uint32_t min_val) =
        \forall integer k; 0 <= k < n ==> arr[k] <= max_val && arr[k] >= min_val;
*/

/*@
    lemma max_ge_min: \forall uint32_t max_val, uint32_t min_val; max_val >= min_val ==> \true;
*/

/*@
    requires \valid(numbers + (0 .. 2));
    requires valid_range(numbers, 3);
    ensures 0 <= \result <= 3;
    assigns \nothing;
*/
uint32_t func(uint32_t* numbers) {
    uint32_t max_value;
    uint32_t min_value;
    size_t index;
    uint32_t count;
    uint32_t mid_value;
    size_t index2;
    uint32_t count2;

    max_value = numbers[0];
    min_value = numbers[0];
    index = 1;
    count = 0;

    /*@
        loop invariant 0 <= index <= 3;
        loop invariant 0 <= count <= (uint32_t)index;
        loop invariant valid_range(numbers, 3);
        loop invariant processed_first_n(numbers, index, max_value, min_value);
        loop invariant max_value >= min_value;
        loop assigns index, max_value, min_value, count;
        loop variant 3 - index;
    */
    while (index < 3) {
        uint32_t value = numbers[index];
        //@ assert 1 <= value <= 100;
        
        if (value < min_value) {
            min_value = value;
            count += 1;
        }
        //@ assert max_value >= min_value;
        
        if (value > max_value) {
            max_value = value;
        }
        //@ assert max_value >= min_value;
        
        index += 1;
    }

    //@ assert max_value >= min_value;
    mid_value = max_value - (max_value - min_value) / 2;
    index2 = 0;
    count2 = 0;

    /*@
        loop invariant 0 <= index2 <= 3;
        loop invariant 0 <= count2 <= (uint32_t)index2;
        loop invariant valid_range(numbers, 3);
        loop invariant processed_first_n(numbers, index2, max_value, min_value);
        loop invariant max_value >= min_value;
        loop assigns index2, count2;
        loop variant 3 - index2;
    */
    while (index2 < 3) {
        uint32_t value = numbers[index2];
        //@ assert 1 <= value <= 100;
        
        if (value <= mid_value) {
            count2 += 1;
        }
        index2 += 1;
    }

    if (count2 == 0) {
        //@ assert 0 <= count <= 3;
        return count;
    } else {
        //@ assert 0 <= count2 <= 3;
        return count2;
    }
}
