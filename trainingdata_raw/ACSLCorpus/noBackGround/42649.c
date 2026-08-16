#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) >= 2 &&
        \forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] <= 100);
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) ==> 
            (arr)[i] % 2 == 0 || (arr)[i] % 3 == 0 || (arr)[i] % 5 == 0);
    assigns \nothing;
*/
bool func(int* arr, size_t len) {
    size_t index = 0;
    bool result = true;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant ((len) >= 2 &&
        \forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] <= 100);
        loop invariant index > 0 ==> 
            \forall integer i; 0 <= i < index ==> 
                arr[i] % 2 == 0 || arr[i] % 3 == 0 || arr[i] % 5 == 0;
        loop invariant result == true <==> 
            \forall integer i; 0 <= i < index ==> 
                arr[i] % 2 == 0 || arr[i] % 3 == 0 || arr[i] % 5 == 0;
        loop assigns index, result;
        loop variant len - index;
    */
    while (index < len) {
        int value = arr[index];
        bool is_divisible = false;
        int temp_value;
        
        // Check divisibility by 2
        temp_value = value;
        /*@
            loop invariant temp_value >= 0;
            loop invariant temp_value <= value;
            loop invariant temp_value % 2 == value % 2;
            loop assigns temp_value;
            loop variant temp_value;
        */
        while (temp_value >= 2) {
            temp_value -= 2;
        }
        //@ assert temp_value == value % 2;
        if (temp_value == 0) {
            is_divisible = true;
        }
        
        // Check divisibility by 3
        temp_value = value;
        /*@
            loop invariant temp_value >= 0;
            loop invariant temp_value <= value;
            loop invariant temp_value % 3 == value % 3;
            loop assigns temp_value;
            loop variant temp_value;
        */
        while (temp_value >= 3) {
            temp_value -= 3;
        }
        //@ assert temp_value == value % 3;
        if (temp_value == 0) {
            is_divisible = true;
        }
        
        // Check divisibility by 5
        temp_value = value;
        /*@
            loop invariant temp_value >= 0;
            loop invariant temp_value <= value;
            loop invariant temp_value % 5 == value % 5;
            loop assigns temp_value;
            loop variant temp_value;
        */
        while (temp_value >= 5) {
            temp_value -= 5;
        }
        //@ assert temp_value == value % 5;
        if (temp_value == 0) {
            is_divisible = true;
        }
        
        if (!is_divisible) {
            result = false;
            break;
        }
        
        index++;
    }
    
    return result;
}
