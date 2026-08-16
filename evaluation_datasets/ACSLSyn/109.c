#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_divisible_by_3(integer n) = n % 3 == 0;
    predicate is_divisible_by_5(integer n) = n % 5 == 0;
    logic integer mod_3(integer n) = n % 3;
    logic integer mod_5(integer n) = n % 5;
    
    lemma mod_preservation_3:
        \forall integer n, m; n >= 3 && m == n - 3 ==> m % 3 == n % 3;
    lemma mod_preservation_5:
        \forall integer n, m; n >= 5 && m == n - 5 ==> m % 5 == n % 5;
*/

bool is_divisible_by_3_or_5(int input) {
    bool is_divisible_by_3 = false;
    bool is_divisible_by_5 = false;
    int temp_input;
    
    temp_input = input;
    while (temp_input >= 3) {
        temp_input -= 3;
    }
    if (temp_input == 0) {
        is_divisible_by_3 = true;
    }
    
    temp_input = input;
    while (temp_input >= 5) {
        temp_input -= 5;
    }
    if (temp_input == 0) {
        is_divisible_by_5 = true;
    }
    
    return is_divisible_by_3 || is_divisible_by_5;
}

/*@
    predicate valid_input(integer a, integer b) =
        0 <= a <= 100 &&
        2 <= b <= 1000 &&
        b % 2 == 0;

    predicate valid_output(integer res, integer b) =
        res >= 0 && res <= b;
*/

uint32_t map_to_range(uint32_t a, uint32_t b)
{
    uint32_t res = 0;

    if (a <= 5)
    {
        res = 0;
    }
    else if (a <= 12)
    {
        res = b / 2;
    }
    else
    {
        res = b;
    }

    return res;
}

/*@
    predicate valid_bonus_input(integer a, integer b) =
        0 <= a <= 100 &&
        2 <= b <= 1000 &&
        b % 2 == 0;

    predicate final_bonus_valid(integer result, integer b) =
        result >= 0 && result <= b;
*/

uint32_t calculate_fizzbuzz_bonus(uint32_t a, uint32_t b)
{
    uint32_t base_bonus;
    uint32_t final_bonus;

    base_bonus = map_to_range(a, b);

    bool fizzbuzz;
    if (a >= 1) {
        fizzbuzz = is_divisible_by_3_or_5((int)a);
    } else {
        fizzbuzz = false;
    }

    if (fizzbuzz)
    {
        if (base_bonus <= b / 2)
        {
            final_bonus = base_bonus * 2;
        }
        else
        {
            final_bonus = b;
        }
    }
    else
    {
        final_bonus = base_bonus;
    }

    return final_bonus;
}
