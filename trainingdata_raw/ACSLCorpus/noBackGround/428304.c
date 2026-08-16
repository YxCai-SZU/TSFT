/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100 && 1 <= (d) <= 100);
    ensures \result == (a * d >= b * c);
    assigns \nothing;
*/
int func(unsigned long long a, unsigned long long b,
         unsigned long long c, unsigned long long d)
{
    unsigned long long product1;
    unsigned long long product2;
    int result;

    //@ assert a * d <= 10000;
    product1 = a * d;

    //@ assert b * c <= 10000;
    product2 = b * c;

    result = (product1 >= product2) ? 1 : 0;
    return result;
}
