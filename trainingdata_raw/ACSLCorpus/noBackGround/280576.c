/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    requires a != b;
    ensures \result == 6 - a - b;
    ensures \result >= 1;
    ensures \result <= 3;
    ensures \result != a;
    ensures \result != b;
*/
long func(long a, long b) {
    long answer;
    //@ assert (1 <= (a) && (a) <= 3);
    //@ assert (1 <= (b) && (b) <= 3);
    //@ assert ((a) != (b));
    answer = 6 - a - b;
    //@ assert answer == (6 - (a) - (b));
    //@ assert answer >= 1;
    //@ assert answer <= 3;
    //@ assert answer != a;
    //@ assert answer != b;
    return answer;
}
