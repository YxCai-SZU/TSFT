#include <stdint.h>

/*@
    requires (1 <= (a) <= (b) <= 100);
    ensures \result == -1 || (\result >= 0 && \result < 1000000);
    ensures \result == -1 || 
            ((((\result) * 8) / 100) == a && (((\result) * 10) / 100) == b);
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t i = 0;
    int64_t eight_percent;
    int64_t ten_percent;
    int64_t temp;
    int64_t count;
    
    /*@
        loop invariant 0 <= i <= 1000000;
        loop invariant (1 <= (a) <= (b) <= 100);
        loop assigns i, eight_percent, ten_percent, temp, count;
        loop variant 1000000 - i;
    */
    while (i < 1000000)
    {
        // Calculate 8% of i
        temp = i * 8;
        count = 0;
        /*@
            loop invariant temp >= 0;
            loop invariant temp <= i * 8;
            loop invariant count >= 0;
            loop invariant count <= (i * 8) / 100;
            loop invariant (1 <= (a) <= (b) <= 100);
            loop invariant temp == i * 8 - count * 100;
            loop assigns temp, count;
            loop variant temp;
        */
        while (temp >= 100)
        {
            temp -= 100;
            count += 1;
        }
        eight_percent = count;
        
        // Calculate 10% of i
        temp = i * 10;
        count = 0;
        /*@
            loop invariant temp >= 0;
            loop invariant temp <= i * 10;
            loop invariant count >= 0;
            loop invariant count <= (i * 10) / 100;
            loop invariant (1 <= (a) <= (b) <= 100);
            loop invariant temp == i * 10 - count * 100;
            loop assigns temp, count;
            loop variant temp;
        */
        while (temp >= 100)
        {
            temp -= 100;
            count += 1;
        }
        ten_percent = count;
        
        //@ assert eight_percent == (i * 8) / 100;
        //@ assert ten_percent == (i * 10) / 100;
        
        if (eight_percent == a && ten_percent == b)
        {
            return i;
        }
        i += 1;
    }
    return -1;
}

int main()
{
    return 0;
}
