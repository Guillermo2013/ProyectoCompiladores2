# 1 "exemplo.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "exemplo.cpp"


int array[10] = {32,12,3,58,75,218,12,4,2,1};
# 13 "exemplo.cpp"
void autosuma(){
int temp = 0,count2 = 0;
int i = 1,j=0,numLength = 10;
# 40 "exemplo.cpp"
     while( i <= numLength){
          j=0;
          while ( j < numLength-1){
              if (array[j] > array[j+1])
              {
                    temp = array[j];
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
# 90 "exemplo.cpp"
autosuma();



}
