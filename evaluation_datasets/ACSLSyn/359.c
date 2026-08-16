#include <stdbool.h>

/* First function: is_possible_to_have_exactly_x_cats */
/*@
    predicate is_possible(integer a, integer b, integer x) =
        a <= x && a + b >= x;
*/

bool is_possible_to_have_exactly_x_cats(long long a, long long b, long long x) {
    bool result;
    result = (a <= x && a + b >= x);
    return result;
}

/* Second function: check equality via subtraction */
/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n && n <= 100 && 0 <= m && m <= n;

    lemma n_minus_i_positive:
        \forall integer n, m, i;
            is_valid_params(n, m) && i <= m && i >= 0 ==>
            n - i >= 0;
*/

bool func_eq(unsigned int n, unsigned int m)
{
    unsigned int i = 0;
    unsigned int n_copy = n;
    
    while (i < m)
    {
        //@ assert n_copy > 0;
        n_copy -= 1;
        i += 1;
    }
    
    bool is_zero = (n_copy == 0);
    
    if (is_zero)
    {
        //@ assert n == m;
        return true;
    }
    else
    {
        //@ assert n != m;
        return false;
    }
}

/* Third function: check if vector elements are all distinct */
/*@
    predicate valid_vector(int *v, integer len) =
        1 <= len <= 3 &&
        \forall integer i; 0 <= i < len ==> (v[i] == 1 || v[i] == 2 || v[i] == 3);
    
    predicate all_distinct(int *v, integer len) =
        len == 3 && v[0] != v[1] && v[1] != v[2] && v[0] != v[2];
    
    lemma len_three_distinct:
        \forall int *v, integer len;
        valid_vector(v, len) && len == 3 && v[0] != v[1] && v[1] != v[2] && v[0] != v[2] ==>
        all_distinct(v, len);
*/

bool func_check_distinct(int *v, int len)
{
    bool result;
    //@ assert valid_vector(v, len);
    if (len != 3)
    {
        //@ assert !all_distinct(v, len);
        return false;
    }
    if (v[0] == v[1] || v[1] == v[2] || v[0] == v[2])
    {
        //@ assert !all_distinct(v, len);
        return false;
    }
    //@ assert all_distinct(v, len);
    return true;
}

/* Fourth function: check if date is after cutoff */
/*@
    predicate is_valid_date(integer y, integer m) =
        y >= 0 && m >= 1 && m <= 12;

    predicate after_cutoff(integer y, integer m) =
        y > 2019 || (y == 2019 && m > 4);
*/

bool func_date_check(int year, int month)
{
    bool result;

    //@ assert is_valid_date(year, month);

    if (year < 2019)
    {
        //@ assert year < 2019;
        result = false;
    }
    else if (year > 2019)
    {
        //@ assert year > 2019;
        result = true;
    }
    else
    {
        if (month > 4)
        {
            //@ assert year == 2019 && month > 4;
            result = true;
        }
        else
        {
            //@ assert year == 2019 && month <= 4;
            result = false;
        }
    }

    //@ assert result == true <==> after_cutoff(year, month);
    return result;
}

/* Synthesized function: Date-based resource allocation system */
/*@
    predicate valid_allocation(integer a, integer b, integer x, integer n, integer m, 
                               int *v, integer len, integer year, integer month) =
        is_possible(a, b, x) && is_valid_params(n, m) && valid_vector(v, len) && 
        is_valid_date(year, month) &&
        (after_cutoff(year, month) ==> (n == m && all_distinct(v, len)));
*/

bool resource_allocation_check(long long a, long long b, long long x, 
                               unsigned int n, unsigned int m,
                               int *v, int len,
                               int year, int month)
{
    bool possible = is_possible_to_have_exactly_x_cats(a, b, x);
    
    bool equal_count = func_eq(n, m);
    
    bool distinct = func_check_distinct(v, len);
    
    bool after_cutoff_date = func_date_check(year, month);
    
    bool result = possible && (!after_cutoff_date || (equal_count && distinct));
    
    return result;
}
