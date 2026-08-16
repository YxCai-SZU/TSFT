#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 200000;
  requires \valid(arr + (0 .. n-1));
  requires ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (arr)[i] >= 1 && (arr)[i] <= (n));
  ensures \result >= 0 && \result <= n;
  assigns \nothing;
*/
int func(int n, int *arr) {
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant (0 <= (i) <= (n) &&
      0 <= (count) <= (i) &&
      (((n)) >= 1 && ((n)) <= 200000 &&
      \forall integer i; 0 <= i < ((n)) ==> ((arr))[i] >= 1 && ((arr))[i] <= ((n))));
      loop invariant n - i >= 0;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < (size_t)n) {
        //@ assert i < n;
        if ((int)i == arr[i] - 1) {
            count++;
        }
        i++;
    }
    
    int min_value = (count < 2) ? count : 2;
    return min_value;
}
