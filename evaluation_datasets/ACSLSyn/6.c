#include <stdbool.h>
#include <stddef.h>

/* Original first function with its specification */
/*@ predicate valid_range(integer n, integer m) = 
      1 <= n && n <= 20 && 1 <= m && m <= 20; */

/*@ lemma product_range: 
      \forall integer n, m; valid_range(n, m) ==> 1 <= n * m && n * m <= 400; */

int func(int n, int m)
{
    //@ assert valid_range(n, m);
    //@ assert 1 <= n * m && n * m <= 400;
    return n * m;
}

/* Original second function with its specification */
/*@
    predicate bitwise_eq(integer a, integer b, integer c) =
        (a | b) == (a | c) && (a & c) == (b & c);
*/

bool func_bitwise(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    //@ assert bitwise_eq(a, b, c) <==> ((a | b) == (a | c) && (a & c) == (b & c));
    result = ((a | b) == (a | c) && (a & c) == (b & c));
    return result;
}

/* Original third function with its specification */
/*@
    predicate is_special_pair(integer x, integer y) =
        (x == 0 && y == 5) ||
        (x == 5 && y == 0) ||
        (x == 5 && y == 5) ||
        (x == 10 && y == 10);
 */

bool logical_inequality_example(unsigned int x, unsigned int y)
{
    //@ assert x <= 10 && y <= 10;
    return (x == 0 && y == 5) || (x == 5 && y == 0) || (x == 5 && y == 5) || (x == 10 && y == 10);
}

/* 
 * Synthesized function: Image Filter Configuration Validator
 * 
 * Real-world scenario: Validates configuration parameters for a special image filter.
 * The filter requires a grid size (n x m) where both dimensions are between 1 and 20.
 * It also requires two pixel values (x, y) that form a "special pair" defining a color
 * transformation rule. Additionally, the filter applies a bitwise consistency check
 * between three mask values (a, b, c) to ensure proper channel blending.
 * 
 * Data flow:
 * 1. Calculate grid area using func(n, m)
 * 2. Check if pixel pair (x, y) is special using logical_inequality_example
 * 3. Verify bitwise consistency of masks using func_bitwise
 * 
 * The high-level property: The configuration is valid if and only if the grid area 
 * is within expected bounds AND the pixel pair is special AND the masks are bitwise consistent.
 */

bool validate_filter_config(int n, int m, unsigned int a, unsigned int b, unsigned int c,
                             unsigned int x, unsigned int y)
{
    int grid_area;
    bool special_pair;
    bool bitwise_consistent;
    bool config_valid;
    
    /* Step 1: Calculate grid area */
    grid_area = func(n, m);
    
    /* Step 2: Check if pixel pair is special */
    special_pair = logical_inequality_example(x, y);
    
    /* Step 3: Verify bitwise consistency of masks */
    bitwise_consistent = func_bitwise(a, b, c);
    
    /* Final validation */
    config_valid = (1 <= grid_area && grid_area <= 400) && 
                   special_pair && 
                   bitwise_consistent;
    
    //@ assert config_valid <==> (1 <= n * m && n * m <= 400 && is_special_pair(x, y) && ((a | b) == (a | c) && (a & c) == (b & c)));
    
    return config_valid;
}
