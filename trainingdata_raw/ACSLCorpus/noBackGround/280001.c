#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(test_tup + (0 .. length-1));
  assigns \nothing;
  ensures \result == true <==> (\exists integer i; 0 <= i < (length) && (test_tup)[i] == 0);
*/
bool check_none(int *test_tup, size_t length) {
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= length;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (test_tup)[j] != 0);
        loop assigns i;
        loop variant length - i;
    */
    while (i < length) {
        if (test_tup[i] == 0) {
            //@ assert (\exists integer i; 0 <= i < (length) && (test_tup)[i] == 0);
            return true;
        }
        i++;
    }
    //@ assert \forall integer j; 0 <= j < length ==> test_tup[j] != 0;
    return false;
}
