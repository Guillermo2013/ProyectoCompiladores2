# 1 "exemplo.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "exemplo.cpp"

int array[10] = {100,200,300,10,500,600,700,800,900,1000};
int num[10] = {1,3,52,54,3,5,6,12,67,90};
# 1 "exemplo2.cpp" 1



void Arimetico(){
int x, y;

    x = 50;
    y = 23;

    printf("X = %d, Y = %d\n", x, y);

    printf("Add %d\n", x + y);
    printf("Sub %d\n", x - y);
    printf("Mul %d\n", x * y);
    printf("Div %d\n", x / y);
    printf("Mod %d\n", x % y);

}
# 5 "exemplo.cpp" 2
# 1 "WhileTest.cpp" 1

void WhileTest() {
    int total;
    int count;
    int number;
    total = 0;
    count = 0;

    while (count < 3) {


        number += 12;
        printf("Number [%d] = %d\n", count, number);
        count = count + 1;
        total = total + number;
    }
    printf ("The total is %d\n", total);

}
# 6 "exemplo.cpp" 2
# 1 "IfTest.cpp" 1

void IfTest() {
    int x1, y1;


    x1 = 100 + 32;
    y1 = 100 + 43;

    printf("X = %d, Y = %d\n", x1, y1);

    if (x1 == y1)
        printf ("X %d is equal to Y %d \n",x1,y1);
    else
        printf ("X %d is no equal to Y %d \n",x1,y1);

}
# 7 "exemplo.cpp" 2
# 1 "RelOperators.cpp" 1


void Relacionales() {
    int x2, y2;

    x2 = 100 / 22;
    y2 = 100 / 52;

    printf("x = %d\n", x2);
    printf("y = %d\n", y2);


    printf ("(x > y: %d) ", x2 > y2);


    printf("(x < y: %d )", x2 < y2);


    printf("(x >= y: %d) ", x2 >= y2);


    printf("(x <= y: %d )", x2 <= y2);


    printf("(x != y: %d) ", x2 != y2);


    printf("(x == y: %d)\n ", x2 == y2);

}
# 8 "exemplo.cpp" 2
# 1 "ForTest.cpp" 1





void ForTest() {
    int i;

    for (i = 0; i <= 10; i++) {
        printf ("i = %d ", i);
    }

    printf(" End of loop\n");
}
# 9 "exemplo.cpp" 2
# 1 "gcd.cpp" 1



 int gcd(int a, int b) {
int mod;
  if (b == 0)
    {
 return(a);
    }
    else
     {
   mod = a%b;
 return gcd(b, mod) ;
     }
}
# 10 "exemplo.cpp" 2
# 1 "bubblesort.cpp" 1

void BubbleSort()
{
int i,flag = 1;
int temp,j;
int numLength = 10;

      for(i = 1; (i <= numLength) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
         {
               if (num[j+1] > num[j])
              {
                    temp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = temp;
                    flag = 1;
               }
          }
     }
      for (j=0; j < numLength; j++)
      {
 printf("array[%d]== %d",j,num[j]);
      }
     return;
}
# 11 "exemplo.cpp" 2
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



}
