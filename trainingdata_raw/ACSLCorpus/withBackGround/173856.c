#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(integer n, int *an) =
        n >= 1 && n <= 100 &&
        \forall integer i; 0 <= i < n ==> 1 <= an[i] && an[i] <= 1000;

    predicate condition_holds(integer n, int *an) =
        \forall integer i; 0 <= i < n ==>
            (an[i] % 2 == 0 ==> (an[i] % 3 == 0 || an[i] % 5 == 0));

    lemma condition_preserved:
        \forall integer n, int *an, integer k;
        valid_array(n, an) && 0 <= k <= n &&
        (\forall integer j; 0 <= j < k ==>
            (an[j] % 2 == 0 ==> (an[j] % 3 == 0 || an[j] % 5 == 0)))
        ==> condition_holds(k, an);
*/

/*@
    requires n >= 1 && n <= 100;
    requires \valid(an + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= an[i] && an[i] <= 1000;
    assigns \nothing;
    ensures \result == true <==> condition_holds(n, an);
*/
bool func(size_t n, int *an) {
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant valid_array(n, an);
        loop invariant \forall integer j; 0 <= j < i ==>
            (an[j] % 2 == 0 ==> (an[j] % 3 == 0 || an[j] % 5 == 0));
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        int a = an[i];
        if (a % 2 == 0) {
            //@ assert a % 2 == 0;
            if (a % 3 != 0 && a % 5 != 0) {
                //@ assert !(a % 3 == 0 || a % 5 == 0);
                return false;
            }
        }
        i++;
    }
    //@ assert condition_holds(n, an);
    return true;
}
