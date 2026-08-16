/*@
    requires (0 <= (a) && (a) < 10000) && (0 <= (b) && (b) < 10000);
    ensures \result == 1 <==> (a * b) % 2 == 0;
    assigns \nothing;
*/
_Bool func(unsigned long long a, unsigned long long b)
{
    unsigned long long product;
    _Bool result;
    unsigned long long temp;

    product = a * b;
    //@ assert 0 <= product && product < 10000 * 10000;

    result = 0;
    temp = product;

    /*@
        loop invariant 0 <= temp && temp <= product;
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 0)
    {
        result = 1;
    }

    return result;
}
