#include <stdbool.h>

/* Scenario: Two-factor authentication code validation system
 * 
 * The system validates an authentication code by:
 * 1. First checking if the two-digit code contains digit 9 (a "master digit")
 * 2. Then applying a secondary validation rule based on the code and a device-specific parameter
 * 
 * Data flow:
 * - Input: two-digit authentication code (n) and device parameter (d)
 * - Step 1: func_contains_nine(n) checks if n has digit 9
 * - Step 2: func_secondary_check(n, d) applies secondary validation
 * - Output: overall authentication result
 */

/*@
    predicate is_two_digit(integer n) = 10 <= n && n <= 99;

    logic integer mod_10(integer x) = x % 10;

    logic integer div_10(integer x) = x / 10;

    lemma mod_10_range: \forall integer n; is_two_digit(n) ==> 0 <= mod_10(n) && mod_10(n) <= 9;

    lemma div_10_range: \forall integer n; is_two_digit(n) ==> 1 <= div_10(n) && div_10(n) <= 9;
*/

int func_contains_nine(unsigned long long n)
{
    unsigned long long rem;
    unsigned long long last_digit;
    unsigned long long quot;
    unsigned long long temp_n;
    unsigned long long first_digit;

    rem = n;
    while (rem >= 10)
    {
        rem -= 10;
    }
    while (rem < 0)
    {
        rem += 10;
    }
    last_digit = rem;

    quot = 0;
    temp_n = n;
    while (temp_n >= 10)
    {
        temp_n -= 10;
        quot += 1;
    }

    rem = quot;
    while (rem >= 10)
    {
        rem -= 10;
    }
    while (rem < 0)
    {
        rem += 10;
    }
    first_digit = rem;

    return (last_digit == 9 || first_digit == 9);
}

/*@
    predicate condition_holds(integer n, integer d) =
        n + 2 * d >= 3 * d + 1 || n >= d + 1;
*/

bool func_secondary_check(int n, int d)
{
    bool result;

    //@ assert 1 <= n <= 20;
    //@ assert 1 <= d <= 20;

    if (n + 2 * d >= 3 * d + 1)
    {
        //@ assert n + 2 * d >= 3 * d + 1;
        result = true;
    }
    else if (n >= d + 1)
    {
        //@ assert n >= d + 1;
        result = true;
    }
    else
    {
        //@ assert !(n + 2 * d >= 3 * d + 1) && !(n >= d + 1);
        result = false;
    }

    //@ assert result == true <==> (n + 2 * d >= 3 * d + 1 || n >= d + 1);
    return result;
}

/*@
    predicate auth_success(integer code, integer device_param) =
        (is_two_digit(code) ==> (mod_10(code) == 9 || mod_10(div_10(code)) == 9))
        && (1 <= code <= 20 ==> (code + 2 * device_param >= 3 * device_param + 1 || code >= device_param + 1));
*/

bool authenticate(unsigned long long code, int device_param)
{
    bool has_master_digit;
    bool secondary_check_passed;
    bool auth_result;

    has_master_digit = func_contains_nine(code);
    //@ assert has_master_digit == true <==> (mod_10(code) == 9 || mod_10(div_10(code)) == 9);

    secondary_check_passed = func_secondary_check((int)code, device_param);
    //@ assert secondary_check_passed == true <==> (code + 2 * device_param >= 3 * device_param + 1 || (int)code >= device_param + 1);

    auth_result = has_master_digit && secondary_check_passed;

    //@ assert auth_result == true <==> ((mod_10(code) == 9 || mod_10(div_10(code)) == 9) && (code + 2 * device_param >= 3 * device_param + 1 || code >= device_param + 1));

    return auth_result;
}
