#include <stdint.h>

/*@
  requires ((1) <= (A) && (A) <= (20)) && ((1) <= (B) && (B) <= (20));
  ensures (((1) <= ((A)) && ((A)) <= (9)) && ((1) <= ((B)) && ((B)) <= (9))) ==> \result == A * B;
  ensures !(((1) <= ((A)) && ((A)) <= (9)) && ((1) <= ((B)) && ((B)) <= (9))) ==> \result == -1;
  assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    //@ assert ((1) <= (A) && (A) <= (20));
    //@ assert ((1) <= (B) && (B) <= (20));
    
    if (1 <= A && A <= 9 && 1 <= B && B <= 9) {
        //@ assert (((1) <= ((A)) && ((A)) <= (9)) && ((1) <= ((B)) && ((B)) <= (9)));
        //@ assert A * B <= 81;
        return A * B;
    } else {
        return -1;
    }
}
