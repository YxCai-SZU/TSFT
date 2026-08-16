#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * (314)) / 100);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi_approx;
    int64_t product;
    int64_t result;
    int64_t temp;
    int64_t divisor;
    int64_t count;
    
    pi_approx = 314;
    
    //@ assert 2 * r * (314)<= 2 * 100 * 314;
    product = 2 * r * pi_approx;
    
    result = 0;
    temp = product;
    divisor = 100;
    count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant (314)== 314;
        loop invariant product == 2 * r * (314);
        loop invariant divisor == 100;
        loop invariant temp >= 0;
        loop invariant count * divisor + temp == product;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        count += 1;
    }
    
    result = count;
    
    //@ assert result * 100 + temp == product;
    //@ assert result * 100 + temp == 2 * r * (314);
    //@ assert result == (2 * r * 314) / 100;
    
    return result;
}

int main(void)
{
    return 0;
}
