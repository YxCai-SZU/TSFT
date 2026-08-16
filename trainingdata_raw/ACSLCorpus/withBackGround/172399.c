#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer m, integer x, size_t len_an) =
        1 <= n <= 100 &&
        1 <= m <= 100 &&
        1 <= x <= n - 1 &&
        len_an == m;

    predicate valid_array(int *an, size_t m, integer n, integer x) =
        \forall size_t i; 0 <= i < m ==> 
            1 <= an[i] <= n && an[i] != x;

    predicate count_invariant(size_t i, size_t m, integer count0, integer count1) =
        0 <= i <= m &&
        count0 >= 0 && count0 <= i &&
        count1 >= 0 && count1 <= i;
*/

/*@
    logic integer min(integer a, integer b) = a < b ? a : b;
*/

/*@
    lemma count_bounds:
        \forall size_t i, m; 0 <= i <= m ==> 
        \forall integer count0, count1; count_invariant(i, m, count0, count1) ==> 
            count0 <= m && count1 <= m;
*/

/*@
    requires 1 <= n <= 100 && 1 <= m <= 100 && 1 <= x <= n - 1;
    requires \valid(an + (0..m-1));
    requires \forall size_t i; 0 <= i < m ==> 1 <= an[i] <= n && an[i] != x;
    ensures \result <= m;
    assigns \nothing;
*/
size_t func(size_t n, size_t m, size_t x, int *an) {
    // Variable declarations at top of scope
    size_t i;
    int count0;
    int count1;
    size_t ans;
    
    // Initialize count variables
    count0 = 0;
    count1 = 0;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= m;
        loop invariant count_invariant(i, m, count0, count1);
        loop invariant \forall size_t j; 0 <= j < m ==> 1 <= an[j] <= n && an[j] != x;
        loop assigns i, count0, count1;
        loop variant m - i;
    */
    while (i < m) {
        int a = an[i];
        
        if (a < (int)x) {
            //@ assert 1 <= a <= n && a != x;
            int current = count0;
            count0 = current + 1;
            //@ assert count0 == current + 1;
        } else if (a > (int)x) {
            //@ assert 1 <= a <= n && a != x;
            int current = count1;
            count1 = current + 1;
            //@ assert count1 == current + 1;
        }
        //@ assert a != x;
        
        i = i + 1;
        //@ assert count_invariant(i, m, count0, count1);
    }
    
    //@ assert i == m;
    //@ assert count0 <= m && count1 <= m;
    
    if (count0 < count1) {
        ans = (size_t)count0;
        //@ assert ans == count0;
    } else {
        ans = (size_t)count1;
        //@ assert ans == count1;
    }
    
    // Postcondition
    //@ assert ans <= m;
    return ans;
}
