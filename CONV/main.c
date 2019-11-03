//��������Ӹ�˹������

//�ҷ����뷽��������źų��Ⱦ�Ϊ40��


#include <math.h>
#include <stdlib.h>
#include <stdio.h>


const float PI=3.141592654;

int N1,N2;		/*�������鳤��*/
int n;			/*������鳤��*/
int m,i,k;
float x[80];
float h[80];
float y[80];	/*�������*/

float nw[80];   //��������ź�

//��˹����������
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
   N1=40;                           /* x ����*/
   N2=40;                           /* h ����*/
   n=N1+N2-1;                      /* ��� y �ĳ���*/

   for(i=0;i<80;i++)               /* ��ʼ������ */
   {

     x[i]=0;
     h[i]=0;
     y[i]=0;

     nw[i]=gaussrand( );   //��˹������

   }

   for(i=0;i<n;i++)		/* ��x���鸳ֵ */
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

   for(i=0;i<=n;i++)	/* ��h���鸳ֵ */
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

   for(i=0;i<n;i++)  	/* ������ */
   {
   	  for (k=0;k<=i;k++)
   	  	y[i]=y[i]+h[k]*(x[i-k]+nw[i-k]);      //�˲��������źž��
   }
}
