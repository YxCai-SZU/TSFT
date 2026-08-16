#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(a + (0..4));
  requires ((5) == 5 &&
      (\forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] && (a)[i] <= 5) &&
      (\exists integer i; 0 <= i < (5) && (a)[i] == 0));
  ensures \result >= 1 && \result <= 5;
  ensures a[\result - 1] == 0;
*/
int func(int* a) {
    int i;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant \valid(a + (0..4));
      loop invariant ((5) == 5 &&
      (\forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] && (a)[i] <= 5) &&
      (\exists integer i; 0 <= i < (5) && (a)[i] == 0));
      loop invariant \forall integer k; 0 <= k < i ==> a[k] != 0;
      loop assigns i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (a[i] == 0) {
            //@ assert a[i] == 0;
            //@ assert \exists integer j; 0 <= j < 5 && a[j] == 0;
            return i + 1;
        }
        //@ assert a[i] != 0;
        i = i + 1;
    }
    //@ assert \forall integer k; 0 <= k < 5 ==> a[k] != 0;
    //@ assert \exists integer i; 0 <= i < 5 && a[i] == 0;
    return -1;
}
