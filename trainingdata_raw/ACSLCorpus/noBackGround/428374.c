#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    ensures \result == (6283185307 * a) / 1000000000;
*/
int64_t func(int64_t a)
{
    int64_t multiplier;
    int64_t result;
    int64_t temp;
    int64_t divisor;
    int64_t count;
    
    multiplier = 6283185307;
    result = 0;
    //@ assert 1 <= a * multiplier <= 100 * 6283185307;
    temp = a * multiplier;
    divisor = 1000000000;
    count = 0;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant multiplier == 6283185307;
        loop invariant divisor == 1000000000;
        loop invariant temp >= 0;
        loop invariant temp == a * multiplier - count * divisor;
        loop invariant count >= 0;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        count += 1;
    }
    result = count;
    
    //@ assert result * divisor + temp == a * multiplier;
    //@ assert temp < divisor;
    
    return result;
}

int main()
{
    return 0;
}
