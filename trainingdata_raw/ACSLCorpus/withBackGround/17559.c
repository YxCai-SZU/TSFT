#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_numbers(integer n, uint32_t *numbers) =
    n > 0 &&
    \valid(numbers + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> numbers[i] > 0 && numbers[i] <= 100;
*/

/*@ predicate count_invariant(integer n, uint32_t *numbers, integer index, integer count) =
    0 <= index <= n &&
    0 <= count <= index;
*/

/*@ lemma count_non_negative:
    \forall integer n, uint32_t *numbers, integer index, integer count;
    count_invariant(n, numbers, index, count) ==> count >= 0;
*/

/*@
    requires n > 0;
    requires \valid(numbers + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> numbers[i] > 0 && numbers[i] <= 100;
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
uint32_t func(uint32_t n, uint32_t *numbers) {
    uint32_t count = 0;
    uint32_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        uint32_t value = numbers[index];
        
        //@ assert value > 0 && value <= 100;
        
        if ((value & 1) == 1 || (value & 1) == 0) {
            count = count + 1;
        }
        
        //@ assert count <= index + 1;
        index = index + 1;
    }
    
    //@ assert count <= n;
    return count;
}
