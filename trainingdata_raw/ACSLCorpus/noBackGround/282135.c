#include <stdbool.h>

/*@
  requires n > 0;
  requires \valid(arr + (0 .. n-1));
  requires (\forall integer i, j; 0 <= i < j < (n) ==> (arr)[i] <= (arr)[j]);
  ensures \result == true ==> (\exists integer i, j; 0 <= i < j < (n) && (arr)[i] == (arr)[j]);
  ensures \result == false ==> (\forall integer i, j; 0 <= i < j < (n) ==> (arr)[i] != (arr)[j]);
*/
bool has_duplicates(int *arr, int n) {
    int i = 1;
    /*@
      loop invariant 1 <= i <= n;
      loop invariant \forall integer k, l; 0 <= k < l < i ==> arr[k] != arr[l];
      loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (arr)[i] <= (arr)[j]);
      loop assigns i;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 1 <= i && i < n;
        if (arr[i] == arr[i - 1]) {
            return true;
        }
        i++;
    }
    return false;
}
