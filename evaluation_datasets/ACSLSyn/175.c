#include <stdint.h>
#include <stdbool.h>

/* First function: computes sum of interior angles of a polygon */
/*@
    predicate valid_n(integer n) = 3 <= n && n <= 100;
*/

int64_t polygon_angle_sum(int64_t n)
{
    int64_t ans;
    //@ assert valid_n(n);
    ans = 180 * (n - 2);
    //@ assert ans == 180 * (n - 2);
    return ans;
}

/* Second function: checks color code validity */
/*@ predicate valid_range(integer x) = 1 <= x <= 9; */

bool color_code_valid(int r, int g, int b) {
    int temp;
    bool result;
    
    //@ assert 10 * g + b <= 99;
    
    temp = 10 * g + b;
    result = (temp % 4 == 0);
    return result;
}

/*@
    logic integer polygon_angle_sum(integer n) = 180 * (n - 2);
*/

/* Synthesized function: validates a polygon's color code based on its interior angle sum */
bool validate_polygon_color(int64_t n, int r, int g, int b) {
    bool angle_valid;
    bool code_valid;
    bool result;
    
    angle_valid = (polygon_angle_sum(n) == 180 * (n - 2));
    
    code_valid = color_code_valid(r, g, b);
    
    result = angle_valid && code_valid;
    
    //@ assert result <==> (valid_n(n) && (10*g + b) % 4 == 0 && polygon_angle_sum(n) == 180*(n-2));
    
    return result;
}
