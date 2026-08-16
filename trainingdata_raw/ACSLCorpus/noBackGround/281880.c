#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    int32_t a_;
    int32_t a2;
    int32_t a3;
    int32_t ans;
    
    a_ = (int32_t)a;
    
    //@ assert (1 <= (a_) && (a_) <= 10);
    
    //@ assert 1 <= a_ * a_ && a_ * a_ <= 100;
    a2 = a_ * a_;
    
    //@ assert 1 <= a_ * a_ * a_ && a_ * a_ * a_ <= 1000;
    a3 = a_ * a_ * a_;
    
    //@ assert 1 <= a_ + a2 && a_ + a2 <= 110;
    
    //@ assert 1 <= a_ + a2 + a3 && a_ + a2 + a3 <= 1110;
    ans = a_ + a2 + a3;
    
    //@ assert ans == ((a_) + (a_) * (a_) + (a_) * (a_) * (a_));
    return ans;
}

int main()
{
    return 0;
}
