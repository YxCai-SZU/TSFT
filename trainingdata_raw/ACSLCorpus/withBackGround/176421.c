#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 3;
    predicate b_in_range(integer b) = 1 <= b <= 3;
    predicate product_in_range(integer a, integer b) = a * b <= 9;
    
    logic integer modulo_2(integer c) = c % 2;
    
    lemma product_range_lemma:
        \forall integer a, b;
            a_in_range(a) && b_in_range(b) ==> product_in_range(a, b);
*/

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b) {
    // Variable declarations at scope top
    unsigned int c;
    bool is_odd;
    unsigned int temp;
    
    //@ assert a > 0 && a <= 3;
    //@ assert b > 0 && b <= 3;
    //@ assert a * b <= 9;
    
    c = a * b;
    
    temp = c;
    /*@
        loop invariant 0 <= temp <= a * b;
        loop invariant temp % 2 == c % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2) {
        temp = temp - 2;
    }
    
    is_odd = (temp == 1);
    return is_odd;
}
