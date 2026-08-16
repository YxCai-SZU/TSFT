#include <stdint.h>
#include <stdbool.h>

/* Scenario: E-commerce order processing system - verifying if a discount coupon is applicable
   based on order amount, inventory checks, and customer loyalty points */

/*@
    predicate valid_input(integer x) = 1 <= x <= 100000;
    logic integer compute_ans(integer x) =
        (x / 500) * 1000 + ((x % 500) / 5) * 5;
    lemma ans_formula_correct:
        \forall integer x; valid_input(x) ==>
            compute_ans(x) == (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

uint32_t compute_discount(uint32_t x)
{
    uint32_t ans;
    uint32_t temp_x;
    
    ans = 0;
    temp_x = x;
    
    //@ assert valid_input(x);
    
    if (500 <= temp_x)
    {
        //@ assert temp_x == x;
        ans += (temp_x / 500) * 1000;
        temp_x = temp_x % 500;
        //@ assert ans == (x / 500) * 1000;
    }
    
    if (5 <= temp_x)
    {
        //@ assert temp_x == x % 500;
        ans += (temp_x / 5) * 5;
        //@ assert ans == (x / 500) * 1000 + ((x % 500) / 5) * 5;
    }
    
    //@ assert ans == compute_ans(x);
    return ans;
}

/*@
    predicate X_in_range(integer X) = 1 <= X <= 205;
    predicate Y_in_range(integer Y) = 1 <= Y <= 205;
    predicate ans_valid(integer ans) = ans >= -1;
*/

int32_t check_inventory(uint16_t X, uint16_t Y)
{
    int32_t ans = -1;
    uint16_t i = 0;
    
    while (i < 205)
    {
        if (X <= i)
        {
            uint16_t j = 0;
            
            while (j < 205)
            {
                if (Y <= j)
                {
                    uint16_t k = X + j - Y;
                    
                    //@ assert k == X + j - Y;
                    
                    if (i == j && j == k && i > 0)
                    {
                        ans = 1;
                    }
                    break;
                }
                j += 1;
            }
        }
        i += 1;
    }
    
    //@ assert ans >= -1;
    return ans;
}

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;
    logic integer safe_product(integer t, integer s) = t * s;
    lemma product_bounds: \forall integer t, s;
        valid_params(10000, t, s) ==> safe_product(t, s) <= 100000000;
*/

bool check_delivery_feasibility(long d, long t, long s)
{
    long product;
    bool result;

    //@ assert t > 0 && s > 0;
    
    //@ assert t * s <= 10000 * 10000;
    
    if (t == 0 || s == 0) {
        return false;
    }
    
    if (t < 0 || s < 0) {
        return false;
    }
    
    //@ assert t * s <= 10000 * 10000;
    
    product = t * s;
    //@ assert product == safe_product(t, s);
    
    if (d <= product) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (d <= safe_product(t, s));
    return result;
}

/*@ predicate is_valid_x(integer x) = 1 <= x <= 200; */
/*@ predicate is_valid_i(integer i, integer x) = 1 <= i <= x + 1; */
/*@ predicate is_valid_ans(integer ans) = ans == 0 || ans == 1; */
/*@ predicate is_valid_temp(integer temp, integer i) = 0 <= temp <= i; */
/*@ predicate temp_mod_condition(integer temp, integer i) = temp % 6 == i % 6; */

int32_t validate_loyalty_points(uint32_t x)
{
    int32_t ans = 0;
    uint32_t i = 1;
    
    while (i <= x)
    {
        bool is_ok = false;
        uint32_t temp = i;
        
        while (temp >= 6)
        {
            //@ assert temp % 6 == i % 6;
            temp -= 6;
        }
        
        if (temp == 0)
        {
            is_ok = true;
        }
        
        if (is_ok)
        {
            ans = 1;
            break;
        }
        
        i += 1;
    }
    
    //@ assert is_valid_ans(ans);
    return ans;
}

/*@
    predicate valid_order_params(integer order_amount, integer width, integer height,
                                 integer distance, integer time_per_unit, integer speed,
                                 integer loyalty_points) =
        valid_input(order_amount) &&
        X_in_range(width) && Y_in_range(height) &&
        valid_params(distance, time_per_unit, speed) &&
        is_valid_x(loyalty_points);
    
    predicate promotion_eligible(integer discount, integer inventory_check, 
                                 bool delivery_ok, int32_t loyalty_check) =
        discount > 500 && inventory_check == 1 && delivery_ok == true && loyalty_check == 1;
*/

int32_t process_order_promotion(uint32_t order_amount, uint16_t width, uint16_t height,
                                long distance, long time_per_unit, long speed,
                                uint32_t loyalty_points)
{
    int32_t promotion_result = 0;
    uint32_t discount = 0;
    int32_t inventory_result = -1;
    bool delivery_result = false;
    int32_t loyalty_result = 0;
    
    discount = compute_discount(order_amount);
    
    inventory_result = check_inventory(width, height);
    
    delivery_result = check_delivery_feasibility(distance, time_per_unit, speed);
    
    loyalty_result = validate_loyalty_points(loyalty_points);
    
    if (discount > 500 && inventory_result == 1 && delivery_result == true && loyalty_result == 1)
    {
        promotion_result = 1;
    }
    
    //@ assert (promotion_result == 1) ==> (discount > 500 && inventory_result == 1 && delivery_result == true && loyalty_result == 1);
    
    return promotion_result;
}
