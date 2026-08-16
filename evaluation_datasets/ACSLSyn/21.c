/* *****************************************************************************
 * Scenario: Network Packet Filtering
 *
 * Description:
 *   In a network packet filtering system, we need to validate whether a packet
 *   (represented by parameters a, b, c, d) should be allowed through based on
 *   two independent rule sets:
 *     - Rule set 1 (func): checks if the packet matches either condition1 or
 *       condition2 (e.g., port ranges, address ranges).
 *     - Rule set 2 (func2): checks if a specific flag (c) lies strictly between
 *       two bounds (a and b), which might represent a priority or sequence
 *       number validation.
 *
 *   The synthesized function `validate_packet` first verifies the packet
 *   against rule set 1. If it passes, it then applies rule set 2 for a more
 *   fine-grained check. The final result indicates whether the packet is
 *   allowed (both checks pass) or denied.
 *
 *   The high-level property asserted at the end is that the final decision
 *   (allow or deny) is logically consistent: a packet is allowed if and only
 *   if it satisfies the combined criteria of both rule sets.
 * ****************************************************************************/

#include <stdbool.h>

/* --- First underlying function (Rule set 1) --- */
/*@
    predicate condition1(integer a, integer b, integer c, integer d) =
        c <= b && b + d >= a;

    predicate condition2(integer a, integer b, integer c, integer d) =
        c + d >= a && b <= a;

    predicate result_condition(integer a, integer b, integer c, integer d, integer res) =
        res != 0 <==> (condition1(a, b, c, d) || condition2(a, b, c, d));
 */

int func(int a, int b, int c, int d)
{
    int is_valid = 0;

    if (c <= b && b + d >= a) {
        is_valid = 1;
    } else if (c + d >= a && b <= a) {
        is_valid = 1;
    }

    //@ assert result_condition(a, b, c, d, is_valid);
    return is_valid;
}

/* --- Second underlying function (Rule set 2) --- */
/*@ predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate c_in_range(integer c) = 1 <= c && c <= 100;
    predicate result_condition2(integer a, integer b, integer c, bool result) = 
        result == ((a < c) && (c < b));
 */

bool func2(int a, int b, int c)
{
    bool result;
    result = (a < c) && (c < b);
    //@ assert result_condition2(a, b, c, result);
    return result;
}

/* --- Synthesized high-level function --- */

int validate_packet(int a, int b, int c, int d)
{
    int pass_rule1 = func(a, b, c, d);

    int pass_rule2 = 0;
    if (pass_rule1) {
        pass_rule2 = func2(a, b, c) ? 1 : 0;
    }

    int allow = pass_rule1 && pass_rule2;

    //@ assert (allow == 1) <==> ( ((c <= b && b + d >= a) || (c + d >= a && b <= a)) && ((a < c) && (c < b)) );
    return allow;
}
