#include <stdbool.h>

/*@ requires \valid(dices + (0..1));
    requires ((2) == 2 &&
    \forall integer j; 0 <= j < (2) ==> 1 <= (dices)[j] <= 100);
    assigns \nothing;
    ensures 0 <= \result <= 100;
*/
int count_possible_dices(int *dices) {
    int count = 0;
    int i = 1;
    
    /*@ loop invariant 1 <= i <= 101;
        loop invariant 0 <= count <= i - 1;
        loop invariant ((2) == 2 &&
    \forall integer j; 0 <= j < (2) ==> 1 <= (dices)[j] <= 100);
        loop assigns count, i;
    */
    while (i < 101) {
        int sum = i + dices[0];
        
        //@ assert 1 <= i <= 100;
        //@ assert 2 <= sum <= 200;
        
        if (sum == dices[1]) {
            count += 1;
        }
        
        i += 1;
    }
    
    //@ assert i == 101;
    //@ assert 0 <= count <= 100;
    return count;
}
