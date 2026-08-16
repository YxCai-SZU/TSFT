#include <stdbool.h>

/*@ requires (1 <= (numbers[0]) && (numbers[0]) <= 100 &&
      1 <= (numbers[1]) && (numbers[1]) <= 100 &&
      1 <= (numbers[2]) && (numbers[2]) <= 100);
    ensures \result >= 0 && \result <= numbers[0] + numbers[1] + numbers[2];
*/
int func(int numbers[3])
{
    int tmp;
    int a = numbers[0];
    int b = numbers[1];
    int c = numbers[2];
    
    //@ assert (1 <= (a) && (a) <= 100 &&       1 <= (b) && (b) <= 100 &&       1 <= (c) && (c) <= 100);
    
    if (a < b) {
        if (b < c) {
            tmp = a;
        } else {
            if (a < c) {
                tmp = a;
            } else {
                tmp = c;
            }
        }
    } else {
        if (a < c) {
            tmp = a;
        } else {
            if (b < c) {
                tmp = b;
            } else {
                tmp = c;
            }
        }
    }
    
    //@ assert 1 <= tmp && tmp <= 100;
    //@ assert 3 <= a + b + c && a + b + c <= 300;
    //@ assert tmp <= a + b + c;
    //@ assert a + b + c - tmp >= 0;
    
    return a + b + c - tmp;
}
