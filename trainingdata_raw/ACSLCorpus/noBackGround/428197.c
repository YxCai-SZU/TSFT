#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures ((\result) == 1 || (\result) == 5 || (\result) == 3 || (\result) == 2) || (\result >= 1 && \result <= 3);
    ensures \result == 6 - a - b || ((\result) == 1 || (\result) == 5 || (\result) == 3 || (\result) == 2);
    assigns \nothing;
 */
int func(int a, int b) {
    int result;
    int vec[4];
    int index;
    int i;
    
    result = 6 - a - b;
    
    //@ assert result == 6 - a - b;
    
    if (result == 1 || result == 5 || result == 3 || result == 2) {
        //@ assert ((result) == 1 || (result) == 5 || (result) == 3 || (result) == 2);
        return result;
    } else {
        vec[0] = 1;
        vec[1] = 5;
        vec[2] = 3;
        vec[3] = 2;
        
        index = 0;
        
        /*@ loop invariant 0 <= index <= 4;
            loop invariant \forall integer k; 0 <= k < 4 ==> ((vec[k]) == 1 || (vec[k]) == 5 || (vec[k]) == 3 || (vec[k]) == 2);
            loop invariant (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
            loop assigns index;
            loop variant 4 - index;
         */
        while (index < 4) {
            //@ assert index < 4;
            if (vec[index] == result) {
                //@ assert ((vec[index]) == 1 || (vec[index]) == 5 || (vec[index]) == 3 || (vec[index]) == 2);
                return vec[index];
            }
            index = index + 1;
        }
        
        //@ assert false;
        return 0;
    }
}

int main() {
    return 0;
}
