#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(arr + (0 .. 4));
  requires ((5) == 5 &&
      \forall integer i; 0 <= i < (5) ==> 1 <= (arr)[i] && (arr)[i] <= 5);
  requires (\exists integer i; 0 <= i < (5) && (arr)[i] == 0);
  ensures 1 <= \result && \result <= 5;
  ensures arr[\result - 1] == 0;
*/
int func(int* arr) {
    int index = 0;
    /*@
      loop invariant 0 <= index <= 5;
      loop invariant \forall integer i; 0 <= i < index ==> 1 <= arr[i] && arr[i] <= 5;
      loop invariant ((5) == 5 &&
      \forall integer i; 0 <= i < (5) ==> 1 <= (arr)[i] && (arr)[i] <= 5);
      loop invariant (\exists integer i; 0 <= i < (5) && (arr)[i] == 0);
      loop assigns index;
      loop variant 5 - index;
    */
    while (index < 5) {
        //@ assert 0 <= index < 5;
        if (arr[index] == 0) {
            //@ assert arr[index] == 0;
            //@ assert 0 <= index < 5;
            return index + 1;
        }
        //@ assert arr[index] != 0;
        index++;
    }
    return -1;
}
