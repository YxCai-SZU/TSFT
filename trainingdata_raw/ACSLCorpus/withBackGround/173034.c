#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_index(integer i) = 0 <= i < 5;
    logic integer expected_value(integer i) = i * 10;
*/

/*@
    requires \valid(numbers + (0..4));
    requires \forall integer i; 0 <= i < 5 ==> numbers[i] == i * 10;
    ensures \result == 1 || \result == 0;
*/
int func(unsigned int* numbers) {
    unsigned int v[5];
    int result;
    
    v[0] = 0;
    v[1] = 10;
    v[2] = 20;
    v[3] = 30;
    v[4] = 40;
    
    //@ assert \forall integer i; 0 <= i < 5 ==> v[i] == i * 10;
    
    //@ assert numbers[0] == 0;
    //@ assert numbers[1] == 10;
    //@ assert numbers[2] == 20;
    //@ assert numbers[3] == 30;
    //@ assert numbers[4] == 40;
    
    result = 1;
    //@ assert result == 1 || result == 0;
    return result;
}
