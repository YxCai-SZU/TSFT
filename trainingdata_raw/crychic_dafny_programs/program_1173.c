// Generated C + ACSL

typedef struct {
  int whole;
  int fractional;
} Decimal;

/*@
  predicate IsValid(integer fractional) =
    0 <= fractional && fractional < 100;
*/

/*@
    requires IsValid(productPrice.fractional) && IsValid(discount.fractional);
    requires discount.whole <= productPrice.whole;
    requires productPrice.whole >= 0 && discount.whole >= 0;
    requires productPrice.fractional >= discount.fractional ==> 
        productPrice.whole - discount.whole >= 0;
    requires productPrice.fractional < discount.fractional ==> 
        productPrice.whole - discount.whole - 1 >= 0;
    assigns \nothing;
    ensures IsValid(\result.fractional);
    ensures \result.whole ==
        (productPrice.fractional >= discount.fractional ?
            productPrice.whole - discount.whole :
            productPrice.whole - discount.whole - 1);
    ensures \result.fractional ==
        (productPrice.fractional >= discount.fractional ?
            productPrice.fractional - discount.fractional :
            productPrice.fractional - discount.fractional + 100);
    ensures \result.whole >= 0;
*/
Decimal CalculateFinalPrice(Decimal productPrice, Decimal discount)
{
  int wholePart = (productPrice.whole - discount.whole);
  int fractionalPart = (productPrice.fractional - discount.fractional);
  /*@ assert productPrice.fractional >= discount.fractional ==> 
        wholePart >= 0; */
  /*@ assert productPrice.fractional < discount.fractional ==> 
        wholePart >= 1; */
  if ((fractionalPart < 0))
  {
    wholePart = (wholePart - 1);
    fractionalPart = (fractionalPart + 100);
    /*@ assert wholePart >= 0; */
    /*@ assert fractionalPart >= 0 && fractionalPart < 100; */
  }
  /*@ assert fractionalPart >= 0 && fractionalPart < 100; */
  Decimal result = {wholePart, fractionalPart};
  /*@ assert wholePart >= 0 && wholePart <= 2147483647; */
  return result;
}