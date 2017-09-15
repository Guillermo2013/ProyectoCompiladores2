# 1 "exemplo.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "exemplo.cpp"

int a[10] = {100,200,300,1,500,600,700,800,900,1000};
# 1 "exemplo2.cpp" 1

# 1 "WhileTest.cpp" 1
# 1 "IfTest.cpp" 1
# 1 "RelOperators.cpp" 1
# 1 "ForTest.cpp" 1





void ForTest() {
    int i;

    for (i = 0; i <= 10; i++) {
        printf ("i = %d ", i);
    }

    printf("i= %d \n End of loop\n",i);
}
# 2 "RelOperators.cpp" 2

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
ForTest();
}
# 2 "IfTest.cpp" 2
void IfTest() {
    int x1, y1;


    x1 = 100 + 32;
    y1 = 100 + 43;

    printf("X = %d, Y = %d\n", x1, y1);

    if (x1 == y1)
        printf ("X %d is equal to Y %d \n",x1,y1);
    else
        printf ("X %d is no equal to Y %d \n",x1,y1);
    Relacionales();
}
# 2 "WhileTest.cpp" 2
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
  IfTest();
}
# 3 "exemplo2.cpp" 2

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
    WhileTest();
}
# 4 "exemplo.cpp" 2
void autosuma(){
a[0] += 10;
printf("suma %d \n",a[0]);
a[1] -= 10;
printf("resta %d \n",a[1]);
a[2] /= 10;
printf("division %d \n",a[2]);

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
  printf("Hello World!\n");
 autosuma();

}
