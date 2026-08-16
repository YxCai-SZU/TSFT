#include <stdbool.h>

/*@ predicate distinct_elements(int *arr, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> arr[i] != arr[j];
*/

/*@ lemma distinct_preserved:
      \forall int *arr, integer len, integer idx;
        0 <= idx < len && distinct_elements(arr, len) ==>
        distinct_elements(arr, len);
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    requires \valid(an + (0..n-1));
    requires \valid(bn + (0..m-1));
    requires distinct_elements(an, n);
    requires distinct_elements(bn, m);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int m, int *an, int *bn) {
    int count = 0;
    int na = 0;
    
    /*@
        loop invariant 0 <= na <= n;
        loop invariant 0 <= count <= na;
        loop invariant distinct_elements(an, n);
        loop invariant distinct_elements(bn, m);
        loop assigns na, count;
        loop variant n - na;
    */
    while (na < n) {
        int a = an[na];
        int nb = 0;
        
        /*@
            loop invariant 0 <= nb <= m;
            loop invariant 0 <= count <= na;
            loop invariant distinct_elements(an, n);
            loop invariant distinct_elements(bn, m);
            loop assigns nb, count;
            loop variant m - nb;
        */
        while (nb < m) {
            int b = bn[nb];
            //@ assert distinct_elements(an, n);
            if (a == b) {
                count += 1;
                break;
            }
            nb += 1;
        }
        na += 1;
    }
    return count;
}
