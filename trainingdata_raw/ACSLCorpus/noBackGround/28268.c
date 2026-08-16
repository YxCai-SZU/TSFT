#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= (x / 11) * 2 + 2;
*/
int64_t func(int64_t x)
{
    int64_t res;
    int64_t temp;
    int64_t cnt;
    
    res = 0;
    temp = x;
    cnt = 0;
    
    /*@
        loop invariant 1 <= x <= 1000000000;
        loop invariant 0 <= temp <= x;
        loop invariant 0 <= cnt <= x / 11;
        loop invariant temp == x - cnt * 11;
        loop assigns temp, cnt;
    */
    while (temp >= 11)
    {
        //@ assert temp >= 11;
        temp -= 11;
        cnt += 1;
    }
    
    res = cnt * 2;
    
    if (temp > 0)
    {
        //@ assert temp > 0;
        res += 1;
    }
    
    if (res < 0)
    {
        //@ assert res < 0;
        res = 0;
    }
    
    //@ assert res >= 0;
    return res;
}
