# 1 "exemplo.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "exemplo.cpp"

int array[10] = {100,200,300,10,500,600,700,800,900,1000};
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
# 4 "exemplo.cpp" 2
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
# 5 "exemplo.cpp" 2
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
# 6 "exemplo.cpp" 2
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
# 7 "exemplo.cpp" 2
# 1 "ForTest.cpp" 1





void ForTest() {
    int i;

    for (i = 0; i <= 10; i++) {
        printf ("i = %d ", i);
    }

    printf(" End of loop\n");
}
# 8 "exemplo.cpp" 2
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
# 9 "exemplo.cpp" 2
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
# 58 "exemplo.cpp"
Arimetico();
WhileTest();
ForTest();
autosuma();
IfTest();
Relacionales();
}
