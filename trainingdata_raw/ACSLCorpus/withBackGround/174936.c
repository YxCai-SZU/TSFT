/*@
    logic integer f(integer x) = x + 1;

    lemma f_increases:
        \forall integer x; f(x) > x;
*/

/*@
    requires \true;
    ensures \exists integer x; f(x) > n;
*/
void exists_prover(int n)
{
    // Variable declarations at top
    int tmp;
    
    //@ assert f(n) > n;
    tmp = n + 1;
    
    //@ assert \exists integer x; f(x) > n;
}
