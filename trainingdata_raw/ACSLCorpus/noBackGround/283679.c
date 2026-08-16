#include <stdbool.h>
#include <stdint.h>

/*@
    requires \valid(s);
    requires \forall integer k; k != element ==> ((k) != (element) ==> \at((s)[\at((s)[0], Pre)], Here) == \at((s)[\at((s)[0], Pre)], Pre));
    ensures \result == (s[element] != 0);
*/
bool check_element(int *s, uint32_t element) {
    bool contains;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= element + 1;
        loop invariant \forall integer j; 0 <= j < i && j != element ==> ((j) != (element) ==> \at((s)[\at((s)[0], Pre)], Here) == \at((s)[\at((s)[0], Pre)], Pre));
        loop assigns i;
    */
    for (i = 0; i <= element; i++) {
        //@ assert i != element ==> ((i) != (element) ==> \at((s)[\at((s)[0], Pre)], Here) == \at((s)[\at((s)[0], Pre)], Pre));
    }
    
    contains = (s[element] != 0);
    //@ assert contains == (s[element] != 0);
    
    return contains;
}
