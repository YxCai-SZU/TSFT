#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_input(int *input, integer len) =
    len >= 3 &&
    \forall integer i; 0 <= i < 3 ==> (input[i] >= 1 && input[i] <= 13);
*/
/*@ logic integer vector_at(int *input, integer i) = input[i];
*/
bool triangle_func(int *input) {
    int a;
    int b;
    int c;
    int ab;
    int bc;
    int ca;
    bool result;
    
    a = input[0];
    b = input[1];
    c = input[2];
    
    //@ assert a == vector_at(input, 0);
    //@ assert b == vector_at(input, 1);
    //@ assert c == vector_at(input, 2);
    
    ab = a + b;
    bc = b + c;
    ca = c + a;
    
    //@ assert ab == a + b;
    //@ assert bc == b + c;
    //@ assert ca == c + a;
    
    result = (ab > c) && (bc > a) && (ca > b);
    
    //@ assert result == (ab > c && bc > a && ca > b);
    
    return result;
}

/*@
    predicate is_valid_range(integer a, integer b) =
        0 <= a <= 1 && 0 <= b <= 1;
    logic integer func_spec(integer a, integer b) = a + b + 1;
*/
uint32_t range_func(uint32_t a, uint32_t b)
{
    //@ assert is_valid_range(a, b);
    //@ assert 0 <= func_spec(a, b) <= 3;
    return a + b + 1;
}

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;
    logic integer safe_product(integer t, integer s) = t * s;
*/
bool speed_func(int d, int t, int s)
{
    bool result;
    int product;

    //@ assert s <= 10000;
    //@ assert t <= 10000;

    if (s > 10000 || t > 10000 || d > 10000)
    {
        //@ assert t * s <= 10000 * 10000;
        return false;
    }

    //@ assert t * s <= 10000 * 10000;
    
    product = t * s;
    result = (product >= d);
    return result;
}

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    logic integer max(integer x, integer y) = (x <= y) ? y : x;
*/
unsigned int area_func(unsigned int n)
{
    unsigned int result;

    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    
    result = (n * n) / 2;
    return result;
}

/*@ logic boolean triangle_func_spec(int *sides) = 
    (sides[1] + sides[2] > sides[0] && 
     sides[0] + sides[2] > sides[1] && 
     sides[0] + sides[1] > sides[2]);
*/

/*@ logic boolean speed_func_spec(int d, int t, int s) = (t * s >= d);
*/

/*@ logic integer area_func_spec(unsigned int n) = (n * n) / 2;
*/

bool synthesize_mission_planner(int *sides, int d, int t, int s, unsigned int n, uint32_t a, uint32_t b)
{
    bool triangle_ok;
    bool speed_ok;
    unsigned int area_val;
    uint32_t range_val;
    bool mission_possible;
    
    triangle_ok = triangle_func(sides);
    //@ assert triangle_ok == (sides[1] + sides[2] > sides[0] && sides[0] + sides[2] > sides[1] && sides[0] + sides[1] > sides[2]);
    
    range_val = range_func(a, b);
    //@ assert range_val == a + b + 1;
    
    speed_ok = speed_func(d, t, s);
    //@ assert speed_ok == (t * s >= d);
    
    area_val = area_func(n);
    //@ assert area_val == (n * n) / 2;
    
    mission_possible = triangle_ok && speed_ok && (area_val > 0);
    
    //@ assert mission_possible == (triangle_func_spec(sides) && speed_func_spec(d, t, s) && (area_func_spec(n) > 0));
    
    return mission_possible;
}
