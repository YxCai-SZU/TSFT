/*@
    requires ((n) >= 0);
    ensures \result >= 0;
    ensures \result == n * n * n;
    assigns \nothing;
*/
int square_cube(int n)
{
    //@ assert ((n) >= 0);
    //@ assert ((n) * (n) * (n)) >= 0;
    //@ assert ((n) * (n) * (n)) == n * n * n;
    return n * n * n;
}

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert ((r) * (r)) <= 10000;
    return r * r;
}

int main()
{
    return 0;
}
