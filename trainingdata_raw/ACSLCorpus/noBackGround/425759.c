/*@
    requires 1 <= a <= 100;
    requires 0 <= b <= a;
    ensures \result == (a == b);
*/
int func(int a, int b) {
    //@ assert 1 <= a <= 100;
    //@ assert 0 <= b <= a;
    return a == b;
}

int main() {
    int v[3] = {2, 3, 2};
    //@ assert ((3) > 0 ==> (&v[0])[0] == (&v[0])[(3)-1]);
    return 0;
}
