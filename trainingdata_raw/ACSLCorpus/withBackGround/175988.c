#include <stdbool.h>

/*@ predicate is_valid_range(integer n) = 3 <= n && n <= 20; */
/*@ predicate is_valid_array(int *p, integer n) = 
      \forall integer k; 0 <= k < n ==> 1 <= p[k] && p[k] <= n; */
/*@ predicate is_distinct(int *p, integer n) = 
      \forall integer k, l; 0 <= k < l < n ==> p[k] != p[l]; */

/*@ lemma array_properties_preserved:
      \forall int *p, integer n; 
      is_valid_range(n) && is_valid_array(p, n) && is_distinct(p, n) ==> 
      \forall integer i; 0 <= i < n ==> 1 <= p[i] && p[i] <= n; */

/*@ requires is_valid_range(n);
    requires \valid(p + (0 .. n-1));
    requires is_valid_array(p, n);
    requires is_distinct(p, n);
    ensures 0 <= \result <= n-2;
    assigns \nothing;
 */
int func(int n, int *p) {
    int count = 0;
    int i = 1;
    
    /*@ loop invariant 1 <= i <= n-1;
        loop invariant 0 <= count <= i-1;
        loop invariant is_valid_array(p, n);
        loop invariant is_distinct(p, n);
        loop invariant is_valid_range(n);
        loop assigns i, count;
        loop variant n - i;
     */
    while (i < n - 1) {
        bool left = true;
        bool right = true;
        int j = 1;
        
        /*@ loop invariant 1 <= j <= n;
            loop invariant is_valid_array(p, n);
            loop invariant is_distinct(p, n);
            loop invariant is_valid_range(n);
            loop assigns j, left, right;
            loop variant n - j;
         */
        while (j < n) {
            if (p[i-1] < p[i+1] && p[i] < p[j]) {
                left = false;
            }
            if (p[i-1] < p[i+1] && p[i] > p[j]) {
                right = false;
            }
            j++;
        }
        
        if (left || right) {
            count++;
        }
        i++;
    }
    
    //@ assert 0 <= count <= n-2;
    return count;
}
