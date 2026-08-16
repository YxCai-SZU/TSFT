/*@
    requires (1 <= (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    //@ assert (1 <= (r) <= 100);
    //@ assert ((r) * (r) <= 10000);
    return r * r;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
int input_int_tuple(int a, int b)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b) <= 10000);
    return a * b;
}

/*@
    requires (1 <= (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int input_int_list(int r)
{
    //@ assert (1 <= (r) <= 100);
    //@ assert ((r) * (r) <= 10000);
    return r * r;
}
