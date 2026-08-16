#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/*@ predicate valid_params(integer n, int *v) =
    n >= 2 && n <= 200000 &&
    \valid(v + (0 .. n-1)) &&
    \forall integer k; 0 <= k < n ==> -1000000000 <= v[k] <= 1000000000;
*/

/*@ predicate result_correct(integer n, int *v, int *res) =
    \forall integer i; 0 <= i < n ==> res[i] == v[n - i - 1];
*/

/*@ lemma index_in_range: \forall integer n, i; 0 <= i < n ==> 0 <= n - i - 1 < n; */

/*@
    requires valid_params(n, v);
    requires \valid(res + (0 .. n-1));
    assigns res[0 .. n-1];
    ensures result_correct(n, v, res);
*/
void reverse_array(size_t n, const int *v, int *res) {
    size_t i = n;
    size_t j = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant j == n - i;
        loop invariant \forall integer k; 0 <= k < j ==> res[k] == v[n - k - 1];
        loop invariant valid_params(n, v);
        loop assigns i, j, res[0 .. n-1];
        loop variant i;
    */
    while (i > 0) {
        i--;
        //@ assert 0 <= i < n;
        res[j] = v[i];
        j++;
    }
}

int main() {
    return 0;
}
