#include <stdbool.h>

/*@
  requires len > 0;
  requires \valid(a + (0 .. len - 1));
  assigns \nothing;
  ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) - 1 ==> (a)[i] < (a)[i + 1]);
*/
bool is_increasing(int *a, int len) {
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= len - 1;
      loop invariant \forall integer j; 0 <= j < i ==> a[j] < a[j + 1];
      loop assigns i;
      loop variant len - 1 - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (a[i] >= a[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}
