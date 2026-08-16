/*@
    requires (1 <= (r) <= 100);
    ensures \result == (((2)* (r) * (314)) / (100));
    assigns \nothing;
*/
long func(long r)
{
    long pi = 314;
    long two = 2;
    long scale = 100;
    long numerator = two * r * pi;
    long quotient = 0;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant (2)== 2;
        loop invariant (100)== 100;
        loop invariant numerator >= 0;
        loop invariant numerator == (2)* r * pi - quotient * (100);
        loop invariant quotient >= 0;
        loop assigns numerator, quotient;
        loop variant numerator;
    */
    while (numerator >= scale)
    {
        numerator -= scale;
        quotient += 1;
    }

    //@ assert quotient == (((2)* (r) * (314)) / (100));
    return quotient;
}

int main(void)
{
    return 0;
}
