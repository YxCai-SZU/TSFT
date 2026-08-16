/*@
    requires m >= n;
    ensures \result >= 0;
*/
int calc_example_10(int n, int m)
{
    //@ assert m >= n;
    //@ assert m - n >= 0;
    return m - n;
}

/*@
    requires a <= b <= c;
    ensures \result <= c + c + c;
*/
int lemma_triple_addition(int a, int b, int c)
{
    //@ assert a + b + c <= c + c + c;
    return a + b + c;
}

int main()
{
    return 0;
}
