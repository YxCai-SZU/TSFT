#include <stdbool.h>


bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    bool answer = true;

    //@ assert a <= b && b <= c && c <= d && d <= e;
    //@ assert e <= 123 && k <= 123;

    if (b - a > k) {
        answer = false;
    } else if (c - b > k) {
        answer = false;
    } else if (d - c > k) {
        answer = false;
    } else if (e - d > k) {
        answer = false;
    }

    //@ assert answer == true <==> ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e) &&         ((b) - (a) <= (k)) && ((c) - (b) <= (k)) && ((d) - (c) <= (k)) && ((e) - (d) <= (k)));
    return answer;
}
