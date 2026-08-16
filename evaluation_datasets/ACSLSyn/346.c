#include <stdint.h>
#include <stdbool.h>

/* ACSL specifications for the underlying functions */

/* Function 1: classify_interval_relation */
/*@
    predicate valid_range(integer x) = 1 <= x && x <= 10000;
    predicate case1(integer a, integer b, integer c, integer d) = 
        a >= c && b >= d;
    predicate case2(integer a, integer b, integer c, integer d) = 
        a <= c && b <= d;
    predicate case0(integer a, integer b, integer c, integer d) = 
        (a < c && b > d) || (a > c && b < d) || (a == c && b == d);
    lemma case_exclusion:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
            !case1(a,b,c,d) && !case2(a,b,c,d) ==> case0(a,b,c,d);
*/

int32_t classify_interval_relation(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    if (a >= c && b >= d)
    {
        //@ assert case1(a,b,c,d);
        return 1;
    }
    else if (a <= c && b <= d)
    {
        //@ assert case2(a,b,c,d);
        return 2;
    }
    else
    {
        //@ assert !case1(a,b,c,d) && !case2(a,b,c,d);
        //@ assert case0(a,b,c,d);
        return 0;
    }
}

/* Function 2: check_multiple_of_3 */
/*@
    predicate is_multiple_of_3(integer x) = (x / 3) * 3 == x;
    logic integer safe_sum(integer a, integer b) = a + b;
*/

bool check_multiple_of_3(unsigned int a, unsigned int b)
{
    bool a_is_multiple_of_3;
    bool b_is_multiple_of_3;
    bool sum_is_multiple_of_3;
    unsigned int sum;

    //@ assert a + b <= 200;
    sum = a + b;

    a_is_multiple_of_3 = (a / 3) * 3 == a;
    b_is_multiple_of_3 = (b / 3) * 3 == b;
    sum_is_multiple_of_3 = (sum / 3) * 3 == sum;

    return a_is_multiple_of_3 || b_is_multiple_of_3 || sum_is_multiple_of_3;
}

/* Function 3: count_greater_elements */
/*@ predicate is_valid_element(integer x) = 0 <= x < 65536; */
/*@ predicate element_greater(integer x, integer e) = x > e ==> x >= e + 1; */
/*@ lemma greater_implies_at_least_one_more: 
      \forall integer x, e; is_valid_element(x) && is_valid_element(e) && x > e ==> x >= e + 1; */

uint32_t count_greater_elements(const uint32_t* list1, uint32_t len, uint32_t element) {
    uint32_t greater_count = 0;
    uint32_t i = 0;
    
    while (i < len) {
        uint32_t x = list1[i];
        if (x > element) {
            greater_count++;
        }
        i++;
    }
    return greater_count;
}

/* Function 4: find_min */
/*@
    predicate is_min(integer ret, integer a, integer b, integer c) =
        ret <= a && ret <= b && ret <= c &&
        (ret == a || ret == b || ret == c);
 */

int find_min(int a, int b, int c)
{
    int min_val = a;
    //@ assert min_val == a;
    if (b < min_val)
    {
        min_val = b;
        //@ assert min_val == b;
    }
    //@ assert min_val <= a && min_val <= b;
    if (c < min_val)
    {
        min_val = c;
        //@ assert min_val == c;
    }
    //@ assert is_min(min_val, a, b, c);
    return min_val;
}

/* Synthesized function: process_data_segment
   Real-world scenario: In a network protocol parser, we process a data segment:
   - We receive four interval boundaries (a,b) and (c,d) that define two ranges.
   - We also have a list of packet sizes (list1) and an element (element) representing a threshold.
   - We check if any of the boundaries or their sum is a multiple of 3 (for alignment checking).
   - We count how many packet sizes exceed the threshold.
   - We find the minimum of three key values: the classification result, the multiple-of-3 check result (as 0/1), and the count of greater elements.
   The high-level property: The final minimum value is consistent with the data invariants.
*/

int process_data_segment(uint32_t a, uint32_t b, uint32_t c, uint32_t d,
                         const uint32_t* list1, uint32_t len, uint32_t element)
{
    int32_t classification = classify_interval_relation(a, b, c, d);
    //@ assert classification == 0 || classification == 1 || classification == 2;
    
    bool multiple_check = check_multiple_of_3(a, b);
    
    uint32_t greater_count = count_greater_elements(list1, len, element);
    //@ assert greater_count <= len;
    
    int multiple_check_int = multiple_check ? 1 : 0;
    int result = find_min((int)classification, multiple_check_int, (int)greater_count);
    
    //@ assert result <= classification && result <= multiple_check_int && result <= (int)greater_count;
    //@ assert result >= 0;
    
    return result;
}
