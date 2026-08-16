#include <stdbool.h>

/*@
  requires \valid_read(input + (0..2));
  requires -100 <= input[0] <= 100;
  requires -100 <= input[1] <= 100;
  requires -100 <= input[2] <= 100;
  ensures \result == (input[0] < input[1] && input[1] < input[2]);
  ensures \result == 1 <==> ((input[0]) < (input[1]) && (input[1]) < (input[2]));
*/
bool is_increasing(int input[3]) {
    bool result;
    //@ assert input[0] < input[1] && input[1] < input[2] ==> ((input[0]) < (input[1]) && (input[1]) < (input[2]));
    if (input[0] < input[1] && input[1] < input[2]) {
        result = true;
        //@ assert result == 1;
    } else {
        //@ assert !(input[0] < input[1] && input[1] < input[2]);
        result = false;
        //@ assert result == 0;
    }
    return result;
}
