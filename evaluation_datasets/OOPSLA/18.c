int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*@
requires flag > 0;
*/
void foo(int flag, int a) {
   int b;
   int j = 0;
   for (b = 0; b < 100 ; ++b){
      if (flag)
         j = j + 1;
   }

   if(flag) {
      /*@ assert j==100; */
   }
}
