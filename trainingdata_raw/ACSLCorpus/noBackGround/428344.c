#include <stdint.h>

/*@
    requires (400 <= (x) && (x) <= 1999);
    ensures \result == (10 - ((x) / 200));
    ensures 1 <= \result && \result <= 8;
*/
int64_t func(int64_t x)
{
    int64_t quotient;
    int64_t remainder;
    int64_t divisor;
    int64_t ans;

    quotient = 0;
    remainder = x;
    divisor = 200;

    /*@
        loop invariant 0 <= quotient <= x / 200;
        loop invariant remainder == x - quotient * divisor;
        loop invariant 0 <= remainder < 200 + x;
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor)
    {
        quotient = quotient + 1;
        remainder = remainder - divisor;
    }

    ans = 10 - quotient;

    //@ assert ans == 10 - (x / 200);
    //@ assert 1 <= ans && ans <= 8;

    return ans;
}

int main()
{
    return 0;
}
