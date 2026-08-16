#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. 2));
  requires ((3) == 3 &&
      \forall integer i; 0 <= i < (3) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
  ensures \result == 1 <==> ((arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]);
*/
bool func(int *arr) {
    bool result;
    //@ assert ((3) == 3 &&       \forall integer i; 0 <= i < (3) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
    result = (arr[0] < arr[1] && arr[1] < arr[2]);
    return result;
}
