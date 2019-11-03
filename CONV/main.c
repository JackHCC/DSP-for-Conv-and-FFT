//卷积中增加高斯白噪声

//且方波与方波卷积，信号长度均为40；


#include <math.h>
#include <stdlib.h>
#include <stdio.h>


const float PI=3.141592654;

int N1,N2;		/*输入数组长度*/
int n;			/*输出数组长度*/
int m,i,k;
float x[80];
float h[80];
float y[80];	/*输出数组*/

float nw[80];   //添加噪声信号

//高斯白噪声函数
double gaussrand( )
{
    static double U, V;
    static int phase = 0;
    double  Z;

    if(phase == 0)
    {
         U = rand() / (RAND_MAX + 1.0);
         V = rand() / (RAND_MAX + 1.0);
         Z = sqrt(-2.0 * log(U))* sin(2.0 * PI * V);
    }
    else
    {
         Z = sqrt(-2.0 * log(U)) * cos(2.0 * PI * V);
    }

    phase = 1 - phase;
    return Z;
}

main()
{
   N1=40;                           /* x 长度*/
   N2=40;                           /* h 长度*/
   n=N1+N2-1;                      /* 输出 y 的长度*/

   for(i=0;i<80;i++)               /* 初始化数组 */
   {

     x[i]=0;
     h[i]=0;
     y[i]=0;

     nw[i]=gaussrand( );   //高斯白噪声

   }

   for(i=0;i<n;i++)		/* 给x数组赋值 */
   {
      if(i<N1)
      {
         //x[i]=pow(2,i);
    	  x[i]=1;
      }

      else
      {
         x[i]=0;
      }
   }

   for(i=0;i<=n;i++)	/* 给h数组赋值 */
   {
      if(i<N2)
      {
         h[i]=1;
      }

      else
      {
         h[i]=0;
      }
   }

   for(i=0;i<n;i++)  	/* 计算卷积 */
   {
   	  for (k=0;k<=i;k++)
   	  	y[i]=y[i]+h[k]*(x[i-k]+nw[i-k]);      //滤波器与混合信号卷积
   }
}
