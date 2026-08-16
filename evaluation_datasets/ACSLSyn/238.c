#include <stdbool.h>

/*@ predicate valid_vector(int *v) =
      \valid(v) &&
      v[0] >= 1 && v[0] <= 100 &&
      v[1] >= 1 && v[1] <= 100 &&
      v[2] >= 1 && v[2] <= 200;
*/

/*@ logic integer vector_sum(integer a, integer b) = a + b; */

bool check_vector(int *v) {
    int a;
    int b;
    int c;
    int sum;
    
    a = v[0];
    b = v[1];
    c = v[2];
    sum = a + b;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 200;
    //@ assert sum == vector_sum(a, b);
    
    if (a <= c && sum >= c) {
        return true;
    } else {
        return false;
    }
}

/*@ predicate is_even(integer n) = n % 2 == 0; */

bool check_even(unsigned int n)
{
    bool is_even_var;
    
    //@ assert 1 <= n <= 100;
    
    switch (n % 2) {
        case 0:
            is_even_var = true;
            break;
        case 1:
            is_even_var = false;
            break;
        default:
            is_even_var = false;
            break;
    }
    
    return is_even_var;
}

bool evaluate_resource_allocation(int *v) {
    bool allocation_feasible = check_vector(v);
    bool result;
    
    if (allocation_feasible) {
        result = check_even(v[0]);
    } else {
        result = !check_even(v[1]);
    }
    
    return result;
}
