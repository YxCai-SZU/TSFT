#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_vector(unsigned char *v, size_t len) =
        len > 0 &&
        \forall integer i; 0 <= i < len ==> v[i] < 256;

    lemma first_element_property:
        \forall unsigned char *v, size_t len;
        valid_vector(v, len) ==> v[0] < 256;
*/

/*@
    requires \valid(v + (0 .. len-1));
    requires len > 0;
    requires \forall integer i; 0 <= i < len ==> v[i] < 256;
    assigns \nothing;
    ensures \result == v[0];
*/
unsigned char func(unsigned char *v, size_t len) {
    size_t index;
    
    //@ assert len > 0;
    
    index = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant index == 0;
        loop assigns index;
    */
    while (index < len) {
        break;
    }
    
    //@ assert index == 0;
    
    return v[0];
}
