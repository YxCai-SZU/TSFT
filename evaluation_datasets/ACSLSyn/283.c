/* Scenario: Network packet validation system
   Data flow: 
   1. Parse packet length N from header (1-100000)
   2. Compute special validation value using func (returns 0/1)
   3. Compute offset using func2 (returns 0-201)
   4. Check if packet validation passes using func3
   The synthesized function validates if a network packet meets certain criteria */

#include <stdint.h>
#include <stdbool.h>

/* Original function 1: validates packet length property */
/*@
    predicate is_valid_N(integer N) = 1 <= N && N <= 100000;
    predicate result_condition(integer result, integer N) =
        result == 0 || result == 1;
    predicate result_one_implies(integer result, integer N) =
        result == 1 ==> (N % 100) * 21 + 1 == N;
    predicate result_zero_implies(integer result, integer N) =
        result == 0 ==> (N % 100) * 21 + 1 != N;
    lemma loop_maintains: \forall integer N, result, i;
        is_valid_N(N) && 1 <= i && i <= 100 && result_condition(result, N) &&
        result_one_implies(result, N) && result_zero_implies(result, N) ==>
        result_condition(result, N) && result_one_implies(result, N) && result_zero_implies(result, N);
*/

int func(int N)
{
    int result;
    int i;
    result = 0;
    i = 1;
    while (i < 100)
    {
        int x;
        x = N - i * 100;
        if (x > 0)
        {
            //@ assert x == N - i * 100;
            if (x * 21 + 1 == N)
            {
                result = 1;
                break;
            }
        }
        i = i + 1;
    }
    return result;
}

/* Original function 2: computes offset value */
/*@
    predicate x_in_range(integer x) = 1 <= x <= 100;
    predicate y_in_range(integer y) = 1 <= y <= 100;
    predicate x_neq_y(integer x, integer y) = x != y;
    predicate result_in_range(integer r) = 0 <= r <= 201;
*/

int64_t func2(int64_t x, int64_t y)
{
    int64_t result;
    
    if (x > y)
    {
        if (x - 1 > 0)
        {
            result = 1 + (y - 1);
        }
        else
        {
            result = y;
        }
    }
    else
    {
        if (y - x - 1 > 0)
        {
            result = x + 1 + (y - x - 1);
        }
        else
        {
            result = x + 1;
        }
    }
    
    //@ assert result >= 0;
    //@ assert result <= 201;
    
    return result;
}

/* Original function 3: checks condition */
/*@
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        b < c || (b >= c && d >= a);
*/

bool func3(int a, int b, int c, int d)
{
    bool result;
    result = false;

    if (b < c)
    {
        result = true;
    }
    else if (b >= c && d >= a)
    {
        result = true;
    }

    //@ assert result == (b < c || (b >= c && d >= a));
    return result;
}

/* Synthesized function: validates network packet
   Takes packet length N, and three header fields a, b, c, d (all 1-100)
   Returns true if packet passes validation */
bool validate_packet(int N, int a, int b, int c, int d)
{
    int validation_result;
    int64_t offset;
    bool final_check;
    
    validation_result = func(N);
    
    offset = func2(a, b);
    
    final_check = func3(a, b, c, d);
    
    //@ assert final_check ==> (b < c || (b >= c && d >= a));
    
    return final_check;
}
