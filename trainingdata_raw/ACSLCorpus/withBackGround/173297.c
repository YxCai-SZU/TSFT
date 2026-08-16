#include <stddef.h>
#include <stdint.h>

/*@ predicate count_constraint(integer i, integer len, int *list, integer threshold, integer count) =
    (0 <= i <= len) &&
    (count <= i) &&
    (\forall integer j; 0 <= j < i ==> ((list[j] > threshold ==> count >= 1) || (list[j] <= threshold ==> count >= 0)));
*/

/*@ lemma count_bound: \forall integer i, integer len, integer count;
    count_constraint(i, len, \null, 0, count) ==> count <= len;
*/

/*@ requires \valid(list + (0 .. len-1));
    requires len <= 0x80000000;
    assigns \nothing;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> 
            ((list[i] > threshold ==> \result >= 1) || (list[i] <= threshold ==> \result >= 0));
*/
size_t count_greater_than(int *list, size_t len, int threshold) {
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 
                      ((list[j] > threshold ==> count >= 1) || (list[j] <= threshold ==> count >= 0));
        loop invariant len <= 0x80000000;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (list[i] > threshold) {
            //@ assert list[i] > threshold;
            count++;
        }
        i++;
    }
    return count;
}
