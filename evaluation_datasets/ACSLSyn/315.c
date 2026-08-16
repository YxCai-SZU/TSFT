#include <stdbool.h>
#include <stdint.h>

/*@ predicate test_bool(integer a) = a == 0; */
/*@ lemma calc_example_8: \forall integer a; test_bool(a) ==> a == 0; */
/*@ predicate test_bool_2(integer a, integer b) = a != 0 || b != 0; */
/*@ lemma calc_example_9: test_bool_2(1, 0); */
/*@ predicate test_bool_3(integer a, integer b, integer c) = a != 0 && b != 0 && c != 0; */
/*@ lemma calc_example_10: test_bool_3(1, 1, 1); */

bool func1(unsigned int a, unsigned int b)
{
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;

    if ((a - 1) / 2 >= b - 1)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == ((a - 1) / 2 >= b - 1);
    return result;
}

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer func_spec(integer n, integer m) =
        n < m / 2 + 1 ? n + (m - 2 * n) / 4 : m / 2 + 1;

    lemma func_bound: \forall integer n, m;
        valid_params(n, m) ==> func_spec(n, m) <= n + m / 2;
*/

uint32_t func2(uint32_t n, uint32_t m)
{
    uint32_t result = 0;
    uint32_t remaining_n = n;
    uint32_t remaining_m = m;

    if (n < m / 2 + 1)
    {
        result += n;
        remaining_m -= 2 * n;
        //@ assert 0 <= remaining_m <= 100 * 2;
        //@ assert remaining_m / 4 <= 100;
        result += remaining_m / 4;
        return result;
    }
    else
    {
        //@ assert m / 2 + 1 <= n + m / 2;
        return m / 2 + 1;
    }
}

/*@ predicate in_range(integer x) = -40 <= x && x <= 40; */

bool func3(int x)
{
    bool result;
    //@ assert in_range(x);
    if (x >= 30) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

bool hvac_control(int temperature, unsigned int a, unsigned int b)
{
    bool is_hot;
    bool demand_exceeds_capacity;
    uint32_t allocated_resources;
    bool resource_feasible;
    bool activate_cooling;

    is_hot = func3(temperature);
    //@ assert is_hot == (temperature >= 30);

    demand_exceeds_capacity = func1(a, b);
    //@ assert demand_exceeds_capacity == ((a - 1) / 2 >= b - 1);

    if (is_hot && demand_exceeds_capacity)
    {
        allocated_resources = func2((uint32_t)a, (uint32_t)b);
        //@ assert allocated_resources <= (uint32_t)a + (uint32_t)b / 2;
        resource_feasible = (allocated_resources <= (uint32_t)a + (uint32_t)b / 2);
    }
    else
    {
        allocated_resources = 0;
        resource_feasible = true;
    }

    if (is_hot && demand_exceeds_capacity && resource_feasible)
    {
        activate_cooling = true;
    }
    else
    {
        activate_cooling = false;
    }

    //@ assert activate_cooling == (temperature >= 30 && ((a - 1) / 2 >= b - 1) && (func_spec((uint32_t)a, (uint32_t)b) <= (uint32_t)a + (uint32_t)b / 2));
    return activate_cooling;
}
