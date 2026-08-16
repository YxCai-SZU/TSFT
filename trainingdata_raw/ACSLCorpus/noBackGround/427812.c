#include <stdbool.h>

/*@ requires 1 <= n <= 1000;
    ensures \result == n / 3;
    assigns \nothing;
*/
int func(int n)
{
    int quotient = 0;
    int remainder = n;
    int divisor = 3;
    bool is_negative = false;

    if (n < 0)
    {
        remainder = -remainder;
        is_negative = true;
    }

    /*@ loop invariant 1 <= n <= 1000;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == n - quotient * divisor || (n < 0 && -remainder == -(n - quotient * divisor));
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    //@ assert 0 <= remainder < 3;

    if (is_negative)
    {
        quotient = -quotient;
    }

    return quotient;
}

int main()
{
    unsigned int v[3] = {0, 1, 2};
    
    //@ assert ((\exists integer i; 0 <= i < (3) && (&v[0])[i] == 0) ||       (\forall integer i; 0 <= i < (3) ==> (&v[0])[i] >= 0));
    
    return 0;
}
