#include <stdint.h>

/*@
    requires (1 <= (x) <= 205 && 1 <= (y) <= 205);
    ensures \result <= 1000000;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y) {
    uint32_t ans = 1000000;
    uint32_t i = 1;
    uint32_t j;

    /*@
        loop invariant 1 <= i <= 206;
        loop invariant ans <= 1000000;
        loop invariant (1 <= (x) <= 205 && 1 <= (y) <= 205);
        loop assigns i, j, ans;
        loop variant 206 - i;
    */
    while (i < 206) {
        j = 1;
        /*@
            loop invariant 1 <= j <= 206;
            loop invariant ans <= 1000000;
            loop invariant (1 <= (x) <= 205 && 1 <= (y) <= 205);
            loop invariant 1 <= i <= 205;
            loop assigns j, ans;
            loop variant 206 - j;
        */
        while (j < 206) {
            int32_t diff1 = (i > x) ? (int32_t)(i - x) : (int32_t)(x - i);
            int32_t diff2 = (j > y) ? (int32_t)(j - y) : (int32_t)(y - j);
            int32_t dist_squared;
            uint32_t dist;

            //@ assert 0 <= diff1 <= 204;
            //@ assert 0 <= diff2 <= 204;
            //@ assert diff1 * diff1 <= 41616;
            //@ assert diff2 * diff2 <= 41616;
            //@ assert diff1 * diff1 + diff2 * diff2 <= 83232;

            dist_squared = diff1 * diff1 + diff2 * diff2;
            dist = (dist_squared < 0) ? (uint32_t)(-dist_squared) : (uint32_t)dist_squared;
            ans = (dist < ans) ? dist : ans;
            j++;
        }
        i++;
    }
    return ans;
}
