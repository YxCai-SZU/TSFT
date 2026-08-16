#include <limits.h>

/*@
    predicate is_valid_x(integer x) = 0 <= x <= 1000000000;

    logic integer div_500_result(integer x) = x / 500;
    logic integer mod_500_result(integer x) = x % 500;
    logic integer div_5_result(integer m) = m / 5;
    logic integer expected_result(integer x) = 
        div_500_result(x) * 1000 + div_5_result(mod_500_result(x)) * 5;

    lemma div_500_bound: \forall integer x; is_valid_x(x) ==> 0 <= div_500_result(x);
    lemma mod_500_bound: \forall integer x; is_valid_x(x) ==> 0 <= mod_500_result(x) < 500;
    lemma div_5_bound: \forall integer m; 0 <= m < 500 ==> 0 <= div_5_result(m) <= 99;
*/

/*@
    requires is_valid_x(x);
    ensures \result == expected_result(x);
    assigns \nothing;
*/
long func(long x) {
    long div_500;
    long temp_x;
    long mod_500;
    long div_5;
    long result;
    
    div_500 = 0;
    temp_x = x;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant div_500 >= 0;
        loop invariant temp_x == x - div_500 * 500;
        loop assigns temp_x, div_500;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        temp_x = temp_x - 500;
        div_500 = div_500 + 1;
    }
    
    mod_500 = temp_x;
    div_5 = 0;
    
    /*@
        loop invariant 0 <= mod_500 <= x;
        loop invariant div_5 >= 0;
        loop invariant mod_500 == x - div_500 * 500 - div_5 * 5;
        loop invariant div_500 >= 0;
        loop invariant div_500 <= x / 500;
        loop invariant div_5 <= (x - div_500 * 500) / 5;
        loop assigns mod_500, div_5;
        loop variant mod_500;
    */
    while (mod_500 >= 5) {
        mod_500 = mod_500 - 5;
        div_5 = div_5 + 1;
    }
    
    result = div_500 * 1000 + div_5 * 5;
    
    //@ assert result == expected_result(x);
    return result;
}

int main() {
    return 0;
}
