/*@
    requires \valid(v + (0..2));
    requires \forall integer i, j; 0 <= i < 3 && 0 <= j < 3 && i != j ==> v[i] != v[j];
    ensures \result == 1;
    assigns \nothing;
*/
int func(int v[3]) {
    //@ assert (\forall integer i, j; 0 <= i < (3) && 0 <= j < (3) && i != j ==> (v)[i] != (v)[j]);
    return 1;
}

int main() {
    return 0;
}
