/*@
    requires \true;
    ensures \result == 0;
*/
int main() {
    int result = 0;

    //@ assert ((((7) <= (5) ? (7) : (5))) <= (((8) <= (5) ? (8) : (5))));

    return result;
}
