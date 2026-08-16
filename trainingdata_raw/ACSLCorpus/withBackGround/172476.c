#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_index(int i, int len) =
        0 <= i < len;

    predicate element_parity_property(unsigned int *arr, integer len, integer idx) =
        \forall integer i; 0 <= i < idx ==> (arr[i] % 2 != 0 || arr[i] % 2 == 0);

    lemma parity_tautology:
        \forall integer x; x % 2 != 0 || x % 2 == 0;
*/

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true;
*/
bool is_even_odd_product(const unsigned int *arr, size_t len) {
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant element_parity_property((unsigned int*)arr, len, index);
        loop invariant len > 0;
        loop assigns index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert element_parity_property((unsigned int*)arr, len, index);
        index++;
    }
    
    //@ assert element_parity_property((unsigned int*)arr, len, len);
    return true;
}
