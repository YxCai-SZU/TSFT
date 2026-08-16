/*@
    predicate valid_range(integer N, integer i) =
        1 <= N && N <= 100 && 1 <= i && i <= N;

    logic integer compute_j(integer N, integer i) = N - i + 1;

    lemma j_bounds:
        \forall integer N, i; valid_range(N, i) ==> 
            1 <= compute_j(N, i) && compute_j(N, i) <= N;
*/

/*@
    requires valid_range(N, i);
    ensures 1 <= \result && \result <= N;
    ensures \result == compute_j(N, i);
    assigns \nothing;
*/
long func(long N, long i) {
    long j;
    //@ assert valid_range(N, i);
    j = N - i + 1;
    //@ assert j == compute_j(N, i);
    //@ assert 1 <= j && j <= N;
    return j;
}

int main() {
    return 0;
}
