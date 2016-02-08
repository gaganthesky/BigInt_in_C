#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE_Arr 1000000

void reConvertNum(int a[],long long int size)
{
	long long int i;
	
	for(i=size-1;i>=0;i--)
	{

		printf("%d",a[i]);

	}

}

long long int convertArray(int a[], int num)
{
	int q=num,r=num;
	long long int size = 0;
	long long int i = 0;

	for(i=0;i<SIZE_Arr;i++)
	{
		a[i] = 0;
	}

	i = 0;

	while(q>=10)
	{
		size = size + 1;
		q = num/10;
		r = num%10;
		a[i] = r;
		
		num = q;
		i++;

	}
	a[i] = q;
	size = size+1;
	
	return size;
}

long long int addition(int a[], int b[], int d[], long long int size1, long long int size2, long long int size4)
{
	long long int i = 0;
	int carry_sum = 0, sum;
	while(i<=size1 || i<=size2)
	{
		sum = a[i] + b[i]+carry_sum;
		carry_sum = 0;
		if(sum>9)
		{
			d[i] = sum%10;
			carry_sum = sum/10;
			size4++;
		}

		else
		{
			d[i] = sum;
			size4++;
		}
		i++;
	}

	if(d[size4-1]==0)
	{
		size4--;
	}

	return size4;

}

long long int multiply(int a[], int b[], int c[], long long int size1, long long int size2, long long int size3, long long int j)
{
	long long int i;
	int prod,carry_mul = 0;
	
	if(j == size2)
	{
		return size3;
	}

	else
	{

		for(i=0;i<size1;i++)
		{
			prod = (b[j] * a[i]) + carry_mul;
			carry_mul = prod/10;
			c[j+i] = c[j+i] + prod%10;
		}
		c[j+i] = carry_mul;
		size3 = j+i;
		size3++;
		
		j++;

		return multiply(a,b,c,size1,size2,size3,j);
	}

}


void fibMod(int a[], int b[], long long int size_a, long long int size_b, int N)
{
	//int temp_B[SIZE_Arr];
	int *temp_B = malloc(SIZE_Arr*sizeof(int));
	//int *j;
	long long int i, size_c, size_d;

	//int c[SIZE_Arr],  d[SIZE_Arr];
	int *c = malloc(SIZE_Arr*sizeof(int));
	int *d = malloc(SIZE_Arr*sizeof(int));
		/*for(i=0;i<SIZE_Arr;i++)
	    {
	    	c[i] = 0;
	    	d[i] = 0;
	    }*/

	if(N == 2)
	{
		reConvertNum(b,size_b);
		return ;
	}
	else
	{
		for(i=0;i<size_b;i++)
		{
			temp_B[i] = b[i];
		}
		
		size_c = multiply(b,b,c,size_b,size_b,0,0);
			if(c[size_c-1] == 0)
				size_c--;
		size_d = addition(a,c,d,size_a,size_c,0);
		
		size_a = size_b;

		for(i=0;i<size_d;i++)
		{
			b[i] = d[i];
		}
		size_b = size_d;
        
        //free(c);
        //free(d);
		return fibMod(temp_B,b,size_a,size_b,N-1);
	}
}

int main() {

    /* Enter your code here. Read input from STDIN. Prlong long int output to STDOUT */    
    int N;
    int A,B;
//    long long int i;

    scanf("%d %d %d", &A,&B,&N);

    //int a[SIZE_Arr], b[SIZE_Arr];

    int *a = malloc(SIZE_Arr*sizeof(int));
    int *b = malloc(SIZE_Arr*sizeof(int));

    long long int size_a = convertArray(a,A);
    
    long long int size_b = convertArray(b,B);
    
    fibMod(a,b,size_a,size_b,N);
   
	//reConvertNum(b,size_b);
	free(a);
	free(b);

	return 0;
}
