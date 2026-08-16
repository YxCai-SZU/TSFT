/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert ((r * r) <= 10000);
    return r * r;
}

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result <= a * b && \result <= c;
    assigns \nothing;
*/
int func2(int a, int b, int c)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    //@ assert ((a * b) <= 10000);
    if (a * b < c) {
        return a * b;
    } else {
        return c;
    }
}
