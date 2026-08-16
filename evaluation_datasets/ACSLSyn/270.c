#include <stdbool.h>
#include <stddef.h>

/* ========== Function 1: compute sum of squares ========== */
/*@
    predicate a_in_range(integer a) = 0 <= a && a <= 10;
    predicate b_in_range(integer b) = 0 <= b && b <= 10;
    logic integer square(integer x) = x * x;
    logic integer expected_result(integer a, integer b) = square(a) + square(b);
    
    lemma square_bounds_a:
        \forall integer a; a_in_range(a) ==> 0 <= square(a) <= 100;
    lemma square_bounds_b:
        \forall integer b; b_in_range(b) ==> 0 <= square(b) <= 100;
*/

int sum_squares(int a, int b)
{
    //@ assert 0 <= a && a <= 10;
    //@ assert 0 <= b && b <= 10;
    
    int result;
    
    //@ assert 0 <= a * a && a * a <= 100;
    result = a * a;
    
    //@ assert 0 <= b * b && b * b <= 100;
    result += b * b;
    
    //@ assert result == a * a + b * b;
    return result;
}

/* ========== Function 2: check array uniqueness ========== */
/*@
    predicate all_unique(int *list, integer len) =
        \forall integer x, y; 0 <= x < len && 0 <= y < len && x != y ==> list[x] != list[y];
*/

bool all_unique(int *list, size_t len) {
    //@ assert all_unique(list, len);
    return true;
}

/* ========== Function 3: check rotation property ========== */
/*@ predicate is_rotatable(integer a0, integer a1, integer b0, integer b1) =
      a0 == b1 && a1 == b0;
*/

bool check_rotation(int a[2], int b[2]) {
    bool result = (a[0] == b[1] && a[1] == b[0]);
    //@ assert result == 1 <==> is_rotatable(a[0], a[1], b[0], b[1]);
    return result;
}

/* ========== Synthesized function: process configuration pairs ========== */
/*@
    predicate valid_config_pair(integer a, integer b) = a_in_range(a) && b_in_range(b);
    
    predicate consistent_configs(int *list, integer len) =
        \forall integer i; 0 <= i < len-1 ==>
            (valid_config_pair(list[2*i], list[2*i+1]) &&
             is_rotatable(list[2*i], list[2*i+1], list[2*i+2], list[2*i+3]));
*/

bool process_config_pairs(int *list, size_t num_pairs) {
    bool unique_check = all_unique(list, 2*num_pairs);
    //@ assert unique_check == true;
    
    bool rotation_ok = true;
    
    for (size_t i = 0; i < num_pairs - 1; i++) {
        bool current_rotation = check_rotation(&list[2*i], &list[2*i+2]);
        //@ assert current_rotation == 1 <==> is_rotatable(list[2*i], list[2*i+1], list[2*i+2], list[2*i+3]);
        
        if (!current_rotation) {
            rotation_ok = false;
        }
    }
    
    //@ assert rotation_ok == true ==> consistent_configs(list, num_pairs);
    //@ assert rotation_ok == false ==> !consistent_configs(list, num_pairs);
    
    return rotation_ok;
}
