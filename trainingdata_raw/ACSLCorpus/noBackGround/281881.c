/*@
    requires \valid(a);
    requires *a == 1;
    ensures *a * *a == *a;
*/
void verify_multiplication_idempotency(int* a) {
    //@ assert ((*a) == 1);
}
