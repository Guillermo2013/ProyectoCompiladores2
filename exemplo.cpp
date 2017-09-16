
int a[10] = {100,200,300,1,500,600,700,800,900,1000};
#include "exemplo2.cpp"
void autosuma(){
a[0] += 10;
printf("suma %d \n",a[0]);
a[1] -= 10;
printf("resta %d \n",a[1]);
a[2] /= 10;
printf("division %d \n",a[2]);
a[3] *= 1;
printf("multi %d \n",a[3]);
a[4] %= 10;
printf("mod %d \n",a[4]);
a[5] |= 10;
printf("or %d \n",a[5]);
a[6] &= 10;
printf("and %d \n",a[6]);
a[7] ^= 10;
printf("xor %d \n",a[7]);
a[8] <<= 1;
printf("corrimiento iz %d \n",a[8]);
a[9] >>= 1;
printf("corrimiento de %d \n",a[9]);
Arimetico();

}


void main(){
  int rando1;
  int rando2;
  printf("Hello World!\n");
  srand(time(0));	
  rando1 = rand();
  rando2 = rand();
  
  printf("rando1 = %d !\n",rando1);
  printf("rando2 = %d !\n",rando2);
 autosuma();

 
}
