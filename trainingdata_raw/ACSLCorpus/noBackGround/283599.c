/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 3 * (r));
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3;
    int circumference;
    //@ assert pi == 3;
    circumference = 2 * pi * r;
    //@ assert circumference == 2 * 3 * r;
    return circumference;
}

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (2 * 3 * ((a) + (b)));
    assigns \nothing;
*/
int func2(int a, int b)
{
    int pi = 3;
    int sum;
    int circumference;
    //@ assert pi == 3;
    sum = a + b;
    //@ assert sum == a + b;
    circumference = 2 * pi * sum;
    //@ assert circumference == 2 * 3 * (a + b);
    return circumference;
}

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 3 * (r));
    assigns \nothing;
*/
int func3(int r)
{
    int pi = 3;
    int circumference;
    //@ assert pi == 3;
    circumference = 2 * pi * r;
    //@ assert circumference == 2 * 3 * r;
    return circumference;
}
