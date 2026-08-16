#include <stddef.h>

/*@
    predicate equal_ranges{L}(int *s1, int *s2, integer start, integer end) =
        \forall integer i; start <= i < end ==> s1[i] == s2[i];
*/

/*@
    requires 0 <= 10 <= len && 10 <= 20 <= len && 20 <= 30 <= len;
    requires \valid(s1+(0..len-1)) && \valid(s2+(0..len-1));
    requires \forall integer i; 0 <= i < len ==> s1[i] == s2[i];
    ensures equal_ranges(s1, s2, 10, 20);
    assigns \nothing;
*/
void use_arith(int *s1, int *s2, size_t len) {
    //@ assert 0 <= 10 <= len;
    
    /*@
        loop invariant 10 <= i <= 20;
        loop invariant \forall integer j; 10 <= j < i ==> s1[j] == s2[j];
        loop assigns i;
    */
    for (size_t i = 10; i < 20; ++i) {
        //@ assert s1[i] == s2[i];
    }
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
