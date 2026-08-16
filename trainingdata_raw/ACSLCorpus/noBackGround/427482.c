#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. 2));
    requires ((3) == 3 &&
        (arr)[0] >= 1 && (arr)[0] <= 100 &&
        (arr)[1] >= 1 && (arr)[1] <= 100 &&
        (arr)[2] >= 1 && (arr)[2] <= 100);
    ensures \result <==> ((arr[1]) - (arr[0]) == (arr[2]) - (arr[1]));
*/
bool func(int *arr)
{
    int a;
    int b;
    int c;
    int diff1;
    int diff2;
    bool is_equal;

    a = arr[0];
    b = arr[1];
    c = arr[2];

    diff1 = b - a;
    diff2 = c - b;

    is_equal = (diff1 == diff2);

    //@ assert is_equal <==> (b - a == c - b);

    return is_equal;
}
