#include <stdbool.h>

/*@
    requires \valid_read(numbers + (0 .. 2));
    requires ((len) >= 3 &&
    1 <= (numbers)[0] <= 13 &&
    1 <= (numbers)[1] <= 13 &&
    1 <= (numbers)[2] <= 13);
    ensures \result == (numbers[2] < numbers[1] && numbers[1] < numbers[0]);
*/
bool func(int* numbers, int len) {
    // Variable declarations at top
    bool result;
    
    //@ assert len >= 3;
    //@ assert 1 <= numbers[0] && numbers[0] <= 13;
    //@ assert 1 <= numbers[1] && numbers[1] <= 13;
    //@ assert 1 <= numbers[2] && numbers[2] <= 13;
    
    if (numbers[2] < numbers[1] && numbers[1] < numbers[0]) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
