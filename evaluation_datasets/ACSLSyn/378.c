#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ===== Original functions with ACSL specifications ===== */

/* First function: func from snippet 1 */
/*@
    predicate equal_length{L}(int *a, int *b, int *c, integer len) =
        \valid(a + (0 .. len-1)) &&
        \valid(b + (0 .. len-1)) &&
        \valid(c + (0 .. len-1));

    predicate non_empty(integer len) = len > 0;

    predicate result_condition{L}(int *a, int *b, int *c, integer len) =
        a[0] < b[0] && c[0] < b[0];
*/

bool func1(int *a, int *b, int *c, size_t len) {
    bool result;
    
    //@ assert non_empty(len);
    
    result = (a[0] < b[0]) && (c[0] < b[0]);
    return result;
}

/* Second function: compute_expression from snippet 2 */
/*@
    predicate in_range(integer v) = 1 <= v < 10;

    logic integer expression(integer v) = v * v + 2 * v + 1;

    lemma expression_is_less_than_100:
        \forall integer v; in_range(v) ==> expression(v) <= 100;

    lemma property_holds:
        \forall integer v; in_range(v) ==> expression(v) <= 100;

    lemma verify_all_properties:
        expression(1) <= 100 &&
        expression(2) <= 100 &&
        expression(3) <= 100 &&
        expression(4) <= 100 &&
        expression(5) <= 100 &&
        expression(6) <= 100 &&
        expression(7) <= 100 &&
        expression(8) <= 100 &&
        expression(9) <= 100;
*/

uint32_t compute_expression(uint32_t v)
{
    //@ assert in_range(v);
    uint32_t result;
    result = v * v + 2 * v + 1;
    //@ assert result == expression(v);
    //@ assert result <= 100;
    return result;
}

/* Third function: func from snippet 3 */
/*@
    predicate valid_range(integer x) = 1 <= x <= 5000;
    
    logic integer min(integer x, integer y) = x < y ? x : y;
    
    lemma subtraction_bounds:
        \forall integer b, d; valid_range(b) && valid_range(d) ==> b - d <= 5000;
*/

bool func3(int a, int b, int c, int d)
{
    bool result;
    int min_val;
    
    //@ assert b >= 1;
    //@ assert d >= 1;
    //@ assert b - d <= 5000;
    
    if (a < c) {
        min_val = a;
    } else {
        min_val = c;
    }
    
    result = (min_val >= b - d);
    return result;
}

/* Fourth function: func from snippet 4 */
/*@
    predicate valid_range2(integer a, integer b) =
        3 <= a && a <= 20 && 3 <= b && b <= 20;
    
    logic integer max_product(integer a, integer b) =
        (a - 1) * (b - 1);
*/

int func4(int a, int b)
{
    int ans;
    
    //@ assert a - 1 >= 2;
    //@ assert b - 1 >= 2;
    //@ assert max_product(a, b) <= 19 * 19;
    
    ans = (a - 1) * (b - 1);
    
    if (ans >= 0) {
        return ans;
    } else {
        return 0;
    }
}

/* ===== Synthesized complex function ===== */

/* Scenario: Matrix dimension validation for a graphics rendering system.
   The function validates that a rectangular grid of cells (a x b) can be subdivided 
   into valid sub-regions based on comparison values from data arrays.
   
   Data flow:
   - Input arrays a, b, c (length len) provide comparison thresholds
   - Input values x, y, z, w are dimension parameters
   - The function checks if the grid dimensions and first elements satisfy constraints
   - Then computes an expression based on dimension w
   - Finally validates the grid product bounds
   
   The call chain is:
   1. func1: check if first elements satisfy threshold condition
   2. compute_expression: compute a derived value from dimension w
   3. func3: validate dimension relationships
   4. func4: compute and validate grid product
*/

/*@
    predicate grid_validation{L}(int *a, int *b, int *c, size_t len, int x, int y, int z, int w) =
        equal_length(a, b, c, len) && non_empty(len) &&
        result_condition(a, b, c, len) &&
        valid_range(x) && valid_range(y) && valid_range(z) && valid_range(w) &&
        in_range((uint32_t)w) &&
        valid_range2(x, y) &&
        (x < z ? x : z) >= y - w;
*/

int synthesize_grid_validation(int *a, int *b, int *c, size_t len, int x, int y, int z, int w)
{
    bool threshold_ok = func1(a, b, c, len);
    
    uint32_t expr_val = compute_expression((uint32_t)w);
    
    bool dim_ok = func3(x, y, z, w);
    
    int grid_product = func4(x, y);
    
    //@ assert (threshold_ok && dim_ok) ==> (grid_product >= 0 && grid_product <= (x - 1) * (y - 1));
    
    return grid_product;
}
