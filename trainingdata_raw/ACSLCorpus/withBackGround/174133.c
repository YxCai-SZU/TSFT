/*@
    logic integer gcd(integer a, integer b) =
        (b <= 1 || a <= 1) ? 1 :
        (a == b) ? a :
        (a > b) ? gcd(a - b, b) :
        gcd(a, b - a);
*/

/*@
    lemma gcd_15_10:
        gcd(15, 10) == 5;
*/

/*@
    lemma gcd_24_18:
        gcd(24, 18) == 6;
*/

/*@
    lemma gcd_30_20:
        gcd(30, 20) == 10;
*/

int main() {
    return 0;
}
