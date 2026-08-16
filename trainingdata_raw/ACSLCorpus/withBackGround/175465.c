#include <stdbool.h>

/*@ predicate is_even_mod(integer x) = x % 2 == 0; */

/*@ lemma mod_preservation: \forall integer x, y; 
      x >= 0 && y >= 0 && x <= y && y <= 100 ==> 
      (x % 2 == y % 2) ==> (is_even_mod(x) <==> is_even_mod(y)); */

/*@ requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == true <==> (n % 2 == 0 || m % 2 == 0);
    assigns \nothing;
*/
bool func(int n, int m) {
    bool is_even_n = false;
    bool is_even_m = false;
    int temp_n = n;
    int temp_m = m;
    
    //@ assert 1 <= n <= 100 && 1 <= m <= 100;
    
    /*@ loop invariant 0 <= temp_n <= n;
        loop invariant temp_n <= 100;
        loop invariant temp_n % 2 == n % 2;
        loop assigns temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 2) {
        temp_n -= 2;
    }
    
    if (temp_n == 0) {
        is_even_n = true;
    }
    
    /*@ loop invariant 0 <= temp_m <= m;
        loop invariant temp_m <= 100;
        loop invariant temp_m % 2 == m % 2;
        loop assigns temp_m;
        loop variant temp_m;
    */
    while (temp_m >= 2) {
        temp_m -= 2;
    }
    
    if (temp_m == 0) {
        is_even_m = true;
    }
    
    //@ assert is_even_n == (n % 2 == 0);
    //@ assert is_even_m == (m % 2 == 0);
    
    if (is_even_n || is_even_m) {
        //@ assert is_even_n || is_even_m;
        return true;
    } else {
        //@ assert !is_even_n && !is_even_m;
        return false;
    }
}
