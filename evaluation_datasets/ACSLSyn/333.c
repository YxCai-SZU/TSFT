#include <stdbool.h>

/* Scenario: Date validation and processing system for a scheduling application.
 * The system validates a date (month, day), computes a derived constraint value,
 * and then checks if the resulting processing code satisfies certain combinatorial conditions.
 * Data flow: input date -> compute monthly limit -> use limit with date components for constraint check.
 */

/* ===== First code snippet (adapted) ===== */
/*@
    predicate condition_one(integer a, integer b, integer c) =
        c % b == 0 && c + b <= 2 * a;

    predicate condition_two(integer a, integer c, integer d) =
        a % d == 0 && a + d <= 2 * c;
*/

bool func_constraint(unsigned long long a, unsigned long long b,
                     unsigned long long c, unsigned long long d)
{
    if (c % b == 0 && c + b <= 2 * a) {
        //@ assert condition_one(a, b, c);
        return true;
    } else if (a % d == 0 && a + d <= 2 * c) {
        //@ assert condition_two(a, c, d);
        return true;
    } else {
        //@ assert !condition_one(a, b, c) && !condition_two(a, c, d);
        return false;
    }
}

/* ===== Second code snippet (adapted) ===== */
/*@
    predicate valid_input(int *input, integer len) =
        len == 2 &&
        1 <= input[0] <= 12 &&
        1 <= input[1] <= 31;

    logic integer func_result(integer month, integer day) =
        month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12 ? 31 :
        month == 4 || month == 6 || month == 9 || month == 11 ? 30 :
        month == 2 ? (day > 28 ? 28 : day) :
        31;

    lemma result_bounds:
        \forall integer month, day;
        1 <= month <= 12 && 1 <= day <= 31 ==>
        1 <= func_result(month, day) <= 48;
*/

int func_date_limit(int *input)
{
    int result;
    int month = input[0];
    int day = input[1];

    //@ assert 1 <= month <= 12;
    //@ assert 1 <= day <= 31;

    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12)
    {
        //@ assert func_result(month, day) == 31;
        result = 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        //@ assert func_result(month, day) == 30;
        result = 30;
    }
    else if (month == 2)
    {
        if (day > 28)
        {
            //@ assert func_result(month, day) == 28;
            result = 28;
        }
        else
        {
            //@ assert func_result(month, day) == day;
            result = day;
        }
    }
    else
    {
        //@ assert func_result(month, day) == 31;
        result = 31;
    }

    //@ assert 1 <= result <= 48;
    //@ assert result == func_result(month, day);
    return result;
}

/* ===== Third code snippet (adapted) ===== */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

int func_sum_pair(int a, int b, int c)
{
    int max_val;
    int sum;
    
    max_val = a;
    if (b > max_val) {
        max_val = b;
    }
    if (c > max_val) {
        max_val = c;
    }
    
    sum = a + b + c;
    sum -= max_val;
    
    //@ assert sum == a + b || sum == b + c || sum == c + a;
    //@ assert sum >= 0;
    
    return sum;
}

bool is_odd_func(unsigned int n)
{
    return n % 2 != 0;
}

/* ===== Synthesized Complex Function ===== */
bool process_date_schedule(int *input, int month_offset, int day_offset)
{
    int date_limit;
    int pair_sum;
    bool result;

    date_limit = func_date_limit(input);
    //@ assert 1 <= date_limit <= 48;

    pair_sum = func_sum_pair(input[0], input[1], month_offset);
    //@ assert pair_sum == input[0] + input[1] || pair_sum == input[1] + month_offset || pair_sum == input[0] + month_offset;
    //@ assert pair_sum >= 0;

    result = func_constraint((unsigned long long)date_limit, 
                             (unsigned long long)pair_sum, 
                             (unsigned long long)day_offset, 
                             (unsigned long long)(input[0] + input[1]));

    return result;
}
