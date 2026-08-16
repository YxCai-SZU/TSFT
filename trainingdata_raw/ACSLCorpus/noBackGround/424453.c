#include <stdbool.h>
#include <stddef.h>

/*@
  requires (3 <= (N) && (N) <= 20);
  requires \valid(P + (0 .. N-1));
  requires \forall size_t i; 0 <= i && i < N ==> (1 <= (P[i]) && (P[i]) <= (long long)(N));
  requires (\forall size_t i, j; 0 <= i && i < j && j < (N) ==> (P)[i] != (P)[j]);
  assigns \nothing;
  ensures 0 <= \result <= (int)(N - 2);
*/
int func(size_t N, const long long *P) {
    int res = 0;
    size_t i = 1;
    
    /*@
      loop invariant 1 <= i <= N - 1;
      loop invariant 0 <= res <= (int)(i - 1);
      loop invariant \forall size_t k; 0 <= k && k < N ==> (1 <= (P[k]) && (P[k]) <= (long long)(N));
      loop invariant (\forall size_t i, j; 0 <= i && i < j && j < (N) ==> (P)[i] != (P)[j]);
      loop invariant (3 <= (N) && (N) <= 20);
      loop assigns i, res;
      loop variant N - i;
    */
    while (i < N - 1) {
        long long p_i_minus_1 = P[i - 1];
        long long p_i = P[i];
        long long p_i_plus_1 = P[i + 1];
        
        //@ assert 0 <= i-1 && i-1 < N;
        //@ assert 0 <= i && i < N;
        //@ assert 0 <= i+1 && i+1 < N;
        
        if ((p_i_minus_1 < p_i && p_i < p_i_plus_1) || 
            (p_i_minus_1 > p_i && p_i > p_i_plus_1)) {
            //@ assert res + 1 <= (int)(i);
            res = res + 1;
        }
        i = i + 1;
    }
    return res;
}
