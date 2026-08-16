int main() {
    int a1[10], b1[10], c1[10];
    int a2[10], b2[10], c2[10];
    int i;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> a1[j] == a2[j];
        loop invariant \forall integer j; 0 <= j < i ==> b1[j] == b2[j];
        loop invariant \forall integer j; 0 <= j < i ==> c1[j] == c2[j];
        loop assigns i, a1[0..9], a2[0..9], b1[0..9], b2[0..9], c1[0..9], c2[0..9];
    */
    for (i = 0; i < 10; i++) {
        a1[i] = i;
        a2[i] = i;
        b1[i] = i * 2;
        b2[i] = i * 2;
        c1[i] = i * 3;
        c2[i] = i * 3;
    }
    
    //@ assert (\forall integer i; 0 <= i < (10) ==> (&a1[0])[i] == (&a2[0])[i] &&         \forall integer i; 0 <= i < (10) ==> (&b1[0])[i] == (&b2[0])[i] &&         \forall integer i; 0 <= i < (10) ==> (&c1[0])[i] == (&c2[0])[i]);
    
    /*@ assert \forall integer i; 0 <= i < 10 ==> a1[i] == a2[i]; */
    /*@ assert \forall integer j; 0 <= j < 10 ==> b1[j] == b2[j]; */
    /*@ assert \forall integer k; 0 <= k < 10 ==> c1[k] == c2[k]; */
    
    return 0;
}
