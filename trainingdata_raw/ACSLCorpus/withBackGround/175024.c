#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate c_in_range(integer c) = 1 <= c <= 100;
    predicate d_in_range(integer d) = 1 <= d <= 100;
    
    logic integer sum_ab1(integer a, integer b) = a + b + 1;
    logic integer sum_cd(integer c, integer d) = c + d;
    logic integer sum_ad(integer a, integer d) = a + d;
    logic integer c_plus_1(integer c) = c + 1;
    
    lemma sum_ab1_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> sum_ab1(a, b) <= 201;
    lemma sum_cd_bound: \forall integer c, d; c_in_range(c) && d_in_range(d) ==> sum_cd(c, d) <= 200;
    lemma sum_ad_bound: \forall integer a, d; a_in_range(a) && d_in_range(d) ==> sum_ad(a, d) <= 200;
    lemma c_plus_1_bound: \forall integer c; c_in_range(c) ==> c_plus_1(c) <= 101;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (a + b + 1 >= c && c + d >= b || a + d >= c + 1);
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= d && d <= 100;
    //@ assert a + b + 1 <= 201;
    //@ assert c + d <= 200;
    //@ assert a + d <= 200;
    //@ assert c + 1 <= 101;
    
    if (a + b + 1 >= c && c + d >= b || a + d >= c + 1) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
