#include <stdbool.h>

/*@ requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || (n / 10) % 10 == 9);
    assigns \nothing;
 */
bool func(unsigned long n) {
    unsigned long n_mod_10 = n;
    unsigned long n_div_10 = n;
    unsigned long count = 0;
    bool result;

    // First loop: compute n % 10
    /*@ loop invariant 10 <= n <= 99;
        loop invariant 0 <= n_mod_10 <= n;
        loop invariant n_mod_10 == n || n_mod_10+10 == n || n_mod_10+20 == n || 
                       n_mod_10+30 == n || n_mod_10+40 == n || n_mod_10+50 == n || 
                       n_mod_10+60 == n || n_mod_10+70 == n || n_mod_10+80 == n || 
                       n_mod_10+90 == n;
        loop invariant ((n_mod_10) % 10) == ((n) % 10);
        loop assigns n_mod_10;
        loop variant n_mod_10;
     */
    while (n_mod_10 >= 10) {
        //@ assert n_mod_10 >= 10;
        n_mod_10 -= 10;
    }

    // Second loop: compute n / 10
    /*@ loop invariant 10 <= n <= 99;
        loop invariant 0 <= n_div_10 <= n;
        loop invariant 0 <= count <= n / 10;
        loop invariant n_div_10 == n - 10 * count;
        loop invariant count > 0 ==> ((n_div_10) % 10) == ((n) % 10);
        loop assigns n_div_10, count;
        loop variant n_div_10;
     */
    while (n_div_10 >= 10) {
        //@ assert n_div_10 >= 10;
        n_div_10 -= 10;
        count += 1;
    }

    unsigned long n_div_10_mod_10 = count;
    
    //@ assert n_mod_10 == n % 10;
    //@ assert n_div_10_mod_10 == n / 10;
    
    result = (n_mod_10 == 9) || (n_div_10_mod_10 == 9);
    return result;
}
