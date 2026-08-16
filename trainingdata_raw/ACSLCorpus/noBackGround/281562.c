/*@
    requires \true;
    ensures \true;
*/
void example_max_min_usage(void) {
    //@ assert (((20) > (10)) ? (20) : (10)) >= 20;
    //@ assert (((100) > (200)) ? (100) : (200)) >= 100;
    //@ assert (((20) < (10)) ? (20) : (10)) <= 20;
    //@ assert (((100) < (200)) ? (100) : (200)) <= 200;
}

int main() {
    return 0;
}
