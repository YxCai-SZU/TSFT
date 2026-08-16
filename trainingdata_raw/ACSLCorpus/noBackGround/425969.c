#include <stdbool.h>

/*@
    requires 1 <= n <= 100000;
    ensures ((n) % 2 == 1) ==> \result == 1;
    ensures ((n) % 2 == 0) ==> \result == ((n) / 2);
*/
int func(int n)
{
    int result;
    int count;
    int temp_n;

    //@ assert 1 <= n <= 100000;

    if (n % 2 == 1) {
        //@ assert ((n) % 2 == 1);
        result = 1;
    } else {
        //@ assert ((n) % 2 == 0);
        count = 0;
        temp_n = n;

        /*@
            loop invariant 0 <= temp_n <= n;
            loop invariant 0 <= count <= (n - temp_n) / 2;
            loop invariant temp_n + 2 * count == n;
            loop invariant 1 <= n <= 100000;
            loop assigns temp_n, count;
            loop variant temp_n;
        */
        while (temp_n >= 2) {
            temp_n -= 2;
            count += 1;
        }
        result = count;
    }

    //@ assert ((n) % 2 == 1) ==> result == 1;
    //@ assert ((n) % 2 == 0) ==> result == n / 2;
    return result;
}
