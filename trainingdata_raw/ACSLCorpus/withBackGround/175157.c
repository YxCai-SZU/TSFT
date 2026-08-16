#include <stdbool.h>
#include <stddef.h>

/*@ predicate a_in_range(int *a, integer n, integer len) =
      len == n &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= n;
*/

/*@ predicate b_in_range(int *b, integer n, integer len) =
      len == n &&
      \forall integer i; 0 <= i < n ==> 1 <= b[i] && b[i] <= 50;
*/

/*@ predicate c_in_range(int *c, integer n, integer len) =
      len == n &&
      \forall integer i; 0 <= i < n ==> 1 <= c[i] && c[i] <= 50;
*/

/*@ lemma arrays_preserved:
      \forall int *a, *b, *c, integer n;
      a_in_range(a, n, n) && b_in_range(b, n, n) && c_in_range(c, n, n) ==>
      (\forall integer k; 0 <= k < n ==> 1 <= a[k] && a[k] <= n) &&
      (\forall integer k; 0 <= k < n ==> 1 <= b[k] && b[k] <= 50) &&
      (\forall integer k; 0 <= k < n ==> 1 <= c[k] && c[k] <= 50);
*/

/*@
  requires 1 <= n <= 20;
  requires \valid_read(a + (0 .. n-1));
  requires \valid_read(b + (0 .. n-1));
  requires \valid_read(c + (0 .. n-1));
  requires a_in_range(a, n, n);
  requires b_in_range(b, n, n);
  requires c_in_range(c, n, n);
  ensures \result >= 0;
*/
int func(int n, int *a, int *b, int *c) {
    int ret = 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ret >= 0;
      loop invariant ret <= i * 100;
      loop invariant a_in_range(a, n, n);
      loop invariant b_in_range(b, n, n);
      loop invariant c_in_range(c, n, n);
      loop assigns ret, i;
      loop variant n - i;
    */
    while (i < n) {
        int num = a[i];
        //@ assert 1 <= num && num <= n;
        ret = ret + b[num - 1];
        
        if (i + 1 < n && a[i + 1] == num + 1) {
            ret = ret + c[num - 1];
        }
        
        i += 1;
    }
    
    return ret;
}
