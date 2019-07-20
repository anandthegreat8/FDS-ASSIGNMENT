#include<stdio.h>
#include<stdlib.h>
void add(int **a,int **b,int r,int o)					//ADD FUNCTION
{
	int **c=(int **)malloc(r*sizeof(int*));
	for(int i=0;i<r;i++)
	{
		c[i]=(int*)malloc(o*sizeof(int));
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<o;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("THE ADDITON OF TWO MATRIX:\n" );
	for(int i=0;i<r;i++)
	{	printf("\n");
		for(int j=0;j<o;j++)
		{
			printf("\t");
			printf("\t %d",c[i][j]);
		}
	}
	free(c);

}
void subtract(int **a,int **b,int r,int o)			//subtract Function
{
	int **c =(int **)malloc(r*sizeof(int *));
	for(int i=0;i<r;i++)
	{
		c[i]=(int*)malloc(o*sizeof(int));
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<o;j++)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	}
	printf("THE SUBTRACTION OF TWO MATRIX:\n" );
	for(int i=0;i<r;i++)
	{	printf("\n");
		for(int j=0;j<o;j++)
		{
			printf("\t");
			printf("\t %d",c[i][j]);
		}
	}
	free(c);
}
void multiply(int **a,int **b,int r,int o)			//multiply Function
{
	int **c =(int **)malloc(r*sizeof(int *));
	for(int i=0;i<r;i++)
	{
		c[i]=(int*)malloc(o*sizeof(int));
	}

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<o;j++)
		{
			c[i][j]=0;
			for (int k=0;k<o;k++)
			{
				c[i][j]+=a[i][j]*b[k][j];
			}

		}
	}
	printf("THE MULTIPLICATION OF TWO MATRIX:\n" );
	for(int i=0;i<r;i++)
	{	printf("\n");
		for(int j=0;j<o;j++)
		{
			printf("\t");
			printf("\t %d",c[i][j]);
		}
	}
	free(c);
}
void saddle(int **a,int r,int o)			//Saddle Point Function
{
	int min,max,u=0,count=0,flag=0;
	for(int i=0;i<r;i++)
	{
		min=a[i][0];
		for(int j=0;j<o;j++)
		{
			if(min<a[i][j])
			{
				min=a[i][j];
				count=j;
			}
		}
		for(int k=0;k<r;k++)
		{
			if(a[k][count]>min)
			{
				continue ;
			}
			else
			{		flag=1;
					break ;
			}
		}
		if(flag==1)
			break;
		else
			continue;
	}
	if(flag==0)
		printf("THE SADDLE POINT OF MATRIX:\n%d",min );
	else
		printf("THE SADDLE POINT DOES NOT EXSIST\n" );
}
void magic(int **a,int r,int o)			//Magic Square Function
{
	int sum=0,flag=0;
	for(int i=0;i<r;i++)
	{	sum=0;
		for(int j=0;j<o;j++)
		{
			sum+=a[i][j];
		}
		if(sum==15)
		{
			continue;
		}
		else
		{
			flag=1;
			break ;
		}
	}
	if(flag==0)
		printf("THE MATRIX IS A SQUARE MATRIX\n");
	else
		printf("THE MATRIX IS NOT A MAGIC SQUARE\n" );
}
int main()																										//main function
{
	int n=0,r,c,i,j,k,l;
	printf("ENTER THE NO. OF ROWS:");
	scanf("%d",&r);
	printf("ENTER THE NO. OF COLUMN:");
	scanf("%d",&c);
	int **a=(int**)malloc(r*sizeof(int*));
	for(i=1;i<=r;i++)
	{
		a[i]=(int*)malloc(c*sizeof(int));
	}
	printf("\nENTER THE ELEMENTS FOR FIRST MATRIX:\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j< c; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int **b=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
	{
		b[i]=(int*)malloc(c*sizeof(int));
	}
	printf("\nENTER THE ELEMENTS FOR SECOND MATRIX:\n");
	for (i = 0; i < r; ++i)
	{
		for (j = 0; j< c; ++j)
		{
			scanf("%d",&b[i][j]);
		}
	}
	while(n!=6)														//menu
	{
		printf("\nENTER YOUR CHOICE:\n1.ADD\n2.SUBTRACT\n3.MULTIPLY\n4.SADDLE POINT\n5.MAGIC SQUARE\n6.EXIT\n");
		scanf("%d",&n);
		switch (n)
		{
			case 1:
			{
				add(a,b,r,c);
				break ;
			}
			case 2:
			{
				subtract(a,b,r,c);
				break ;
			}
			case 3:
			{
				multiply(a,b,r,c);
				break ;
			}
			case 4:
			{
				saddle(a,r,c);
				break ;
			}
			case 5:
			{
				magic(a,r,c);
				break ;
			}
			case 6:
			{
				break ;
			}
			default:
			{
				printf("ENTER RIGHT CHOICE SIR\n");
			}
		}

	}
	free(a);
	free(b);
	return 0;

}
