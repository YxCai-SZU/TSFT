#include <stdbool.h>

/*@
    predicate valid_range(integer x) = -100 <= x && x <= 100;
    
    logic integer subtract(integer a, integer b) = a - b;
*/

/*@
    requires \valid(numbers + (0..1));
    requires valid_range(numbers[0]);
    requires valid_range(numbers[1]);
    ensures \result == subtract(numbers[0], numbers[1]);
    assigns \nothing;
*/
int func(int numbers[2]) {
    int result;
    
    //@ assert valid_range(numbers[0]);
    //@ assert valid_range(numbers[1]);
    
    result = numbers[0] - numbers[1];
    
    //@ assert result == subtract(numbers[0], numbers[1]);
    return result;
}

int main() {
    return 0;
}
