#include<stdio.h>
int main()
{
	int matA[2][2],matB[2][2],matC[2][2];
	int i,j,p,q,r,s,t,u,v;
	printf("Enter the values of matrix A\n");
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{
			scanf("%d",&matA[i][j]);
		}
	}
	printf("Enter the values of matrix B\n");
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{
			scanf("%d",&matB[i][j]);
		}
	}
	p=(matA[1][1]+matA[2][2])*(matB[1][1]+matB[2][2]);
	q=(matA[2][1]+matA[2][2])*matB[1][1];
	r=matA[1][1]*(matB[1][2]-matB[2][2]);
	s=matA[2][2]*(matB[2][1]-matB[1][1]);
	t=(matA[1][1]+matA[1][2])*matB[2][2];
	u=(matA[2][1]-matA[1][1])*(matB[1][1]+matB[1][2]);
	v=(matA[1][2]-matA[2][2])*(matB[2][1]+matB[2][2]);
	
	matC[1][1]=p+s-t+v;
	matC[1][2]=r+t;
	matC[2][1]=q+s;
	matC[2][2]=p+r-q+u;
	
	printf("The A matrix is \n");
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{
			printf("%d\t",matA[i][j]);
		}
		printf("\n");
	}
	
	printf("The B matrix is \n");
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{
			printf("%d\t",matB[i][j]);
		}
		printf("\n");
	}
	
	printf("The multiplication matrix is \n");
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{
			printf("%d\t",matC[i][j]);
		}
		printf("\n");
	}
	return 0;
}
