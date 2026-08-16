#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) > 0 && (n) <= 200000 &&
      \valid((a) + (0..(n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
  ensures \result >= 0 && \result <= n;
*/
int func(int n, int *a) {
    int v[200000];
    int i = 0;
    
    //@ assert n > 0 && n <= 200000;
    
    /*@
      loop invariant ((i) >= 0 && (i) <= (n) &&
      \valid((&v[0]) + (0..(n)-1)) &&
      \forall integer j; 0 <= j < (i) ==> (&v[0])[j] == 0);
      loop invariant n > 0 && n <= 200000;
      loop assigns i, v[0..n-1];
      loop variant n - i;
    */
    while (i < n) {
        //@ assert i >= 0 && i < n;
        v[i] = 0;
        i = i + 1;
        //@ assert ((i) >= 0 && (i) <= (n) &&       \valid((&v[0]) + (0..(n)-1)) &&       \forall integer j; 0 <= j < (i) ==> (&v[0])[j] == 0);
    }
    
    i = 0;
    /*@
      loop invariant ((i) >= 0 && (i) <= (n) &&
      \valid((&v[0]) + (0..(n)-1)) &&
      \forall integer j; 0 <= j < (n) ==> (&v[0])[j] >= 0 &&
      \forall integer j; 0 <= j < (n) ==> (&v[0])[j] <= (i));
      loop invariant ((n) > 0 && (n) <= 200000 &&
      \valid((a) + (0..(n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
      loop assigns i, v[0..n-1];
      loop variant n - i;
    */
    while (i < n) {
        //@ assert i >= 0 && i < n;
        int index = a[i] - 1;
        //@ assert 0 <= index && index < n;
        int current_value = v[index];
        v[index] = current_value + 1;
        i = i + 1;
        //@ assert ((i) >= 0 && (i) <= (n) &&       \valid((&v[0]) + (0..(n)-1)) &&       \forall integer j; 0 <= j < (n) ==> (&v[0])[j] >= 0 &&       \forall integer j; 0 <= j < (n) ==> (&v[0])[j] <= (i));
    }
    
    int max_value = 0;
    int j = 0;
    /*@
      loop invariant ((j) >= 0 && (j) <= (n) &&
      (max_value) >= 0 &&
      (max_value) <= (n) &&
      \valid((&v[0]) + (0..(n)-1)) &&
      \forall integer k; 0 <= k < (j) ==> (max_value) >= (&v[0])[k]);
      loop invariant ((n) > 0 && (n) <= 200000 &&
      \valid((a) + (0..(n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
      loop assigns j, max_value;
      loop variant n - j;
    */
    while (j < n) {
        //@ assert j >= 0 && j < n;
        int value = v[j];
        if (value > max_value) {
            max_value = value;
        }
        j = j + 1;
        //@ assert ((j) >= 0 && (j) <= (n) &&       (max_value) >= 0 &&       (max_value) <= (n) &&       \valid((&v[0]) + (0..(n)-1)) &&       \forall integer k; 0 <= k < (j) ==> (max_value) >= (&v[0])[k]);
    }
    
    //@ assert max_value <= n;
    return max_value;
}
