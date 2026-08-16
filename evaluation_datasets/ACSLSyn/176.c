/* 
 * Scenario: Industrial water level management system
 * 
 * A water tank has a maximum safe capacity of 100 units. 
 * There are two input pipes (b and c) that can be opened to fill the tank.
 * We need to determine if the tank can be filled to level 'a' using pipes b and c,
 * and then compute the total water usage efficiency metric.
 * 
 * Function combine_water_management:
 *   - Takes target level a, and flow rates b and c (all in range 1-100)
 *   - First checks if target level a can be reached by combining flows b and c
 *   - Then computes an efficiency metric based on the flow rates and target
 *   - Returns 1 if target is reachable AND efficiency metric is positive, 0 otherwise
 */

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer compute_result(integer a, integer b, integer c) =
        c > a + b + 1 ? a + b + 1 + b :
        c == a + b + 1 ? a + b + b :
        c + b;

    lemma result_non_negative:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            compute_result(a, b, c) >= 0;

    lemma result_upper_bound:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            compute_result(a, b, c) <= 200;

    predicate can_reach_level_a_condition(integer a, integer b, integer c) =
        b + c >= a;

    predicate combined_property(integer a, integer b, integer c) =
        can_reach_level_a_condition(a, b, c) ==> compute_result(a, b, c) >= 0;
*/

int combine_water_management(long a, long b, long c)
{
    long efficiency;
    int reachable;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    {
        unsigned long long combined_height;
        combined_height = b + c;
        //@ assert combined_height == b + c;
        reachable = combined_height >= a;
    }
    //@ assert reachable == 1 <==> can_reach_level_a_condition(a, b, c);

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    {
        long result;
        if (c > a + b + 1)
        {
            result = a + b + 1 + b;
        }
        else if (c == a + b + 1)
        {
            result = a + b + b;
        }
        else
        {
            result = c + b;
        }
        //@ assert result == compute_result(a, b, c);
        //@ assert result >= 0;
        //@ assert result <= 200;
        efficiency = result;
    }
    //@ assert efficiency == compute_result(a, b, c);
    //@ assert efficiency >= 0;
    //@ assert efficiency <= 200;

    //@ assert combined_property(a, b, c);

    return reachable && (efficiency >= 0);
}

int main()
{
    return 0;
}
