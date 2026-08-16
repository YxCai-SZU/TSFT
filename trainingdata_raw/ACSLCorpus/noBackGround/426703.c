/*@
    requires 0 <= x <= 1;
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    //@ assert 0 <= x <= 1;
    if (x == 0) {
        result = 1;
    } else {
        result = 0;
    }
    //@ assert (x == 0 && result == 1) || (x == 1 && result == 0);
    return result;
}

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
int func2(int a, int b, int c)
{
    int result;
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
    result = (a < b && b < c);
    //@ assert result == (a < b && b < c);
    return result;
}

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (100) <= 100);
    ensures \result == (a > b);
    assigns \nothing;
*/
int func3(int a, int b)
{
    int result;
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (100) <= 100);
    result = (a > b);
    //@ assert result == (a > b);
    return result;
}

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (100) <= 100);
    ensures \result == (a >= b);
    assigns \nothing;
*/
int func4(int a, int b)
{
    int result;
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (100) <= 100);
    result = (a >= b);
    //@ assert result == (a >= b);
    return result;
}
