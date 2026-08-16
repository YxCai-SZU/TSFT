#include <stdbool.h>
#include <stdint.h>

/* First function: compute remaining capacity */
/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result1(integer a, integer b, integer c) =
        a - b < c ? c - (a - b) : 0;

    lemma result_properties:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        compute_result1(a, b, c) >= 0 &&
        compute_result1(a, b, c) <= c &&
        (a - b >= c ==> compute_result1(a, b, c) == 0) &&
        (a - b < c ==> compute_result1(a, b, c) == c - (a - b));
*/

int func(int a, int b, int c)
{
    int result;
    
    //@ assert valid_input(a, b, c);
    
    if (a - b < c) {
        //@ assert a - b < c;
        result = c - (a - b);
    } else {
        //@ assert a - b >= c;
        result = 0;
    }
    
    //@ assert result == compute_result1(a, b, c);
    return result;
}

/* Second function: compute total cost */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer compute_result2(integer n) = n * 800 - (n / 15) * 200;
    
    lemma result_nonnegative: 
        \forall integer n; is_valid_n(n) ==> compute_result2(n) >= 0;
*/

int32_t func2(uint32_t n) {
    uint32_t ans;
    
    //@ assert is_valid_n(n);
    
    ans = n * 800 - n / 15 * 200;
    
    //@ assert ans == compute_result2(n);
    
    return (int32_t)ans;
}

/* Synthesized function: Inventory restocking cost calculator
   Scenario: A warehouse has current stock 'current', minimum required stock 'min_stock', 
   each restock unit costs 800, and there is a 200 discount every 15 units.
   The function calculates the total restocking cost based on shortage.
*/
/*@
    predicate valid_inventory(integer current, integer min_stock, integer unit_cost, integer discount_interval) =
        valid_input(current, min_stock, unit_cost) && is_valid_n(unit_cost) && unit_cost <= 20 && discount_interval == 15;

    logic integer shortage(integer current, integer min_stock, integer unit_cost) =
        compute_result1(current, min_stock, unit_cost);

    logic integer total_cost(integer current, integer min_stock, integer unit_cost) =
        compute_result2(compute_result1(current, min_stock, unit_cost));

    lemma cost_nonnegative:
        \forall integer current, min_stock, unit_cost;
        valid_inventory(current, min_stock, unit_cost, 15) ==>
        total_cost(current, min_stock, unit_cost) >= 0;
*/

int32_t inventory_restock_cost(int current, int min_stock, int unit_cost) {
    int shortage_amount = func(current, min_stock, unit_cost);
    
    //@ assert shortage_amount == compute_result1(current, min_stock, unit_cost);
    //@ assert shortage_amount >= 0 && shortage_amount <= unit_cost;
    
    int32_t cost;
    if (shortage_amount == 0) {
        cost = 0;
    } else {
        //@ assert shortage_amount >= 1 && shortage_amount <= 20;
        //@ assert is_valid_n(shortage_amount);
        cost = func2((uint32_t)shortage_amount);
    }
    
    //@ assert cost == compute_result2(shortage_amount);
    //@ assert cost >= 0;
    
    //@ assert cost >= 0 && cost == compute_result2(compute_result1(current, min_stock, unit_cost));
    
    return cost;
}
