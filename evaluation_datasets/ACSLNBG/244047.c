#include <stdbool.h>


bool func(int* arr, int len) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert len >= 3;
    a = arr[0];
    b = arr[1];
    c = arr[2];
    result = (a < b) && (b < c);
    
    //@ assert result == (arr[0] < arr[1] && arr[1] < arr[2]);
    return result;
}
