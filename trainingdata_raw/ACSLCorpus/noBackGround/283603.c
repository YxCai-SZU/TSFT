#include <stdbool.h>
#include <stddef.h>

/*@
    requires n > 0 && n <= 200000;
    requires \valid(a + (0..n-1));
    requires ((n) > 0 && (n) <= 200000 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t n, const int a[]) {
    size_t m = 0;
    int count = 0;
    
    /*@
        loop invariant 0 <= m <= n;
        loop invariant 0 <= count <= m;
        loop invariant ((n) > 0 && (n) <= 200000 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000);
        loop invariant m > 0 ==> \forall integer k; 0 <= k < m ==> 1 <= a[k] <= 1000000;
        loop assigns m, count;
        loop variant n - m;
    */
    while (m < n) {
        bool divisible = false;
        size_t i = 0;
        
        /*@
            loop invariant 0 <= i <= m;
            loop invariant ((n) > 0 && (n) <= 200000 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000);
            loop invariant m > 0 ==> \forall integer k; 0 <= k < m ==> 1 <= a[k] <= 1000000;
            loop invariant i > 0 ==> \forall integer k; 0 <= k < i ==> 1 <= a[k] <= 1000000;
            loop invariant 0 <= count <= m;
            loop invariant m < n;
            loop assigns i, divisible;
            loop variant m - i;
        */
        while (i < m) {
            //@ assert i < n && m < n;
            
            int diff = a[m] - a[i];
            int abs_diff = diff >= 0 ? diff : -diff;
            bool is_divisible = true;
            int temp = abs_diff;
            
            /*@
                loop invariant temp >= 0;
                loop invariant temp <= abs_diff;
                loop invariant m < n;
                loop assigns temp;
                loop variant temp;
            */
            while (temp >= 2) {
                temp -= 2;
            }
            
            if (temp != 0) {
                is_divisible = false;
            }
            
            if (is_divisible) {
                divisible = true;
                break;
            }
            i++;
        }
        
        if (!divisible) {
            count++;
        }
        m++;
    }
    return count;
}
