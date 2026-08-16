/*@
    requires n + 1 == m;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_13(int n, int m)
{
    //@ assert 2 * n + 2 == 2 * (n + 1);
    //@ assert 2 * (n + 1) == 2 * m;
    //@ assert 2 * n + 2 == 2 * m;
    return 0;
}

/*@
    requires n + 1 == m;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_14(int n, int m)
{
    //@ assert 2 * n + 2 == 2 * (n + 1);
    //@ assert 2 * (n + 1) == 2 * m;
    //@ assert 2 * n + 2 == 2 * m;
    return 0;
}

/*@
    ensures \result == 0;
    assigns \nothing;
*/
int main()
{
    return 0;
}

/*@
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_identity(int n)
{
    //@ assert n == n;
    return 0;
}

/*@
    requires a == b;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_congruence(int a, int b)
{
    //@ assert a * 2 == b * 2;
    return 0;
}

/*@
    requires n + 1 == m;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_addition(int n, int m)
{
    //@ assert 2 * n + 2 == 2 * m;
    return 0;
}
