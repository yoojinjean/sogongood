#include<stdio.h>
#include<stdlib.h>
//bugfix의 주석
#define E 5
#define MAX 500
double a0,a1,a2,a3;

double f(double x)    
{
        x=a0+a1*x+a2*(x*x)+a3*(x*x*x);
        return x;
}
//master로 수정
double Bisect(double xl, double xu, double es)
{
   int iter=0;
    double fl,fr,fu,test;
   double ea=0;
   double xr=0,xrold;
   int count=0;

   do{
   fl=f(xl);
   do
   {
      xrold=xr;
      xr=(xl+xu)/2;
      fr=f(xr);
      iter+=1;

      if(xr!=0)
      {
         ea=(xr-xrold)/xr*100;
         if(ea<0)
            ea=-ea;
      }
      test=fl*fr;
      if(test<0)
         xu=xr;
      else if(test>0)
      {
         xl=xr;
         fl=fr;
      }
      else
         ea=0;
         
   }while(ea>es || iter<MAX);
   count++;
   return xr;
   
   printf("%d",count);
   }while(count>3);
   printf("%d",count);
}

   


   int main(void)
{
        double x1,x2;
        int i=0;
      double result;
        printf("input value a0: ");
        scanf("%lf",&a0);
        printf("input value a1: ");
        scanf("%lf",&a1);
        printf("input value a2: ");
        scanf("%lf",&a2);
        printf("input value a3: ");
        scanf("%lf",&a3);
 
   result=Bisect(-10,10,0.001);
   printf("%f",result);

    system("pause");

    return 0;

}