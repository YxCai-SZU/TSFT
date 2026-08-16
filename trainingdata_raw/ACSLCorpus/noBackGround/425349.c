#include <stdbool.h>
#include <stddef.h>

/*@ requires k >= 1 && k <= 500;
    requires \valid(heights + (0..len-1));
    requires ((len) >= 1 && (len) <= 100000 &&
      \forall integer i; 0 <= i < (len) ==> 1 <= (heights)[i] && (heights)[i] <= 500);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= len;
*/
int func(int k, int *heights, size_t len) {
    int ans = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant ((ans) >= 0 && (ans) <= (index) && (index) <= (len));
        loop invariant index > 0 ==> 
            \forall integer i; 0 <= i < index ==> 1 <= heights[i] && heights[i] <= 500;
        loop invariant k >= 1 && k <= 500;
        loop assigns ans, index;
        loop variant len - index;
    */
    while (index < len) {
        int h = heights[index];
        //@ assert 1 <= h && h <= 500;
        if (h >= k) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}
