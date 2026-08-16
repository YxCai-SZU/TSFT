/*@
    requires ((a) > 0);
    requires ((b) > 0);
    ensures ((\result) >= 0);
    ensures \result <= a;
    ensures \result <= b;
*/
int func(int a, int b) {
    int ans;
    //@ assert ((a) > 0);
    //@ assert ((b) > 0);
    if (a < b) {
        ans = a;
        //@ assert ((a) < (b));
    } else {
        ans = b;
        //@ assert ((a) >= (b));
    }
    //@ assert ((ans) >= 0);
    //@ assert ans <= a;
    //@ assert ans <= b;
    return ans;
}

int main() {
    return 0;
}
