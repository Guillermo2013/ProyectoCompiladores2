
int array[10] = {100,200,300,10,500,600,700,800,900,1000};
int num[10] = {1,3,52,54,3,5,6,12,67,90};
#include "exemplo2.cpp"
#include "WhileTest.cpp"
#include "IfTest.cpp"
#include "RelOperators.cpp"
#include "ForTest.cpp"
#include "gcd.cpp"
#include "bubblesort.cpp"
void autosuma(){
int count2 = 0;
array[count2++] += 10;
printf("suma %d \n",array[0]);
array[count2++] -= 10;
printf("resta %d \n",array[1]);
array[count2++] /= 10;
printf("division %d \n",array[2]);

array[count2++] %= 10;
printf("mod %d \n",array[4]);
array[count2++] |= 10;
printf("or %d \n",array[5]);
array[count2++] &= 10;
printf("and %d \n",array[6]);
array[count2++] ^= 10;
printf("xor %d \n",array[7]);
array[count2++] <<= 1;
printf("corrimiento iz %d \n",array[8]);
array[count2++] >>= 1;
printf("corrimiento de %d \n",array[9]);


}


void main(){


  int rando1;
  int rando2;
  int x4, y4, z,a2,b2;

  printf("Hello World!\n");
  srand(time(0));	
  rando1 = rand();
  rando2 = rand();
  
  printf("rando1 = %d !\n",rando1);
  printf("rando2 = %d !\n",rando2);
 
    a2 = 70;
    b2 = 15;
    
    x4 = a2;
    y4 = b2;
    z = gcd(x4, y4);

    printf("GCD(%d, %d) = %d\n", a2, b2, z);

Arimetico();
WhileTest();
ForTest();
//BubbleSort();
autosuma();
//IfTest();
//Relacionales();
}
