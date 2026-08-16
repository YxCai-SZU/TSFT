#include <stdbool.h>

/*@ requires \valid_read(numbers + (0 .. len-1));
    requires ((len) > 0 &&
        \forall integer i; 0 <= i < (len) ==> (1 <= ((numbers)[i]) <= 100));
    ensures \result >= 0 && \result <= 100;
    ensures \exists integer max_idx, min_idx; 
            0 <= max_idx < len && 0 <= min_idx < len && 
            numbers[max_idx] - numbers[min_idx] == \result;
*/
int func(int *numbers, int len) {
    int max_value;
    int min_value;
    int i;
    
    max_value = numbers[0];
    min_value = numbers[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant ((len) > 0 &&
        \forall integer i; 0 <= i < (len) ==> (1 <= ((numbers)[i]) <= 100));
        loop invariant \forall integer k; 0 <= k < i ==> max_value >= numbers[k];
        loop invariant \forall integer k; 0 <= k < i ==> min_value <= numbers[k];
        loop invariant (\exists integer idx; (0) <= idx < (i) && (numbers)[idx] == (max_value));
        loop invariant (\exists integer idx; (0) <= idx < (i) && (numbers)[idx] == (min_value));
        loop assigns i, max_value, min_value;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (0 <= (i) < (len));
        
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
        
        if (numbers[i] < min_value) {
            min_value = numbers[i];
        }
        
        i = i + 1;
    }
    
    //@ assert (\exists integer idx; (0) <= idx < (len) && (numbers)[idx] == (max_value));
    //@ assert (\exists integer idx; (0) <= idx < (len) && (numbers)[idx] == (min_value));
    
    return max_value - min_value;
}

int main() {
    return 0;
}
