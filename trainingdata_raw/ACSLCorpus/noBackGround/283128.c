/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
unsigned long func(unsigned long a, unsigned long b) {
    // Variable declarations at scope top
    unsigned long answer;
    
    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    
    //@ assert a * b <= 100 * 100;
    
    answer = a * b;
    
    //@ assert answer <= 10000;
    
    return answer;
}
