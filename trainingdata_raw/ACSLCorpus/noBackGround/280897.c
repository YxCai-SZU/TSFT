#include <stdbool.h>

/*@
    requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    requires -100 <= D <= 100;
    ensures \result == true <==> (((A) <= (C) && (D) <= (B)) || ((A) <= (D) && (C) <= (B)));
 */
bool func(int A, int B, int C, int D)
{
    bool is_possible = false;
    int a = A;
    int b = B;
    int c = C;
    int d = D;

    //@ assert -100 <= A <= 100;
    //@ assert -100 <= B <= 100;
    //@ assert -100 <= C <= 100;
    //@ assert -100 <= D <= 100;

    if (a <= c && d <= b) {
        is_possible = true;
    } else if (a <= d && c <= b) {
        is_possible = true;
    }

    //@ assert is_possible == true <==> (((A) <= (C) && (D) <= (B)) || ((A) <= (D) && (C) <= (B)));
    return is_possible;
}
