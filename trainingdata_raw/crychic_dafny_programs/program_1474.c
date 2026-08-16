// Generated C + ACSL

/*@
    requires a >= 0;
    decreases a;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures a % 2 == 0 ==> \result == 1;
    ensures a % 2 == 1 ==> \result == 0;
*/
int IsEven(int a)
{
  return ((a == 0)) ? (1) : (((a == 1)) ? (0) : (IsEven((a - 2))));
}

// ```c
// /*@
//   axiomatic EvenPlus_properties {
//     lemma EvenPlus_statement:
//       \forall integer x, integer y;
//         (x >= 0 && y >= 0 && IsEven(x) && IsEven(y)) ==>
//         IsEven(x + y);
//   }
// */
// ```

// ```c
// /*@
//   axiomatic EvenPlus2_properties {
//     lemma EvenPlus2_statement:
//       \forall integer x, integer y;
//         (x >= 0 && y >= 0 && IsEven(x) && IsEven(y)) ==>
//         IsEven(x + y);
//   }
// */
// ```

// ```c
// /*@
//   axiomatic EvenPlus3_properties {
//     lemma EvenPlus3_statement:
//       \forall integer x, integer y;
//         (x >= 0 && y >= 0 && IsEven(x) && IsEven(y)) ==>
//         IsEven(x + y);
//   }
// */
// ```

// ```c
// /*@
//   axiomatic EvenPlus4_properties {
//     lemma EvenPlus4_statement:
//       \forall integer x, y, z;
//         x >= 0 && y >= 0 &&
//         IsEven(x) && IsEven(y) &&
//         z == x + y
//         ==> IsEven(z);
//   }
// */
// ```