#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 1000000;
    
    logic integer compute_result(integer n) = 
        (n / 500) * 1000 + ((n % 500) / 5) * 5;
*/

/*@
    requires is_valid_n(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
size_t func(size_t n) {
    size_t div500 = 0;
    size_t temp_n = n;
    size_t mod500;
    size_t div5 = 0;
    size_t result;
    
    //@ assert is_valid_n(n);
    
    /*@
        loop invariant 1 <= n && n <= 1000000;
        loop invariant 0 <= temp_n && temp_n <= n;
        loop invariant div500 <= n / 500;
        loop invariant temp_n == n - div500 * 500;
        loop assigns temp_n, div500;
        loop variant temp_n;
    */
    while (temp_n >= 500) {
        temp_n -= 500;
        div500 += 1;
    }
    
    mod500 = temp_n;
    
    /*@
        loop invariant 1 <= n && n <= 1000000;
        loop invariant 0 <= mod500 && mod500 <= n;
        loop invariant div5 <= n / 5;
        loop invariant mod500 == n - div500 * 500 - div5 * 5;
        loop assigns mod500, div5;
        loop variant mod500;
    */
    while (mod500 >= 5) {
        mod500 -= 5;
        div5 += 1;
    }
    
    result = div500 * 1000 + div5 * 5;
    //@ assert result == compute_result(n);
    return result;
}

int main() {
    return 0;
}
