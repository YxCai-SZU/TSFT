#include <stdint.h>

/* First function: time addition modulo 24 (e.g., for time-of-day scheduling) */
/*@
    predicate valid_range_time(integer x) = 0 <= x <= 23;

    logic integer mod24(integer x) = x % 24;

    logic integer conditional_result(integer a, integer b) =
        mod24(a + b) < 24 ? mod24(a + b) : mod24(a + b) - 24;
*/

uint32_t add_time(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;

    //@ assert valid_range_time(a) && valid_range_time(b);
    sum = a + b;
    result = sum % 24;

    if (result < 24)
    {
        //@ assert result == mod24(a + b);
        return result;
    }
    else
    {
        //@ assert result == mod24(a + b);
        return result - 24;
    }
}

/* Second function: priority boost computation (e.g., for scheduling priority) */
/*@
    predicate valid_range_priority(integer x) = 1 <= x <= 100;

    lemma product_bound: \forall integer a, b; 
        valid_range_priority(a) && valid_range_priority(b) ==> a * b <= 10000;
*/

int32_t compute_boost(uint32_t a, uint32_t b)
{
    //@ assert valid_range_priority(a);
    //@ assert valid_range_priority(b);
    //@ assert a * b <= 10000;
    return (int32_t)(a * b + 1);
}

/* Synthesized function: schedule_next_event
 * Real-world scenario: In a real-time scheduling system, given a current time (hour, 0-23)
 * and a base priority (1-100), compute the next event time by adding a delay derived from priority.
 * The delay is computed as the priority boost modulo 24, then added to the current time.
 *
 * Data flow:
 *   - Input: current_hour (0-23), base_priority (1-100), urgency_factor (1-100)
 *   - Step 1: Compute priority boost using compute_boost(base_priority, urgency_factor)
 *   - Step 2: Compute delay = boost % 24 (clamped to valid time range)
 *   - Step 3: Compute next hour using add_time(current_hour, delay)
 *   - Output: next_hour (0-23)
 *
 * High-level property: The result is always a valid hour (0-23).
 */

uint32_t schedule_next_event(uint32_t current_hour, uint32_t base_priority, uint32_t urgency_factor)
{
    int32_t boost;
    uint32_t delay;
    uint32_t next_hour;

    boost = compute_boost(base_priority, urgency_factor);
    //@ assert boost == (int32_t)(base_priority * urgency_factor + 1);

    delay = (uint32_t)(boost % 24);
    //@ assert 0 <= delay && delay <= 23;

    next_hour = add_time(current_hour, delay);
    //@ assert 0 <= next_hour && next_hour <= 23;

    //@ assert valid_range_time(next_hour);
    return next_hour;
}
