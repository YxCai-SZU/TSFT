#include <stdbool.h>

/*@ predicate valid_range(integer v) = 1 <= v && v <= 100; */

/*@ predicate valid_input(int *input) = 
      \valid(input + (0..5)) &&
      valid_range(input[0]) &&
      valid_range(input[1]) &&
      valid_range(input[2]) &&
      valid_range(input[3]) &&
      valid_range(input[4]) &&
      valid_range(input[5]); */

/*@
  requires valid_input(input);
  ensures \result == (input[2] <= input[5] && input[4] <= input[1]);
*/
bool func(int *input)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert valid_range(input[0]);
    //@ assert valid_range(input[1]);
    //@ assert valid_range(input[2]);
    //@ assert valid_range(input[3]);
    //@ assert valid_range(input[4]);
    //@ assert valid_range(input[5]);

    result = (input[2] <= input[5] && input[4] <= input[1]);
    return result;
}
