#include <stdio.h>
int main()
{
 double a, b, q, s=0, z, e, c=0, sum=0, k=0, x;
 int n = 1; 
 printf ("Определенный интеграл x^2 \n");
 printf ("a=");
 scanf ("%lf",&a);
 printf ("b=");
 scanf ("%lf",&b);
 printf ("e=");
 scanf ("%lf",&e);
 printf ("po formule= %lf \n", (b*b*b-a*a*a)/3);
 do {
  q=(b-a)/n;
  z=s;
  x=a+0.5*q;
   do {
   sum=sum+x*x;
   x=x+q;
   }
   while (x < b);
  x=0;
  s=sum*q;
 }
 while ((s-z)>=e);
 printf ("integral= %lf \n", s);
 printf ("n= %d", n);
}
