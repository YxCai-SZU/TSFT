#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_whitespace(char c) = 
      c == ' ' || c == '\t' || c == '\n' || c == '\r';
*/

/*@ predicate is_eol(char c) = 
      c == '\r' || c == '\n';
*/

/*@ predicate valid_array(int *p, integer n) =
      n >= 3 && n <= 20 &&
      \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n &&
      \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@ lemma array_properties_preserved:
      \forall int *p, integer n, integer i;
      valid_array(p, n) && 1 <= i <= n-1 ==>
      valid_array(p, n);
*/

/*@
  requires \valid(p+(0..n-1));
  requires valid_array(p, n);
  assigns \nothing;
  ensures \result <= n - 2;
*/
size_t func(size_t n, int *p) {
    size_t cnt = 0;
    size_t i = 1;
    
    /*@
      loop invariant 1 <= i <= n-1;
      loop invariant cnt <= i-1;
      loop invariant valid_array(p, n);
      loop assigns i, cnt;
      loop variant n-i;
    */
    while (i < n - 1) {
        bool pp = (p[i - 1] < p[i]) && (p[i] < p[i + 1]);
        bool qq = (p[i - 1] > p[i]) && (p[i] > p[i + 1]);
        
        //@ assert pp || qq ==> cnt+1 <= i;
        if (pp || qq) {
            cnt += 1;
        }
        i += 1;
    }
    return cnt;
}
