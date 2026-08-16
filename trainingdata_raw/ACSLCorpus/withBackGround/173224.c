#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate x_in_range(integer x) = 1 <= x && x <= 1010;
    
    logic integer div_100_8(integer x) = (x * 8) / 100;
    logic integer div_100_10(integer x) = (x * 10) / 100;
    
    lemma main_loop_decreases:
        \forall integer x; 1 <= x < 1010 ==> 1010 - (x + 1) < 1010 - x;
    
    lemma inner_loop1_decreases:
        \forall integer temp_ax; temp_ax >= 100 ==> temp_ax - 100 < temp_ax;
    
    lemma inner_loop2_decreases:
        \forall integer temp_bx; temp_bx >= 100 ==> temp_bx - 100 < temp_bx;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> div_100_8(\result) == a && div_100_10(\result) == b;
*/
int64_t func(uint64_t a, uint64_t b)
{
    uint64_t x;
    uint64_t ax;
    uint64_t bx;
    uint64_t aa;
    uint64_t bb;
    uint64_t temp_ax;
    uint64_t temp_bx;
    
    x = 1;
    
    /*@
        loop invariant x_in_range(x);
        loop invariant a_in_range(a) && b_in_range(b);
        loop assigns x, ax, bx, aa, bb, temp_ax, temp_bx;
        loop variant 1010 - x;
    */
    while (x < 1010)
    {
        //@ assert x * 8 <= 1010 * 8;
        //@ assert x * 10 <= 1010 * 10;
        
        ax = x * 8;
        bx = x * 10;
        aa = 0;
        bb = 0;
        temp_ax = ax;
        
        /*@
            loop invariant 0 <= temp_ax;
            loop invariant 0 <= aa;
            loop invariant temp_ax + aa * 100 == x * 8;
            loop invariant a_in_range(a) && b_in_range(b);
            loop assigns aa, temp_ax;
            loop variant temp_ax;
        */
        while (temp_ax >= 100)
        {
            aa += 1;
            temp_ax -= 100;
        }
        
        temp_bx = bx;
        
        /*@
            loop invariant 0 <= temp_bx;
            loop invariant 0 <= bb;
            loop invariant temp_bx + bb * 100 == x * 10;
            loop invariant a_in_range(a) && b_in_range(b);
            loop assigns bb, temp_bx;
            loop variant temp_bx;
        */
        while (temp_bx >= 100)
        {
            bb += 1;
            temp_bx -= 100;
        }
        
        if (aa == a && bb == b)
        {
            return (int64_t)x;
        }
        
        x += 1;
    }
    
    return -1;
}

int main()
{
    return 0;
}
