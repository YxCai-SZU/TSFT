#include <stdbool.h>

/*@
  requires \valid(arr + (0 .. 2));
  requires ((3) == 3 &&
      \forall integer i; 0 <= i < (3) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
  ensures \result == 1 || \result == 0;
  ensures \result == 1 ==> ((arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]);
  ensures \result == 0 ==> !((arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]);
*/
int can_arrange_gte(int *arr) {
    int ret;
    //@ assert ((3) == 3 &&       \forall integer i; 0 <= i < (3) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
    if (arr[0] < arr[1] && arr[1] < arr[2]) {
        //@ assert ((arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]);
        ret = 1;
    } else {
        //@ assert !((arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]);
        ret = 0;
    }
    //@ assert ret == 1 || ret == 0;
    return ret;
}
