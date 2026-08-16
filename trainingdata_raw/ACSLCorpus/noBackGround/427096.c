#include <stdbool.h>

/*@
  requires \valid_read(arr + (0..2));
  requires ((3) == 3 &&
      \forall integer i; 0 <= i < (3) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
  ensures \result == 1 <==> ((arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]);
  assigns \nothing;
*/
bool is_increasing_func(int arr[3]) {
    int a;
    int b;
    int c;
    
    a = arr[0];
    b = arr[1];
    c = arr[2];
    
    //@ assert arr[0] == a;
    //@ assert arr[1] == b;
    //@ assert arr[2] == c;
    
    return a < b && b < c;
}
