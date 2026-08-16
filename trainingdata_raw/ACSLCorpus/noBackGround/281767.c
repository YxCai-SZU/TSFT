#include <stdbool.h>

/*@ requires (3 <= (n) && (n) <= 100 &&
   1 <= (a) && (a) < (b) && (b) < 20 &&
   \valid((p) + (0 .. (n)-1)) &&
   \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
    ensures \result >= 0;
*/
int func(int n, int a, int b, int* p) {
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant count >= 0 && count1 >= 0 && count2 >= 0;
        loop invariant count <= index && count1 <= index && count2 <= index;
        loop assigns count, count1, count2, index;
        loop variant n - index;
    */
    while (index < n) {
        int pi = p[index];
        
        //@ assert 0 <= index < n;
        //@ assert 1 <= pi && pi <= 20;
        
        if (pi < a) {
            count += 1;
        } else if (pi < b) {
            count1 += 1;
        } else {
            count2 += 1;
        }
        
        index += 1;
    }
    
    int min_value;
    if (count < count1) {
        if (count < count2) {
            min_value = count;
        } else {
            min_value = count2;
        }
    } else if (count1 < count2) {
        min_value = count1;
    } else {
        min_value = count2;
    }
    
    //@ assert min_value >= 0;
    return min_value;
}
