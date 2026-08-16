/*@
    requires 1 <= r <= 100;
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
unsigned int func(unsigned int r)
{
    //@ assert 1 <= r <= 100;
    //@ assert r * r <= 10000;
    return r * r;
}

/*@
    assigns \nothing;
*/
void mainf(void)
{
    //@ assert (((1) * ((1) + 1)) / 2) == 1;
    //@ assert (((2) * ((2) + 1)) / 2) == 3;
    //@ assert (((3) * ((3) + 1)) / 2) == 6;
}
