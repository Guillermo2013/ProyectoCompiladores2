

//Funcion que calcula el maximo comun divisor
 int gcd(int a, int b) {
int mod;  
  if (b == 0) 
    { 
	return(a); 
    }
    else 
     {
  	mod = a%b;
	return  gcd(b, mod) ; 
     }
}

