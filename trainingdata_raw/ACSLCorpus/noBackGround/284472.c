#include <stddef.h>
#include <stdint.h>

#define MOD_VALUE 1000000007LL

/*@
    requires 1 <= n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall size_t i; 0 <= i < n ==> 0 <= a[i] <= 1000;
    ensures \result >= 0 && \result < MOD_VALUE;
    assigns \nothing;
*/
int64_t func(size_t n, int64_t *a) {
    int64_t sum = 0;
    size_t na = 0;
    
    /*@
        loop invariant 0 <= na <= n;
        loop invariant sum >= 0 && sum < MOD_VALUE;
        loop invariant ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 0 <= (a)[i] <= 1000);
        loop assigns na, sum;
        loop variant n - na;
    */
    while (na < n) {
        size_t nb = na + 1;
        
        /*@
            loop invariant na < nb <= n;
            loop invariant sum >= 0 && sum < MOD_VALUE;
            loop invariant ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 0 <= (a)[i] <= 1000);
            loop invariant 0 <= a[na] <= 1000;
            loop assigns nb, sum;
            loop variant n - nb;
        */
        while (nb < n) {
            //@ assert 0 <= a[na] <= 1000;
            //@ assert 0 <= a[nb] <= 1000;
            //@ assert a[na] * a[nb] <= 1000000;
            
            int64_t product = a[na] * a[nb];
            int64_t mod_product = product;
            
            /*@
                loop invariant mod_product >= 0;
                loop invariant mod_product <= product + MOD_VALUE;
                loop invariant ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 0 <= (a)[i] <= 1000);
                loop assigns mod_product;
                loop variant mod_product;
            */
            while (mod_product >= MOD_VALUE) {
                mod_product -= MOD_VALUE;
            }
            
            sum += mod_product;
            
            /*@
                loop invariant sum >= 0 && sum < 2 * MOD_VALUE;
                loop invariant ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 0 <= (a)[i] <= 1000);
                loop assigns sum;
                loop variant sum;
            */
            while (sum >= MOD_VALUE) {
                sum -= MOD_VALUE;
            }
            
            nb++;
        }
        na++;
    }
    
    int64_t final_sum = sum;
    
    /*@
        loop invariant final_sum >= 0 && final_sum < 2 * MOD_VALUE;
        loop invariant ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 0 <= (a)[i] <= 1000);
        loop assigns final_sum;
        loop variant final_sum;
    */
    while (final_sum >= MOD_VALUE) {
        final_sum -= MOD_VALUE;
    }
    
    return final_sum;
}
