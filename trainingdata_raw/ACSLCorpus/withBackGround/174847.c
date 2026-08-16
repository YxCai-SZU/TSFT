#include <stddef.h>

/*@
    predicate valid_array(integer n, int *an) =
        n >= 1 && n <= 100 &&
        \valid(an + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= an[i] && an[i] <= 100;

    predicate loop_invariant(integer n, int *an, integer index, integer count, integer num) =
        index <= n &&
        count >= 0 &&
        count <= index &&
        valid_array(n, an) &&
        num == index;

    lemma count_bounds: \forall integer n, integer count; 0 <= count <= n ==> count >= 0 && count <= n;
*/

/*@
    requires n >= 1 && n <= 100;
    requires \valid(an + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= an[i] && an[i] <= 100;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(size_t n, const int *an) {
    int count = 0;
    size_t num = 0;
    size_t index = 0;

    /*@
        loop invariant loop_invariant(n, an, index, count, num);
        loop assigns index, num, count;
        loop variant n - index;
    */
    while (index < n) {
        int a = an[index];
        num += 1;
        
        //@ assert num == index + 1;
        
        if (a % 2 == 0 && num % 2 == 1) {
            count += 1;
        }
        index += 1;
        
        //@ assert num == index;
    }

    //@ assert count >= 0 && count <= n;
    return count;
}
