#include <stdbool.h>
#include <limits.h>

/*@
  requires (2 <= (n) && (n) <= 20);
  requires \valid(inputs + (0 .. n-1));
  requires (\forall integer j; 0 <= j < (n) ==> 1 <= (inputs)[j] && (inputs)[j] <= 100);
  ensures \result >= 0;
*/
int func(int n, int *inputs) {
    int max_val;
    int min_val;
    int i;
    int count;
    int j;
    int n_minus_count;
    
    max_val = inputs[0];
    min_val = inputs[0];
    i = 1;
    
    /*@
      loop invariant 1 <= i <= n;
      loop invariant (\forall integer k; 0 <= k < (i) ==> (max_val) >= (inputs)[k]);
      loop invariant (\forall integer k; 0 <= k < (i) ==> (min_val) <= (inputs)[k]);
      loop invariant 1 <= max_val <= 100;
      loop invariant 1 <= min_val <= 100;
      loop assigns i, max_val, min_val;
    */
    while (i < n) {
        //@ assert max_val >= 1 && max_val <= 100;
        max_val = (inputs[i] > max_val) ? inputs[i] : max_val;
        //@ assert min_val >= 1 && min_val <= 100;
        min_val = (inputs[i] < min_val) ? inputs[i] : min_val;
        i = i + 1;
    }
    
    count = 0;
    j = 0;
    
    /*@
      loop invariant 0 <= j <= n;
      loop invariant ((count) >= 0 && (count) <= (j));
      loop assigns j, count;
    */
    while (j < n) {
        //@ assert count >= 0 && count <= j;
        if (inputs[j] == max_val || inputs[j] == min_val) {
            count = count + 1;
        }
        j = j + 1;
    }
    
    n_minus_count = n - count;
    
    if (n_minus_count < count) {
        //@ assert n_minus_count >= 0;
        return n_minus_count;
    } else {
        //@ assert count >= 0;
        return count;
    }
}
