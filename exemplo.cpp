
int array[10] = {100,200,300,10,500,600,700,800,900,1000};
#include "exemplo2.cpp"
#include "WhileTest.cpp"
#include "IfTest.cpp"
#include "RelOperators.cpp"
#include "ForTest.cpp"
#include "gcd.cpp"
void autosuma(){
array[0] += 10;
printf("suma %d \n",array[0]);
array[1] -= 10;
printf("resta %d \n",array[1]);
array[2] /= 10;
printf("division %d \n",array[2]);

array[4] %= 10;
printf("mod %d \n",array[4]);
array[5] |= 10;
printf("or %d \n",array[5]);
array[6] &= 10;
printf("and %d \n",array[6]);
array[7] ^= 10;
printf("xor %d \n",array[7]);
array[8] <<= 1;
printf("corrimiento iz %d \n",array[8]);
array[9] >>= 1;
printf("corrimiento de %d \n",array[9]);


}


void main(){

/*
  int rando1;
  int rando2;
  int x, y, z,a,b;

  printf("Hello World!\n");
  srand(time(0));	
  rando1 = rand();
  rando2 = rand();
  
  printf("rando1 = %d !\n",rando1);
  printf("rando2 = %d !\n",rando2);
 
    a = 10;
    b = 20;
    
    x = a;
    y = b;
    z = gcd(x, y);

    printf("GCD(%d, %d) = %d\n", a, b, z);
*/
Arimetico();
WhileTest();
ForTest();
autosuma();
IfTest();
Relacionales();
}
