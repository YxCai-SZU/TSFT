#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(p + (0 .. n-1));
  requires ((n) >= 3 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
  assigns \nothing;
  ensures ((\result) >= 0 && (\result) <= (n) - 2);
*/
int func(int n, int *p) {
    int cnt = 0;
    int i = 1;
    
    /*@
      loop invariant 1 <= i <= n - 1;
      loop invariant cnt >= 0;
      loop invariant cnt <= i - 1;
      loop invariant ((n) >= 3 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
      loop assigns cnt, i;
      loop variant n - i;
    */
    while (i < n - 1) {
        int p_i_minus_1 = p[i - 1];
        int p_i = p[i];
        int p_i_plus_1 = p[i + 1];
        
        //@ assert p_i_minus_1 >= 1 && p_i_minus_1 <= n;
        //@ assert p_i >= 1 && p_i <= n;
        //@ assert p_i_plus_1 >= 1 && p_i_plus_1 <= n;
        
        if ((p_i_minus_1 < p_i && p_i < p_i_plus_1) || 
            (p_i_minus_1 > p_i && p_i > p_i_plus_1)) {
            cnt += 1;
        }
        i += 1;
    }
    
    //@ assert ((cnt) >= 0 && (cnt) <= (n) - 2);
    return cnt;
}
