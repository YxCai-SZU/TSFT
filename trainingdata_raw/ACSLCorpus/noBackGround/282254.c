#include <stddef.h>
#include <stdbool.h>

/*@ requires n > 0;
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (0 <= ((numbers)[i]) <= 1000));
    ensures \result >= 0;
    ensures \exists integer max_idx, min_idx; 
            0 <= max_idx < n && 0 <= min_idx < n && 
            numbers[max_idx] - numbers[min_idx] == \result;
*/
int func(size_t n, int numbers[]) {
    int max_num;
    int min_num;
    size_t i;
    
    max_num = numbers[0];
    min_num = numbers[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= n;
        loop invariant \forall integer k; 0 <= k < i ==> max_num >= numbers[k];
        loop invariant \forall integer k; 0 <= k < i ==> min_num <= numbers[k];
        loop invariant \exists integer k; 0 <= k < i && max_num == numbers[k];
        loop invariant \exists integer k; 0 <= k < i && min_num == numbers[k];
        loop assigns max_num, min_num, i;
        loop variant n - i;
    */
    while (i < n) {
        int num = numbers[i];
        
        //@ assert (0 <= (num) <= 1000);
        
        if (num > max_num) {
            max_num = num;
        }
        
        if (num < min_num) {
            min_num = num;
        }
        
        i++;
    }
    
    //@ assert \exists integer max_idx; 0 <= max_idx < n && max_num == numbers[max_idx];
    //@ assert \exists integer min_idx; 0 <= min_idx < n && min_num == numbers[min_idx];
    //@ assert max_num - min_num >= 0;
    
    return max_num - min_num;
}

int main() {
    return 0;
}
