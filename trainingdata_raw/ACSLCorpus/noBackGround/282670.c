/*@
    requires (1 <= (h) && (h) <= 10000 &&
        1 <= (a) && (a) <= 10000);
    ensures \result >= 0;
    ensures \result * a >= h;
    ensures (\result - 1) * a < h;
    assigns \nothing;
*/
unsigned int func(unsigned int h, unsigned int a)
{
    unsigned int res;

    //@ assert (1 <= (h) && (h) <= 10000 &&         1 <= (a) && (a) <= 10000);
    //@ assert (((h) + (a) - 1) / (a)) * a >= h;
    //@ assert ((((h) + (a) - 1) / (a)) - 1) * a < h;

    res = (h + a - 1) / a;

    //@ assert res == (((h) + (a) - 1) / (a));
    //@ assert res >= 0;
    //@ assert res * a >= h;
    //@ assert (res - 1) * a < h;

    return res;
}
