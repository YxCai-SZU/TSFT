#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(v + (0 .. len-1));
    requires \forall size_t i; 0 <= i < len ==> v[i] != 0;
    assigns \nothing;
    ensures \result == true <==> (\forall size_t i; 0 <= i < (len) ==> (v)[i] != 0);
*/
bool func(const int *v, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==> v[j] != 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            return false;
        }
        i++;
    }
    //@ assert i == len;
    //@ assert \forall size_t j; 0 <= j < len ==> v[j] != 0;
    return true;
}
