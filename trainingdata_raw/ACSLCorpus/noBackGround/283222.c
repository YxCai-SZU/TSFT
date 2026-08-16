#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((l) / 3) * ((l) / 3) * ((l) / 3);
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    int64_t e;
    int64_t temp_l;
    
    e = 0;
    temp_l = l;
    
    /*@
        loop invariant 0 <= e;
        loop invariant 0 <= temp_l;
        loop invariant l == 3 * e + temp_l;
        loop invariant (1 <= (l) <= 1000);
        loop assigns e, temp_l;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l -= 3;
        e += 1;
    }
    
    //@ assert 0 <= e && e <= 333;
    //@ assert 0 <= temp_l && temp_l <= 1000;
    //@ assert e * e >= 0 && e * e <= 333 * 333;
    //@ assert e * e * e >= 0 && e * e * e <= 333 * 333 * 333;
    
    return e * e * e;
}

int main(void)
{
    return 0;
}
