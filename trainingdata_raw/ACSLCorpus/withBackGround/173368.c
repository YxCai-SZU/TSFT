/*@
    logic integer hypotenuse_square(integer n, integer m) = n * n + m * m;

    lemma hypotenuse_square_non_negative:
        \forall integer n, m; n >= 0 && m >= 0 ==> hypotenuse_square(n, m) >= 0;

    lemma hypotenuse_square_inequality:
        \forall integer n, m; n >= 0 && m >= 0 ==> 
            hypotenuse_square(n, m) >= n * n;
*/

/*@
    requires n >= 0 && m >= 0;
    ensures \result == hypotenuse_square(n, m);
    assigns \nothing;
*/
int compute_hypotenuse_square(int n, int m) {
    return n * n + m * m;
}

/*@
    assigns \nothing;
*/
int main() {
    int x = 3;
    int y = 4;
    int result;
    
    result = compute_hypotenuse_square(x, y);
    
    //@ assert result >= 0;
    //@ assert result >= x * x;
    
    return 0;
}
