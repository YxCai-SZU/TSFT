#include <stdbool.h>

/*@
    predicate a_leq_c(integer a, integer c) = a <= c;
    predicate b_geq_d(integer b, integer d) = b >= d;
    
    lemma both_conditions:
        \forall integer a, b, c, d;
        a_leq_c(a, c) && b_geq_d(b, d) ==> a <= c && b >= d;
*/

/*@
    requires 0 <= a <= 1;
    requires 0 <= b <= 1;
    requires 0 <= c <= 1;
    requires 0 <= d <= 1;
    ensures \result == true <==> (a <= c && b >= d);
*/
bool func(int a, int b, int c, int d) {
    int a_leq_c;
    int b_geq_d;
    int result;
    bool ret_val;
    
    //@ assert 0 <= a <= 1 && 0 <= b <= 1 && 0 <= c <= 1 && 0 <= d <= 1;
    
    if (a <= c) {
        a_leq_c = 1;
    } else {
        a_leq_c = 0;
    }
    
    if (b >= d) {
        b_geq_d = 1;
    } else {
        b_geq_d = 0;
    }
    
    //@ assert a_leq_c == 1 <==> a <= c;
    //@ assert b_geq_d == 1 <==> b >= d;
    
    result = a_leq_c * b_geq_d;
    ret_val = (result == 1);
    
    //@ assert ret_val == true <==> (a <= c && b >= d);
    return ret_val;
}
