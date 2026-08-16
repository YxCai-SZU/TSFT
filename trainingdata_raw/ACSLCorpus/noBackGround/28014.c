#include <stdbool.h>

/*@
    requires \valid_read(input + (0..2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> 1 <= (input)[i] && (input)[i] <= 9);
    ensures \result == 1 <==> ((input)[0] < (input)[1] && (input)[1] < (input)[2]);
    assigns \nothing;
*/
bool func(int input[3])
{
    //@ assert ((3) == 3 &&         \forall integer i; 0 <= i < (3) ==> 1 <= (input)[i] && (input)[i] <= 9);
    return input[0] < input[1] && input[1] < input[2];
}
