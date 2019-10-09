#include<stdio.h>
#include<string.h>
int main()
{ char ch;
  char a[20][100],temp[100];
  int n,k=0,flag=0;
  printf("ENTER THE NO. OF STRING YOU WANT TO ENTER:\n");
  scanf("%d",&n);
  while(getchar()!='\n');
  printf("\nENTER YOUR STRING :\n");
  for(int i=0;i<n;i++)
  {
    scanf("%s",a[i]);
  }
  for(int i=0;i<n-1;i++)
  { k=0;
    flag=0;
    int j=i;
    while(flag!=1)
    {

      if(a[j][k]>a[j+1][k])
      {
        strcpy(temp,a[j]);
        strcpy(a[j],a[j+1]);
        strcpy(a[j+1],temp);
        j++;
      }
      else if(a[j][k]==a[j+1][k])
      {
        k++;
        if (a[j][k]=='\0'||a[j+1][k]=='\0')
        {  if(strcmp(a[j],a[j+1])<0)
          {
            j++;
          }
          else
          {
            strcpy(temp,a[j]);
            strcpy(a[j],a[j+1]);
            strcpy(a[j+1],temp);
            j++;
          }
        }
        continue;
      }


      if(j==n)
        break;
    }
    printf("\nAFTER %d LOOP:\n",i+1);
    for(int h=0;h<n;h++)
    {
      printf("%s\t",a[h]);
    }
  }
  return 0;
}
