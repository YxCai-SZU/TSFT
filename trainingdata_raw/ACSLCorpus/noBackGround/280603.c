#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(list + (0 .. len-1));
  assigns \nothing;
  ensures \result == true <==> (\exists integer i; 0 <= i < (len) && (list)[i] == (value));
*/
bool contains_value(int *list, size_t len, int value) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> list[j] != value;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list[i] == value) {
            //@ assert (\exists integer i; 0 <= i < (len) && (list)[i] == (value));
            return true;
        }
        i++;
    }
    //@ assert !(\exists integer i; 0 <= i < (len) && (list)[i] == (value));
    return false;
}
