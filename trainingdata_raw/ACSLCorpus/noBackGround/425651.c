/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
unsigned long func(unsigned long a, unsigned long b, unsigned long h)
{
    unsigned long quotient = 0;
    unsigned long remainder = (a + b) * h;

    //@ assert 1 <= a + b <= 200;
    //@ assert 1 <= (a + b) * h <= 20000;

    /*@
        loop invariant 0 <= quotient <= (((a) + (b)) * (h) / 2);
        loop invariant remainder == (a + b) * h - 2 * quotient;
        loop invariant 1 <= (a + b) * h <= 20000;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
        quotient += 1;
    }

    //@ assert quotient == (((a) + (b)) * (h) / 2);
    return quotient;
}

int main()
{
    return 0;
}
