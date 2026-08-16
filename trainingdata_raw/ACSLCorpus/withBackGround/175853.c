#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= b <= 100;

    logic integer div8(integer i) = i * 8 / 100;
    logic integer div10(integer i) = i * 10 / 100;

    lemma div8_range: \forall integer i; 1 <= i <= 1000 ==> 0 <= div8(i) <= 80;
    lemma div10_range: \forall integer i; 1 <= i <= 1000 ==> 0 <= div10(i) <= 100;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 1 || \result == -1;
    ensures \result == -1 || (div8(\result) == a && div10(\result) == b);
*/
int64_t func(int64_t a, int64_t b) {
    int64_t i = 1;
    /*@
        loop invariant 1 <= a <= b <= 100;
        loop invariant 1 <= i <= 1001;
        loop invariant \forall integer j; 1 <= j < i ==> !(div8(j) == a && div10(j) == b);
        loop assigns i;
        loop variant 1001 - i;
    */
    while (i <= 1000) {
        int64_t aa = 0;
        int64_t bb = 0;
        int64_t temp;
        
        temp = i * 8;
        /*@
            loop invariant 0 <= aa <= div8(i);
            loop invariant temp == i * 8 - aa * 100;
            loop assigns aa, temp;
            loop variant temp;
        */
        while (temp >= 100) {
            temp -= 100;
            aa += 1;
        }
        
        temp = i * 10;
        /*@
            loop invariant 0 <= bb <= div10(i);
            loop invariant temp == i * 10 - bb * 100;
            loop assigns bb, temp;
            loop variant temp;
        */
        while (temp >= 100) {
            temp -= 100;
            bb += 1;
        }
        
        //@ assert aa == div8(i);
        //@ assert bb == div10(i);
        
        if (aa == a && bb == b) {
            return i;
        }
        i += 1;
    }
    return -1;
}
