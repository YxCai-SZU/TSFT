/*@
    requires (\forall integer i; 0 <= i < (len) ==> (v)[i] > 0);
    requires (\forall integer i; 0 <= i < (len) ==> (v)[i] < 10);
    ensures \result == 1 <==> (\forall integer i; 0 <= i < len ==> v[i] > 0 && v[i] < 10);
    assigns \nothing;
*/
int func(unsigned int *v, unsigned int len) {
    unsigned int i;
    i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> v[j] > 0 && v[j] < 10;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert v[i] > 0 && v[i] < 10;
        i = i + 1;
    }
    return 1;
}

int main() {
    return 0;
}
