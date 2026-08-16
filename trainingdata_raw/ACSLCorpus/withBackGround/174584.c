#include <stdint.h>

/*@
    predicate valid_n(integer n) = 2 <= n && n <= 200000;
    
    predicate valid_array(integer n, int64_t *a) =
        \valid(a + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 0 <= a[i] && a[i] <= 1000000000;
    
    logic integer mod_value = 1000000007;
    
    lemma product_bound:
        \forall integer b, c;
        0 <= b <= 1000000000 && 0 <= c <= 1000000000 ==>
        b * c <= 1000000000000000000;
*/

/*@
    requires valid_n(n);
    requires valid_array(n, a);
    ensures 0 <= \result < mod_value;
*/
int64_t func(int64_t n, int64_t *a) {
    int64_t mod_value = 1000000007;
    int64_t sum = 0;
    uint64_t na = 0;
    
    /*@
        loop invariant 0 <= na <= n;
        loop invariant 0 <= sum < mod_value;
        loop invariant valid_n(n);
        loop invariant valid_array(n, a);
        loop assigns na, sum;
        loop variant n - na;
    */
    while (na < (uint64_t)n) {
        int64_t b = a[na];
        uint64_t nb = na + 1;
        
        /*@
            loop invariant na < nb <= n;
            loop invariant 0 <= sum < mod_value;
            loop invariant valid_n(n);
            loop invariant valid_array(n, a);
            loop assigns nb, sum;
            loop variant n - nb;
        */
        while (nb < (uint64_t)n) {
            int64_t c = a[nb];
            
            //@ assert 0 <= b && b <= 1000000000;
            //@ assert 0 <= c && c <= 1000000000;
            //@ assert b * c <= 1000000000000000000;
            
            int64_t product = b * c;
            int64_t mod_product = product;
            
            /*@
                loop invariant 0 <= mod_product <= product + mod_value;
                loop assigns mod_product;
                loop variant mod_product;
            */
            while (mod_product >= mod_value) {
                mod_product -= mod_value;
            }
            
            sum += mod_product;
            
            /*@
                loop invariant 0 <= sum < 2 * mod_value;
                loop assigns sum;
                loop variant sum;
            */
            while (sum >= mod_value) {
                sum -= mod_value;
            }
            
            nb++;
        }
        na++;
    }
    
    int64_t final_sum = sum;
    
    /*@
        loop invariant 0 <= final_sum < 2 * mod_value;
        loop assigns final_sum;
        loop variant final_sum;
    */
    while (final_sum >= mod_value) {
        final_sum -= mod_value;
    }
    
    return final_sum;
}
