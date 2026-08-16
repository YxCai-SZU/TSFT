#include <stdbool.h>

/*@ predicate is_valid_index(integer i, integer N) = 0 <= i < N; */

/*@ predicate is_valid_value(integer v) = 1 <= v <= 1000000000; */

/*@ predicate array_valid(int *Vs, integer N) = 
      \forall integer i; 0 <= i < N ==> is_valid_value(Vs[i]); */

/*@ lemma answer_bounds: 
      \forall integer N, answer, i; 
      1 <= N <= 100000 && 0 <= answer <= i && 0 <= i <= N ==> 
      0 <= answer <= N; */

/*@ requires 1 <= N <= 100000;
    requires \valid(Vs+(0..N-1));
    requires array_valid(Vs, N);
    ensures 0 <= \result <= N;
    assigns \nothing;
 */
int func(int N, int *Vs) {
    int answer = 0;
    int M = 1000000001;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= N;
        loop invariant 0 <= answer <= i;
        loop invariant 1 <= M <= 1000000001;
        loop invariant array_valid(Vs, N);
        loop assigns answer, M, i;
        loop variant N - i;
     */
    while (i < N) {
        int V = Vs[i];
        
        //@ assert is_valid_value(V);
        
        if (V <= M) {
            //@ assert V <= M;
            answer += 1;
            M = V;
            //@ assert 0 <= answer <= i+1;
        }
        i += 1;
    }
    
    //@ assert 0 <= answer <= N;
    return answer;
}
