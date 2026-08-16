#include <stddef.h>
/*@
    predicate valid_array(integer N, size_t *P) =
        N >= 2 && N <= 200000 &&
        \valid(P+(0..N-1)) &&
        \forall integer i; 0 <= i < N ==> P[i] >= 1 && P[i] <= 1000;

    predicate loop_invariant(integer N, size_t *P, size_t index, size_t answer, size_t min_value) =
        1 <= index && index <= N &&
        1 <= answer && answer <= index &&
        min_value >= 1 && min_value <= 1000 &&
        \forall integer i; 0 <= i < index ==> min_value <= P[i];

    lemma answer_range: \forall integer N, size_t *P, size_t answer;
        valid_array(N, P) && 1 <= answer && answer <= N ==> answer >= 1 && answer <= N;
*/

/*@
    requires valid_array(N, P);
    ensures \result >= 1 && \result <= N;
    assigns \nothing;
*/
size_t func(size_t N, size_t *P) {
    size_t answer = 1;
    size_t index = 1;
    size_t min_value = P[0];

    /*@
        loop invariant 1 <= index <= N;
        loop invariant 1 <= answer <= index;
        loop invariant min_value >= 1 && min_value <= 1000;
        loop invariant \forall integer i; 0 <= i < index ==> min_value <= P[i];
        loop invariant valid_array(N, P);
        loop assigns answer, index, min_value;
        loop variant N - index;
    */
    while (index < N) {
        //@ assert index < N && index >= 1;
        if (P[index] <= min_value) {
            answer += 1;
            min_value = P[index];
        }
        index += 1;
    }
    //@ assert answer >= 1 && answer <= N;
    return answer;
}
