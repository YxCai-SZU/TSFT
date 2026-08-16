#include <stdbool.h>

/*@ requires \valid(numbers + (0..1));
    requires numbers[0] >= 1 && numbers[0] <= 20;
    requires numbers[1] >= 1 && numbers[1] <= 20;
    assigns \nothing;
    ensures (numbers[0] < 10 && numbers[1] < 10) ==> \result == numbers[0] * numbers[1];
    ensures (numbers[0] >= 10 || numbers[1] >= 10) ==> \result == -1;
*/
int func(int numbers[2]) {
    int result = 0;
    
    if (numbers[0] >= 10 || numbers[1] >= 10) {
        //@ assert ((1 <= (numbers[0]) && (numbers[0]) <= 20) && (1 <= (numbers[1]) && (numbers[1]) <= 20) && ((numbers[0]) >= 10 || (numbers[1]) >= 10));
        return -1;
    }
    
    //@ assert 1 <= numbers[0] && numbers[0] <= 10;
    //@ assert 1 <= numbers[1] && numbers[1] <= 10;
    //@ assert numbers[0] * numbers[1] <= 100;
    //@ assert ((1 <= (numbers[0]) && (numbers[0]) <= 20) && (1 <= (numbers[1]) && (numbers[1]) <= 20) && ((numbers[0]) < 10 && (numbers[1]) < 10));
    
    return numbers[0] * numbers[1];
}
