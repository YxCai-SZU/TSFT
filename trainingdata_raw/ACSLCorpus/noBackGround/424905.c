#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (n / 10 == 9 || n % 10 == 9);
*/
bool func(long n) {
    long n_abs;
    long div;
    long temp;
    long mod_res;
    
    // Calculate absolute value
    if (n < 0) {
        n_abs = -n;
    } else {
        n_abs = n;
    }
    
    // First loop: compute division part
    div = 0;
    temp = n_abs;
    /*@
        loop invariant 0 <= temp <= n_abs;
        loop invariant 0 <= div <= n_abs / 10;
        loop invariant temp == n_abs - 10 * div;
        loop assigns temp, div;
        loop variant temp;
    */
    while (temp >= 10) {
        temp -= 10;
        div += 1;
    }
    
    // Second loop: compute modulo part
    mod_res = n_abs;
    /*@
        loop invariant 0 <= mod_res <= n_abs;
        loop invariant mod_res == n_abs - 10 * ((n_abs - mod_res) / 10);
        loop assigns mod_res;
        loop variant mod_res;
    */
    while (mod_res >= 10) {
        mod_res -= 10;
    }
    
    // Final check
    if (div == 9 || mod_res == 9) {
        return true;
    } else {
        return false;
    }
}

