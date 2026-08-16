#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    lemma product_bound:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            a * b * c <= 1000;
*/

/*@
    predicate is_mod_100_times_21_le_x(integer x) =
        (x % 100) * 21 <= x;
 */

bool func_int(int e1, int e2, int e3)
{
    bool result;
    int product;
    
    //@ assert 1 <= e1 && e1 <= 10;
    //@ assert 1 <= e2 && e2 <= 10;
    //@ assert 1 <= e3 && e3 <= 10;
    
    product = e1 * e2 * e3;
    //@ assert product <= 1000;
    
    result = (product == 175);
    return result;
}

bool func_ull(unsigned long long x)
{
    unsigned long long x_100;
    unsigned long long x_mod_100;
    bool result;

    x_100 = x / 100;
    x_mod_100 = x % 100;

    //@ assert x_mod_100 <= 100;
    //@ assert x_mod_100 * 21 <= 2100;

    result = (x_mod_100 * 21) <= x;
    return result;
}

bool check_product_and_mod_constraint(int a, int b, int c, unsigned long long d)
{
    bool product_result;
    bool mod_constraint_result;
    bool final_result;

    product_result = func_int(a, b, c);
    mod_constraint_result = func_ull(d);

    final_result = product_result && mod_constraint_result;

    //@ assert (product_result == (a * b * c == 175)) && (mod_constraint_result == ((d % 100) * 21 <= d));
    //@ assert final_result == (a * b * c == 175 && (d % 100) * 21 <= d);

    return final_result;
}
