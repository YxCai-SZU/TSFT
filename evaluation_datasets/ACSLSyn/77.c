#include <stdbool.h>

/* ACSL predicates and lemmas from the original functions */
/*@
    predicate in_range_7(integer x) = 1 <= x && x <= 7;
    predicate in_range_8(integer v) = 1 <= v <= 8;
    predicate is_valid_params(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;
    predicate valid_params(integer k, integer a, integer b) =
        1 <= k && k <= 1000 &&
        1 <= a && a <= b && b <= 1000;

    logic integer max_value(integer n) = n / 2 + n % 2;
    logic integer safe_div_mul(integer k, integer b) = (b / k) * k;

    lemma max_value_lemma:
        \forall integer n; 1 <= n <= 100 ==> max_value(n) >= 0;
    lemma mul_assoc_comm:
        \forall integer x, y, z;
            in_range_8(x) && in_range_8(y) && in_range_8(z) ==>
            (x * y) * z == (y * z) * x;
    lemma div_bound: \forall integer k, integer b;
        valid_params(k, 1, b) ==> b / k <= 1000;
    lemma mul_bound: \forall integer k, integer b;
        valid_params(k, 1, b) ==> (b / k) * k <= 1000000;
*/

/* Original function 1: checks triangle-like inequality on sorted values */
bool func1(int a, int b, int c, int k)
{
    int temp;
    int a_var = a;
    int b_var = b;
    int c_var = c;
    int k_var = k;
    
    //@ assert in_range_7(a_var) && in_range_7(b_var) && in_range_7(c_var) && in_range_7(k_var);
    
    if (a_var > b_var) {
        temp = a_var;
        a_var = b_var;
        b_var = temp;
    }
    
    //@ assert a_var <= b_var;
    
    if (b_var > c_var) {
        temp = b_var;
        b_var = c_var;
        c_var = temp;
    }
    
    //@ assert b_var <= c_var;
    
    if (c_var > a_var) {
        temp = c_var;
        c_var = a_var;
        a_var = temp;
        temp = a_var;
        a_var = b_var;
        b_var = temp;
    }
    
    //@ assert in_range_7(a_var) && in_range_7(b_var) && in_range_7(c_var) && in_range_7(k_var);
    
    return c_var >= k_var - a_var - b_var || c_var <= a_var + b_var - k_var;
}

/* Original function 2: checks if k is within allowed maximum */
bool func2(int n, int k)
{
    int max;
    int n_mod_2;
    int original_n;

    original_n = n;
    n_mod_2 = n;

    while (n_mod_2 >= 2)
    {
        n_mod_2 = n_mod_2 - 2;
    }

    max = n / 2 + n_mod_2;

    //@ assert max == max_value(original_n);

    if (k <= max)
    {
        //@ assert k <= max_value(original_n);
        return true;
    }
    else
    {
        //@ assert k > max_value(original_n);
        return false;
    }
}

/* Original function 3: verifies associativity/commutativity property */
bool func3(unsigned int x, unsigned int y, unsigned int z)
{
    bool result;

    //@ assert x * y <= 64;
    //@ assert y * z <= 64;
    //@ assert x * (y * z) <= 512;
    //@ assert (x * y) * z <= 512;
    //@ assert (y * z) * x <= 512;
    //@ assert x * (y * z) == (x * y) * z;
    //@ assert (y * z) * x == (x * y) * z;

    result = ((x * y) * z) == ((y * z) * x);
    return result;
}

/* Original function 4: checks divisibility bound */
int func4(int k, int a, int b)
{
    int result;

    //@ assert b / k <= 1000;
    //@ assert (b / k) * k <= 1000000;

    result = (a <= (b / k) * k);
    return result;
}

/* 
 * Synthesized complex function: Resource Allocation Validator
 * 
 * Real-world scenario: A system allocates resources to processes. It validates
 * that a given allocation satisfies multiple constraints:
 * 1. Resource bounds must satisfy a triangle inequality (func1)
 * 2. Allocation count must be within allowed maximum (func2)
 * 3. Multiplication properties must hold for resource sizes (func3)
 * 4. Allocation must be within divisibility limits (func4)
 *
 * Data flow: The function takes resource parameters and validates them through
 * a chain of 4 checks, ensuring the allocation is valid overall.
 */

/*@
    predicate valid_allocation(integer a, integer b, integer c, integer k, 
                               integer n, integer x, integer y, integer z) =
        in_range_7(a) && in_range_7(b) && in_range_7(c) && in_range_7(k) &&
        is_valid_params(n, k) &&
        in_range_8(x) && in_range_8(y) && in_range_8(z) &&
        valid_params(k, a, b) &&
        (c >= k - a - b || c <= a + b - k) &&
        k <= max_value(n) &&
        ((x * y) * z == (y * z) * x) &&
        a <= (b / k) * k;
*/

bool validate_resource_allocation(int a, int b, int c, int k, int n, 
                                  unsigned int x, unsigned int y, unsigned int z)
{
    bool result1, result2, result3, result4;
    bool final_result;

    result1 = func1(a, b, c, k);
    
    result2 = func2(n, k);
    
    result3 = func3(x, y, z);
    
    result4 = func4(k, a, b);

    final_result = result1 && result2 && result3 && result4;

    //@ assert final_result <==> valid_allocation(a, b, c, k, n, x, y, z);

    return final_result;
}
