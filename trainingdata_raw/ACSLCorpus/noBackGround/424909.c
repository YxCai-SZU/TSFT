#include <stddef.h>
#include <stdbool.h>

/*@ requires 1 <= k <= 500;
    requires \valid(heights + (0..7));
    requires (\forall integer i; 0 <= i < 8 ==> 1 <= (heights)[i] <= 500);
    ensures \result >= 0 && \result <= 8;
    ensures ((\result) == 0 || (\result) == 1 || (\result) == 2 || (\result) == 3 || (\result) == 4 ||
      (\result) == 5 || (\result) == 6 || (\result) == 7 || (\result) == 8);
*/
size_t func(size_t k, size_t heights[8]) {
    size_t ans = 0;
    size_t index = 0;
    
    //@ assert 1 <= k <= 500;
    
    /*@ loop invariant 0 <= index <= 8;
        loop invariant ans >= 0;
        loop invariant ans <= index;
        loop invariant index > 0 ==> ((ans) == 0 || (ans) == 1 || (ans) == 2 || (ans) == 3 || (ans) == 4 ||
      (ans) == 5 || (ans) == 6 || (ans) == 7 || (ans) == 8);
        loop invariant \forall integer j; 0 <= j < index ==> 
            (heights[j] >= k ==> ans > 0);
        loop assigns ans, index;
    */
    while (index < 8) {
        size_t h = heights[index];
        
        //@ assert 1 <= h <= 500;
        
        if (h >= k) {
            ans += 1;
        }
        
        index += 1;
    }
    
    //@ assert ((ans) == 0 || (ans) == 1 || (ans) == 2 || (ans) == 3 || (ans) == 4 ||       (ans) == 5 || (ans) == 6 || (ans) == 7 || (ans) == 8);
    return ans;
}
