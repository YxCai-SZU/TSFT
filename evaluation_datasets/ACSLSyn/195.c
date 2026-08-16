#include <stdbool.h>
#include <stdint.h>

/* First function: check if sum of three dice values meets a threshold */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 7;
    logic integer total_sum(integer a, integer b, integer c) = a + b + c;
    predicate is_enough_condition(integer sum, integer k) = sum >= k;
*/

bool check_dice_sum(int a, int b, int c, int k)
{
    int sum;
    bool is_enough;

    sum = a + b + c;
    is_enough = false;

    if (sum == k || sum > k) {
        is_enough = true;
    }

    //@ assert is_enough == true <==> sum >= k;

    return is_enough;
}

/* Second function: check if a value fits within a product constraint */
/*@
    predicate is_product_safe(integer t, integer s) =
        t <= 10000 && s <= 10000 && (t * s) <= 4294967295;
*/

bool check_product_fit(uint32_t d, uint32_t t, uint32_t s)
{
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert is_product_safe(t, s);
    return d <= t * s;
}

/* Synthesized function: Dice game scoring system
 * Scenario: In a dice game, a player rolls three dice (values 1-7 each).
 * The player's score is the sum of the dice. To win a reward, the score must
 * meet a threshold k. Additionally, the reward value d must fit within
 * the product of the dice values (t * s, where t and s are two of the dice),
 * ensuring the reward is not too large relative to the dice outcome.
 * This function validates both conditions for a valid game round.
 */
bool validate_game_round(int a, int b, int c, int k, uint32_t d)
{
    bool sum_condition;
    bool product_condition;

    sum_condition = check_dice_sum(a, b, c, k);

    product_condition = check_product_fit(d, (uint32_t)a, (uint32_t)b);

    //@ assert sum_condition == true <==> (a + b + c) >= k;
    //@ assert product_condition == true <==> d <= a * b;

    //@ assert (sum_condition && product_condition) == ((a + b + c) >= k && d <= a * b);

    return sum_condition && product_condition;
}
