#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. 4));
  requires ((5) == 5 &&
      (\forall integer i; 0 <= i < (5) ==> 1 <= (arr)[i] && (arr)[i] <= 5) &&
      (\exists integer i; 0 <= i < (5) && (arr)[i] == 0));
  ensures 1 <= \result <= 5;
  ensures \exists integer i; 0 <= i < 5 && (arr[i] == 0 || arr[i] == \result);
*/
unsigned int func(unsigned int *arr) {
    unsigned int result = 0;
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant result == 0 || (1 <= result <= 5);
      loop invariant (\exists integer j; 0 <= j < (i) && ((arr)[j] == 0 || (arr)[j] == (result)));
      loop invariant ((5) == 5 &&
      (\forall integer i; 0 <= i < (5) ==> 1 <= (arr)[i] && (arr)[i] <= 5) &&
      (\exists integer i; 0 <= i < (5) && (arr)[i] == 0));
      loop assigns i, result;
      loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (arr[i] == 0) {
            result = (unsigned int)(i + 1);
            break;
        }
        i++;
    }
    //@ assert 1 <= result <= 5;
    return result;
}
