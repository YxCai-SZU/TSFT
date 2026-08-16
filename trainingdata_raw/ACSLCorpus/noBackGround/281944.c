/*@
    requires \true;
    ensures \result == 1;
*/
int test_case1() {
    int result;
    //@ assert (((1) <= (2) && (1) <= (3)) ? (1) : (((2) <= (1) && (2) <= (3)) ? (2) : (3))) == 1;
    result = 1;
    return result;
}

/*@
    requires \true;
    ensures \result == 100;
*/
int test_case2() {
    int result;
    //@ assert (((100) <= (200) && (100) <= (300)) ? (100) : (((200) <= (100) && (200) <= (300)) ? (200) : (300))) == 100;
    result = 100;
    return result;
}

int main() {
    int r1;
    int r2;
    
    r1 = test_case1();
    r2 = test_case2();
    
    return 0;
}
