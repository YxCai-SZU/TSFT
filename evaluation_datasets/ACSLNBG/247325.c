#include <stdbool.h>


bool func(int a, int b, int c) {
    int ab;
    int bc;
    int ac;
    int sum;
    
    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;
    
    if (a == b) {
        ab = 1;
    } else {
        ab = 0;
    }
    
    if (b == c) {
        bc = 1;
    } else {
        bc = 0;
    }
    
    if (a == c) {
        ac = 1;
    } else {
        ac = 0;
    }
    
    sum = ab + bc + ac;
    
    //@ assert sum == 1 ==> (((a) == (b) && (b) != (c)) || ((a) == (c) && (a) != (b)) || ((b) == (c) && (a) != (b)));
    
    return sum == 1;
}
