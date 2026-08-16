#include <stdbool.h>

/*@
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> 1 <= (input)[i] && (input)[i] <= 9);
    ensures \result == 1 <==> ((input)[0] < (input)[1] && (input)[1] < (input)[2]);
    assigns \nothing;
*/
bool is_increasing(int input[3]) {
    //@ assert ((3) == 3 &&         \forall integer i; 0 <= i < (3) ==> 1 <= (input)[i] && (input)[i] <= 9);
    
    if (input[0] < input[1] && input[1] < input[2]) {
        //@ assert ((input)[0] < (input)[1] && (input)[1] < (input)[2]);
        return true;
    } else {
        //@ assert !((input)[0] < (input)[1] && (input)[1] < (input)[2]);
        return false;
    }
}
