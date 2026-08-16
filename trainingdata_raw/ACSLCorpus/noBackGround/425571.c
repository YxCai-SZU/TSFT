#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 314 / 100);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at scope top
    int pi_approx;
    int circumference;
    int divisor;
    int result;
    int temp;
    int count;
    
    pi_approx = 314;
    circumference = r * 2 * pi_approx;
    divisor = 100;
    result = 0;
    temp = circumference;
    count = 0;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert (314)== 314;
    //@ assert circumference == r * 2 * (314);
    //@ assert (100)== 100;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant (314)== 314;
        loop invariant circumference == r * 2 * (314);
        loop invariant (100)== 100;
        loop invariant circumference == (temp + (100)* count);
        loop invariant count == (circumference - temp) / (100);
        loop invariant count * (100)<= r * 2 * (314);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= (100);
        temp -= divisor;
        count += 1;
        //@ assert circumference == (temp + (100)* count);
    }
    
    result = count;
    
    //@ assert result == (2 * (r) * 314 / 100);
    return result;
}
