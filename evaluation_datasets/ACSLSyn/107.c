#include <stdint.h>

/* First function: checks if two values are both <=8 or both >8 */
/*@
    predicate both_le_8(integer a, integer b) = a <= 8 && b <= 8;
    predicate both_gt_8(integer a, integer b) = a > 8 && b > 8;
    predicate valid_range(integer a, integer b) = 1 <= a && a <= 16 && 1 <= b && b <= 16 && a + b <= 16;
*/

int func1(unsigned long a, unsigned long b) {
    unsigned long max_value;
    unsigned long min_value;
    unsigned long sum_value;
    int result;

    max_value = (a > b) ? a : b;
    min_value = (a < b) ? a : b;
    sum_value = a + b;

    if (max_value > 8 && min_value <= 8 && sum_value <= 16) {
        result = 0;
    } else {
        //@ assert both_le_8(a, b) || both_gt_8(a, b);
        result = 1;
    }

    return result;
}

/* Second function: complex decision logic based on three inputs */
/*@
    predicate valid_input(integer a, integer b, integer c) =
        0 <= a && a <= 50 &&
        0 <= b && b <= 50 &&
        0 <= c && c <= 50;

    logic integer func_result(integer a, integer b, integer c) =
        c == 0 ?
            (a == b ? 0 : 1)
        : (b == 0 ?
            (a < c ? 1 : 2)
        : (b >= c ?
            (a == b ? 1 : 2)
        : (a > b + c ? 0 :
            (a == b + c ? 1 : 2))));

    lemma result_range:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> 0 <= func_result(a, b, c) <= 2;
*/

uint32_t func2(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t ans;
    //@ assert valid_input(a, b, c);

    if (c == 0)
    {
        if (a == b)
        {
            ans = 0;
        }
        else
        {
            ans = 1;
        }
    }
    else
    {
        if (b == 0)
        {
            if (a < c)
            {
                ans = 1;
            }
            else
            {
                ans = 2;
            }
        }
        else if (b >= c)
        {
            if (a == b)
            {
                ans = 1;
            }
            else
            {
                ans = 2;
            }
        }
        else
        {
            if (a > b + c)
            {
                ans = 0;
            }
            else if (a == b + c)
            {
                ans = 1;
            }
            else
            {
                ans = 2;
            }
        }
    }

    //@ assert ans >= 0 && ans <= 2;
    //@ assert ans == func_result(a, b, c);
    return (uint32_t)ans;
}

/* Synthesized function: resource allocation decision based on capacity and demand */
/* Scenario: A resource allocator that checks if two resource demands (a,b) are balanced 
   within a capacity constraint, then makes an allocation decision using a complex rule set.
   Data flow: func1 validates demand balance, func2 makes final allocation decision. */

/*@
    predicate valid_demands(integer a, integer b) = 
        1 <= a && a <= 16 && 1 <= b && b <= 16 && a + b <= 16;
    predicate valid_allocation(integer a, integer b, integer c) = 
        0 <= a && a <= 50 && 0 <= b && b <= 50 && 0 <= c && c <= 50;
*/

uint32_t resource_allocator(uint32_t a, uint32_t b, uint32_t c) {
    int balance_status;
    uint32_t allocation;
    
    balance_status = func1((unsigned long)a, (unsigned long)b);
    
    if (balance_status == 1) {
        //@ assert both_le_8(a, b) || both_gt_8(a, b);
        allocation = func2(a, b, c);
    } else {
        allocation = 0;
    }
    
    //@ assert (allocation == 1) ==> (both_le_8(a, b) || both_gt_8(a, b));
    return allocation;
}
