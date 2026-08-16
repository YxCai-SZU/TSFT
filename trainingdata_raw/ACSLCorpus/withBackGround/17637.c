#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(int *p, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n &&
      \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@ predicate loop_invariant(int *p, integer n, integer i, integer idx, integer cnt) =
      0 <= i <= n - 1 &&
      1 <= idx <= n &&
      cnt >= 1 &&
      cnt <= i + 1 &&
      \forall integer k; 0 <= k < n ==> p[k] >= 1 && p[k] <= n &&
      \forall integer k, j; 0 <= k < j < n ==> p[k] != p[j];
*/

/*@ lemma cnt_bounds: \forall integer n, cnt; 
      n >= 1 && cnt >= 1 && cnt <= n ==> cnt >= 1 && cnt <= n;
*/

/*@
  requires n >= 1 && n <= 200000;
  requires \valid(p + (0 .. n-1));
  requires is_valid_array(p, n);
  ensures \result >= 1 && \result <= n;
*/
int func(int n, int *p)
{
    int cnt = 1;
    size_t idx = 1;
    int i = 0;
    
    /*@ loop invariant loop_invariant(p, n, i, idx, cnt);
        loop invariant idx <= n;
        loop invariant i <= n - 1;
        loop assigns cnt, idx, i;
        loop variant n - idx;
    */
    while (idx < (size_t)n && i < n - 1) {
        //@ assert loop_invariant(p, n, i, idx, cnt);
        
        if (p[idx] < p[idx - 1]) {
            cnt += 1;
            //@ assert cnt >= 2;
        } else {
            break;
        }
        
        idx += 1;
        i += 1;
    }
    
    //@ assert cnt >= 1;
    //@ assert cnt <= n;
    return cnt;
}
