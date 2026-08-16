#include <stdbool.h>
#include <stddef.h>

/* ===== Original function 1 (unchanged) ===== */
/*@
    predicate is_valid_range(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100;

    logic integer condition_holds(integer x, integer y) =
        (y % 2 == 0 && (x * 2 <= y && y <= x * 4)) ? 1 : 0;

    lemma ans_equivalence:
        \forall integer x, y;
        is_valid_range(x, y) ==>
        (condition_holds(x, y) == 1 <==> 
        (y % 2 == 0 && (x * 2 <= y && y <= x * 4)));
*/

bool func1(unsigned int x, unsigned int y)
{
    bool ans;

    ans = true;

    if (y % 2 == 0)
    {
        if (x * 2 <= y && y <= x * 4)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }
    else
    {
        ans = false;
    }

    //@ assert ans == true <==> condition_holds(x, y) == 1;

    return ans;
}

/* ===== Original function 2 (unchanged) ===== */
/*@
    predicate valid_range_ab(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
*/

/*@
    logic integer scaled_value(integer a) = (a * 8) / 100;
*/

/*@
    lemma scaled_value_range: \forall integer a; 1 <= a <= 100 ==> 0 <= scaled_value(a) <= 8;
*/

bool func2(unsigned int a, unsigned int b)
{
    bool result;
    unsigned int scaled;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100;
    
    scaled = (a * 8) / 100;
    //@ assert scaled == scaled_value(a);
    
    result = scaled <= b;
    //@ assert result == (scaled_value(a) <= b);
    
    return result;
}

/* ===== Original function 3 (unchanged) ===== */
/*@
    predicate is_condition(integer x) =
        x >= 2000 && (x % 2000 <= 1000);
 */

bool func3(unsigned long long x)
{
    unsigned long long div;
    unsigned long long rem;
    bool result;

    div = x / 2000;
    rem = x % 2000;

    //@ assert rem == x % 2000;
    //@ assert div == x / 2000;

    result = x >= 2000 && (rem <= 1000);
    return result;
}

/* ===== Original function 4 (unchanged) ===== */
/*@
    predicate valid_range_x(integer x) = 1 <= x <= 100000;

    logic integer compute_result(integer x) =
        (x / 500 * 1000) + ((x % 500) / 5 * 5);

    lemma temp_bound: \forall integer x, temp_x;
        valid_range_x(x) && temp_x == x % 500 ==> temp_x / 5 * 5 <= 5000;
*/

size_t func4(size_t x)
{
    size_t result = 0;
    size_t temp_x = 0;
    
    //@ assert valid_range_x(x);
    
    temp_x = x / 500;
    result = temp_x * 1000;
    
    temp_x = x % 500;
    //@ assert temp_x / 5 * 5 <= 5000;
    
    result = result + (temp_x / 5 * 5);
    
    //@ assert result == compute_result(x);
    return result;
}

/* ===== Synthesized high-level function =====
   Scenario: Industrial process controller that validates sensor data and computes actuator settings.
   Data flow:
     1. func1 checks if sensor pair (x,y) meets condition (e.g., temperature/pressure ratio)
     2. func2 checks if scaled sensor value fits within calibration range
     3. func3 validates a timestamp or counter value
     4. func4 computes a motor position from a control parameter
   The overall system state is valid if all checks pass and the computed position is positive.
*/

/*@
    predicate system_state_valid(integer x, integer y, integer a, integer b, unsigned long long t, size_t c) =
        is_valid_range(x, y) && valid_range_ab(a, b) && 1 <= t <= 1000000000000 && valid_range_x(c) &&
        condition_holds(x, y) == 1 && scaled_value(a) <= b && 
        (t >= 2000 && (t % 2000 <= 1000)) &&
        compute_result(c) > 0;
*/

bool process_controller(unsigned int x, unsigned int y, unsigned int a, unsigned int b, unsigned long long t, size_t c)
{
    bool cond_ok;
    bool range_ok;
    bool timestamp_ok;
    size_t position;
    bool overall_valid;

    cond_ok = func1(x, y);
    //@ assert cond_ok == true <==> condition_holds(x, y) == 1;

    range_ok = func2(a, b);
    //@ assert range_ok == (scaled_value(a) <= b);

    timestamp_ok = func3(t);
    //@ assert timestamp_ok == (t >= 2000 && (t % 2000 <= 1000));

    position = func4(c);
    //@ assert position == compute_result(c);

    overall_valid = cond_ok && range_ok && timestamp_ok && (position > 0);

    //@ assert overall_valid == true <==> system_state_valid(x, y, a, b, t, c);

    return overall_valid;
}
