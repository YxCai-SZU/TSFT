#include <stdbool.h>
#include <stdint.h>

/*@
    requires \valid(numbers + (0..2));
    requires ((3) == 3 &&
    (numbers)[0] >= -100 &&
    (numbers)[1] <= 100 &&
    (numbers)[2] >= -100 && (numbers)[2] <= 100);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= 3;
*/
int32_t func(int64_t numbers[3]) {
    int32_t count = 0;
    int32_t index = 0;
    
    /*@
        loop invariant 0 <= index <= 3;
        loop invariant 0 <= count <= index;
        loop invariant \forall integer k; 0 <= k < index ==> (numbers[k] == 0 ==> count >= 1);
        loop invariant ((3) == 3 &&
    (numbers)[0] >= -100 &&
    (numbers)[1] <= 100 &&
    (numbers)[2] >= -100 && (numbers)[2] <= 100);
        loop assigns count, index;
        loop variant 3 - index;
    */
    while (index < 3) {
        int64_t value = numbers[index];
        bool is_zero = false;
        
        if (value == 0) {
            is_zero = true;
        }
        
        if (is_zero) {
            //@ assert value == 0 ==> is_zero == true;
            count += 1;
        }
        
        //@ assert \forall integer k; 0 <= k < index ==> (numbers[k] == 0 ==> count >= 1);
        index += 1;
    }
    
    //@ assert count >= 0 && count <= 3;
    return count;
}
