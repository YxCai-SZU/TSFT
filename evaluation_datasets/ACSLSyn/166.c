#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;
    predicate valid_a(integer a) = 1 <= a && a <= 10;

    logic integer max_product(integer t, integer s) = t * s;
    logic integer func_spec(integer a) = a * 800 - (a / 3) * 200;

    lemma product_bound: \forall integer t, s; 
        valid_range(t) && valid_range(s) ==> max_product(t, s) <= 10000 * 10000;

    lemma division_property:
        \forall integer a, x, r;
            x == a / 3 && r == a % 3 ==>
            a * 800 - x * 200 == func_spec(a);
*/

bool func1(int d, int t, int s)
{
    bool result;

    //@ assert valid_range(d);
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    //@ assert d <= 10000;
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert max_product(t, s) <= 10000 * 10000;

    result = d <= t * s;
    return result;
}

int32_t func2(uint32_t a)
{
    uint32_t x;
    uint32_t r;
    int32_t result;

    x = a / 3;
    r = a % 3;
    
    //@ assert x == a / 3;
    //@ assert r == a % 3;
    
    result = (int32_t)a * 800 - (int32_t)x * 200;
    
    //@ assert result == func_spec(a);
    return result;
}

bool check_budget_and_discount(uint32_t a, int d, int t, int s)
{
    bool budget_ok;
    int32_t discount;

    discount = func2(a);

    budget_ok = func1(d, t, s);

    //@ assert discount == func_spec(a);
    //@ assert budget_ok == (d <= t * s);

    bool final_result;
    if (discount >= 0) {
        final_result = budget_ok;
    } else {
        final_result = !budget_ok;
    }

    //@ assert final_result == (func_spec(a) >= 0 ? (d <= t * s) : !(d <= t * s));

    return final_result;
}

int main(void)
{
    return 0;
}
