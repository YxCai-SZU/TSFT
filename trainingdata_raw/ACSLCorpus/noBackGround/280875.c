#include <limits.h>

/*@
    requires (1 <= (x) <= 10000);
    ensures \result == (((((x)) / 1000) * 1000) + (((((x)) % 1000) / 100) * 100) + ((((((x)) % 1000) % 100) / 10) * 10) + (((((x)) % 1000) % 100) % 10));
    assigns \nothing;
*/
int func(int x) {
    int result = 0;
    int temp_x = x;
    int count = 0;

    // Handle the thousands
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant 0 <= temp_x;
        loop invariant 0 <= count <= x / 1000;
        loop invariant x == temp_x + 1000 * count;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 1000) {
        temp_x -= 1000;
        count += 1;
    }
    result += count * 1000;

    count = 0;
    // Handle the hundreds
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant 0 <= temp_x;
        loop invariant 0 <= count <= (x % 1000) / 100;
        loop invariant x == temp_x + 1000 * (x / 1000) + 100 * count;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 100) {
        temp_x -= 100;
        count += 1;
    }
    result += count * 100;

    count = 0;
    // Handle the tens
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant 0 <= temp_x;
        loop invariant 0 <= count <= (x % 100) / 10;
        loop invariant x == temp_x + 1000 * (x / 1000) + 100 * ((x % 1000) / 100) + 10 * count;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 10) {
        temp_x -= 10;
        count += 1;
    }
    result += count * 10;
    result += temp_x;

    //@ assert result == (((((x)) / 1000) * 1000) + (((((x)) % 1000) / 100) * 100) + ((((((x)) % 1000) % 100) / 10) * 10) + (((((x)) % 1000) % 100) % 10));
    return result;
}
