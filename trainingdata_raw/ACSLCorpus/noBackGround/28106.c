#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(list+(0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == true <==> (\exists size_t k; 0 <= k < (len) && (list)[k] == (element));
*/
bool contains_element(int *list, size_t len, int element) {
    size_t i = 0;
    /*@ loop invariant 0 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==> list[j] != element;
        loop invariant len < 0x80000000;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list[i] == element) {
            //@ assert (\exists size_t k; 0 <= k < (len) && (list)[k] == (element));
            return true;
        }
        i++;
    }
    //@ assert \forall size_t j; 0 <= j < len ==> list[j] != element;
    //@ assert !(\exists size_t k; 0 <= k < (len) && (list)[k] == (element));
    return false;
}
