#include <stdbool.h>
#include <limits.h>

/* =====================================================================
   Scenario: A sensor data fusion system for a smart home.
   Three sensors (temperature, humidity, pressure) produce values.
   The system checks if sensor readings are consistent and within safe ranges,
   then decides whether to trigger an alert (bool) and at what level (1-3).
   The synthesized function `sensor_fusion` calls:
     - func1: check if sensor pair (x,y) is in valid condition range
     - func2: check if two sensor values are both small (<=8)
     - func3: compute alert level from three sensor readings
   The final assert checks: if all three sensor values are valid and within range,
   the alert level is safe (1) and condition holds.
   ===================================================================== */

/* --- func1 (from snippet 1) --- */
/*@
    predicate is_valid_range(integer x, integer y) =
        0 <= x <= 10 && 0 <= y <= 10;

    logic integer condition(integer x, integer y) =
        (x * 3 <= y * 2 + 1 || x * 2 <= y * 3 + 1) ? 1 : 0;
*/

bool func1(int x, int y)
{
    unsigned int x_unsigned;
    unsigned int y_unsigned;
    bool result1;
    bool result2;
    bool result;

    //@ assert is_valid_range(x, y);

    x_unsigned = (x < 0) ? 0 : (unsigned int)x;
    y_unsigned = (y < 0) ? 0 : (unsigned int)y;

    //@ assert x_unsigned == (x < 0 ? 0 : (unsigned int)x);
    result1 = (x_unsigned * 3) <= (y_unsigned * 2 + 1);

    //@ assert y_unsigned == (y < 0 ? 0 : (unsigned int)y);
    result2 = (x_unsigned * 2) <= (y_unsigned * 3 + 1);

    //@ assert result1 == (x * 3 <= y * 2 + 1);
    result = result1 || result2;

    //@ assert result == (condition(x, y) == 1);
    return result;
}

/* --- func2 (from snippet 2) --- */
/*@
    predicate both_small(integer a, integer b) =
        a <= 8 && b <= 8;
 */

int func2(long a, long b)
{
    int a_bool;
    int b_bool;
    int result;

    a_bool = (a > 8) ? 0 : 1;
    b_bool = (b > 8) ? 0 : 1;

    //@ assert a_bool == 1 <==> a <= 8;
    //@ assert b_bool == 1 <==> b <= 8;

    result = a_bool && b_bool;
    return result;
}

/* --- func3 (from snippet 3) --- */

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer adjust_result(integer r) =
        r == 0 ? 1 :
        (r == 1 || r == 2) ? r :
        3;
*/

int func3(int a, int b, int c)
{
    int result;
    int final_result;

    result = -1;

    if (a == b) {
        result = c;
    } else if (b == c) {
        result = a;
    } else if (a == c) {
        result = b;
    } else {
        result = 0;
    }

    final_result = result;
    if (result == 0) {
        final_result += 1;
    } else if (result == 1 || result == 2) {
        final_result += 0;
    } else {
        final_result -= result - 1;
    }

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    //@ assert final_result >= 1 && final_result <= 3;

    return final_result;
}

/* --- synthesized function: sensor_fusion --- */

int sensor_fusion(int x, int y, long a, long b, int c, int d, int e)
{
    bool cond_result;
    int both_small_result;
    int alert_level;
    int final_decision;

    cond_result = func1(x, y);

    both_small_result = func2(a, b);

    alert_level = func3(c, d, e);

    if (cond_result && (both_small_result == 1) && (alert_level <= 2)) {
        final_decision = 1;
    } else {
        final_decision = 0;
    }

    //@ assert (cond_result == (condition(x, y) == 1)) && (both_small_result == 1 <==> both_small(a, b)) && (1 <= alert_level <= 3) ==> (final_decision == 1 || final_decision == 0);

    return final_decision;
}
