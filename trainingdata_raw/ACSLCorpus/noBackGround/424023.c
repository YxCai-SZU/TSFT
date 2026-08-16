#include <stdbool.h>

/*@
  requires \valid_read(arr + (0 .. 2));
  requires ((3) == 3 &&
      \forall integer i; 0 <= i < (3) ==> (1 <= ((arr)[i]) && ((arr)[i]) <= 100));
  ensures \result == (arr[0] < arr[1] && arr[1] < arr[2]);
*/
bool func(int *arr) {
    bool answer = true;
    int first;
    int second;
    int third;

    first = arr[0];
    second = arr[1];
    third = arr[2];

    //@ assert (1 <= (first) && (first) <= 100);
    //@ assert (1 <= (second) && (second) <= 100);
    //@ assert (1 <= (third) && (third) <= 100);

    if (first >= second || second >= third) {
        answer = false;
    }

    //@ assert answer == (first < second && second < third);
    return answer;
}
