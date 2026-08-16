#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ requires ((3) == 3 &&
      \valid((numbers) + (0..(3)-1)) &&
      (1 <= ((numbers)[0]) <= 100) &&
      (1 <= ((numbers)[1]) <= 100) &&
      (1 <= ((numbers)[2]) <= 100));
    assigns \nothing;
    ensures 0 <= \result <= 3;
*/
int64_t func(int64_t numbers[3]) {
    int64_t sorted_numbers[3];
    int64_t result = 0;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    size_t len = 3;
    
    // Copy array
    sorted_numbers[0] = numbers[0];
    sorted_numbers[1] = numbers[1];
    sorted_numbers[2] = numbers[2];
    
    // Bubble sort outer loop
    i = 0;
    /*@ loop invariant 0 <= i <= 3;
        loop invariant (1 <= (sorted_numbers[0]) <= 100);
        loop invariant (1 <= (sorted_numbers[1]) <= 100);
        loop invariant (1 <= (sorted_numbers[2]) <= 100);
        loop assigns i, j, sorted_numbers[0], sorted_numbers[1], sorted_numbers[2];
        loop variant 3 - i;
    */
    while (i < len) {
        j = 0;
        /*@ loop invariant 0 <= j <= 2;
            loop invariant (1 <= (sorted_numbers[0]) <= 100);
            loop invariant (1 <= (sorted_numbers[1]) <= 100);
            loop invariant (1 <= (sorted_numbers[2]) <= 100);
            loop assigns j, sorted_numbers[0], sorted_numbers[1], sorted_numbers[2];
            loop variant 2 - j;
        */
        while (j < len - 1) {
            int64_t current = sorted_numbers[j];
            int64_t next = sorted_numbers[j + 1];
            if (current > next) {
                sorted_numbers[j] = next;
                sorted_numbers[j + 1] = current;
            }
            j++;
        }
        i++;
    }
    
    // Count duplicates
    k = 0;
    result = 0;
    /*@ loop invariant 0 <= k <= 2;
        loop invariant 0 <= result <= k;
        loop invariant (1 <= (sorted_numbers[0]) <= 100);
        loop invariant (1 <= (sorted_numbers[1]) <= 100);
        loop invariant (1 <= (sorted_numbers[2]) <= 100);
        loop assigns k, result;
        loop variant 2 - k;
    */
    while (k < len - 1) {
        //@ assert (1 <= (sorted_numbers[k]) <= 100);
        //@ assert (1 <= (sorted_numbers[k+1]) <= 100);
        if (sorted_numbers[k] == sorted_numbers[k + 1]) {
            result++;
        }
        k++;
    }
    
    //@ assert 0 <= result <= 3;
    return result;
}
