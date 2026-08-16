#include <stdbool.h>
#include <stdint.h>

/* 
 * Real-world scenario: Inventory Package Validation System
 * 
 * This system validates incoming inventory packages by checking:
 * 1. Whether the package dimensions (as a vector of 3 values) satisfy a triangular sum condition
 * 2. Whether the package weight class (X,Y) can be processed by the system
 * 3. Whether the package priority code (x) passes a special validation
 * 4. Whether the package count (n) is even and the total volume (t*s) exceeds a threshold (d)
 * 
 * The final validation result indicates whether the entire package batch is acceptable.
 */

/* Original function 1: checks if any two of three numbers sum to the third */
/*@
    predicate valid_vector(int *v) =
        \valid(v) &&
        \valid(v+1) &&
        \valid(v+2) &&
        1 <= v[0] && v[0] <= 100 &&
        1 <= v[1] && v[1] <= 100 &&
        1 <= v[2] && v[2] <= 100;

    logic integer sum_condition(integer a, integer b, integer c) =
        (a + b == c) ? 1 :
        (b + c == a) ? 1 :
        (a + c == b) ? 1 : 0;
*/

bool func1(int *v)
{
    bool result;
    
    //@ assert \valid(v) && \valid(v+1) && \valid(v+2);
    //@ assert 1 <= v[0] && v[0] <= 100;
    //@ assert 1 <= v[1] && v[1] <= 100;
    //@ assert 1 <= v[2] && v[2] <= 100;

    result = (v[0] + v[1] == v[2]) ||
             (v[1] + v[2] == v[0]) ||
             (v[0] + v[2] == v[1]);

    return result;
}

/* Original function 2: computes X + (Y/2) with loop invariant */

unsigned int func2(unsigned int X, unsigned int Y)
{
    unsigned int ans;
    unsigned int temp;
    unsigned int count;
    
    ans = 0;
    temp = X;
    count = 0;
    
    while (temp >= 2 && temp <= 200)
    {
        //@ assert temp >= 2 && temp <= 200;
        temp -= 2;
        count += 1;
        //@ assert temp + 2 * count == X;
    }
    
    ans = X + (Y / 2);
    //@ assert ans == X + (Y / 2);
    return ans;
}

/* Original function 3: validates package priority code */
/*@
    predicate is_valid_x(integer x) = 1 <= x <= 100000;
    
    logic integer compute_d(integer x) = 
        (x / 100) + ((x % 100 != 0) ? 1 : 0);
    
    lemma d_bound: \forall integer x; is_valid_x(x) ==> compute_d(x) <= 1000;
*/

int32_t func3(uint32_t x)
{
    uint32_t d;
    uint32_t dd;
    
    //@ assert is_valid_x(x);
    
    d = (x / 100) + ((x % 100 != 0) ? 1 : 0);
    
    //@ assert d <= 1000;
    
    dd = d * 100 + 21;
    
    if ((x % 100) * 21 >= x) {
        return 1;
    } else {
        return 0;
    }
}

/* Original function 4: checks evenness, product threshold, and complement */
/*@ predicate is_even(integer n) = n % 2 == 0; */

int func4a(int n)
{
    //@ assert 1 <= n <= 100;
    if (n % 2 == 0) {
        //@ assert is_even(n);
        return 1;
    } else {
        //@ assert !is_even(n);
        return 0;
    }
}

/*@
    logic integer product(integer a, integer b) = a * b;
    predicate product_ge_d(integer t, integer s, integer d) = product(t, s) >= d;
*/

/*@
    lemma product_bounds:
        \forall integer t, s;
            1 <= t <= 10000 && 1 <= s <= 10000 ==> 1 <= product(t, s) <= 100000000;
*/

bool func4b(int d, int t, int s)
{
    //@ assert 1 <= d <= 10000;
    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    //@ assert 1 <= product(t, s) <= 100000000;
    return t * s >= d;
}

/*@
    logic integer complement(integer x) = 1 - x;
    predicate is_zero(integer x) = x == 0;
*/

int func4c(int x)
{
    //@ assert 0 <= x <= 1;
    if (x == 0) {
        //@ assert is_zero(x);
        return 1;
    } else {
        //@ assert !is_zero(x);
        return 0;
    }
}

/* 
 * Synthesized function: validate_package_batch
 * 
 * High-level property: The batch is accepted if and only if:
 *   - The package dimensions satisfy the triangular sum condition AND
 *   - The weight class processing succeeds (result >= threshold) AND
 *   - The priority code passes validation AND
 *   - The package count is even and volume exceeds threshold
 * 
 * This property ensures that only complete valid batches are accepted.
 */

/*@
    predicate batch_accept_condition(int *v, unsigned int X, unsigned int Y, 
                                     uint32_t x, int n, int d, int t, int s) =
        sum_condition(v[0], v[1], v[2]) == 1 &&
        X + (Y / 2) >= 50 &&
        (x % 100) * 21 >= x &&
        is_even(n) && product(t, s) >= d;
*/

bool validate_package_batch(int *v, unsigned int X, unsigned int Y,
                            uint32_t x, int n, int d, int t, int s)
{
    bool dim_ok;
    unsigned int weight_result;
    int32_t priority_ok;
    int even_ok;
    bool volume_ok;
    int complement_ok;
    bool batch_accepted;
    
    dim_ok = func1(v);
    
    weight_result = func2(X, Y);
    
    priority_ok = func3(x);
    
    even_ok = func4a(n);
    volume_ok = func4b(d, t, s);
    complement_ok = func4c(priority_ok);
    
    batch_accepted = dim_ok && (weight_result >= 50) && (priority_ok == 1) && 
                     (even_ok == 1) && volume_ok;
    
    //@ assert batch_accepted == true <==> batch_accept_condition(v, X, Y, x, n, d, t, s);
    
    return batch_accepted;
}
