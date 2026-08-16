/*@
    requires (-64 <= (x) && (x) < 64);
    ensures \result == (2 * (x));
    assigns \nothing;
*/
int double_func(int x)
{
    //@ assert (-64 <= (x) && (x) < 64);
    int result = x + x;
    //@ assert result == (2 * (x));
    return result;
}

/*@
    requires (-32 <= (x) && (x) < 32);
    ensures \result == (4 * (x));
    assigns \nothing;
*/
int quadruple(int x)
{
    //@ assert (-32 <= (x) && (x) < 32);
    int x2 = double_func(x);
    //@ assert x2 == (2 * (x));
    int result = x2 + x2;
    //@ assert result == (4 * (x));
    return result;
}

/*@
    requires (-16 <= (x) && (x) < 16);
    ensures \result == (8 * (x));
    assigns \nothing;
*/
int octuple(int x)
{
    //@ assert (-16 <= (x) && (x) < 16);
    int x4 = quadruple(x);
    //@ assert x4 == (4 * (x));
    int result = x4 + x4;
    //@ assert result == (8 * (x));
    return result;
}

int main()
{
    int n = octuple(10);
    //@ assert n == (8 * (10));
    //@ assert n == 80;
    return 0;
}
