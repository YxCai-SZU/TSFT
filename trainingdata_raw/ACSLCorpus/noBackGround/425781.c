#include <stdbool.h>

/*@
    requires (\valid((input) + (0..2)) &&
        1 <= (input)[0] <= 100 &&
        1 <= (input)[1] <= 100 &&
        1 <= (input)[2] <= 100);
    ensures \result <==> ((((input[1])) - ((input[0]))) == (((input[2])) - ((input[1]))));
*/
bool func(int *input)
{
    int a;
    int b;
    int c;
    int diff1_val;
    int diff2_val;
    bool in_arithmetic_progression;

    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert a == input[0] && b == input[1] && c == input[2];
    
    diff1_val = b - a;
    diff2_val = c - b;

    //@ assert diff1_val == ((b) - (a));
    //@ assert diff2_val == ((c) - (b));
    
    in_arithmetic_progression = (diff1_val == diff2_val);

    //@ assert in_arithmetic_progression <==> ((((b)) - ((a))) == (((c)) - ((b))));
    
    return in_arithmetic_progression;
}
