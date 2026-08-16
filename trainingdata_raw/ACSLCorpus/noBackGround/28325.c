#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len > 2;
    assigns \nothing;
    ensures ((\result) <==> 
      ((0 <= (0) && (0) < ((len))) && (0 <= (1) && (1) < ((len))) && (0 <= (2) && (2) < ((len))) && 
       (arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]));
*/
bool func(int* arr, size_t len) {
    bool result;
    
    //@ assert len > 2;
    //@ assert (0 <= (0) && (0) < (len));
    //@ assert (0 <= (1) && (1) < (len));
    //@ assert (0 <= (2) && (2) < (len));
    
    result = (arr[0] < arr[1] && arr[1] < arr[2]);
    return result;
}

int main() {
    return 0;
}
