/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result == (((a) * 3) + (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert a * 3 <= 300;
    //@ assert (a * 3) + b <= 400;
    return (a * 3) + b;
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <==> ((a) <= (c) && (c) <= (b));
    assigns \nothing;
*/
int is_between(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
    return (a <= c) && (c <= b);
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result == (((a) * 3) + (b));
    assigns \nothing;
*/
int func2(int a, int b)
{
    //@ assert a * 3 <= 300;
    //@ assert (a * 3) + b <= 400;
    return (a * 3) + b;
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <==> ((a) <= (c) && (c) <= (b));
    assigns \nothing;
*/
int is_between2(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
    return (a <= c) && (c <= b);
}
