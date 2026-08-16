#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(size_t N, int *Hs) =
      N >= 1 && N <= 20 &&
      \valid(Hs + (0 .. N-1)) &&
      \forall size_t i; 0 <= i < N ==> Hs[i] >= 1 && Hs[i] <= 100;
*/

/*@ predicate loop_invariant(size_t N, int *Hs, size_t i, int res, int max_h) =
      0 <= i && i <= N &&
      res >= 0 &&
      res <= (int)i &&
      valid_params(N, Hs) &&
      \forall size_t j; 0 <= j < N ==> Hs[j] >= 1 && Hs[j] <= 100;
*/

/*@ lemma res_non_negative:
      \forall size_t N, int *Hs, size_t i, int res, int max_h;
      loop_invariant(N, Hs, i, res, max_h) ==> res >= 0;
*/

/*@ lemma res_bound_by_i:
      \forall size_t N, int *Hs, size_t i, int res, int max_h;
      loop_invariant(N, Hs, i, res, max_h) ==> res <= (int)i;
*/

/*@
  requires valid_params(N, Hs);
  assigns \nothing;
  ensures \result >= 0;
*/
int func(size_t N, int *Hs) {
    int max_h = 0;
    size_t i = 0;
    int res = 0;
    
    /*@
      loop invariant loop_invariant(N, Hs, i, res, max_h);
      loop assigns i, res, max_h;
      loop variant N - i;
    */
    while (i < N) {
        int h = Hs[i];
        
        //@ assert h >= 1 && h <= 100;
        
        if (max_h <= h) {
            max_h = h;
            res += 1;
        }
        
        //@ assert res >= 0;
        //@ assert res <= (int)(i + 1);
        
        i += 1;
    }
    
    //@ assert res >= 0;
    return res;
}
