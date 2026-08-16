#include <stdbool.h>

/*@
    requires \valid_read(numbers + (0..2));
    requires 0 <= numbers[0] && numbers[0] < 10;
    requires 0 <= numbers[1] && numbers[1] < 10;
    requires 0 <= numbers[2] && numbers[2] < 10;
    assigns \nothing;
    ensures \result == (numbers[0] < numbers[1] && numbers[1] < numbers[2]);
 */
bool func(const unsigned int numbers[3])
{
    //@ assert numbers[0] < 10;
    //@ assert numbers[1] < 10;
    //@ assert numbers[2] < 10;
    
    if (numbers[0] < numbers[1] && numbers[1] < numbers[2]) {
        return true;
    } else {
        return false;
    }
}
