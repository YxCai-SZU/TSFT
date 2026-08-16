#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * r * 31415926535897932 / 10000000000000000;
*/
int64_t func(int64_t r)
{
    int64_t pi = 31415926535897932;
    int64_t result = 0;
    int64_t temp = 2 * r * pi;
    int64_t divisor = 10000000000000000;

    //@ assert (1 <= (r) <= 100);
    //@ assert pi == (31415926535897932);
    //@ assert divisor == (10000000000000000);
    //@ assert temp == (2 * (r) * (31415926535897932));
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == (31415926535897932);
        loop invariant divisor == (10000000000000000);
        loop invariant temp >= 0;
        loop invariant result * divisor + temp == 2 * r * pi;
        loop invariant result * divisor + temp <= 2 * 100 * (31415926535897932);
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        result += 1;
    }

    //@ assert result * divisor + temp == 2 * r * pi;
    return result;
}

int main()
{
    return 0;
}
