#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    int64_t l_cubed;
    int64_t v;
    int64_t temp;
    int64_t divisor;

    //@ assert 1 <= l <= 1000;
    
    l_cubed = l * l * l;
    v = 0;
    temp = l_cubed;
    divisor = 27;

    /*@
        loop invariant v * 27 + temp == l_cubed;
        loop invariant 0 <= temp;
        loop invariant 0 <= v;
        loop assigns v, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        v += 1;
    }

    //@ assert 0 <= temp < divisor;
    return v;
}

int main(void)
{
    return 0;
}
