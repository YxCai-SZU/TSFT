#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate a_non_negative(integer a) = a >= -100;
    predicate b_non_negative(integer b) = b >= -100;
    predicate a_is_int(integer a) = a == (int)a;
    predicate b_is_int(integer b) = b == (int)b;
    
    logic integer abs_val(integer x) = x < 0 ? -x : x;
    
    lemma unsigned_bound:
        \forall integer x; -100 <= x <= 100 ==> 0 <= abs_val(x) <= 100;
    
    lemma square_bound:
        \forall integer x; 0 <= x <= 100 ==> x * x <= 10000;
*/

/*@
    requires a_in_range(a);
    requires b_in_range(b);
    requires a_non_negative(a);
    requires b_non_negative(b);
    requires a_is_int(a);
    requires b_is_int(b);
    ensures \result == (a * a > b * b);
*/
bool func(int a, int b) {
    unsigned long long a_unsigned;
    unsigned long long b_unsigned;
    unsigned long long a_squared;
    unsigned long long b_squared;
    bool result;
    
    //@ assert a >= -100 && a <= 100;
    //@ assert b >= -100 && b <= 100;
    
    a_unsigned = (a < 0) ? (unsigned long long)(-a) : (unsigned long long)a;
    b_unsigned = (b < 0) ? (unsigned long long)(-b) : (unsigned long long)b;
    
    //@ assert 0 <= a_unsigned <= 100;
    //@ assert 0 <= b_unsigned <= 100;
    
    //@ assert a_unsigned * a_unsigned <= 10000;
    //@ assert b_unsigned * b_unsigned <= 10000;
    
    a_squared = a_unsigned * a_unsigned;
    b_squared = b_unsigned * b_unsigned;
    
    result = (a_squared > b_squared);
    
    //@ assert result == (a * a > b * b);
    return result;
}
