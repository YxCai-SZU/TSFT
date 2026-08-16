#include <stdbool.h>

/*@
  requires \valid(v+(0..4));
  requires v[0] >= -100 && v[0] <= 100;
  requires v[1] >= -100 && v[1] <= 100;
  requires v[2] >= -100 && v[2] <= 100;
  requires v[3] >= -100 && v[3] <= 100;
  requires v[4] >= -100 && v[4] <= 100;
  ensures ((\result) == (v[0]) || (\result) == (v[1]) || (\result) == (v[2]) || (\result) == (v[3]) || (\result) == (v[4]));
*/
long func(long v[5])
{
    long min_val;
    int i;
    min_val = v[0];
    i = 1;
    //@ assert (\exists integer j; 0 <= j < (1) && (min_val) == (v)[j]);
    
    /*@ loop invariant 1 <= i <= 5;
        loop invariant (\exists integer j; 0 <= j < (i) && (min_val) == (v)[j]);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (min_val) <= (v)[k]);
        loop assigns min_val, i;
        loop variant 5 - i;
    */
    while (i < 5) {
        long val;
        val = v[i];
        if (val < min_val) {
            min_val = val;
        }
        i = i + 1;
    }
    //@ assert ((min_val) == (v[0]) || (min_val) == (v[1]) || (min_val) == (v[2]) || (min_val) == (v[3]) || (min_val) == (v[4]));
    return min_val;
}
