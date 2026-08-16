/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int func(int r)
{
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert ((r) * (r)) <= 10000;
    return r * r;
}

/*@
    requires (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    ensures \result == ((a) + (b));
    assigns \nothing;
*/
int input_int_tuple(int a, int b)
{
    //@ assert (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    return a + b;
}
