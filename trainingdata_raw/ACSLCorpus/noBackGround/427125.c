#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> ((a) + (b) >= (c) && (a) + (c) >= (b) && (b) + (c) >= (a));
  assigns \nothing;
*/
bool func(int a, int b, int c) {
    int min = a;
    int mid = b;
    int max = c;
    int temp;

    //@ assert a + b + c == min + mid + max;

    if (min > mid) {
        temp = min;
        min = mid;
        mid = temp;
    }
    //@ assert min <= mid;

    if (mid > max) {
        temp = mid;
        mid = max;
        max = temp;
    }
    //@ assert mid <= max;

    if (min > mid) {
        temp = min;
        min = mid;
        mid = temp;
    }
    //@ assert ((min) <= (mid) && (mid) <= (max));

    //@ assert ((min) + (mid) >= (max) && (min) + (max) >= (mid) && (mid) + (max) >= (min)) <==> (min + mid >= max);
    return (min + mid >= max);
}
