#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 1000000000);
    ensures \result == ( (a / 100) % 5 == 0 || (a / 100) % 5 == 1 );
    assigns \nothing;
*/
bool func(unsigned long long a)
{
    unsigned long long quotient = 0;
    unsigned long long remainder = a;
    
    /*@
        loop invariant 1 <= a && a <= 1000000000;
        loop invariant 0 <= quotient && quotient <= a / 100;
        loop invariant remainder == ((a) - (quotient) * 100);
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        quotient += 1;
        remainder -= 100;
        //@ assert remainder == ((a) - (quotient) * 100);
    }
    
    unsigned long long mod_result = quotient;
    
    /*@
        loop invariant 1 <= a && a <= 1000000000;
        loop invariant 0 <= mod_result && mod_result <= quotient;
        loop invariant mod_result <= a / 100;
        loop invariant ((quotient) % 5 == (mod_result) % 5);
        loop assigns mod_result;
        loop variant mod_result;
    */
    while (mod_result >= 5)
    {
        mod_result -= 5;
        //@ assert ((quotient) % 5 == (mod_result) % 5);
    }
    
    //@ assert mod_result == (a / 100) % 5;
    return mod_result == 0 || mod_result == 1;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
