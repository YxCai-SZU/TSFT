/* ============================================================
 * Scenario: Network Packet Filter Rule Processor
 *
 * In a network security system, we have a set of packet filter rules.
 * Each rule is defined by:
 *   - a priority (positive integer)
 *   - a port range [min_port, max_port] (both positive integers)
 *   - an action (allow/deny)
 * 
 * The system processes a batch of rules and determines:
 *   1) The "minimum conflict value" between rule priorities (first function)
 *   2) The "maximum priority" among a subset of rules (third function)
 *   3) The "unique action" for a given port (fourth function)
 *   4) A "global invariant" that the final output satisfies certain bounds
 *
 * This synthesized function represents a rule processor that:
 *   - Takes an array of rule priorities and a threshold value
 *   - Computes a conflict metric (min_val from func)
 *   - Computes a maximum priority (from caller2 logic)
 *   - Selects a unique action based on port comparisons (from func logic)
 *   - Verifies that the output is a valid priority value (1 <= result <= 100)
 * ============================================================ */

#include <stddef.h>
#include <stdbool.h>

/* ============================================================
 * Function 1 (adapted from first code snippet):
 *   double_greater_than: returns 2*x, asserts x > y and result > 2*y
 * ============================================================ */
/*@
    logic integer double_val(integer x) = x * 2;

    predicate double_greater_than(integer x, integer y) =
        x > y ==> double_val(x) > double_val(y);

    lemma double_greater_than_lemma:
        \forall integer x, y; x > y ==> double_val(x) > double_val(y);
*/

int double_greater_than(int x, int y)
{
    //@ assert x > y;
    int result = x * 2;
    //@ assert result == double_val(x);
    //@ assert result > double_val(y);
    return result;
}

/* ============================================================
 * Function 2 (adapted from second code snippet):
 *   func: given n, m, x and an array numbers, returns min_val
 *   where min_val is the minimum of (r,l) and then further
 *   reduced by (i-1) for i > x.
 * ============================================================ */
/*@ predicate valid_params(integer n, integer m, integer x) =
      1 <= n && n <= 100 &&
      1 <= m && m <= 100 &&
      1 <= x && x <= n - 1;
*/

/*@ predicate valid_array(int *arr, integer m, integer n, integer x) =
      \forall integer i; 0 <= i < m ==> 
        1 <= arr[i] && arr[i] <= n && arr[i] != x;
*/

/*@ logic integer min_val(integer a, integer b) =
      a < b ? a : b;
*/

/*@ lemma bounds_preserved:
      \forall integer n, m, x, l, r, idx;
      valid_params(n, m, x) &&
      0 <= idx && idx <= m &&
      0 <= l && l <= idx &&
      0 <= r && r <= idx &&
      l + r <= idx
      ==> 0 <= l && l <= m && 0 <= r && r <= m;
*/

int func(int n, int m, int x, int *numbers) {
    int l = 0;
    int r = 0;
    size_t index = 0;
    
    while (index < (size_t)m) {
        int i = numbers[index];
        //@ assert 1 <= i && i <= n && i != x;
        
        if (i > x) {
            r = r + 1;
        }
        if (i < x) {
            l = l + 1;
        }
        index = index + 1;
    }
    
    int min_val_result = (r < l) ? r : l;
    //@ assert 0 <= min_val_result <= m;
    
    size_t j = 0;
    while (j < (size_t)m) {
        int i = numbers[j];
        //@ assert 1 <= i && i <= n && i != x;
        
        if (i > x && i - 1 < min_val_result) {
            min_val_result = i - 1;
        }
        j = j + 1;
    }
    
    //@ assert 0 <= min_val_result <= m;
    return min_val_result;
}

/* ============================================================
 * Function 3 (adapted from third code snippet):
 *   caller2: returns 30 (simulating maximum priority computation)
 * ============================================================ */
/*@
    predicate is_positive(integer x) = x > 0;

    logic integer max_of_three(integer x, integer y, integer z) =
        (x >= y && x >= z) ? x :
        (y >= x && y >= z) ? y :
        z;

    lemma max_of_three_property:
        \forall integer x, y, z;
            is_positive(x) && is_positive(y) && is_positive(z) ==>
            max_of_three(x, y, z) >= x &&
            max_of_three(x, y, z) >= y &&
            max_of_three(x, y, z) >= z;
*/

int caller2(void) {
    int result;
    //@ assert max_of_three(10, 20, 30) == 30;
    result = 30;
    return result;
}

/* ============================================================
 * Function 4 (adapted from fourth code snippet):
 *   func: given three integers a,b,c, returns the "unique" one
 *   or 0 if all distinct.
 * ============================================================ */
/*@
    predicate a_eq_b(integer a, integer b) = a == b;
    predicate a_eq_c(integer a, integer c) = a == c;
    predicate b_eq_c(integer b, integer c) = b == c;
    predicate all_distinct(integer a, integer b, integer c) = a != b && a != c && b != c;

    lemma condition_1:
        \forall integer a, b, c;
        -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100 &&
        a_eq_b(a, b) && !a_eq_c(a, c) ==> a == b && a != c;

    lemma condition_2:
        \forall integer a, b, c;
        -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100 &&
        a_eq_c(a, c) && !a_eq_b(a, b) ==> a == c && a != b;

    lemma condition_3:
        \forall integer a, b, c;
        -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100 &&
        b_eq_c(b, c) && !a_eq_b(a, b) ==> b == c && a != b;

    lemma condition_4:
        \forall integer a, b, c;
        -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100 &&
        all_distinct(a, b, c) ==> a != b && a != c && b != c;
*/

int func_select(int a, int b, int c)
{
    int result;

    //@ assert -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100;

    if (a == b)
    {
        //@ assert a_eq_b(a, b);
        result = c;
        //@ assert (a == b && a != c) ==> result == c;
    }
    else if (a == c)
    {
        //@ assert a_eq_c(a, c);
        result = b;
        //@ assert (a == c && a != b) ==> result == b;
    }
    else if (b == c)
    {
        //@ assert b_eq_c(b, c);
        result = a;
        //@ assert (b == c && a != b) ==> result == a;
    }
    else
    {
        //@ assert all_distinct(a, b, c);
        result = 0;
        //@ assert (a != b && a != c && b != c) ==> result == 0;
    }

    return result;
}

/* ============================================================
 * Synthesized function: process_rule_priorities
 * 
 * Scenario:
 *   Given a set of rule priorities (array priorities of length m),
 *   a threshold priority x, and three candidate priorities a,b,c,
 *   compute:
 *     1) conflict = func(n, m, x, priorities)  -- conflict metric
 *     2) max_priority = caller2()  -- maximum priority (30)
 *     3) selected = func_select(a, b, c)  -- unique action selector
 * 
 *   The function verifies that the final result (conflict) is
 *   within valid bounds (0 <= result <= m) and that the max_priority
 *   is positive.
 * 
 *   High-level property (assert Q): 
 *     The final output (conflict) is a valid priority value
 *     in the range [0, m], and the max_priority is positive.
 * ============================================================ */

int process_rule_priorities(int m, int x, int *priorities, int a, int b, int c)
{
    int conflict = func(100, m, x, priorities);
    //@ assert 0 <= conflict <= m;

    int max_priority = caller2();
    //@ assert max_priority == 30;
    //@ assert max_priority > 0;

    int selected = func_select(a, b, c);
    //@ assert (a == b && a != c) ==> selected == c;
    //@ assert (a == c && a != b) ==> selected == b;
    //@ assert (b == c && a != b) ==> selected == a;
    //@ assert (a != b && a != c && b != c) ==> selected == 0;

    //@ assert 0 <= conflict <= m && max_priority > 0;

    return conflict;
}

/* ============================================================
 * Example main function (for testing, not required by synthesis)
 * ============================================================ */
int main(void)
{
    int priorities[5] = {10, 20, 30, 40, 50};
    int result = process_rule_priorities(5, 25, priorities, 10, 20, 30);
    return 0;
}
