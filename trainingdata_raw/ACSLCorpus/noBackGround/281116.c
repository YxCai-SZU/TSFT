/*@
    requires a > 0 && b > 0;
    ensures \result == (a + b) * b;
    ensures \result == a * b + b * b;
*/
int non_linear_arith_example14(int a, int b)
{
    //@ assert a > 0 && b > 0;
    //@ assert a + b > 0;
    //@ assert (a + b) * b == a * b + b * b;
    return (a + b) * b;
}

/*@
    requires a > 0 && b > 0;
    ensures \result == a * b + b * b;
*/
int non_linear_arith_example15(int a, int b)
{
    //@ assert a > 0 && b > 0;
    //@ assert a * b + b * b == a * b + b * b;
    return a * b + b * b;
}

/*@
    requires a > 0 && b > 0;
    ensures \result >= b * b;
*/
int non_linear_arith_example16(int a, int b)
{
    //@ assert a > 0 && b > 0;
    //@ assert a * b >= 0;
    //@ assert (a * b + b * b) >= b * b;
    return a * b + b * b;
}

/*@
    requires a > 0 && b > 0;
    ensures \result >= b * b;
*/
int non_linear_arith_example17(int a, int b)
{
    //@ assert a > 0 && b > 0;
    //@ assert a + b >= 0;
    //@ assert (a + b) * b >= b * b;
    return (a + b) * b;
}

/*@
    requires a > 0 && b > 0;
    ensures \result >= a * b;
*/
int non_linear_arith_example18(int a, int b)
{
    //@ assert a > 0 && b > 0;
    //@ assert (a + b) * b >= a * b;
    return (a + b) * b;
}

int main()
{
    return 0;
}
