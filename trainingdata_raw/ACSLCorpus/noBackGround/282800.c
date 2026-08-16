/*@
requires \true;
assigns \nothing;
ensures \true;
*/
int main() {
    //@ assert (10 < 0 ? -10 : 10) >= 0;
    //@ assert (-10 < 0 ? -(-10) : -10) >= 0;
    return 0;
}
