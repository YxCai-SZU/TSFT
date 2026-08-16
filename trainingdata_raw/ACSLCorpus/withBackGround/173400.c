#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ predicate all_even_before(unsigned int *v, integer len, integer idx) =
      \forall integer i; 0 <= i < idx ==> v[i] % 2 == 0;
*/

/*@ predicate all_even(unsigned int *v, integer len) =
      \forall integer i; 0 <= i < len ==> v[i] % 2 == 0;
*/

/*@ lemma all_even_implies_all_even_before:
      \forall unsigned int *v, integer len, integer idx;
        all_even(v, len) && 0 <= idx <= len ==> all_even_before(v, len, idx);
*/

/*@ lemma all_even_before_extend:
      \forall unsigned int *v, integer len, integer idx;
        all_even_before(v, len, idx) && idx < len && v[idx] % 2 == 0 ==>
        all_even_before(v, len, idx + 1);
*/

/*@ requires \valid(v + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == -1 ==> all_even(v, len);
    ensures 0 <= \result < len ==> v[\result] % 2 != 0 && all_even_before(v, len, \result);
*/
int find_first_odd(const unsigned int *v, size_t len) {
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant all_even_before((unsigned int*)v, len, index);
        loop invariant len < 0x80000000;
        loop assigns index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert index < len;
        if (v[index] % 2 != 0) {
            //@ assert v[index] % 2 != 0;
            //@ assert all_even_before((unsigned int*)v, len, index);
            return (int)index;
        }
        //@ assert v[index] % 2 == 0;
        //@ assert all_even_before((unsigned int*)v, len, index);
        index++;
        //@ assert index <= len;
    }
    //@ assert index == len;
    //@ assert all_even_before((unsigned int*)v, len, len);
    //@ assert all_even((unsigned int*)v, len);
    return -1;
}
