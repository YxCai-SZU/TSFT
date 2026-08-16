#include <stdint.h>


int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t ans;

    //@ assert (1 <= (a) && (a) <= 9);
    //@ assert (1 <= (b) && (b) <= 9);
    //@ assert (1 <= (c) && (c) <= 9);

    if (a == b && b == c) {
        //@ assert (111 * (a) + 111 * (b) + 111 * (c)) <= 333 * 9;
        ans = 111 * a + 111 * b + 111 * c;
    } else if (a == b) {
        //@ assert (111 * (a) + 111 * (b) + 10 * (c) + 1) <= 333 * 9 + 10 * 9 + 1;
        ans = 111 * a + 111 * b + 10 * c + 1;
    } else if (b == c) {
        //@ assert (111 * (a) + 111 * (b) + 10 * (c) + 1) <= 333 * 9 + 10 * 9 + 1;
        ans = 111 * a + 111 * b + 10 * c + 1;
    } else if (a == c) {
        //@ assert (111 * (a) + 10 * (b) + 111 * (c) + 1) <= 333 * 9 + 10 * 9 + 1;
        ans = 111 * a + 10 * b + 111 * c + 1;
    } else {
        //@ assert (111 * (a) + 10 * (b) + 10 * (c)) <= 333 * 9;
        ans = 111 * a + 10 * b + 10 * c;
    }

    return ans;
}
