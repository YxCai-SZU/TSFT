/*@
    predicate positive(integer n) = n > 0;

    lemma nonlinear_arith:
        \forall integer n, m;
            positive(n) && positive(m) ==> n * m > 0;

    lemma nonlinear_arith_add:
        \forall integer n, m, k;
            positive(n) && positive(m) && positive(k) ==> n * m + k > 0;
*/

/*@
    requires positive(n) && positive(m);
    ensures \result > 0;
*/
int calc_example_20(int n, int m)
{
    //@ assert positive(n) && positive(m);
    //@ assert n * m > 0;
    return n * m;
}

/*@
    requires positive(n) && positive(m) && positive(k);
    ensures \result > 0;
*/
int calc_example_21(int n, int m, int k)
{
    //@ assert positive(n) && positive(m) && positive(k);
    //@ assert n * m + k > 0;
    return n * m + k;
}

int main()
{
    return 0;
}
