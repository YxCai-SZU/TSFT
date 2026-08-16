#include <stdint.h>
/*@
    predicate valid_input(integer x, integer y) =
        1 <= x <= 205 && 1 <= y <= 205;

    logic integer distance(integer x, integer y, integer i) =
        (x > i ? x - i : i - x) + (y > i ? y - i : i - y) + 1;

    lemma ans_bound:
        \forall integer x, y, i, ans;
        0 <= x <= 204 && 0 <= y <= 204 && 0 <= i < 202 && ans <= 1000000 ==>
        distance(x, y, i) <= 1000000;
*/

/*@
    requires valid_input(x, y);
    ensures \result <= 1000000;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y) {
    uint32_t ans = 1000000;
    uint32_t x_local = x - 1;
    uint32_t y_local = y - 1;
    uint32_t i = 0;

    /*@
        loop invariant 0 <= i <= 202;
        loop invariant 0 <= x_local <= 204;
        loop invariant 0 <= y_local <= 204;
        loop invariant ans <= 1000000;
        loop invariant 1 <= x_local + 1 <= 205;
        loop invariant 1 <= y_local + 1 <= 205;
        loop assigns i, ans;
        loop variant 202 - i;
    */
    while (i < 202) {
        uint32_t dist = 0;
        
        if (x_local > i) {
            dist += (x_local - i);
        } else {
            dist += (i - x_local);
        }
        
        if (y_local > i) {
            dist += (y_local - i);
        } else {
            dist += (i - y_local);
        }
        
        dist += 1;
        
        //@ assert dist == distance(x_local, y_local, i);
        //@ assert dist <= 1000000;
        
        if (dist < ans) {
            ans = dist;
        }
        
        i++;
    }
    
    return ans;
}
