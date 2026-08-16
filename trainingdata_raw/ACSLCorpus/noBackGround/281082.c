/*@
requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
ensures \result == 1 <==> (((a) == (b) && (b) != (c)) ||
    ((a) != (b) && (b) == (c)) ||
    ((a) == (c) && (b) != (c)));
assigns \nothing;
*/
int func(int a, int b, int c) {
    int is_all_identical;
    int is_two_identical;
    
    is_all_identical = 0;
    is_two_identical = 0;
    
    if (a == b) {
        is_two_identical = 1;
    } else if (a == c) {
        is_two_identical = 1;
    } else if (b == c) {
        is_two_identical = 1;
    }
    
    if (a == b && b == c) {
        is_all_identical = 1;
    }
    
    if (is_all_identical) {
        //@ assert !(((a) == (b) && (b) != (c)) ||     ((a) != (b) && (b) == (c)) ||     ((a) == (c) && (b) != (c)));
        return 0;
    } else {
        //@ assert is_two_identical == 1 <==> (((a) == (b) && (b) != (c)) ||     ((a) != (b) && (b) == (c)) ||     ((a) == (c) && (b) != (c)));
        return is_two_identical;
    }
}
