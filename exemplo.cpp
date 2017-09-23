

int array[10] = {32,12,3,58,75,218,12,4,2,1};
 

//#include "exemplo2.cpp"
//#include "WhileTest.cpp"
//#include "IfTest.cpp"
//#include "RelOperators.cpp"
//#include "ForTest.cpp"
//#include "gcd.cpp"

void autosuma(){
int temp = 0,count2 = 0;
int i = 1,j=0,numLength = 10;   

/*
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

 //----------------burbuja----------- // 
*/	
     while( i <= numLength){
          j=0;
          while ( j < numLength-1){
              if (array[j] >  array[j+1])     
              { 
                    temp =  array[j];            
                    array[j] = array[j+1];
                     array[j+1] = temp;      
               }
		j++;
          }
	 i++;	
    }
      j=0;
      while ( j < numLength)
      {
	printf("array[%d]== %d \n",j,array[j]);
	 j++;
      }

	
}

void main(){

/*
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
*/
//Arimetico();
//WhileTest();
//ForTest();
autosuma();
//IfTest();
//Relacionales();

}
