#include <stdbool.h>

/*@ predicate is_valid_range(integer a) = 1 <= a <= 5000;
    predicate is_valid_third(integer a) = 1 <= a <= 10000;
    predicate result_condition(integer a, integer b, integer c) = 
        c >= a + b && c <= 2 * a + b;
*/

bool triangle_constraint_func(int v[3]) {
    //@ assert is_valid_range(v[0]);
    //@ assert is_valid_range(v[1]);
    //@ assert is_valid_third(v[2]);
    return v[2] >= v[0] + v[1] && v[2] <= 2 * v[0] + v[1];
}

/*@
    predicate is_even(integer x) = x % 2 == 0;
*/

bool even_check_func(unsigned int a, unsigned int b) {
    bool is_even_result = false;
    unsigned int temp_a;
    unsigned int temp_b;
    bool is_a_even;
    bool is_b_even;

    if (a % 2 == 0 || b % 2 == 0) {
        is_even_result = true;
    }

    temp_a = a;
    while (temp_a >= 2) {
        temp_a -= 2;
    }
    is_a_even = (temp_a == 0);

    temp_b = b;
    while (temp_b >= 2) {
        temp_b -= 2;
    }
    is_b_even = (temp_b == 0);

    if (is_a_even || is_b_even) {
        is_even_result = true;
    }

    //@ assert is_even_result == (a % 2 == 0 || b % 2 == 0);
    return is_even_result;
}

/*@
    predicate valid_triangle_sides(integer a, integer b, integer c) =
        1 <= a <= 5000 && 1 <= b <= 5000 && 1 <= c <= 10000 &&
        c >= a + b && c <= 2 * a + b;

    predicate at_least_one_side_even(integer a, integer b, integer c) =
        a % 2 == 0 || b % 2 == 0 || c % 2 == 0;
*/

bool validate_triangle_with_parity(int v[3]) {
    bool triangle_valid;
    bool parity_valid;
    
    triangle_valid = triangle_constraint_func(v);
    
    bool even_a_b = even_check_func((unsigned int)v[0], (unsigned int)v[1]);
    bool even_a_c = even_check_func((unsigned int)v[0], (unsigned int)v[2]);
    bool even_b_c = even_check_func((unsigned int)v[1], (unsigned int)v[2]);
    
    parity_valid = even_a_b || even_a_c || even_b_c;
    
    //@ assert triangle_valid <==> valid_triangle_sides(v[0], v[1], v[2]);
    //@ assert parity_valid <==> at_least_one_side_even(v[0], v[1], v[2]);
    
    return triangle_valid && parity_valid;
}
