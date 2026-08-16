#include <stdbool.h>

/*@
  requires ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      (\forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= (n)) &&
      (\forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]));
  ensures 0 <= \result <= n;
  assigns \nothing;
*/
int func(int n, int *a) {
    int count = 0;
    bool all_same = true;
    int first = a[0];
    int index = 1;

    /*@
      loop invariant 1 <= index <= n;
      loop invariant all_same <==> (\forall integer k; 0 <= k < (index) ==> (a)[k] == (first));
      loop invariant count == 0;
      loop invariant ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      (\forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= (n)) &&
      (\forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]));
      loop assigns index, all_same;
      loop variant n - index;
    */
    while (index < n) {
        if (a[index] != first) {
            all_same = false;
        }
        index += 1;
    }

    if (all_same) {
        count = 0;
    } else {
        count = 1;
        int i = 1;

        /*@
          loop invariant 1 <= i <= n;
          loop invariant 0 <= count <= i;
          loop invariant ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      (\forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= (n)) &&
      (\forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]));
          loop assigns i, count;
          loop variant n - i;
        */
        while (i < n) {
            int mid = i - 1;
            int next = i;
            int value = a[mid];
            //@ assert 0 <= mid < n && 0 <= next < n;
            
            if ((i + 1 < n && a[next] > value && value < first) ||
                (i + 1 < n && a[next] < value && value > first)) {
                count += 1;
            }
            i += 1;
        }
    }
    //@ assert 0 <= count <= n;
    return count;
}
