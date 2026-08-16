/*@
    requires \true;
    ensures \true;
    assigns \nothing;
*/
int main() {
    int a, b, c, res;

    //@ assert ((a) < (b) && (a) < (c) ? (a) :         (b) < (c) ? (b) :         (c)) <= a;
    //@ assert ((a) < (b) && (a) < (c) ? (a) :         (b) < (c) ? (b) :         (c)) <= b;
    //@ assert ((a) < (b) && (a) < (c) ? (a) :         (b) < (c) ? (b) :         (c)) <= c;

    if (a < b && a < c) {
        res = a;
        //@ assert res <= b;
        //@ assert res <= c;
    } else if (b < c) {
        res = b;
        //@ assert res <= c;
    } else {
        res = c;
    }

    //@ assert ((res) <= (a) && (res) <= (b) && (res) <= (c) &&         ((res) == (a) || (res) == (b) || (res) == (c)));
    return 0;
}
