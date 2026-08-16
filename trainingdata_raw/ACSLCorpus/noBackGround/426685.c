#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(input + (0 .. 2));
    requires ((len) >= 3 &&
        1 <= (input)[0] && (input)[0] <= 100 &&
        1 <= (input)[1] && (input)[1] <= 100 &&
        1 <= (input)[2] && (input)[2] <= 200);
    ensures ((\result) == ((input)[2] <= (((input))[0] + ((input))[1])));
    assigns \nothing;
*/
bool func(int *input, size_t len) {
    int x;
    int y;
    int z;
    bool result;

    //@ assert ((len) >= 3 &&         1 <= (input)[0] && (input)[0] <= 100 &&         1 <= (input)[1] && (input)[1] <= 100 &&         1 <= (input)[2] && (input)[2] <= 200);
    
    x = input[0];
    y = input[1];
    z = input[2];
    
    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    //@ assert 1 <= z && z <= 200;
    
    result = (z <= x + y);
    
    //@ assert ((result) == ((input)[2] <= (((input))[0] + ((input))[1])));
    return result;
}
