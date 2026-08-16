#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 100; */

/*@
  requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
  ensures \result == true <==> (a + b == c || a + c == b || b + c == a);
  assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int tmp_a = a;
    unsigned int tmp_b = b;
    unsigned int tmp_c = c;
    
    //@ assert is_valid_range(tmp_a) && is_valid_range(tmp_b) && is_valid_range(tmp_c);
    
    if (tmp_a <= tmp_b && tmp_a <= tmp_c) {
        // a already smallest
    } else if (tmp_b <= tmp_a && tmp_b <= tmp_c) {
        unsigned int temp = tmp_a;
        tmp_a = tmp_b;
        tmp_b = temp;
    } else {
        unsigned int temp = tmp_a;
        tmp_a = tmp_c;
        tmp_c = temp;
    }
    
    //@ assert is_valid_range(tmp_a) && is_valid_range(tmp_b) && is_valid_range(tmp_c);
    
    return (tmp_a + tmp_b == tmp_c) || (tmp_a + tmp_c == tmp_b) || (tmp_b + tmp_c == tmp_a);
}
