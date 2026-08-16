#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 3 && n <= 200000;
  requires \valid(p + (0 .. n-1));
  requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
  assigns \nothing;
  ensures \result >= 0;
*/
int func(int n, int *p) {
    int count = 0;
    size_t i = 1;

    /*@
      loop invariant 1 <= i <= n-1;
      loop invariant count >= 0;
      loop invariant count <= (int)(i - 1);
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < (size_t)n - 1) {
        int p_i_minus_1 = p[i - 1];
        int p_i = p[i];
        int p_i_plus_1 = p[i + 1];

        //@ assert p_i_minus_1 != p_i && p_i != p_i_plus_1;
        if ((p_i_minus_1 < p_i && p_i < p_i_plus_1) || 
            (p_i_minus_1 > p_i && p_i > p_i_plus_1)) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
