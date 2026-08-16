#include <stdbool.h>

/*@ requires \valid(input + (0 .. 5));
    requires (\forall integer i; 0 <= i < (6) ==> 0 <= (input)[i] && (input)[i] <= 1000000000);
    requires ((6) == 6 && (input)[0] + (input)[1] + (input)[2] <= 1000000000);
    ensures \result == (input[0] + input[1] + input[2] == input[5]);
*/
bool func(int *input) {
    int sum;
    int i;

    sum = input[0] + input[1] + input[2];
    i = 3;

    /*@ loop invariant 3 <= i <= 5;
        loop invariant sum == input[0] + input[1] + input[2];
        loop invariant (\forall integer i; 0 <= i < (6) ==> 0 <= (input)[i] && (input)[i] <= 1000000000);
        loop invariant sum <= 1000000000;
        loop invariant ((6) == 6 && (input)[0] + (input)[1] + (input)[2] <= 1000000000);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert (\forall integer i; 0 <= i < (6) ==> 0 <= (input)[i] && (input)[i] <= 1000000000);
        i += 1;
    }

    //@ assert sum == input[0] + input[1] + input[2];
    return sum == input[5];
}
