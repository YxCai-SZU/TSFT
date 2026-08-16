#include <stdbool.h>

/*@
    requires (10 <= (N) && (N) <= 99);
    ensures \result == (N / 10 == 9 || N % 10 == 9);
*/
bool func(int N) {
    int n;
    int div;
    int temp_n;
    int mod_result;
    bool result;

    n = N;
    div = 0;
    temp_n = N;

    /*@
        loop invariant 10 <= N && N <= 99;
        loop invariant 0 <= temp_n && temp_n <= N;
        loop invariant temp_n == N - 10 * div;
        loop assigns temp_n, div;
    */
    while (temp_n >= 10) {
        //@ assert temp_n >= 10;
        temp_n -= 10;
        div += 1;
    }

    mod_result = N;
    /*@
        loop invariant 10 <= N && N <= 99;
        loop invariant 0 <= mod_result && mod_result <= N;
        loop invariant mod_result == N - 10 * ((N - mod_result) / 10);
        loop assigns mod_result;
    */
    while (mod_result >= 10) {
        //@ assert mod_result >= 10;
        mod_result -= 10;
    }

    result = (div == 9 || mod_result == 9);
    //@ assert result == (N / 10 == 9 || N % 10 == 9);
    return result;
}

int main() {
    return 0;
}
