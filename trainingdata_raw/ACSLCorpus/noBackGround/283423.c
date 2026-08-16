#include <stdbool.h>

/*@ requires \valid(numbers + (0..2));
    requires (\valid((numbers)) && (numbers)[0] >= 1 && (numbers)[0] <= 100 &&
    (numbers)[1] >= 1 && (numbers)[1] <= 100 &&
    (numbers)[2] >= 1 && (numbers)[2] <= 100);
    ensures ((\result) == (numbers)[0] - (numbers)[1] || (\result) == (numbers)[1] - (numbers)[0] ||
    (\result) == (numbers)[0] - (numbers)[2] || (\result) == (numbers)[2] - (numbers)[0] ||
    (\result) == (numbers)[1] - (numbers)[2] || (\result) == (numbers)[2] - (numbers)[1]);
*/
int func(int* numbers) {
    int min_num;
    int max_num;
    int i;
    
    min_num = numbers[0];
    max_num = numbers[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= 3;
        loop invariant min_num <= max_num;
        loop invariant \exists integer j; 0 <= j < i && min_num == numbers[j];
        loop invariant \exists integer j; 0 <= j < i && max_num == numbers[j];
        loop invariant \forall integer k; 0 <= k < i ==> min_num <= numbers[k] && max_num >= numbers[k];
        loop invariant (\valid((numbers)) && (numbers)[0] >= 1 && (numbers)[0] <= 100 &&
    (numbers)[1] >= 1 && (numbers)[1] <= 100 &&
    (numbers)[2] >= 1 && (numbers)[2] <= 100);
        loop assigns min_num, max_num, i;
    */
    while (i < 3) {
        int num;
        num = numbers[i];
        
        //@ assert num >= 1 && num <= 100;
        
        if (num < min_num) {
            min_num = num;
        }
        
        if (num > max_num) {
            max_num = num;
        }
        
        i += 1;
    }
    
    //@ assert min_num >= 1 && max_num <= 100;
    //@ assert max_num - min_num >= -99 && max_num - min_num <= 99;
    
    return max_num - min_num;
}
