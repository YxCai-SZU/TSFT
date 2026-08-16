int unknown1();
int unknown2();
int unknown3();
int unknown4();

void foo(int flag) {
   int j = 2; 
   int k = 0;

   while(unknown1()){ 
     if (flag)
       j = j + 4;
     else {
       j = j + 2;
       k = k + 1;
     }
   }
   if(k != 0) {
     /*@ assert j == 2 * k + 2; */
   }
}
