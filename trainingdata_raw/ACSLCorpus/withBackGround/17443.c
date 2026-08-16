#include <stdbool.h>

/*@
    predicate a_multiple_of_3(integer a) = (a / 3) * 3 == a;
    predicate b_multiple_of_3(integer b) = (b / 3) * 3 == b;
    predicate sum_multiple_of_3(integer a, integer b) = ((a + b) / 3) * 3 == a + b;
    
    lemma a_mod_equiv: \forall integer a; 1 <= a <= 100 ==> (a_multiple_of_3(a) <==> a % 3 == 0);
    lemma b_mod_equiv: \forall integer b; 1 <= b <= 100 ==> (b_multiple_of_3(b) <==> b % 3 == 0);
    lemma sum_mod_equiv: \forall integer a, b; 1 <= a <= 100 && 1 <= b <= 100 ==> 
        (sum_multiple_of_3(a, b) <==> (a + b) % 3 == 0);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(unsigned long long a, unsigned long long b) {
    bool a_multiple_of_3;
    bool b_multiple_of_3;
    bool sum_multiple_of_3;
    bool result;
    
    a_multiple_of_3 = (a / 3) * 3 == a;
    b_multiple_of_3 = (b / 3) * 3 == b;
    sum_multiple_of_3 = ((a + b) / 3) * 3 == a + b;
    
    //@ assert a_multiple_of_3 == ((a / 3) * 3 == a);
    //@ assert b_multiple_of_3 == ((b / 3) * 3 == b);
    //@ assert sum_multiple_of_3 == (((a + b) / 3) * 3 == a + b);
    
    result = a_multiple_of_3 || b_multiple_of_3 || sum_multiple_of_3;
    
    return result;
}
