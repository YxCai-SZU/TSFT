// Generated C + ACSL

/*@
  axiomatic GCD_properties {
    logic integer gcd_logic(integer a, integer b);
    
    axiom gcd_equal:
      \forall integer a; a > 0 ==> gcd_logic(a, a) == a;
    
    axiom gcd_subtract_left:
      \forall integer a, b; 
        a > b > 0 ==> gcd_logic(a, b) == gcd_logic(a - b, b);
    
    axiom gcd_subtract_right:
      \forall integer a, b; 
        b > a > 0 ==> gcd_logic(a, b) == gcd_logic(a, b - a);
    
    axiom gcd_divides_both:
      \forall integer a, b;
        a > 0 && b > 0 ==>
        a % gcd_logic(a, b) == 0 && b % gcd_logic(a, b) == 0;
    
    axiom gcd_positive:
      \forall integer a, b;
        a > 0 && b > 0 ==> gcd_logic(a, b) > 0;
    
    axiom gcd_le_both:
      \forall integer a, b;
        a > 0 && b > 0 ==>
        gcd_logic(a, b) <= a && gcd_logic(a, b) <= b;
  }
*/

/*@
    requires a > 0;
    requires b > 0;
    decreases a + b;
    assigns \nothing;
    ensures \result > 0;
    ensures \result <= a;
    ensures \result <= b;
    ensures a % \result == 0;
    ensures b % \result == 0;
    ensures \result == gcd_logic(a, b);
*/
int gcd(int a, int b)
{
  /*@ assert a > 0 && b > 0; */
  
  if (a == b) {
    /*@ assert gcd_logic(a, a) == a; */
    return a;
  } else if (b > a) {
    /*@ assert b > a > 0; */
    /*@ assert (a + (b - a)) < (a + b); */
    /*@ assert gcd_logic(a, b) == gcd_logic(a, b - a); */
    return gcd(a, (b - a));
  } else {
    /*@ assert a > b > 0; */
    /*@ assert ((a - b) + b) < (a + b); */
    /*@ assert gcd_logic(a, b) == gcd_logic(a - b, b); */
    return gcd((a - b), b);
  }
}