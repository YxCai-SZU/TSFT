#include <stdint.h>
#include <stdbool.h>

/* ACSL specifications from first snippet */
/*@
    predicate valid_range_small(integer x) = 0 <= x <= 10;

    logic integer product(integer a, integer b) = a * b;
    logic integer triple_product(integer a, integer b, integer c) = a * b * c;

    lemma product_bound:
        \forall integer a, b;
        valid_range_small(a) && valid_range_small(b) ==> product(a, b) <= 100;

    lemma triple_product_bound:
        \forall integer a, b, c;
        valid_range_small(a) && valid_range_small(b) && valid_range_small(c) ==> triple_product(a, b, c) <= 1000;
*/

/* ACSL specifications from second snippet */
/*@
    predicate valid_range_large(integer x) =
        1 <= x <= 10000;

    logic integer safe_mul(integer a, integer b) =
        a * b;

    lemma mul_bounds:
        \forall integer t, s;
        valid_range_large(t) && valid_range_large(s) ==>
        safe_mul(t, s) <= 10000 * 10000;

    lemma taka_time_bound:
        \forall integer v_taka, time;
        valid_range_large(v_taka) && 0 <= time <= 10000 ==>
        safe_mul(v_taka, time) <= 10000 * 10000;

    lemma aoki_time_bound:
        \forall integer v_aoki, time;
        valid_range_large(v_aoki) && 0 <= time <= 10000 ==>
        safe_mul(v_aoki, time) <= 10000 * 10000;
*/

/* First function: compute product of two small integers */
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert product(a, b) <= 100;
    return a * b;
}

/* Second function: compute triple product of three small integers */
uint32_t func2(uint32_t a, uint32_t b, uint32_t c)
{
    //@ assert product(a, b) <= 100;
    //@ assert triple_product(a, b, c) <= 1000;
    return a * b * c;
}

/* Third function: check if distance can be covered given speeds and time */
bool func3(int d, int t, int s)
{
    int dist;
    int v_taka;
    int v_aoki;
    int time;
    int dist_taka;
    int dist_aoki;
    bool result;

    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    dist = d;
    v_taka = t;
    v_aoki = s;
    time = 0;

    //@ assert v_taka * time <= 10000 * 10000;
    //@ assert v_aoki * time <= 10000 * 10000;

    dist_taka = v_taka * time;
    dist_aoki = v_aoki * time;
    result = (t * s >= d) ? true : false;
    
    return result;
}

/*@
    logic integer initial_allocation(integer base, integer mult) = base * mult;
    logic integer bonus_allocation(integer base, integer mult, integer bonus) = base * mult * bonus;
*/

/* Synthesized function: Resource allocation validator
 * 
 * Real-world scenario: A system that validates resource allocation requests.
 * Given:
 *   - base_allocation: base resource units (0-10)
 *   - multiplier: allocation multiplier (0-10)  
 *   - extra_bonus: extra bonus units (0-10)
 *   - total_resources: total available resources (1-10000)
 *   - time_units: time units for allocation (1-10000)
 *   - speed: allocation speed (1-10000)
 * 
 * The function computes:
 *   1. Initial allocation = base_allocation * multiplier
 *   2. Bonus allocation = initial_allocation * extra_bonus
 *   3. Checks if total_resources can be allocated given speed and time
 * 
 * Returns: true if allocation plan is feasible (all resources can be allocated within constraints)
 */
bool resource_allocation_validator(uint32_t base_allocation, uint32_t multiplier, 
                                    uint32_t extra_bonus, int total_resources, 
                                    int time_units, int speed)
{
    uint32_t initial_allocation;
    uint32_t bonus_allocation;
    bool time_feasible;
    bool allocation_sufficient;
    
    initial_allocation = func(base_allocation, multiplier);
    
    bonus_allocation = func2(base_allocation, multiplier, extra_bonus);
    
    time_feasible = func3(total_resources, time_units, speed);
    
    allocation_sufficient = (bonus_allocation >= (uint32_t)total_resources);
    
    //@ assert (allocation_sufficient || time_feasible) ==> (product(base_allocation, multiplier) <= 100 && triple_product(base_allocation, multiplier, extra_bonus) <= 1000 && time_units * speed <= 10000 * 10000);
    
    return allocation_sufficient || time_feasible;
}

int main(void)
{
    return 0;
}
