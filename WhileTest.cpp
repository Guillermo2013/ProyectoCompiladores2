
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
