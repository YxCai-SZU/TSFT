#include <stdbool.h>
#include <stddef.h>

/*@
  requires 3 <= n <= 20;
  requires \valid(p+(0..n-1));
  requires (\forall integer j; 0 <= j < (n) ==> 1 <= (p)[j] <= (n));
  requires (\forall integer j; 0 <= j < (n)-1 ==> (p)[j] != (p)[j+1]);
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n-2;
*/
int func(int n, int *p) {
    int cnt = 0;
    int i = 2;
    /*@
      loop invariant 2 <= i <= n;
      loop invariant cnt >= 0;
      loop invariant cnt <= i-2;
      loop invariant (\forall integer j; 0 <= j < (n) ==> 1 <= (p)[j] <= (n));
      loop invariant (\forall integer j; 0 <= j < (n)-1 ==> (p)[j] != (p)[j+1]);
      loop assigns cnt, i;
      loop variant n-i;
    */
    while (i < n) {
        int p_i_minus_2 = p[i-2];
        int p_i_minus_1 = p[i-1];
        int p_i = p[i];
        if ((p_i_minus_2 < p_i_minus_1 && p_i_minus_1 < p_i) ||
            (p_i_minus_2 > p_i_minus_1 && p_i_minus_1 > p_i)) {
            cnt += 1;
        }
        i += 1;
    }
    return cnt;
}
