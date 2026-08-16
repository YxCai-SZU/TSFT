#include <stdbool.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;
    
    logic integer mod_100(integer n) = n % 100;
    logic integer div_100(integer n) = n / 100;
    logic integer multiplied(integer n) = div_100(n) * 21;
    
    lemma mod_100_range: \forall integer n; is_valid_n(n) ==> 0 <= mod_100(n) && mod_100(n) <= 99;
    lemma div_100_range: \forall integer n; is_valid_n(n) ==> 0 <= div_100(n) && div_100(n) <= 1000;
    lemma multiplied_range: \forall integer n; is_valid_n(n) ==> 0 <= multiplied(n) && multiplied(n) <= 21000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> multiplied(n) <= n;
    ensures \result == 0 ==> multiplied(n) > n;
*/
unsigned int func(unsigned int n) {
    unsigned int num;
    unsigned int tens;
    unsigned int ones;
    unsigned int div_100_val;
    unsigned int temp_n;
    unsigned int multiplied_val;
    
    num = n % 100;
    tens = num / 10;
    ones = num % 10;
    
    div_100_val = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant 0 <= temp_n <= n;
        loop invariant div_100_val <= n / 100;
        loop invariant temp_n == n - 100 * div_100_val;
        loop assigns temp_n, div_100_val;
    */
    while (temp_n >= 100) {
        //@ assert temp_n >= 100;
        temp_n -= 100;
        div_100_val += 1;
    }
    
    //@ assert temp_n == n % 100;
    //@ assert div_100_val == n / 100;
    
    multiplied_val = div_100_val * 21;
    
    //@ assert multiplied_val == multiplied(n);
    
    if (tens == 0 && ones == 0) {
        //@ assert multiplied_val <= n;
        return 1;
    } else if (multiplied_val <= n) {
        //@ assert multiplied_val <= n;
        return 1;
    } else {
        //@ assert multiplied_val > n;
        return 0;
    }
}
