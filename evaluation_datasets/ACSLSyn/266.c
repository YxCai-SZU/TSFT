#include <stdint.h>

/* Original function 1: resource allocation limiter */
/*@ predicate valid_range(integer x) = 1 <= x <= 100; */

uint32_t func_limiter(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t ans;
    
    ans = b;
    
    if (a + b <= c) {
        ans += c - (a + b);
    } else {
        ans += c;
    }
    
    if (d < ans) {
        ans = d;
    }
    
    return ans;
}

/* Original function 2: condition verifier */
/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate within_bounds(integer v) = 1 <= v <= 100;
    predicate satisfies_condition(integer x, integer y, integer z) =
        is_even(z) && x <= z && y <= z && x + y <= z;
*/

_Bool func_verifier(int x, int y, int z)
{
    int temp;
    _Bool is_even_flag;
    
    temp = z;
    is_even_flag = 0;
    
    while (temp >= 2)
    {
        temp -= 2;
    }
    
    is_even_flag = (temp == 0);
    
    if (is_even_flag && (x <= z && y <= z) && ((x + y) <= z))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Original function 3: prize calculator */
/*@
    predicate is_valid_range(integer x, integer y) =
        1 <= x <= 205 && 1 <= y <= 205;

    logic integer compute_result(integer x, integer y) =
        (x == 1 && y == 1) ? 1000000 :
        ((x == 1 || y == 1 || x == 205 || y == 205) && (x != 1 || y != 1)) ? 500000 : 0;

    lemma result_values:
        \forall integer x, y;
        is_valid_range(x, y) ==> 
        (compute_result(x, y) == 0 || compute_result(x, y) == 1000000 || compute_result(x, y) == 500000);
*/

int32_t func_prize(uint16_t x, uint16_t y)
{
    int32_t ans;
    
    if (x == 1 && y == 1) {
        ans = 1000000;
    } else if ((x == 1 || y == 1 || x == 205 || y == 205) && (x != 1 || y != 1)) {
        ans = 500000;
    } else {
        ans = 0;
    }
    
    return ans;
}

/* Synthesized function: Gaming tournament prize distribution system
 * Scenario: A tournament allocates prizes to players based on grid positions.
 * Inputs: 
 * - a, b, c, d: resource allocation parameters (1-100)
 * - x, y: grid coordinates (1-205)
 * - z: maximum capacity (1-100, even required for special prize)
 * Flow:
 * 1. Use func_limiter to compute a capped resource allocation
 * 2. Use func_verifier to check if the grid position + allocation satisfies special conditions
 * 3. Use func_prize to compute the base prize based on grid position
 * 4. If conditions are satisfied, double the prize; otherwise return base prize
 */

int32_t tournament_prize_system(uint32_t a, uint32_t b, uint32_t c, uint32_t d, 
                                uint16_t x, uint16_t y, int z)
{
    uint32_t allocation;
    _Bool condition_met;
    int32_t base_prize;
    int32_t final_prize;
    
    allocation = func_limiter(a, b, c, d);
    
    if (allocation < 1) {
        allocation = 1;
    } else if (allocation > 100) {
        allocation = 100;
    }
    
    condition_met = func_verifier((int)allocation, (int)allocation, z);
    
    base_prize = func_prize(x, y);
    
    if (condition_met && base_prize > 0) {
        final_prize = base_prize * 2;
    } else {
        final_prize = base_prize;
    }
    
    return final_prize;
}
