#include <stdbool.h>

/*@
    requires \valid(numbers + (0..2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> 1 <= (numbers)[i] <= 100);
    ensures \result == ((((numbers[0]) + (numbers[1]) == (numbers[2])) ? 1 : (((numbers[1]) + (numbers[2]) == (numbers[0])) ? 1 : (((numbers[2]) + (numbers[0]) == (numbers[1])) ? 1 : 0))) == 1);
*/
bool func(int *numbers) {
    int a = 0;
    int b = 0;
    int c = 0;
    int index = 0;

    /*@
        loop invariant 0 <= index <= 3;
        loop invariant index >= 1 ==> a == numbers[0];
        loop invariant index >= 2 ==> b == numbers[1];
        loop invariant index >= 3 ==> c == numbers[2];
        loop assigns a, b, c, index;
        loop variant 3 - index;
    */
    while (index < 3) {
        if (index == 0) {
            a = numbers[index];
        } else if (index == 1) {
            b = numbers[index];
        } else if (index == 2) {
            c = numbers[index];
        }
        index++;
    }

    //@ assert a <= 100 && b <= 100 && c <= 100;
    return (a + b == c) || (b + c == a) || (c + a == b);
}
