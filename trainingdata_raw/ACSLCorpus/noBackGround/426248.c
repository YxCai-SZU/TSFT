/*@
    requires (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9) && (1 <= (c) && (c) <= 9);
    ensures \result == ((a == b && a != c) || (b == c && b != a) || (c == a && c != b));
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b, unsigned int c)
{
    int answer = 0;
    
    //@ assert (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9) && (1 <= (c) && (c) <= 9);
    
    if (a == b && a != c) {
        answer = 1;
    }
    
    if (b == c && b != a) {
        answer = 1;
    }
    
    if (c == a && c != b) {
        answer = 1;
    }
    
    //@ assert answer == ((a == b && a != c) || (b == c && b != a) || (c == a && c != b));
    
    return answer;
}
