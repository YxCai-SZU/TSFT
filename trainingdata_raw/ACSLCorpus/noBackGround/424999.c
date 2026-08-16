#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * (r) * (31415)) / 10000);
*/
int32_t func(int32_t r)
{
    int32_t pi = 31415;
    int32_t circumference = 0;
    int32_t temp = 2 * r * pi;
    int32_t count = 0;
    
    //@ assert temp == 2 * r * (31415);
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant temp >= 0;
        loop invariant temp == 2 * r * (31415)- 10000 * count;
        loop invariant count <= (2 * r * (31415)) / 10000;
        loop invariant circumference == count;
        loop assigns circumference, temp, count;
    */
    while (temp >= 10000) {
        //@ assert temp >= 10000;
        circumference += 1;
        temp -= 10000;
        count += 1;
        //@ assert temp == 2 * r * (31415)- 10000 * count;
    }
    
    //@ assert circumference == ((2 * (r) * (31415)) / 10000);
    return circumference;
}
