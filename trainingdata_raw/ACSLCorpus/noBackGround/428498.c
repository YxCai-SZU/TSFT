/*@
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    ensures \result == (x * y) / 100;
    assigns \nothing;
*/
unsigned int func(unsigned int x, unsigned int y)
{
    //@ assert x <= 100;
    //@ assert y <= 100;
    //@ assert x * y <= 10000;

    unsigned int res;
    res = (x * y) / 100;
    return res;
}
