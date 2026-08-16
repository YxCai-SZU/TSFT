#include <stddef.h>
#include <stdbool.h>

/*@
    requires (2 <= (N) <= 100000 &&
        \valid((inputs) + (0 .. (N)-1)) &&
        (\forall integer i; 0 <= i < (N) ==> 1 <= (inputs)[i] <= (N)) &&
        (\forall integer i, j; 0 <= i < j < (N) ==> (inputs)[i] != (inputs)[j]));
    ensures 1 <= \result <= N;
    assigns \nothing;
*/
int func(size_t N, const int *inputs) {
    size_t button = 1;
    int result = 1;
    size_t index = 0;
    
    //@ assert (0 <= (index) <= (N)-1 &&         1 <= (button) <= (index)+1 &&         1 <= (result) <= (index)+1 &&         (2 <= ((N)) <= 100000 &&         \valid(((inputs)) + (0 .. ((N))-1)) &&         (\forall integer i; 0 <= i < ((N)) ==> 1 <= ((inputs))[i] <= ((N))) &&         (\forall integer i, j; 0 <= i < j < ((N)) ==> ((inputs))[i] != ((inputs))[j])));
    
    /*@
        loop invariant (0 <= (index) <= (N)-1 &&
        1 <= (button) <= (index)+1 &&
        1 <= (result) <= (index)+1 &&
        (2 <= ((N)) <= 100000 &&
        \valid(((inputs)) + (0 .. ((N))-1)) &&
        (\forall integer i; 0 <= i < ((N)) ==> 1 <= ((inputs))[i] <= ((N))) &&
        (\forall integer i, j; 0 <= i < j < ((N)) ==> ((inputs))[i] != ((inputs))[j])));
        loop invariant index <= N-1;
        loop assigns index, button, result;
        loop variant N - index;
    */
    while (index < N - 1) {
        //@ assert 0 <= index < N-1;
        
        if (inputs[index] == button) {
            button += 1;
        } else {
            result += 1;
        }
        index += 1;
        
        //@ assert (0 <= (index) <= (N)-1 &&         1 <= (button) <= (index)+1 &&         1 <= (result) <= (index)+1 &&         (2 <= ((N)) <= 100000 &&         \valid(((inputs)) + (0 .. ((N))-1)) &&         (\forall integer i; 0 <= i < ((N)) ==> 1 <= ((inputs))[i] <= ((N))) &&         (\forall integer i, j; 0 <= i < j < ((N)) ==> ((inputs))[i] != ((inputs))[j])));
    }
    
    //@ assert index == N-1;
    //@ assert 1 <= result <= N;
    return result;
}
