#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((314 * (r) * 2) / 100);
*/
int32_t func(uint32_t r)
{
    // Variable declarations at scope top
    int32_t pi;
    int32_t circumference;
    int32_t result;
    int32_t temp;
    int32_t count;
    
    pi = 314;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert 1 <= r * 2 <= 200;
    //@ assert 314 * (r * 2) <= 62800;
    
    circumference = ((int32_t)(r * 2)) * pi;
    result = 0;
    temp = circumference;
    count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant circumference == ((int32_t)(r * 2)) * pi;
        loop invariant result == 0;
        loop invariant temp >= 0;
        loop invariant temp == circumference - count * 100;
        loop invariant count >= 0;
        loop invariant count <= circumference / 100;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 100)
    {
        temp -= 100;
        count += 1;
    }
    
    result = count;
    
    //@ assert result == ((314 * (r) * 2) / 100);
    return result;
}

int main()
{
    return 0;
}
