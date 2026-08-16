#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(a + (0..len-1));
    requires \valid_read(b + (0..len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result == true ==> (\forall integer i; 0 <= i < (len) ==> (a)[i] == (b)[i]);
    ensures \result == false ==> (\exists integer i; 0 <= i < (len) && (a)[i] != (b)[i]);
*/
bool func(int *a, int *b, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] == b[j];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (a[i] != b[i]) {
            //@ assert (\exists integer i; 0 <= i < (len) && (a)[i] != (b)[i]);
            return false;
        }
        i++;
    }
    //@ assert (\forall integer i; 0 <= i < (len) ==> (a)[i] == (b)[i]);
    return true;
}
