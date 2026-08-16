#include <stdbool.h>

/*@ requires \valid_read(numbers + (0 .. 2));
    requires ((len) >= 3 &&
    \forall integer i; 0 <= i < 3 ==> ((numbers)[i] >= 1 && (numbers)[i] <= 13));
    ensures \result == 1 <==> ((numbers[2]) >= (numbers[0]) + (numbers[1]) && (numbers[1]) >= 1 && (numbers[0]) >= 1);
*/
bool func(int* numbers, int len) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert numbers[0] >= 1 && numbers[0] <= 13;
    a = numbers[0];
    //@ assert numbers[1] >= 1 && numbers[1] <= 13;
    b = numbers[1];
    //@ assert numbers[2] >= 1 && numbers[2] <= 13;
    c = numbers[2];
    
    //@ assert a + b <= 26;
    result = (c >= a + b && b >= 1 && a >= 1);
    return result;
}
