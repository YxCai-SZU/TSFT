#include <stdbool.h>

/* ===================== Original Functions (Unmodified) ===================== */

/* --- Function 1: func (threshold check) --- */
/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_threshold(integer a) = a * 2 + 1;

    predicate result_condition(integer a, integer b, bool result) =
        result == (b >= compute_threshold(a));
*/

bool func(long a, long b)
{
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;

    if (a <= 0 || b <= 0) {
        return false;
    }

    //@ assert 1 <= a * 2 + 1 <= 201;

    //@ assert 1 <= b <= 100;

    result = (b >= (a * 2 + 1));
    //@ assert result == (b >= (a * 2 + 1));
    return result;
}

/* --- Function 2: is_palindrome_c --- */
/*@ predicate is_palindrome(integer n) =
      100 <= n && n <= 999 &&
      (n / 100 == n % 10) && (n % 100 / 10 == n % 100 % 10);
*/

/*@ lemma division_bound: \forall integer n; 100 <= n && n <= 999 ==> n / 100 <= 9; */
/*@ lemma modulo_bound: \forall integer n; 100 <= n && n <= 999 ==> n % 100 <= 99; */
/*@ lemma division_modulo_bound: \forall integer n; 100 <= n && n <= 999 ==> n % 100 / 10 <= 9; */
/*@ lemma double_modulo_bound: \forall integer n; 100 <= n && n <= 999 ==> n % 100 % 10 <= 9; */

bool is_palindrome_c(unsigned int n) {
    bool res;
    
    //@ assert n / 100 <= 9;
    //@ assert n % 100 <= 99;
    //@ assert n % 100 / 10 <= 9;
    //@ assert n % 100 % 10 <= 9;
    
    res = (n / 100 == n % 10) && (n % 100 / 10 == n % 100 % 10);
    return res;
}

/* --- Function 3: func (max of sum/diff/prod) --- */
/*@
    predicate is_in_range(integer x) = -100 <= x <= 100;
    
    logic integer sum(integer a, integer b) = a + b;
    logic integer diff(integer a, integer b) = a - b;
    logic integer prod(integer a, integer b) = a * b;
    
    lemma product_in_range: 
        \forall integer a, b; 
        is_in_range(a) && is_in_range(b) ==> -10000 <= prod(a, b) <= 10000;
*/

int max_func(int A, int B)
{
    int max_ab;
    int max_result;
    
    //@ assert -10000 <= A * B <= 10000;
    
    if (A * B > A + B)
    {
        max_ab = A * B;
    }
    else
    {
        max_ab = A + B;
    }
    
    if (max_ab > A - B)
    {
        max_result = max_ab;
    }
    else
    {
        max_result = A - B;
    }
    
    //@ assert max_result >= A + B && max_result >= A - B && max_result >= A * B;
    
    return max_result;
}

/* ===================== Synthesized Complex Function ===================== */

/* 
 * Scenario: Ticket validation system for a theme park.
 * - Each ticket has an ID (3-digit palindrome) and a priority code (a,b).
 * - The system checks if the ticket ID is a palindrome, then computes a priority threshold,
 *   and finally determines the maximum allowed ride duration (in minutes) based on the priority.
 * 
 * Data flow:
 *   1. ticket_id (n) -> is_palindrome_c -> bool palindrome_ok
 *   2. threshold parameters (a,b) -> func -> bool threshold_ok
 *   3. ride parameters (A,B) -> max_func -> int max_duration
 * 
 * High-level property: The final output (max_duration) is always at least as large as the sum,
 * difference, and product of the ride parameters, AND the ticket is valid (palindrome and threshold check).
 */

/*@
    predicate valid_ticket(unsigned int n, long a, long b) =
        (100 <= n && n <= 999) && valid_range((integer)a, (integer)b) &&
        (n / 100 == n % 10) && (n % 100 / 10 == n % 100 % 10) &&
        (b >= (a * 2 + 1));
    
    predicate ride_max_property(int max_dur, int A, int B) =
        max_dur >= A + B && max_dur >= A - B && max_dur >= A * B;
*/

int validate_and_compute(unsigned int n, long a, long b, int A, int B)
{
    bool palindrome_ok = is_palindrome_c(n);
    
    bool threshold_ok = func(a, b);
    
    int max_duration = max_func(A, B);
    
    //@ assert (palindrome_ok && threshold_ok) ==> (max_duration >= A + B && max_duration >= A - B && max_duration >= A * B);
    
    return max_duration;
}
