/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result == (((a) * (b)) / 2);
    ensures \result <= a * b;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    //@ assert a * b <= 10000;
    unsigned int product;
    unsigned int res;

    product = a * b;
    res = product / 2;

    //@ assert res == (((a) * (b)) / 2);
    //@ assert res <= a * b;

    return res;
}
