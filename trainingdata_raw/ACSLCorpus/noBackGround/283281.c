#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(list+(0..len-1));
  requires len > 0;
  assigns \nothing;
  ensures \result == 1 <==> (\exists integer i; (0 <= (i) < ((len)) && ((list))[(i)] == ((target))));
*/
bool search(int *list, size_t len, int target) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> !(0 <= (j) < (len) && (list)[(j)] == (target));
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (list[i] == target) {
            //@ assert (0 <= (i) < (len) && (list)[(i)] == (target));
            return true;
        }
        //@ assert !(0 <= (i) < (len) && (list)[(i)] == (target));
        i++;
    }
    //@ assert \forall integer j; 0 <= j < len ==> !(0 <= (j) < (len) && (list)[(j)] == (target));
    return false;
}
