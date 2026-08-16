#include <stdbool.h>
#include <stdint.h>

/* Original first function: checks ordering of three numbers */
/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;
*/

bool func(unsigned long a, unsigned long b, unsigned long c)
{
    bool ret;

    ret = false;

    if (a < b)
    {
        if (b < c)
        {
            ret = true;
        }
    }

    //@ assert ret == (a < b && b < c);

    return ret;
}

/* Original second function: computes sum based on ordering comparisons */
#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer safe_sum(integer x, integer y) = x + y;

    lemma sum_bounds:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 
            2 <= safe_sum(x, y) <= 20000;
*/

int32_t func2(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    int32_t result;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    if (a < b) {
        if (c < d) {
            //@ assert 2 <= b + d <= 20000;
            result = (int32_t)(b + d);
        } else {
            //@ assert 2 <= b + c <= 20000;
            result = (int32_t)(b + c);
        }
    } else {
        if (c < d) {
            //@ assert 2 <= a + d <= 20000;
            result = (int32_t)(a + d);
        } else {
            //@ assert 2 <= a + c <= 20000;
            result = (int32_t)(a + c);
        }
    }
    
    //@ assert 1 <= result <= 20000;
    return result;
}

/* Synthesized function: Temperature sensor data validation and safe average calculation
   Scenario: An IoT device reads temperature samples from four sensors (a,b,c,d).
   It first checks if three consecutive samples (a,b,c) are in strictly increasing order
   (indicating a heating trend), then computes a safe sum of two appropriate samples
   to derive a temperature metric, ensuring no overflow.
   The final assertion verifies that when the samples are ordered, the result is always
   within a safe range for the application.
*/

int32_t synthesize_temperature_metric(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    bool ordered = func((unsigned long)a, (unsigned long)b, (unsigned long)c);
    int32_t metric;
    
    if (ordered) {
        metric = func2(a, b, c, d);
    } else {
        //@ assert valid_range(a) && valid_range(c);
        //@ assert 2 <= a + c <= 20000;
        metric = (int32_t)(a + c);
        //@ assert 1 <= metric <= 20000;
    }
    
    //@ assert 1 <= metric <= 20000;
    return metric;
}
