#include<stdio.h>

double in[10];
int ind[10];
double P[10],W[10];

void Insertion_Sort(double ratio[] , double profit[] , double weight[], int n)
{
	double k=0.0,p=0.0,q=0.0;
	int i,pos;
	for(i=1 ; i<n ; i++)
	{
		k = ratio[i];
		p = profit[i];
		q = weight[i];
		pos = i;
		while(pos>0 && k > ratio[pos-1])
		{
			ratio[pos] = ratio[pos-1];
			profit[pos] = profit[pos-1];
			weight[pos] = weight[pos-1];
			pos = pos -1;
		}
		ratio[pos] = k;
		profit[pos] = p;
		weight[pos] = q;
	}
}

void GreedyStrategy(double* P,double* W,int n)
{
	double ratio[10]={0.0};
	int i,j,temp;
    	for (i = 0; i < n; i++) 
	{
      		ratio[i] = P[i] / W[i];
    	}
	
 	Insertion_Sort(ratio,P,W,n);
	
 	printf("\n\n");
    	printf("Ratio array is:\n");
    	for(i=0;i<n;i++)
    	printf("%lf\t",ratio[i]);
	
 	printf("\n\n");
    	printf("Profit array is:\n");
    	for(i=0;i<n;i++)
    	printf("%lf\t",P[i]);
	
    	printf("\n\n");
    	printf("Weight array is:\n");
    	for(i=0;i<n;i++)
    	printf("%lf\t",W[i]);
    	printf("\n\n");
}
void KnapSack(int n,double* pro,double* wei,int capacity)
{
    	int i,j,u;
    	double x[10],tot=0,c;
    	c=capacity;
    	for(i=0;i<n;i++)
    	x[i]=0.0;
    	for(i=0;i<n;i++)
    	{
        	if(c<wei[i])
        	break;
        	else
        	{    
            		x[ind[i]]=1.0;
            		tot=tot+pro[i];
            		c=c-wei[i];
        	}
    	}
    	if(i<n)
        {
        	x[ind[i]]=c/wei[i];
	}
    	tot=tot+(x[ind[i]]*pro[i]);
    	printf("The solution set is:\n");
    	for(i=0;i<n;i++)
      	printf("%lf\t",x[i]);
    	printf("\nprofit:%lf",tot);
}

int main()
{
    	int i,j,n,c,choice;
    	printf("enter no of elements:\n");
    	scanf("%d",&n);
    	printf("enter profit :\n");
    	for(i=0;i<n;i++)
    	{
    		scanf("%lf",&P[i]);
    		ind[i]=i;
	}
   
    	printf("enter weight:\n");
    	for(i=0;i<n;i++)
    	scanf("%lf",&W[i]);
    	for(i=0;i<n;i++)
    	in[i]=W[i];
    	printf("enter space :\n");
    	scanf("%d",&c);
    
    	GreedyStrategy(P,W,n);
        
    	KnapSack(n,P,W,c);
    
    	return 0;
}
