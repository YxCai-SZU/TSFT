#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. n-1));
  requires ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (arr)[i] >= 1 && (arr)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (arr)[i] != (arr)[j]);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(size_t n, int *arr) {
    int min = 2000001;
    int counter = 0;
    size_t i = 0;
    
    /*@
      loop invariant (0 <= (i) <= (n) &&
      0 <= (counter) <= (i) &&
      ((i) > 0 ==> \forall integer j; 0 <= j < (i) ==> (arr)[j] >= 1 && (arr)[j] <= (n)) &&
      \forall integer j, k; 0 <= j < k < (i) ==> (arr)[j] != (arr)[k] &&
      (n) >= 1 && (n) <= 200000 &&
      \forall integer j; 0 <= j < (n) ==> (arr)[j] >= 1 && (arr)[j] <= (n) &&
      \forall integer j, k; 0 <= j < k < (n) ==> (arr)[j] != (arr)[k] &&
      (counter) <= (i));
      loop assigns i, min, counter;
      loop variant n - i;
    */
    while (i < n) {
        int p = arr[i];
        if (p < min) {
            min = p;
            counter += 1;
        }
        i += 1;
    }
    return counter;
}
