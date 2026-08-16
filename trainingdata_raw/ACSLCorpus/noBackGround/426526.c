#include <stdbool.h>

/*@ requires \valid_read(numbers + (0 .. 2));
    requires ((len) >= 3 &&
    \forall integer i; 0 <= i < 3 ==> (1 <= ((numbers)[i]) <= 13));
    ensures \result == (numbers[2] == numbers[0] + numbers[1] ||
                       numbers[1] == numbers[0] + numbers[2] ||
                       numbers[0] == numbers[1] + numbers[2]);
*/
bool func(int *numbers, int len) {
    bool result = false;
    int a;
    int b;
    int c;
    
    //@ assert ((len) >= 3 &&     \forall integer i; 0 <= i < 3 ==> (1 <= ((numbers)[i]) <= 13));
    //@ assert (0 <= (0) < (len));
    a = numbers[0];
    //@ assert (0 <= (1) < (len));
    b = numbers[1];
    //@ assert (0 <= (2) < (len));
    c = numbers[2];
    
    if (a + b == c || a + c == b || b + c == a) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
