#include <stdbool.h>

/*@
    requires \valid(inputs + (0..2));
    requires inputs[0] >= 1 && inputs[0] <= 100;
    requires inputs[1] >= 1 && inputs[1] <= 100;
    requires inputs[2] >= 1 && inputs[2] <= 100;
    ensures \result == true <==> 
            (inputs[0] < inputs[1] && inputs[1] < inputs[2]) ||
            (inputs[0] > inputs[1] && inputs[1] > inputs[2]);
*/
bool is_valid_input(int inputs[3]) {
    int a;
    int b;
    int c;
    bool result;

    a = inputs[0];
    b = inputs[1];
    c = inputs[2];

    //@ assert ((a) >= 1 && (a) <= 100 && (b) >= 1 && (b) <= 100 && (c) >= 1 && (c) <= 100);

    if ((a < b && b < c) || (a > b && b > c)) {
        //@ assert (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        result = true;
    } else {
        //@ assert !(((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        result = false;
    }

    //@ assert result == true <==> ((a < b && b < c) || (a > b && b > c));
    return result;
}
