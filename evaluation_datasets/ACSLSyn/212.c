#include <stdbool.h>

/*@ predicate exists_zero(int *v, integer len) =
      \exists integer i; 0 <= i < len && v[i] == 0;
*/

/*@ predicate all_valid(int *v, integer len) =
      \forall integer i; 0 <= i < len ==> (v[i] == i + 1 || v[i] == 0);
*/

/*@ lemma zero_exists_in_first_three:
      \forall int *v; \forall integer len;
        len >= 3 && all_valid(v, len) && exists_zero(v, 3) ==>
        exists_zero(v, len);
*/

bool func1(int *v, int len) {
    int i = 0;
    bool result = false;
    
    while (i < 3) {
        if (v[i] == 0) {
            result = true;
            return result;
        }
        i = i + 1;
    }
    
    result = false;
    return result;
}

/*@ predicate is_possible_combination(integer a, integer b, integer c) =
      a + b == c || b + c == a || c + a == b;
*/

bool func2(const int x[3]) {
    int a;
    int b;
    int c;
    bool is_possible;
    
    a = x[0];
    b = x[1];
    c = x[2];
    is_possible = false;
    
    if (a + b == c) {
        is_possible = true;
    } else if (b + c == a) {
        is_possible = true;
    } else if (c + a == b) {
        is_possible = true;
    }
    
    return is_possible;
}

bool check_config_and_combination(int *v, int len) {
    bool has_zero;
    bool combination_valid;
    
    has_zero = func1(v, len);
    
    if (!has_zero) {
        int config[3];
        config[0] = v[0];
        config[1] = v[1];
        config[2] = v[2];
        
        combination_valid = func2(config);
    } else {
        combination_valid = false;
    }
    
    return (!has_zero && combination_valid);
}
