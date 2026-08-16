/*@
    predicate f(integer i) = \true;

    predicate g(integer i, integer j) = \true;

    lemma lemma_even_f:
        \forall integer i; i % 2 == 0 ==> f(i);

    lemma lemma_g_proves_f:
        \forall integer i, integer j; g(i, j) ==> f(i);
*/

/*@
    requires n >= 0;
    ensures \result == 1 <==> n % 2 == 0;
    assigns \nothing;
*/
int is_even(unsigned int n)
{
    int ret;
    //@ assert n >= 0;
    ret = (n % 2 == 0) ? 1 : 0;
    //@ assert ret == 1 <==> n % 2 == 0;
    return ret;
}

int main()
{
    return 0;
}
