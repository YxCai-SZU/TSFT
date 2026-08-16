#include <stdbool.h>

/*@
    requires \valid_read(numbers + (0 .. 2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> (1 <= ((numbers)[i]) <= 100));
    ensures \result >= 0;
    ensures \result <= 198;
    assigns \nothing;
*/
int func(int *numbers) {
    int max_val;
    int min_val;
    int i;
    
    max_val = numbers[0];
    min_val = numbers[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> (1 <= ((numbers)[i]) <= 100));
        loop invariant \forall integer k; 0 <= k < i ==> max_val >= numbers[k];
        loop invariant \forall integer k; 0 <= k < i ==> min_val <= numbers[k];
        loop invariant (1 <= (max_val) <= 100);
        loop invariant (1 <= (min_val) <= 100);
        loop assigns max_val, min_val, i;
        loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert ((3) == 3 &&         \forall integer i; 0 <= i < (3) ==> (1 <= ((numbers)[i]) <= 100));
        
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
        
        //@ assert (1 <= (max_val) <= 100);
        
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
        
        //@ assert (1 <= (min_val) <= 100);
        
        i += 1;
    }
    
    //@ assert max_val - min_val >= 0;
    //@ assert max_val - min_val <= 198;
    
    return max_val - min_val;
}

int main() {
    return 0;
}
