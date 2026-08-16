#include <limits.h>

/*@
    predicate valid_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate valid_product(integer v) = -1000000000000000000 <= v <= 1000000000000000000;
    predicate is_candidate(integer res, integer a, integer b, integer c, integer d) =
        res == a*c || res == a*d || res == b*c || res == b*d;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    requires a <= b && c <= d;
    ensures is_candidate(\result, a, b, c, d);
*/
long long func(long long a, long long b, long long c, long long d) {
    // Variable declarations at scope top
    long long ans;
    int i;
    int j;
    long long x;
    long long y;
    long long product;

    //@ assert valid_product(a * c);
    ans = a * c;

    i = 0;
    /*@
        loop invariant 0 <= i <= 2;
        loop invariant valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
        loop invariant a <= b && c <= d;
        loop invariant is_candidate(ans, a, b, c, d);
        loop assigns i, j, x, y, product, ans;
        loop variant 2 - i;
    */
    while (i < 2) {
        j = 0;
        /*@
            loop invariant 0 <= j <= 2;
            loop invariant valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
            loop invariant a <= b && c <= d;
            loop invariant is_candidate(ans, a, b, c, d);
            loop assigns j, x, y, product, ans;
            loop variant 2 - j;
        */
        while (j < 2) {
            x = (i == 0) ? a : b;
            y = (j == 0) ? c : d;
            //@ assert valid_range(x) && valid_range(y);
            product = x * y;
            //@ assert valid_product(product);
            ans = (product > ans) ? product : ans;
            //@ assert is_candidate(ans, a, b, c, d);
            j++;
        }
        i++;
    }

    return ans;
}
