#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student                                                 //class basic
{
	char name[20];
	int roll_no;
	long long int mobile_no;
	float marks[5];
	float per;

}student;
int sea(student *s, int r,int n)                                			// sea function
{
        if ((s+n)->roll_no==r)
        {
            return 1;
        }
    		else
					return 0;
}
int insert(student *s,int m,int n)															//insert function
{
		return 0;
		s=(student*)realloc(s,(n+m)*sizeof(student));
		int y=n;
		int r;

		while(y!=(n+m))
		{   char ch='\0';
		int j=0;
		int flag=2;
		int i=-1;
		printf("\nEnter his roll_no:");
		scanf("%d",&r);
		nhi:
		i++;
		flag=sea(s,r,i);
		if(flag!=0)
		{
			printf("\nTHE ROLL_NO Exsit ,Enter differnt roll number\n" );
			scanf("%d",&r);
			goto nhi;
		}
		else if(i!=n+y)
		goto nhi;
		else
		{	  (s+y)->roll_no = r;
			printf("\nEnter The Name Of the Student:");
			while((getchar()!='\n'));
			while(ch!='\n')
			{
				ch=getchar();
				(s+y)->name[j]=ch;
				j++;
			}
			printf("\nEnter marks in subjects:\n");
			for(int i=0;i<5;i++)
			{   printf("SUBJECT %d:",i+1);
			scanf("%f",&(s+y)->marks[i]);
			printf("\n");
		}
		printf("\nEnter Mobile Number :");
		scanf("%lld",&(s+y)->mobile_no);
		for (int i = 0; i < 5; ++i)
		{
			(s+y)->per=(s+y)->per+(s+y)->marks[i];
		}
		(s+y)->per=(s+y)->per/5;
		y++;
	}
}
}
void ins(student *s,int i,int n)
{
	int l=i+1;
	s=(student*)realloc(s,(n+1)*sizeof(student));
	for(int j=n;j>l;j--)
	{
		*(s+j)=*(s+j-1);
	}
	(s+l)->per=0;
	int y=l;
	int r;
	{   char ch='\0';
			int j=0;
			int flag=2;
			int i=-1;
			printf("\nEnter his roll_no:");
			scanf("%d",&r);
			nhi:
			i++;
			flag=sea(s,r,i);
			if(flag!=0)
			{
					printf("\nTHE ROLL_NO Exsit ,Enter differnt roll number\n" );
					scanf("%d",&r);
					goto nhi;
			}
			else if(i!=n)
				goto nhi;
			else
			{	  (s+y)->roll_no = r;
					printf("\nEnter The Name Of the Student:");
					while((getchar()!='\n'));
					while(ch!='\n')
					{
							ch=getchar();
							(s+y)->name[j]=ch;
							j++;
					}
					printf("\nEnter marks in subjects:\n");
					for(int i=0;i<5;i++)
					{   printf("SUBJECT %d:",i+1);
							scanf("%f",&(s+y)->marks[i]);
							printf("\n");
					}
					printf("\nEnter Mobile Number :");
					scanf("%lld",&(s+y)->mobile_no);
					for (int i = 0; i < 5; ++i)
					{
							(s+y)->per=(s+y)->per+(s+y)->marks[i];
					}
					(s+y)->per=(s+y)->per/5;
			}
	}
}
student* input(int m)																		//input function
{
    student *s=(student*)malloc(m*sizeof(student));
    int n=0;
    while(n!=m)
    {   char ch='\0';
        int j=0,r;
        int flag=2;
        printf("\nEnter his roll_no:");
        scanf("%d",&r);
        (s+n)->roll_no=r;
				while ((getchar()!='\n'));
        printf("\nEnter The Name Of the Student:");
        while(ch!='\n')
        {
          ch=getchar();
          (s+n)->name[j]=ch;
          j++;
        }
        (s+n)->name[j]='\0';
        printf("\nEnter marks in subjects:\n");
        for(int i=0;i<5;i++)
        {   printf("SUBJECT %d:",i+1);
            scanf("%f",&(s+n)->marks[i]);
            printf("\n");
        }
        printf("\nEnter Mobile Number :");
        scanf("%lld",&(s+n)->mobile_no);
				(s+n)->per=0;
        for (int i = 0; i < 5; i++)
        {
            (s+n)->per=(s+n)->per+(s+n)->marks[i];
        }
        (s+n)->per=(s+n)->per/5;
        n++;
    }
    return(s);
}
void output(student *s,int i)																	    //output function
{

			printf("\n%d\t\t%lld\t%.2f\t\t",(s+i)->roll_no,(s+i)->mobile_no,(s+i)->per);
			printf("%s",(s+i)->name);
}

int main()                                                       //MAIN FUNCTION
{
    int n=0,m=0,k=0,j=0,i,count=0,flag=2,temp=0;
    long int p;
    student b;
    student *s;
    strcpy(b.name,"ANAND");
    b.roll_no=0;
    b.mobile_no=7733816710;
    for(int i=0;i<5;i++)
    	b.marks[i]=94.2;
			int h=0;
    do
    {		count=0,flag=2,temp=0;
        printf("\nEnter Your Choice:\n1.Dispaly Master Table\n2.Insert new Entry\n3.Delete an Entry\n4.Display\n5.Search For An Entry\n6.Insert in between\n7.Append\n8.Exit\n");
        scanf("%d",&h);
				flag=2;
        switch(h)
        {
            case 1:
            {	printf("\n-----------------DETAILS---------------\n");
                printf("\nNAME :%s",b.name);
                printf("\nRoll No. :%d",b.roll_no);
                printf("\nMOBILE No.:%lld",b.mobile_no);
                printf("\nMARKS IN EACH SUBJECT:\n");
                for(int i=0;i<5;i++)
                {	printf("SUBJECT %d :",i+1);
                	printf("%.2f\n",b.marks[i]);
                	b.per=b.per+b.marks[i];
                }
                printf("\nPercentage : %.2f %\n ",b.per/5);
								printf("\nHow many Entries you want to add:");
		            scanf("%d",&n);
								s=input(n);
								break;
            }
            case 2:
            {   printf("\nHow many Entries you want to add:");
                scanf("%d",&m);
                flag=insert(s,m,n);
                if(flag==0)
                    printf("\nEntered successfully");
                n=n+m;
                break;
            }
            case 3:
            {
                printf("\nEnter the roll no you want to Delete:");
                scanf("%d",&m);
								for(int k=0;k<n;k++)
								{
									count=sea(s,m,k);
									if(count==1)
									{
										count=k;
										for(int i=count;i<n;i++)
										{
												(s+i)->roll_no=(s+i+1)->roll_no;
												strcpy((s+i)->name,(s+i+1)->name);
												(s+i)->mobile_no=(s+i+1)->mobile_no;
												(s+i)->per=(s+i+1)->per;
										}
										s=(student*)realloc(s,(n-1)*sizeof(student));
										n=n-1;
										break;
									}
									else
										continue;
								}
                break;
            }
            case 4:
            {		printf("\nROLL NO.\tMOBILE NO.\tPERCENTAGE\tNAME\n");
                for(int i=0;i<n;i++)
                {
                    output(s,i);
                }
                break ;
            }
						case 5:
						{
							printf("Enter the Roll Number you want to search:\n" );
							scanf("%d",&m);
							for(int i=0;i<n;i++)
							{
								count=sea(s,m,i);
								if(count==1)
								{
									printf("\nELEMENT FOUND\n");
									break;
								}
							}
								if(count==0)
								{	printf("NOT FOUND\n");
									break;
								}
							break;
						}
						case 6:
						{
							printf("\nEnter the roll number after you want to edit :");
							scanf("%d",&m);
							for(int i=0;i<n;i++)
							{
								count=sea(s,m,i);
								if(count==1)
								{
									printf("\nELEMENT FOUND\n");
									ins(s,i,n);
									n++;
									break;
								}
							}
								if(count==0)
									{
											printf("\nNOT FOUND\n" );
											break;
									}
							break;
						}
						case 7:
						{
							printf("Enter the roll no. you want to edit:");
							scanf("%d",&m);
							break;
						}
       }
     }while(h!=8);
		 free(s);
     return 0;
}
