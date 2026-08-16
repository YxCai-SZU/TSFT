#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x <= 1000000000;
    
    logic integer compute_result(integer x) = 
        (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

unsigned int func(unsigned int x)
{
    unsigned int div500;
    unsigned int below500;
    unsigned int div5;
    unsigned int ans;
    
    div500 = x / 500;
    below500 = x % 500;
    div5 = below500 / 5;
    ans = div500 * 1000 + div5 * 5;
    
    //@ assert below500 < 500 && below500 >= 0;
    //@ assert div5 <= 100;
    //@ assert div5 * 5 <= 500;
    
    return ans;
}

bool func2(int a, int b, int c)
{
    //@ assert a >= -2147483648 && a <= 2147483647;
    //@ assert b >= -2147483648 && b <= 2147483647;
    //@ assert c >= -2147483648 && c <= 2147483647;
    return a < b && b < c;
}

/*@
    logic integer compute_result2(integer x) = (x - 1) / 2 + 1;
    
    lemma result_bounds: \forall integer x; is_valid_input(x) ==> 1 <= compute_result2(x) <= 500000000;
*/

uint64_t func3(uint64_t x)
{
    uint64_t result;
    
    //@ assert x > 0;
    //@ assert x <= 1000000000;
    
    result = (x - 1) / 2 + 1;
    
    //@ assert result == compute_result2(x);
    return result;
}

/*@
    predicate consistent_reward(integer transaction_amount, unsigned int base_points, unsigned int tier_points, unsigned int total_points) =
        is_valid_input(transaction_amount) ==>
        (total_points == base_points + tier_points &&
         base_points == compute_result(transaction_amount) &&
         tier_points == (unsigned int)compute_result2((uint64_t)transaction_amount));
*/

unsigned int process_reward(unsigned int transaction_amount)
{
    unsigned int base_points;
    unsigned int tier_points;
    unsigned int total_points;
    int threshold_check;
    bool is_high_tier;
    
    base_points = func(transaction_amount);
    //@ assert base_points == compute_result(transaction_amount);
    
    threshold_check = (int)transaction_amount;
    is_high_tier = func2(99999, threshold_check, 100001);
    
    if (is_high_tier) {
        tier_points = (unsigned int)func3((uint64_t)transaction_amount);
        //@ assert tier_points == compute_result2((uint64_t)transaction_amount);
    } else {
        tier_points = 0;
    }
    
    total_points = base_points + tier_points;
    
    //@ assert base_points == compute_result(transaction_amount);
    //@ assert tier_points == (is_high_tier ? compute_result2((uint64_t)transaction_amount) : 0);
    //@ assert total_points == base_points + tier_points;
    
    return total_points;
}
