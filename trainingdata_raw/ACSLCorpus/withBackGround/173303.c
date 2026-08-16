#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, integer n) =
      n > 0 && n <= 100 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
*/

/*@ predicate loop_invariant(int *a, integer n, integer num, integer count) =
      valid_array(a, n) &&
      0 <= num <= n &&
      0 <= count <= num &&
      count <= num / 2;
*/

/*@ lemma count_bound: \forall int *a, integer n, integer num, integer count;
      loop_invariant(a, n, num, count) ==> count <= num;
*/

/*@ lemma count_half_bound: \forall int *a, integer n, integer num, integer count;
      loop_invariant(a, n, num, count) ==> count <= num / 2;
*/

/*@ requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *a) {
    int count = 0;
    size_t num = 0;
    
    /*@ loop invariant loop_invariant(a, n, num, count);
        loop invariant num <= n;
        loop assigns count, num;
        loop variant n - num;
    */
    while (num < (size_t)n) {
        //@ assert loop_invariant(a, n, num, count);
        
        if (num + 1 < (size_t)n && (a[num] & 1) == 1 && (a[num + 1] & 1) == 1) {
            //@ assert count <= num / 2;
            count += 1;
            num += 2;
            //@ assert count <= num / 2;
        } else {
            //@ assert count <= num / 2;
            num += 1;
            //@ assert count <= num / 2;
        }
        
        //@ assert count <= num / 2;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
