#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. 2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
    ensures \result == 1 <==> ((((arr))[(0)]) + (((arr))[(1)]) == (((arr))[(2)]) ||
        (((arr))[(1)]) + (((arr))[(2)]) == (((arr))[(0)]) ||
        (((arr))[(0)]) + (((arr))[(2)]) == (((arr))[(1)]));
*/
bool func(int *arr) {
    bool answer = false;
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];

    //@ assert a == ((arr)[(0)]);
    //@ assert b == ((arr)[(1)]);
    //@ assert c == ((arr)[(2)]);

    if (a + b == c) {
        answer = true;
    }
    //@ assert answer == (a + b == c);

    if (b + c == a) {
        answer = true;
    }
    //@ assert answer == (a + b == c || b + c == a);

    if (a + c == b) {
        answer = true;
    }
    //@ assert answer == (a + b == c || b + c == a || a + c == b);

    return answer;
}
