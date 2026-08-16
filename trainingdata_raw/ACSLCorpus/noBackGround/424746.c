#include <stdint.h>

/*@
    requires ((a) >= 1 && (a) <= 100 &&
        (b) >= 1 && (b) <= 100 &&
        (b) % 2 == 0);
    ensures \result == ((a) + (((b)) / 2));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t half_b = 0;
    int64_t i = 0;
    int64_t temp_b = b;
    int64_t result = 0;

    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant 0 <= half_b <= b/2;
        loop invariant temp_b + 2 * half_b == b;
        loop assigns half_b, temp_b;
        loop variant temp_b;
    */
    while (temp_b >= 2)
    {
        half_b += 1;
        temp_b -= 2;
    }

    //@ assert half_b == b / 2;
    
    result = a + half_b;
    
    //@ assert result == a + (b / 2);
    
    return result;
}
