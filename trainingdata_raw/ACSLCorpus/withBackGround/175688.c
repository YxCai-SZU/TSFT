#include <stddef.h>
#include <stdbool.h>

/*@
    predicate count_in_range(integer i, integer c, integer len) =
        0 <= i <= len && 0 <= c <= i;

    predicate element_present(int *list, integer i, integer e, integer c) =
        \forall integer j; 0 <= j < i ==> 
            (list[j] == e ==> c > 0);

    predicate element_absent(int *list, integer i, integer e, integer c) =
        \forall integer j; 0 <= j < i ==> 
            (list[j] != e ==> c <= i - 1);

    lemma loop_invariant_maintained:
        \forall int *list, integer i, integer e, integer c, integer len;
        count_in_range(i, c, len) && element_present(list, i, e, c) && 
        element_absent(list, i, e, c) && i < len ==>
        count_in_range(i+1, (list[i] == e ? c+1 : c), len) &&
        element_present(list, i+1, e, (list[i] == e ? c+1 : c)) &&
        element_absent(list, i+1, e, (list[i] == e ? c+1 : c));
*/

/*@
    requires \valid(list+(0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> 
        (list[i] == element ==> \result > 0);
    ensures \forall integer i; 0 <= i < len ==> 
        (list[i] != element ==> \result <= len - 1);
*/
size_t count_occurrences(int *list, size_t len, int element) {
    size_t count;
    size_t i;
    
    count = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 
            (list[j] == element ==> count > 0);
        loop invariant \forall integer j; 0 <= j < i ==> 
            (list[j] != element ==> count <= i - 1);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert count_in_range(i, count, len);
        
        if (list[i] == element) {
            count = count + 1;
        }
        i = i + 1;
    }
    
    return count;
}
