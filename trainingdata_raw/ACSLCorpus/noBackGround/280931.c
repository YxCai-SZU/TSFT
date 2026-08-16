#include <stdbool.h>
#include <stdint.h>

/*@ requires \valid(arr + (0 .. len-1));
    requires len >= 1;
    requires (\forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] <= 1000);
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) ==> 
        (arr)[i] % 2 == 0 || (arr)[i] % 6 == 0 || (arr)[i] % 10 == 0);
*/
bool func(int *arr, int len) {
    int index = 0;
    bool result = true;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant \forall integer x; 0 <= x < index ==> 
            arr[x] % 2 == 0 || arr[x] % 6 == 0 || arr[x] % 10 == 0;
        loop invariant (\forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] <= 1000);
        loop assigns index, result;
        loop variant len - index;
    */
    while (index < len) {
        int value = arr[index];
        unsigned int value_unsigned;
        
        if (value < 0) {
            value_unsigned = (unsigned int)(value + 2);
        } else {
            value_unsigned = (unsigned int)value;
        }
        
        //@ assert 1 <= value <= 1000;
        
        if (value_unsigned % 2 != 0 && value_unsigned % 6 != 0 && value_unsigned % 10 != 0) {
            result = false;
            //@ assert !(arr[index] % 2 == 0 || arr[index] % 6 == 0 || arr[index] % 10 == 0);
            return result;
        }
        
        //@ assert arr[index] % 2 == 0 || arr[index] % 6 == 0 || arr[index] % 10 == 0;
        index++;
    }
    
    result = true;
    //@ assert (\forall integer i; 0 <= i < (len) ==>          (arr)[i] % 2 == 0 || (arr)[i] % 6 == 0 || (arr)[i] % 10 == 0);
    return result;
}
