/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert ((r) * (r) <= 10000);
    return r * r;
}

/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == x * x * x;
    assigns \nothing;
*/
int func2(int x)
{
    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert ((x) * (x) <= 10000);
    //@ assert ((x) * (x) * (x) <= 1000000);
    return x * x * x;
}
