#include <stdbool.h>

/*@
    predicate exactly_two_fives(integer a, integer b, integer c) =
        (a == 5 && b == 5 && c != 5) ||
        (a == 5 && b != 5 && c == 5) ||
        (a != 5 && b == 5 && c == 5);
    
    predicate at_least_two_fives(integer a, integer b, integer c) =
        (a == 5 && b == 5 && c == 5) ||
        exactly_two_fives(a, b, c);
*/

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == (a == 5 && b == 5 && c == 5 || a == 5 && b == 5 && c != 5 || a == 5 && b != 5 && c == 5 || a != 5 && b == 5 && c == 5);
*/
bool func(int a, int b, int c) {
    int five_count;
    five_count = 0;
    
    if (a == 5) {
        five_count = five_count + 1;
    }
    
    if (b == 5) {
        five_count = five_count + 1;
    }
    
    if (c == 5) {
        five_count = five_count + 1;
    }
    
    //@ assert five_count > 1 ==> at_least_two_fives(a, b, c);
    
    return five_count > 1;
}
