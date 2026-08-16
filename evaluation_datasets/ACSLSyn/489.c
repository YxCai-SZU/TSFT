#include <stdbool.h>

/* ACSL predicates from code snippets */
/*@
    predicate is_odd(integer x) = x % 2 == 1;
    predicate is_even(integer x) = x % 2 == 0;
    predicate a_in_range(integer a) = 0 <= a <= 10000;
    predicate b_in_range(integer b) = 0 <= b <= 10000;
    predicate product_in_range(integer a, integer b) = 0 <= a * b <= 10000 * 10000;
    predicate is_in_range(integer a) = 1 <= a <= 100;
    predicate is_valid_n(integer n) = 1 <= n && n <= 9;
    predicate is_target(integer n) = n == 3 || n == 5 || n == 7;
    
    lemma a_times_10000_bound: \forall integer a; a_in_range(a) ==> 0 <= a * 10000 <= 10000 * 10000;
    lemma full_product_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> 0 <= (a * 10000) * b <= 10000 * 10000 * 10000;
    lemma main_product_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> product_in_range(a, b);
    lemma division_lemma: \forall integer a; is_in_range(a) ==> ((a + 3) / 2) >= 0;
    
    logic integer division_result(integer a) = (a + 3) / 2;
*/

/* Function 1: Check if number is odd */
void is_odd_impl(unsigned int x, int *result)
{
    *result = (x % 2 == 1);
}

/* Function 2: Check if product is within range */
bool product_in_range_check(unsigned int a, unsigned int b)
{
    bool result;
    result = (a * b <= 10000 * 10000);
    return result;
}

/* Function 3: Compute (a+3)/2 using subtraction loop */
long division_by_subtraction(long a)
{
    long result = a + 3;
    long count = 0;
    bool is_negative = false;
    
    if (result < 0)
    {
        is_negative = true;
        result = -result;
    }
    
    while (result >= 2)
    {
        result -= 2;
        count += 1;
    }
    
    if (is_negative)
        return -(count);
    else
        return count;
}

/* Function 4: Check if number is target (3, 5, or 7) */
bool is_target_number(unsigned long n)
{
    int v[3] = {3, 5, 7};
    int index = 0;
    
    while (index < 3)
    {
        if (n == v[index])
        {
            return true;
        }
        index++;
    }
    return false;
}

/* Synthesized function: Validate a data packet in a numerical processing pipeline */
bool validate_packet(unsigned int packet_id)
{
    int is_odd_flag;
    bool product_valid;
    long division_val;
    bool target_check;
    bool final_result;
    
    is_odd_impl(packet_id, &is_odd_flag);
    
    if (!is_odd_flag)
    {
        return false;
    }
    
    product_valid = product_in_range_check(packet_id, 10000);
    
    division_val = division_by_subtraction((long)packet_id);
    
    target_check = is_target_number((unsigned long)division_val);
    
    final_result = (is_odd_flag && target_check);
    
    return final_result;
}
