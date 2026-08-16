#include <stdbool.h>
#include <stddef.h>

int main() {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int data1[10];
    int data2[10];
    size_t size = 10;
    int i;
    
    // Initialize arrays to make them comparable
    /*@ loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> data1[j] == data2[j];
        loop assigns i, data1[0..9], data2[0..9];
    */
    for (i = 0; i < 10; i++) {
        data1[i] = 0;
        data2[i] = 0;
    }
    
    //@ assert x1 == x2;
    //@ assert y1 == y2;
    //@ assert (\forall integer i; 0 <= i < (size) ==> \at((&data1[0])[i],Here) == \at((&data2[0])[i],Here));
    //@ assert ((x1) == (x2) &&         (y1) == (y2) &&         (\forall integer i; 0 <= i < ((size)) ==> \at(((&data1[0]))[i],Here) == \at(((&data2[0]))[i],Here)));
    
    return 0;
}
