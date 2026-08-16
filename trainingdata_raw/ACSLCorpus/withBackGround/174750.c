/*@
    predicate bounds(integer a, integer b, integer c) =
        1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;

    logic integer compute_x1(integer b, integer c) = b * 10 + c;
    logic integer compute_x2(integer a, integer b) = a * 10 + b;
    logic integer compute_x3(integer c, integer a) = c * 10 + a;

    lemma x1_bounds: \forall integer b, c; bounds(1, b, c) ==> 10 <= compute_x1(b, c) <= 99;
    lemma x2_bounds: \forall integer a, b; bounds(a, b, 1) ==> 10 <= compute_x2(a, b) <= 99;
    lemma x3_bounds: \forall integer c, a; bounds(a, 1, c) ==> 10 <= compute_x3(c, a) <= 99;

    lemma mod_property: \forall integer x; 10 <= x <= 99 ==> 0 <= x % 4 <= 3;
*/

#include <stdbool.h>

/*@
    requires bounds(A, B, C);
    ensures \result == (compute_x1(B, C) % 4 < 1 || compute_x2(A, B) % 4 < 1 || compute_x3(C, A) % 4 < 1);
    assigns \nothing;
*/
bool func(int A, int B, int C)
{
    // Variable declarations at scope top
    long long x1;
    long long x2;
    long long x3;
    long long r1;
    long long r2;
    long long r3;
    bool result;

    //@ assert 1 <= A <= 9 && 1 <= B <= 9 && 1 <= C <= 9;

    //@ assert 1 <= B && B <= 9;
    //@ assert 1 <= C && C <= 9;
    //@ assert B * 10 <= 90;
    //@ assert B * 10 + C <= 99;
    x1 = (long long)(B * 10 + C);

    //@ assert 1 <= A && A <= 9;
    //@ assert 1 <= B && B <= 9;
    //@ assert A * 10 <= 90;
    //@ assert A * 10 + B <= 99;
    x2 = (long long)(A * 10 + B);

    //@ assert 1 <= C && C <= 9;
    //@ assert 1 <= A && A <= 9;
    //@ assert C * 10 <= 90;
    //@ assert C * 10 + A <= 99;
    x3 = (long long)(C * 10 + A);

    r1 = x1 % 4;
    r2 = x2 % 4;
    r3 = x3 % 4;

    //@ assert 0 <= r1 <= 3 && 0 <= r2 <= 3 && 0 <= r3 <= 3;
    result = (r1 < 1) || (r2 < 1) || (r3 < 1);
    return result;
}
