#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires ((len) >= 3 &&
    \forall size_t i; 0 <= i < (len) ==> (arr)[i] > 0);
  assigns \nothing;
  ensures \result == \true <==> ((arr[0]) < (arr[1]) && (arr[1]) < (arr[2]));
*/
bool func(unsigned int *arr, size_t len) {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    bool result;

    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert a == arr[0];
    //@ assert b == arr[1];
    //@ assert c == arr[2];

    result = (a < b) && (b < c);
    return result;
}
