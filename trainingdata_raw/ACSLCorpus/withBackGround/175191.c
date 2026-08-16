#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 100; */

/*@
  requires \valid_read(input + (0..2));
  requires is_valid_range(input[0]);
  requires is_valid_range(input[1]);
  requires is_valid_range(input[2]);
  ensures \result == (input[0] < input[1] && input[1] < input[2]);
*/
bool func(const int input[3]) {
    bool result;
    int a;
    int b;
    int c;
    
    result = true;
    a = input[0];
    b = input[1];
    c = input[2];
    
    if (a >= b || b >= c) {
        result = false;
    }
    
    //@ assert result == (a < b && b < c);
    
    return result;
}
