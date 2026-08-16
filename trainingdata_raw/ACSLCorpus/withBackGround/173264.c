#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer mod3(integer x) = x % 3;
    
    lemma mod_property:
        \forall integer x, y; 0 <= x <= y ==> mod3(x) == mod3(y) ==> x % 3 == y % 3;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(unsigned int a, unsigned int b) {
    bool is_possible = false;
    unsigned int a_mod = a;
    unsigned int b_mod = b;
    unsigned int sum_mod = a + b;
    
    //@ assert a_mod == a && b_mod == b && sum_mod == a + b;
    
    /*@
        loop invariant 0 <= a_mod <= a;
        loop invariant a_mod % 3 == a % 3;
        loop invariant a_in_range(a);
        loop assigns a_mod;
        loop variant a_mod;
    */
    while (a_mod >= 3) {
        a_mod -= 3;
    }
    
    /*@
        loop invariant 0 <= b_mod <= b;
        loop invariant b_mod % 3 == b % 3;
        loop invariant b_in_range(b);
        loop assigns b_mod;
        loop variant b_mod;
    */
    while (b_mod >= 3) {
        b_mod -= 3;
    }
    
    /*@
        loop invariant 0 <= sum_mod <= a + b;
        loop invariant sum_mod % 3 == (a + b) % 3;
        loop invariant a_in_range(a) && b_in_range(b);
        loop assigns sum_mod;
        loop variant sum_mod;
    */
    while (sum_mod >= 3) {
        sum_mod -= 3;
    }
    
    //@ assert a_mod == a % 3 && b_mod == b % 3 && sum_mod == (a + b) % 3;
    
    if (a_mod == 0 || b_mod == 0 || sum_mod == 0) {
        is_possible = true;
    }
    
    //@ assert is_possible == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    return is_possible;
}
