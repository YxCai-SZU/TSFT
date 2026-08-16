/*@
    requires m >= n;
    ensures \result >= 0;
*/
int calc_example_10(int n, int m)
{
    int result;
    //@ assert m >= n;
    result = m - n;
    //@ assert ((m) >= (n) ==> (m) - (n) >= 0);
    //@ assert result >= 0;
    return result;
}

/*@
    requires n >= 0;
    ensures \result >= 1;
*/
int calc_example_11(int n)
{
    int result;
    //@ assert n >= 0;
    result = n + 1;
    //@ assert ((n) >= 0 ==> (n) + 1 >= 1);
    //@ assert result >= 1;
    return result;
}

/*@
    requires n < 0;
    ensures \result < 0;
*/
int calc_example_12(int n)
{
    int result;
    //@ assert n < 0;
    result = n - 1;
    //@ assert ((n) < 0 ==> (n) - 1 < 0);
    //@ assert result < 0;
    return result;
}

int main()
{
    return 0;
}
