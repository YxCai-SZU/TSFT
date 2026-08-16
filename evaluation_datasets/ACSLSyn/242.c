#include <stdbool.h>

/* First snippet: distributive property */
/*@
    predicate distributive_mult_add(integer x, integer y, integer z) =
        x * (y + z) == x * y + x * z;

    lemma lemma_mul_is_distributive_add:
        \forall integer x, y, z; distributive_mult_add(x, y, z);
*/

/* Second snippet: game move function */
/*@
    predicate is_valid_input(integer a, integer b) =
        1 <= a && a <= 3 &&
        1 <= b && b <= 3 &&
        a != b;

    predicate result_one_condition(integer a, integer b) =
        (a == 1 && b == 3) ||
        (a == 2 && b == 1) ||
        (a == 3 && b == 2);

    predicate result_minus_one_condition(integer a, integer b) =
        (a == 1 && b == 2) ||
        (a == 2 && b == 3) ||
        (a == 3 && b == 1);

    lemma result_one_implies:
        \forall integer a, b;
        is_valid_input(a, b) && result_one_condition(a, b) ==>
        !result_minus_one_condition(a, b);

    lemma result_minus_one_implies:
        \forall integer a, b;
        is_valid_input(a, b) && result_minus_one_condition(a, b) ==>
        !result_one_condition(a, b);
*/

int func(int a, int b)
{
    int result = 0;

    if ((a == 1 && b == 3) ||
        (a == 2 && b == 1) ||
        (a == 3 && b == 2))
    {
        result = 1;
        //@ assert result_one_condition(a, b);
    }
    else
    {
        result = -1;
        //@ assert result_minus_one_condition(a, b);
    }

    return result;
}

/* Third snippet: availability check */
/*@
    predicate is_even(integer n) = n % 2 == 0;
    logic integer num_even(integer n) = (n % 2 == 0) ? n / 2 : n / 2 + 1;
    logic integer num_odd(integer n) = n / 2;
*/

bool func_availability(int n, int a)
{
    bool n_is_even;
    int num_even_val;
    int num_odd_val;
    bool result;

    n_is_even = (n % 2 == 0);
    
    if (n_is_even) {
        num_even_val = n / 2;
    } else {
        num_even_val = n / 2 + 1;
    }
    
    num_odd_val = n / 2;

    if (a > num_even_val) {
        //@ assert a > num_even_val;
        result = false;
    } else {
        //@ assert a <= num_even_val;
        result = true;
    }
    
    return result;
}

/* 
 * Scenario: A game matchmaking system that checks if a player can join a game session
 * based on their level and the session's even/odd distribution rules.
 * 
 * Data flow:
 * 1. Player provides their level (a) and opponent's level (b)
 * 2. Game session has a total capacity (n) and a target number of even-level players (a_target)
 * 3. The system verifies the move is valid (func), then checks availability (func_availability)
 * 4. Finally, it verifies the distribution property using the move result and capacity
 */

bool synthesized_game_matchmaking(int a, int b, int n, int a_target) {
    int move_result;
    bool availability_result;
    unsigned int x, y, z, left, right;
    
    move_result = func(a, b);
    
    availability_result = func_availability(n, a_target);
    
    x = (move_result == 1) ? 2 : 1;
    y = availability_result ? 3 : 1;
    z = (a + b) % 3;
    
    left = x * (y + z);
    right = x * y + x * z;
    
    //@ assert left == right;
    
    //@ assert (move_result == 1 || move_result == -1) && (availability_result == true || availability_result == false);
    
    return availability_result;
}
