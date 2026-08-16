/*@
    predicate bounds(integer A, integer P) =
        0 <= A && A <= 100 &&
        0 <= P && P <= 100;

    logic integer calc_ans(integer A, integer P) =
        (A * 3 + P) / 2;

    lemma mul3_bound: \forall integer A; bounds(A, 0) ==> A * 3 <= 300;
    lemma sum_bound: \forall integer A, integer P; bounds(A, P) ==> A * 3 + P <= 400;
    lemma div_bound: \forall integer A, integer P; bounds(A, P) ==> calc_ans(A, P) <= 200;
*/

/*@
    requires bounds(A, P);
    ensures \result == calc_ans(A, P);
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int P)
{
    // Variable declarations at scope top
    unsigned int ans;

    //@ assert A * 3 <= 300;
    //@ assert A * 3 + P <= 400;
    //@ assert (A * 3 + P) / 2 <= 200;

    ans = (A * 3 + P) / 2;
    //@ assert ans == calc_ans(A, P);
    return ans;
}
