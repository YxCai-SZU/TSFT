#include <stdbool.h>

/*@
    predicate is_seven(integer digit) = digit == 7;

    logic integer manual_div_100(integer N) = N / 100;
    logic integer manual_mod_100(integer N) = N % 100;
    logic integer manual_div_10(integer N) = N / 10;
    logic integer manual_mod_10(integer N) = N % 10;

    lemma mod_100_range:
        \forall integer N; 100 <= N <= 999 ==> 0 <= manual_mod_100(N) < 100;

    lemma mod_10_range:
        \forall integer N; 0 <= N < 100 ==> 0 <= manual_mod_10(N) < 10;

    lemma div_100_correct:
        \forall integer N; 100 <= N <= 999 ==> 
            manual_div_100(N) == N / 100;

    lemma mod_100_correct:
        \forall integer N; 100 <= N <= 999 ==> 
            manual_mod_100(N) == N % 100;

    lemma div_10_correct:
        \forall integer N; 0 <= N < 100 ==> 
            manual_div_10(N) == N / 10;

    lemma mod_10_correct:
        \forall integer N; 0 <= N < 100 ==> 
            manual_mod_10(N) == N % 10;
*/

/*@
    requires 100 <= N <= 999;
    ensures \result == (N / 100 == 7 || (N / 10) % 10 == 7 || N % 10 == 7);
*/
bool func(int N) {
    int n;
    int hundreds;
    int tens;
    int ones;

    n = N;
    hundreds = 0;
    tens = 0;
    ones = 0;

    /*@
        loop invariant 100 <= N <= 999;
        loop invariant 0 <= hundreds <= N / 100;
        loop invariant n == N - hundreds * 100;
        loop invariant 0 <= n;
        loop assigns n, hundreds;
        loop variant n;
    */
    while (n >= 100) {
        //@ assert n >= 100;
        n -= 100;
        hundreds += 1;
        //@ assert n == N - hundreds * 100;
    }

    /*@
        loop invariant 100 <= N <= 999;
        loop invariant 0 <= hundreds <= N / 100;
        loop invariant 0 <= tens <= (N - hundreds * 100) / 10;
        loop invariant n == N - hundreds * 100 - tens * 10;
        loop invariant 0 <= n;
        loop assigns n, tens;
        loop variant n;
    */
    while (n >= 10) {
        //@ assert n >= 10;
        n -= 10;
        tens += 1;
        //@ assert n == N - hundreds * 100 - tens * 10;
    }

    ones = n;
    //@ assert ones == N - hundreds * 100 - tens * 10;

    return hundreds == 7 || tens == 7 || ones == 7;
}

int main() {
    return 0;
}
