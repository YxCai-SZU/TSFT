/*@
    requires a > b && b > c;
    ensures \result == 1;
    assigns \nothing;
*/
int check_greater_than(int a, int b, int c)
{
    int result;
    //@ assert a > b;
    //@ assert b > c;
    //@ assert a > c;
    result = 1;
    return result;
}

/*@
    requires a >= b && b >= c;
    ensures \result == 1;
    assigns \nothing;
*/
int check_greater_than_or_equal(int a, int b, int c)
{
    int result;
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert a >= c;
    result = 1;
    return result;
}

int main()
{
    int a;
    int b;
    int c;
    int res1;
    int res2;

    a = 5;
    b = 3;
    c = 1;
    //@ assert a > b && b > c;
    res1 = check_greater_than(a, b, c);

    a = 5;
    b = 5;
    c = 3;
    //@ assert a >= b && b >= c;
    res2 = check_greater_than_or_equal(a, b, c);

    return 0;
}
