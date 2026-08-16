/*@
predicate f(integer i, integer j) = \true;

lemma lemma_even_f:
    \forall integer i; i % 2 == 0 ==> f(i, 0);

predicate g(integer i, integer j) = \true;

lemma lemma_g_proves_f:
    \forall integer i, integer j; g(i, j) ==> f(i, j);
*/

/*@
requires \exists integer j; g(i, j);
ensures f(i, 0);
*/
void test_g_proves_f(int i)
{
    //@ assert \exists integer j; g(i, j);
    //@ ghost int chosen_j;
    //@ assert g(i, chosen_j);
    //@ assert f(i, chosen_j);
    //@ assert f(i, 0);
}

int main()
{
    return 0;
}
