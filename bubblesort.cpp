   
void BubbleSort()
{
          
      
      for(i2 = 1; i2 <= numLength; i2++)
     {
         
          for (j2=0; j2 < (numLength -1); j2++)
         {
               if (num[j2+1] > num[j2])     
              { 
                    temp = num[j2];             
                    num[j2] = num[j2+1];
                    num[j2+1] = temp;
                                 
               }
          }
     }
     
      
}
