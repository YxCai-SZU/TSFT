#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * 31415 * (r)) / 10000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t result;
    int64_t temp;
    int64_t count;
    
    pi = 31415;
    result = 0;
    temp = 2 * pi * r;
    count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 31415;
        loop invariant temp >= 0;
        loop invariant temp == 2 * pi * r - 10000 * count;
        loop invariant count >= 0;
        loop invariant count <= (2 * pi * r) / 10000;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 10000)
    {
        temp -= 10000;
        count += 1;
    }
    
    result = count;
    
    //@ assert result == (2 * 31415 * r) / 10000;
    
    return result;
}

int main()
{
    return 0;
}
