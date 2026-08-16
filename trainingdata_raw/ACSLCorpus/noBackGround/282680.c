#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> (a + b == c || b + c == a || c + a == b);
*/
bool func(int a, int b, int c) {
    int smallest;
    int mid;
    int largest;
    int temp;

    smallest = a;
    mid = b;
    largest = c;

    //@ assert 1 <= smallest <= 100 && 1 <= mid <= 100 && 1 <= largest <= 100;

    if (smallest > mid) {
        temp = smallest;
        smallest = mid;
        mid = temp;
    }
    //@ assert smallest <= mid;

    if (mid > largest) {
        temp = mid;
        mid = largest;
        largest = temp;
    }
    //@ assert mid <= largest;

    if (smallest > mid) {
        temp = smallest;
        smallest = mid;
        mid = temp;
    }
    //@ assert ((smallest) <= (mid) && (mid) <= (largest));

    //@ assert smallest + mid <= 200;
    //@ assert smallest + largest <= 200;
    //@ assert mid + largest <= 200;
    //@ assert smallest + mid >= 2;
    //@ assert smallest + largest >= 2;
    //@ assert mid + largest >= 2;

    if (smallest + mid == largest || mid + largest == smallest || largest + smallest == mid) {
        return true;
    } else {
        return false;
    }
}
