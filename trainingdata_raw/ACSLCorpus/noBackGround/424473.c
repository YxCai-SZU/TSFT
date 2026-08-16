#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result <= 40000;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t p;
    int32_t result;
    uint32_t temp_p;
    uint32_t count;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    
    // Ensure no overflow in a * b
    //@ assert a * b <= 10000;
    
    p = a * b;
    result = 0;
    temp_p = p;
    count = 0;

    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant p == a * b;
        loop invariant temp_p >= 0;
        loop invariant count >= 0;
        loop invariant p == temp_p + 2 * count;
        loop assigns temp_p, count;
        loop variant temp_p;
    */
    while (temp_p >= 2)
    {
        temp_p -= 2;
        count += 1;
    }
    
    result = (int32_t)count;
    
    //@ assert result >= 0;
    
    if (result > 0) {
        result -= 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= 40000;
    
    return result;
}
