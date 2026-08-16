/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    // Variable declarations at top of scope
    unsigned int a_1;
    unsigned int a_2;
    unsigned int a_3;
    unsigned int sum;
    
    //@ assert 1 <= a && a <= 10;
    
    a_1 = a;
    a_2 = a * a;
    a_3 = a * a * a;
    
    //@ assert a_2 <= 100;
    //@ assert a_3 <= 1000;
    
    sum = a_1;
    
    if (a_2 <= 10000) {
        sum = sum + a_2;
    } else {
        sum = sum + 10000;
    }
    
    if (a_3 <= 10000) {
        sum = sum + a_3;
    } else {
        sum = sum + 10000;
    }
    
    //@ assert sum == a_1 + a_2 + a_3;
    return sum;
}
