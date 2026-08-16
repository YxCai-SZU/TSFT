#include <stdbool.h>

/*@ requires \valid(input + (0..1));
    requires ((input[0]) >= 1 && (input[0]) <= 100 &&
    (input[1]) >= 1 && (input[1]) <= 100);
    assigns \nothing;
    ensures \result == ((input[1] * 2 + 1) >= input[0]);
*/
bool func(unsigned int input[2]) {
    unsigned int n;
    unsigned int k;
    bool result;

    n = input[0];
    k = input[1];

    //@ assert ((n) >= 1 && (n) <= 100 &&     (k) >= 1 && (k) <= 100);
    //@ assert ((k) * 2 + 1) == k * 2 + 1;

    result = (k * 2 + 1) >= n;
    
    //@ assert result == ((k * 2 + 1) >= n);
    return result;
}
