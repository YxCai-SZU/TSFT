#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer sum_bc(integer b, integer c) = b * 10 + c;
    logic integer product_a(integer a) = a * 10;

    lemma sum_bc_bound: \forall integer b, c; valid_range(b) && valid_range(c) ==> sum_bc(b, c) <= 99;
    lemma product_a_bound: \forall integer a; valid_range(a) ==> product_a(a) <= 90;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (sum_bc(b, c) - product_a(a) < 0);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    // Variable declarations at top of scope
    unsigned long long sum_tmp;
    unsigned long long product_tmp;
    long long sum;
    long long product;
    bool result;

    //@ assert valid_range(b) && valid_range(c);
    //@ assert sum_bc(b, c) <= 99;
    sum_tmp = b * 10 + c;

    //@ assert valid_range(a);
    //@ assert product_a(a) <= 90;
    product_tmp = a * 10;

    sum = (long long)sum_tmp;
    product = (long long)product_tmp;

    //@ assert sum == sum_bc(b, c) && product == product_a(a);
    result = (sum - product < 0) ? true : false;

    //@ assert result == (sum_bc(b, c) - product_a(a) < 0);
    return result;
}
