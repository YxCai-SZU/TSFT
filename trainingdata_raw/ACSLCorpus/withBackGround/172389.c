#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_valid_params(size_t n, int *p) =
      n >= 3 && n <= 200000 &&
      \valid(p + (0 .. n-1)) &&
      (\forall integer i; 0 <= i < n ==> 1 <= p[i] <= (int)n) &&
      (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);
*/

/*@
  requires is_valid_params(n, p);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
size_t func(size_t n, const int *p) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n-2;
      loop invariant 0 <= count <= i;
      loop invariant is_valid_params(n, p);
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n - 2) {
        bool cond1 = p[i] < p[i + 1] && p[i + 1] < p[i + 2];
        bool cond2 = p[i] > p[i + 1] && p[i + 1] > p[i + 2];
        
        //@ assert cond1 || cond2 ==> (p[i] < p[i+1] && p[i+1] < p[i+2]) || (p[i] > p[i+1] && p[i+1] > p[i+2]);
        
        if (cond1 || cond2) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
