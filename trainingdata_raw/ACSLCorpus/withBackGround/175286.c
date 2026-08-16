/*@
predicate is_greater_than_zero(integer x) = x > 0;

lemma lemma_two_greater_than_zero:
    \forall integer x; x > 0 ==> x + x > 0;

lemma establish_forall{L}:
    \forall int *v, integer len;
        (\forall integer i; 0 <= i < len ==> is_greater_than_zero(v[i])) ==>
        (\forall integer i; 0 <= i < len ==> v[i] > -1);
*/

#include <stddef.h>

/*@
    requires \valid(v + (0..len-1));
    requires \forall integer i; 0 <= i < len ==> v[i] > 0;
    ensures \forall integer i; 0 <= i < len ==> v[i] > -1;
*/
void process_array(int *v, size_t len) {
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> v[j] > -1;
        loop assigns i;
        loop variant len - i;
    */
    for (size_t i = 0; i < len; ++i) {
        //@ assert v[i] > 0;
        //@ assert v[i] > -1;
    }
}

int main() {
    return 0;
}
