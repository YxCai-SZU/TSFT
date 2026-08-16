#include <stdbool.h>
#include <stdint.h>

/*@ predicate heights_in_range(int *heights, integer len) =
      len == 5 &&
      \forall integer i; 0 <= i < len ==> 1 <= heights[i] <= 5;
*/

/*@ lemma heights_preserved:
      \forall int *heights, integer len;
      heights_in_range(heights, len) ==>
      \forall integer i; 0 <= i < len ==> 1 <= heights[i] <= 5;
*/

/*@ requires k > 0;
    requires \valid(heights + (0 .. 4));
    requires heights_in_range(heights, 5);
    assigns \nothing;
    ensures 0 <= \result <= 5;
    ensures heights_in_range(heights, 5);
*/
uint32_t func(uint32_t k, int *heights) {
    uint32_t cnt = 0;
    uint32_t index = 0;
    
    /*@ loop invariant 0 <= index <= 5;
        loop invariant cnt >= 0;
        loop invariant cnt <= index;
        loop invariant heights_in_range(heights, 5);
        loop assigns cnt, index;
        loop variant 5 - index;
    */
    while (index < 5) {
        //@ assert heights_in_range(heights, 5);
        uint32_t h = heights[index];
        if (h >= k) {
            cnt = cnt + 1;
        }
        index = index + 1;
    }
    
    //@ assert heights_in_range(heights, 5);
    return cnt;
}
