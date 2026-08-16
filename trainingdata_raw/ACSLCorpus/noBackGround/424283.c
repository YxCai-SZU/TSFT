#include <stdbool.h>

/*@
  requires \valid(arr + (0 .. 4));
  requires ((5) == 5 &&
      \forall integer i; 0 <= i < (5) ==> (1 <= (arr)[i] && (arr)[i] <= 5) &&
      \exists integer i; 0 <= i < (5) && (arr)[i] == 0);
  ensures 1 <= \result <= 5;
  ensures arr[\result - 1] == 0;
  ensures \forall integer i; 0 <= i < 5 && i != \result - 1 ==> arr[i] != 0;
*/
int func(int* arr) {
    int i = 0;
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant \exists integer j; 0 <= j < 5 && arr[j] == 0;
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] != 0;
      loop invariant \forall integer k; 0 <= k < 5 ==> (1 <= arr[k] && arr[k] <= 5);
      loop assigns i;
      loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (arr[i] == 0) {
            //@ assert arr[i] == 0;
            //@ assert \forall integer k; 0 <= k < i ==> arr[k] != 0;
            return i + 1;
        }
        i++;
    }
    return -1;
}
