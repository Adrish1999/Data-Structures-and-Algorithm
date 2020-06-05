#include<stdio.h>

int partition(int[],int,int);
int quicksort(int[],int,int);

int main()
{
  int arr[100];
  int size,i;
  printf("Enter size:\n");
  scanf("%d",&size);
  printf("Enter the array elements:\n");
  for(i=0;i<size;i++)
  {
    scanf("%d",&arr[i]);
  }
  quicksort(arr,0,size-1);
  printf("After quicksort , the sorted array is :\n");
  for(i=0;i<size;i++)
  {
    printf("%d ",arr[i]);
  }
  return 0;
}

int partition(int arr[],int start,int end)
{
int p=start;
while(start<end)
{
	while((p<end)&&(arr[p]<arr[end]))
	end--;
	if((p<end)&&(arr[p]>arr[end]))
	{
		int temp=arr[p];
		arr[p]=arr[end];
		arr[end]=temp;
		start++;
	}
	while((p>start)&&(arr[p]>arr[start]))
	start++;
	if((p>start)&&(arr[p]<arr[start]))
	{
		int temp=arr[p];
		arr[p]=arr[start];
		arr[start]=temp;
		end--;
	}	
}
return p;
}



int quicksort(int arr[],int start, int end)
{
  int pIndex;
  if (start<end)
  {
    pIndex=partition(arr,start,end);
    quicksort(arr,start,pIndex-1);
    quicksort(arr,pIndex+1,end);
  } 
  return 0;
}
