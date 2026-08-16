#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer n) = 3 <= n <= 20; */
/*@ predicate element_in_range(int *p, integer n, integer i) = 
      0 <= i < n ==> p[i] >= 1 && p[i] <= n; */
/*@ predicate adjacent_distinct(int *p, integer n, integer i) = 
      0 <= i < n - 1 ==> p[i] != p[i + 1]; */

/*@ requires 3 <= n <= 20;
    requires \valid(p + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= p[i] <= n;
    requires \forall integer i; 0 <= i < n-1 ==> p[i] != p[i+1];
    ensures \result >= 0;
    assigns \nothing;
 */
int func(int n, int *p) {
    int count = 0;
    int i = 1;
    
    /*@ loop invariant 1 <= i <= n-1;
        loop invariant 0 <= count <= i-1;
        loop invariant \forall integer j; 0 <= j < n ==> 1 <= p[j] <= n;
        loop invariant \forall integer j; 0 <= j < n-1 ==> p[j] != p[j+1];
        loop assigns i, count;
        loop variant n-1 - i;
     */
    while (i < n - 1) {
        //@ assert 1 <= p[i-1] <= n;
        //@ assert 1 <= p[i] <= n;
        //@ assert 1 <= p[i+1] <= n;
        //@ assert p[i-1] != p[i];
        //@ assert p[i] != p[i+1];
        
        if ((p[i - 1] < p[i] && p[i] < p[i + 1]) || 
            (p[i - 1] > p[i] && p[i] > p[i + 1])) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
