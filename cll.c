#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef struct poly
{
            int exp;
            int coef;
            struct poly *next;
}p;

p *p1, *p2, *p3;
p *create();
p *add(p* , p* );
p* mul(p* , p* );

int Eval(p *p1);
void display(p *);

int main()
{
  int choice,result=0;

  printf("\n Program for Polynomial Addition, Multiplication and Evaluation using Circular Linked List");
  printf("\n\nEnter the first polynomial\n\n");
  p1 = create();
  printf("Enter the Second polynomial\n\n");
  p2 = create();

  printf("\nThe first polynomial is as follows\n");
  display(p1);
  printf("\nThe second polynomial is as follows\n");

  display(p2);

  do
  {
    printf("\n\t\t Main Menu");
    printf("\n 1.Addition \n 2.Multiplication \n 3.Evaluation\n 4.Exit ");
    printf("\n Enter Your Choice ");
    scanf("%d",&choice);

    switch(choice)
    {
     case 1:p3=add(p1,p2);
            printf("\n The addition of the polynomials is as follows\n");
            display(p3);
            break;

     case 2:
            p3 = mul(p1,p2);
            printf("\n The multiplication of the polynomials is as follows\n");
            display(p3);
            break;

     case 3:
            result = Eval(p1);
            printf("\n The Evaluation of 1st polynomial is :  %d",result);
            result=Eval(p2);
            printf("\n The Evaluation of 2nd polynomial is : %d",result);
            break;

     case 4:
            break;
    }
}while(choice!=4);

return 0;
}

p *create()
{
   p *temp, *start=NULL,*last;
   int Exp,Coef,flag;
   char ans;

   printf("Enter the polynomial in descending order of exponent\n");

  do
   {
            printf("\nEnter the Coefficient and Exponent of a term :");
            scanf("%d%d",&Coef,&Exp);

            temp = ( p *) malloc( sizeof(p) );
            if ( temp == NULL )
            printf("Unable to allocate memory\n");

            temp -> coef = Coef;
            temp -> exp = Exp ;
            temp -> next = NULL;

            if ( start==NULL)
            {
                        start = temp;
                        last = start;
                        last->next=start;
            }
            else
            {
                        last ->next = temp;
                        last = temp;
                        last->next=start;
            }

            printf("\n Do you want to Add more Terms(y/n)?");
            ans=getch();

      }while(ans=='y');

return (start);
}

void display(p *start)
{
            p *temp ;
            temp = start;
            if ( temp == NULL )
            {
                        printf("The polynomial is empty\n");
                        return;
            }

            while ( temp ->next!=start)
            {
                        printf(" %dx^%d+",temp->coef,temp->exp);
                        temp = temp -> next;
            }

            printf(" %dx^%d",temp->coef,temp->exp);
            getch();
}

p *add(p* start1, p* start2)
{
            p *P1, *P2, *P3, *start3,*temp;
            char ch;
            int Coef;
            P1 = start1;
            P2 = start2;
            P3 = ( p * ) malloc(sizeof( p ) );
            if (P3 == NULL )
            printf("Unable to allocate memory\n");

            start3 = P3;
            while ( P1->next != start1 && P2->next != start2 )
            {
                        if(P1->exp==P2->exp)
                        {
                                    Coef = P1->coef + P2->coef;
                                    P3->exp=P1->exp;
                                    P3->coef=Coef;
                                    P1 = P1->next;
                                    P2 = P2->next;
                        }
                        else if(P1->exp < P2->exp)
                        {
                                    Coef = P2 -> coef;
                                    P3->coef= Coef;
                                    P3->exp=P2->exp;
                                    P2 = P2 -> next;
                        }
                        else if(P1->exp>P2->exp)
                        {
                                    Coef = P1 -> coef;
                                    P3->coef=Coef;
                                    P3->exp=P1->exp;
                                    P1 = P1 -> next;
                        }

                        temp=P3;
                        P3->next=(p*)malloc(sizeof(p));
                        P3=P3->next;
                        P3->next=start3;
            }

           while (P1!=start1)
            {
                        if(P1->exp==P2->exp)
                        {
                                    Coef = P1->coef + P2->coef;
                                    P3->exp=P1->exp;
                                    P3->coef=Coef;
                                    P1 = P1->next;
                                    P2 = P2->next;
                        }
                        else
                        {
                                    P3->coef=P1->coef;
                                    P3->exp=P1->exp;
                                    temp=P3;
                                    P3->next=( p * ) malloc(sizeof( p ));
                                    P3=P3->next;
                                    P3->next=start3;
                                    P1 = P1 -> next;
                        }

                        temp=P3;
                        P3->next=( p * ) malloc(sizeof( p ));
                        P3=P3->next;
                        P3->next=start3;
            }

            while (P2 != start2 )
            {
                        if(P1->exp==P2->exp)
                        {
                                    Coef = P1->coef + P2->coef;
                                    P3->exp=P1->exp;
                                    P3->coef=Coef;
                                    P1 = P1->next;
                                    P2 = P2->next;
                        }
                        else
                        {
                                    P3->coef=P2->coef;
                                    P3->exp=P2->exp;
                                    temp=P3;
                                    P3->next=( p * ) malloc(sizeof( p ));
                                    P3=P3->next;
                                    P3->next=start3;
                                    P2 = P2 -> next;
                        }

                        temp=P3;
                        P3->next=( p * ) malloc(sizeof( p ));
                        P3=P3->next;
                        P3->next=start3;
            }
            P3->next=NULL;
            temp->next=start3;

            free(P3);

return(start3);
}

p* mul(p* start1, p* start2)
{
            p *p1, *p2, *p3, *dummy, *temp,*start3,*New ;
            int Exp, flag;
            int Coef;
            p1 = start1;
            p3 = ( p * ) malloc(sizeof( p ) );
            p3-> next = p3; /*single circu. node*/
            start3=p3;
            temp=p3;

            do
            {
                        p2 = start2;
                        do
                        {
                                     Coef = p1->coef * p2->coef;
                                     Exp = p1->exp + p2 ->exp;
                                     flag = 0;
                                     if ( flag==1)
                                                temp->coef = temp ->coef + Coef;
                                     else
                                     {
                                                New = ( p *) malloc ( sizeof( p));
                                                New->exp = Exp;
                                                New->coef = Coef;
                                                New->next = New; /*creating a CLL for single node*/
                                                p3 -> next = New;
                                                p3 = New;
                                     }

                                     p2 = p2 -> next;
                        }while ( p2 != start2);
                        p1 = p1 -> next;
            }while ( p1 !=start1 );

            start3=temp->next;
            p3 ->next = start3;/*making the third poly.circular*/
            p3 = start3;/*reaching at the starting node of 3rd poly.*/
            free ( temp);

return(p3);
}

int Eval(p* start1)
{
            p *P1;
            int x;
            int sum=0.0,Coef,Exp;
            printf("\n Enter the value of variable x : ");
            scanf("%d",&x);
            P1 = start1;

            do
            {
                        Coef=P1->coef;
                        Exp=P1->exp;
                        sum=sum+Coef*pow(x,Exp);
                        P1 = P1->next;
            }while ( P1!= start1);

return(sum);
}
