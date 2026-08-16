#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(list+(0..len-1));
    requires len <= 0x80000000;
    assigns \nothing;
    ensures \result == true <==> (\exists integer i; 0 <= i < (len) && (list)[i] == 0);
*/
bool split(int *list, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (list)[j] != 0);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (list[i] == 0) {
            //@ assert (\exists integer i; 0 <= i < (len) && (list)[i] == 0);
            return true;
        }
        i = i + 1;
    }
    //@ assert !(\exists integer i; 0 <= i < (len) && (list)[i] == 0);
    return false;
}
