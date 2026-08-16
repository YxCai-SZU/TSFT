#include <stdint.h>
#include <stdbool.h>

/*@
    predicate is_small(integer x) = 1 <= x <= 9;
    predicate both_small(integer n, integer m) = is_small(n) && is_small(m);
    
    logic integer safe_product(integer n, integer m) = n * m;
    
    lemma product_bound: \forall integer n, m; 
        is_small(n) && is_small(m) ==> safe_product(n, m) <= 81;
*/

int32_t func(uint32_t n, uint32_t m)
{
    uint8_t n_is_less_or_equal_9;
    uint8_t m_is_less_or_equal_9;
    int32_t result;
    
    n_is_less_or_equal_9 = (n <= 9);
    m_is_less_or_equal_9 = (m <= 9);
    
    if (n_is_less_or_equal_9 && m_is_less_or_equal_9)
    {
        //@ assert n <= 9 && m <= 9;
        //@ assert n * m <= 81;
        result = (int32_t)(m * n);
        return result;
    }
    else
    {
        result = -1;
        return result;
    }
}

typedef struct {
    int len;
} HashSet;

/*@
    predicate is_valid_hashset(HashSet *m) =
        \valid(m) &&
        m->len >= 0;

    logic integer hashset_len(HashSet *m) = m->len;
*/

void count_elements(HashSet *m)
{
    int count;

    //@ assert is_valid_hashset(m);
    count = m->len;
    //@ assert hashset_len(m) == count;
    //@ assert hashset_len(m) >= 0;
}

/*@
    predicate is_digit(integer d) = 0 <= d && d < 10;
    predicate is_palindrome(integer d1, integer d2, integer d3) = d1 == d3;
*/

int is_palindrome_c(int d1, int d2, int d3)
{
    //@ assert is_digit(d1) && is_digit(d2) && is_digit(d3);
    return d1 == d3;
}

/*@
    predicate valid_output(int result, int d1, int d2, int d3, HashSet *m) =
        (result == d1 && is_palindrome(d1, d2, d3)) || 
        (result == -1 && !is_palindrome(d1, d2, d3));
*/

int process_palindrome_and_product(int d1, int d2, int d3, HashSet *m)
{
    int palindrome_result;
    int32_t product_result;
    int output;
    
    palindrome_result = is_palindrome_c(d1, d2, d3);
    
    count_elements(m);
    
    if (palindrome_result)
    {
        product_result = func(d1, d2);
        output = d1;
    }
    else
    {
        product_result = -1;
        output = -1;
    }
    
    return output;
}
