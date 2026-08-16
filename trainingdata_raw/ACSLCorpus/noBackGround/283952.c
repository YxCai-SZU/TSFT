#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 2 &&
        \valid((numbers) + (0 .. (len)-1)) &&
        2 <= (numbers)[0] <= 20 &&
        2 <= (numbers)[1] <= 20);
    assigns \nothing;
    ensures \result >= 0;
    ensures (numbers[0] == 1 || numbers[1] == 1) ==> \result == 0;
    ensures (numbers[0] != 1 && numbers[1] != 1) ==> \result == numbers[0] - 2 + numbers[1] - 2;
*/
int func(int *numbers, size_t len) {
    int result = 0;
    
    //@ assert len >= 2;
    //@ assert 2 <= numbers[0] <= 20;
    //@ assert 2 <= numbers[1] <= 20;
    
    if (numbers[0] != 1 && numbers[1] != 1) {
        result = numbers[0] - 2 + numbers[1] - 2;
    }
    
    //@ assert (numbers[0] != 1 && numbers[1] != 1) ==> result == numbers[0] - 2 + numbers[1] - 2;
    //@ assert !(numbers[0] != 1 && numbers[1] != 1) ==> result == 0;
    
    return result;
}
