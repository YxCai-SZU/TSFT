/*@
    logic integer f(integer x) = x + 1;
    predicate f_increases(integer x) = f(x) > x;
    lemma f_increases_lemma: \forall integer x; f(x) > x;
    predicate g(integer x) = x > 0;
    lemma g_proves_f_lemma: \forall integer x; x > 0 ==> f(x) > 0;
*/

/*@
    requires n >= 0;
    ensures \exists integer x; f(x) > n;
*/
void exists_prover(int n)
{
    //@ assert f(n) > n;
}

/*@
    requires 2 == 2;
    ensures g(2);
*/
void test_g_prover()
{
    //@ assert f(2) > 0;
}

int main()
{
    return 0;
}
