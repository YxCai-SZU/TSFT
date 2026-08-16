#include <stdbool.h>
#include <limits.h>

/* Predicates and logic from snippet 1 */
/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

/* Predicates and logic from snippet 2 */
/*@ predicate valid_range(integer x) = 1 <= x <= 10000; */
/*@ logic integer product(integer x, integer y) = x * y; */
/*@ lemma product_bounds:
        \forall integer x, y; valid_range(x) && valid_range(y) ==> 
        1 <= product(x, y) <= 100000000;
*/

/* Predicates and logic from snippet 3 */
/*@ predicate is_true(integer value) = value != 0; */

/* Predicates and logic from snippet 4 */
/*@ predicate is_valid_n(integer n) = 1 <= n && n <= 100; */
/*@ logic integer half_plus_one(integer n) = (n + 1) / 2; */
/*@ lemma half_bound: \forall integer n; is_valid_n(n) ==> half_plus_one(n) <= 50; */

/* Function from snippet 1 */
int func1(int n)
{
    int ans = 1;
    
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0) {
        ans = 1;
    } else {
        ans = 1;
    }
    
    //@ assert (is_even(n) ==> ans == 1) && (is_odd(n) ==> ans == 1);
    return ans;
}

/* Function from snippet 2 */
int func2(int a, int b, int c, int d)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    //@ assert product(a, b) <= 100000000;
    //@ assert product(c, d) <= 100000000;
    
    int product1 = a * b;
    int product2 = c * d;
    
    int result;
    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }
    
    //@ assert result >= 1;
    return result;
}

/* Functions from snippet 3 */
bool logical_layers(bool a, bool b, bool c)
{
    bool result;

    //@ assert a != 0;
    result = (a && b) == (b && c);
    
    //@ assert result != 0;
    return result;
}

bool greater_than_or_equal(int a, int b)
{
    bool result;
    
    //@ assert a <= b;
    result = (a <= b);
    
    //@ assert result != 0;
    return result;
}

bool less_than(int a, int b)
{
    bool result;
    
    //@ assert a <= b;
    result = (a <= b);
    
    //@ assert result != 0;
    return result;
}

bool multiple_relations(int a, int b)
{
    bool result;
    
    //@ assert a <= b;
    result = (a <= b);
    
    //@ assert result != 0;
    return result;
}

/* Function from snippet 4 */
int func4(int n)
{
    int result;
    int temp_n;
    int count;
    
    result = 0;
    temp_n = n + 1;
    count = 0;
    
    while (temp_n > 1)
    {
        //@ assert temp_n > 1;
        temp_n -= 2;
        count += 1;
    }
    
    result = count;
    
    //@ assert result == half_plus_one(n);
    return result;
}

/* Synthesized function: a data validation and processing pipeline for a 
   data transformation system that validates input, computes a transformation 
   factor, and produces a normalized output */
int process_data_pipeline(int n, int a, int b, int c, int d)
{
    int result;
    bool logic_check;
    int factor;
    int max_product;
    
    int parity_check = func1(n);
    //@ assert (is_even(n) ==> parity_check == 1) && (is_odd(n) ==> parity_check == 1);
    
    factor = func4(n);
    //@ assert factor == half_plus_one(n);
    //@ assert factor <= 50;
    
    logic_check = logical_layers(a, b, c);
    //@ assert logic_check != 0;
    
    max_product = func2(a, b, c, d);
    //@ assert max_product >= 1;
    //@ assert max_product <= 100000000;
    //@ assert max_product == product(a, b) || max_product == product(c, d);
    
    bool ge_check = greater_than_or_equal(3, 3);
    //@ assert ge_check != 0;
    
    bool lt_check = less_than(1, 2);
    //@ assert lt_check != 0;
    
    bool mr_check = multiple_relations(2, 3);
    //@ assert mr_check != 0;
    
    if (max_product <= 100000000 / factor) {
        result = max_product * factor;
    } else {
        result = 100000000;
    }
    
    //@ assert result >= 1;
    //@ assert result <= 100000000;
    
    return result;
}
