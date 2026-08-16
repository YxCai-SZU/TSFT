#include <stdbool.h>
#include <stddef.h>

/*@ requires (2 <= (len) <= 50);
    requires \forall integer i; (0 <= (i) < (len)) ==> (0 <= (numbers[i]) <= 100);
    ensures \result >= 0;
 */
int func(const int* numbers, size_t len) {
    int d[50];
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant \forall integer i; 0 <= i < index ==> d[i] == ((numbers[i]) * 2 + 1);
        loop invariant (2 <= (len) <= 50);
        loop invariant \forall integer i; (0 <= (i) < (len)) ==> (0 <= (numbers[i]) <= 100);
        loop assigns index, d[0..len-1];
        loop variant len - index;
    */
    while (index < len) {
        int x = numbers[index];
        d[index] = x * 2 + 1;
        index++;
    }
    
    int ret = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant ret >= 0;
        loop invariant ret <= (int)i;
        loop invariant (2 <= (len) <= 50);
        loop invariant \forall integer j; (0 <= (j) < (len)) ==> (0 <= (numbers[j]) <= 100);
        loop assigns i, ret;
        loop variant len - i;
    */
    while (i < len) {
        int a = d[i];
        int b = a - 1;
        int c = a + 1;
        
        //@ assert a == ((numbers[i]) * 2 + 1);
        
        if (b >= 0 && b <= 100) {
            ret = ret + 1;
        } else if (c >= 0 && c <= 100) {
            ret = ret + 1;
        }
        i++;
    }
    
    return ret;
}
