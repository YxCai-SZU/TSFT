#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires ((len) >= 3 &&
      \forall integer i; 0 <= i < (len) ==> (1 <= ((arr)[i]) && ((arr)[i]) <= 1000000000));
  assigns \nothing;
  ensures \result == true <==> (((arr[0]) < (arr[1]) && (arr[1]) < (arr[2])) || ((arr[0]) > (arr[1]) && (arr[1]) > (arr[2])));
*/
bool func(const int *arr, size_t len) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert ((len) >= 3 &&       \forall integer i; 0 <= i < (len) ==> (1 <= ((arr)[i]) && ((arr)[i]) <= 1000000000));
    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert (1 <= (a) && (a) <= 1000000000);
    //@ assert (1 <= (b) && (b) <= 1000000000);
    //@ assert (1 <= (c) && (c) <= 1000000000);
    
    result = (a < b && b < c) || (a > b && b > c);

    //@ assert result == true <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
    return result;
}
