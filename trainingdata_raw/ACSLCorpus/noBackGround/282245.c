/*@
    requires \true;
    ensures \result == 4;
*/
int main() {
    int a;
    int b;
    int c;
    int d;
    int result;

    a = 1;
    b = 2;
    c = 3;
    d = 4;

    //@ assert ((a) > (b) ?             ((b) > (c) ?                 ((c) > (d) ? (a) : (b))                 :                 ((a) > (d) ? (a) : (d)))             :             ((a) > (d) ? (b) : ((b) > (d) ? (b) : (d)))) == 4;
    result = 4;

    return result;
}
