#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_unique(int *v, integer n) =
      \forall integer i, j; 0 <= i < j < n ==> v[i] != v[j];
*/

/*@ predicate in_range(int *v, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= v[i] && v[i] <= n;
*/

/*@ lemma unique_range_implies_index_valid:
      \forall int *v, integer n;
        all_unique(v, n) && in_range(v, n) && 2 <= n <= 50 ==>
        \forall integer i; 0 <= i < n ==> 1 <= v[i] && v[i] <= n;
*/

/*@ lemma unique_preserved:
      \forall int *v, integer n, integer i;
        0 <= i < n && all_unique(v, n) ==> all_unique(v, n);
*/

/*@ requires 2 <= n <= 50;
    requires \valid(v + (0 .. n-1));
    requires all_unique(v, n);
    requires in_range(v, n);
    ensures 0 <= \result <= n;
*/
int func(int n, int *v) {
    int cnt = 0;
    int index = 0;
    int i = 0;

    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= cnt <= i;
        loop invariant all_unique(v, n);
        loop invariant in_range(v, n);
        loop assigns i, cnt, index;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        index = v[i] - 1;
        //@ assert 0 <= index < n;
        
        if (i == index) {
            cnt = cnt + 1;
        }
        
        i = i + 1;
    }
    
    return cnt;
}
