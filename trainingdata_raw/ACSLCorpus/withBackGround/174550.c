/*@
    logic integer g(integer x) = x * 10 + 5;

    lemma lemma_g_greater:
        \forall integer x; g(x) > x * 10;

    lemma exists_prover:
        \forall integer n; \exists integer x; g(x) > n;
*/

/*@
    requires \true;
    ensures \true;
*/
int main() {
    //@ assert \forall integer x; g(x) > x * 10;
    //@ assert \forall integer n; \exists integer x; g(x) > n;
    return 0;
}
