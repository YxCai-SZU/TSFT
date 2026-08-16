#include <stdbool.h>
/*@
    predicate distinct_elements(int *p, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> p[i] != p[j];

    predicate in_range(int *p, integer len, integer N) =
        \forall integer i; 0 <= i < len ==> 1 <= p[i] && p[i] <= N;

    lemma distinct_preserved:
        \forall int *p, integer len, integer N;
        distinct_elements(p, len) && in_range(p, len, N) ==>
            distinct_elements(p, len);

    lemma range_preserved:
        \forall int *p, integer len, integer N;
        distinct_elements(p, len) && in_range(p, len, N) ==>
            in_range(p, len, N);
*/

/*@
    requires 3 <= N && N <= 20;
    requires \valid(p + (0 .. N-1));
    requires distinct_elements(p, N);
    requires in_range(p, N, N);
    ensures \result >= 0;
    ensures \result <= N - 2;
    assigns \nothing;
*/
int func(int N, int *p) {
    int count = 0;
    int i = 2;
    /*@
        loop invariant 2 <= i && i <= N;
        loop invariant 0 <= count && count <= i - 2;
        loop invariant distinct_elements(p, N);
        loop invariant in_range(p, N, N);
        loop invariant 3 <= N && N <= 20;
        loop assigns count, i;
        loop variant N - i;
    */
    while (i < N) {
        int pi = p[i];
        int pi1 = p[i - 1];
        int pi2 = p[i - 2];
        //@ assert 0 <= i && i < N;
        //@ assert 0 <= i-1 && i-1 < N;
        //@ assert 0 <= i-2 && i-2 < N;
        //@ assert distinct_elements(p, N);
        //@ assert in_range(p, N, N);
        
        if ((pi < pi1 && pi1 < pi2) || (pi > pi1 && pi1 > pi2)) {
            //@ assert count >= 0;
            //@ assert count <= i - 2;
            count += 1;
            //@ assert count >= 1;
            //@ assert count <= i - 1;
        }
        i += 1;
        //@ assert i >= 3;
        //@ assert i <= N;
        //@ assert count <= i - 2;
    }
    //@ assert i == N;
    //@ assert count >= 0;
    //@ assert count <= N - 2;
    return count;
}
