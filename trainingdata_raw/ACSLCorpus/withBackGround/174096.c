#include <stdbool.h>

/*@
    predicate is_abs(integer n, integer abs) =
        (n >= 0 ==> abs == n) && (n < 0 ==> abs == -n);
    
    logic integer manual_div(integer n, integer div) = n - 10 * div;
    
    lemma div_correct: \forall integer n, div, temp;
        10 <= n <= 99 && 0 <= temp <= n && temp == manual_div(n, div) && div >= 0 ==> 
        (temp < 10 ==> div == n / 10);
    
    lemma mod_correct: \forall integer n, div, temp;
        10 <= n <= 99 && 0 <= temp <= n && temp == manual_div(n, div) && div >= 0 ==> 
        (temp < 10 ==> temp == n % 10);
*/

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || n / 10 == 9);
*/
bool func(int n) {
    int n_abs;
    int div = 0;
    int temp;
    int mod_result;
    int div_neg;
    bool result;
    
    // Calculate absolute value
    if (n < 0) {
        n_abs = -n;
    } else {
        n_abs = n;
    }
    //@ assert is_abs(n, n_abs);
    
    temp = n_abs;
    
    /*@
        loop invariant 0 <= temp <= n_abs;
        loop invariant temp == manual_div(n_abs, div);
        loop invariant div >= 0;
        loop assigns temp, div;
    */
    while (temp >= 10) {
        temp -= 10;
        div += 1;
    }
    
    //@ assert temp < 10;
    mod_result = temp;
    
    // Adjust sign for division result
    if (n < 0) {
        div_neg = -div;
    } else {
        div_neg = div;
    }
    
    //@ assert div_neg == n / 10;
    //@ assert mod_result == n % 10;
    
    result = (div_neg == 9 || mod_result == 9);
    
    return result;
}
