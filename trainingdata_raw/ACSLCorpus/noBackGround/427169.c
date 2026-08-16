#include <stdint.h>
#include <stddef.h>

/*@
    requires N >= 2 && N <= 100000;
    requires \valid(A + (0..N-1));
    requires ((N) >= 2 && (N) <= 100000 &&
        \forall size_t i; 0 <= i < (N) ==> 0 <= (A)[i] && (A)[i] <= 1000000000);
    ensures 0 <= \result < 1000000007;
    assigns \nothing;
*/
int64_t func(size_t N, const int64_t *A) {
    const int64_t MOD = 1000000007;
    int64_t sum = 0;
    size_t na = 0;
    size_t nb = 0;
    
    /*@
        loop invariant 0 <= na <= N;
        loop invariant 0 <= sum < MOD;
        loop invariant ((N) >= 2 && (N) <= 100000 &&
        \forall size_t i; 0 <= i < (N) ==> 0 <= (A)[i] && (A)[i] <= 1000000000);
        loop assigns na, nb, sum;
        loop variant N - na;
    */
    while (na < N) {
        int64_t a = A[na];
        nb = na + 1;
        
        /*@
            loop invariant na < nb <= N;
            loop invariant 0 <= sum < MOD;
            loop invariant ((N) >= 2 && (N) <= 100000 &&
        \forall size_t i; 0 <= i < (N) ==> 0 <= (A)[i] && (A)[i] <= 1000000000);
            loop assigns nb, sum;
            loop variant N - nb;
        */
        while (nb < N) {
            //@ assert 0 <= a && a <= 1000000000;
            //@ assert 0 <= A[nb] && A[nb] <= 1000000000;
            //@ assert a * A[nb] <= 1000000000000000000;
            
            int64_t product = a * A[nb];
            int64_t mod_product = product;
            
            /*@
                loop invariant 0 <= mod_product <= product + MOD;
                loop invariant product <= 1000000000000000000;
                loop assigns mod_product;
                loop variant mod_product;
            */
            while (mod_product >= MOD) {
                mod_product -= MOD;
            }
            
            sum += mod_product;
            
            /*@
                loop invariant 0 <= sum <= MOD + mod_product;
                loop assigns sum;
                loop variant sum;
            */
            while (sum >= MOD) {
                sum -= MOD;
            }
            
            nb++;
        }
        na++;
    }
    
    /*@
        loop invariant 0 <= sum <= MOD + MOD;
        loop assigns sum;
        loop variant sum;
    */
    while (sum >= MOD) {
        sum -= MOD;
    }
    
    return sum;
}
