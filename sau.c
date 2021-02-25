#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITY 9999
#define MAX 5
static int k;
static int t;
static int count1=0;
static int count2=0;
struct node
{
char name[10];
double number;
struct node *next1;
struct node *next2;
}*head1,*tail1,*head2,*tail2;
void reserve1(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       { double ele=0;
        char a[10];
        struct node *new1;
        new1=(struct node *)malloc(sizeof(struct node));
        printf("enter the name and contact number\n");
        scanf("%s",a);
        scanf("%lf",&ele);
        strcpy(new1->name,a);
        new1->number=ele;
if(head1==NULL)
{
head1=tail1=new1;
tail1->next1=NULL;
}
else
{
new1->next1=head1;
head1=new1;
}
}
}
}

void delete1()
{
char a[10];
printf("Enter the name to be deleted\n");
scanf("%s",a);
int flag=0;
struct node *traverse1;
traverse1=head1;
if(strcmp(head1->name,a)==0)
{
flag=1;
head1=head1->next1;

}
else
{
for(traverse1=head1;traverse1->next1!=NULL;traverse1=traverse1->next1)
{
if(strcmp(traverse1->next1->name,a)==0)
{
tail1=traverse1;
tail1->next1=NULL;
}
else
{
traverse1->next1=traverse1->next1->next1;
free(traverse1);
flag=1;
break;
}
}
}
if(flag==0)
printf("name not found\n");

}
void display1()
{       FILE *fp;
struct node *traverse1=head1;
fp=fopen("op.txt","w");
while(traverse1!=NULL)
{
fprintf(fp,"YOU HAVE BOOKED SEAT FOR HUBLI TO BANGLORE\n");
printf("name: %s\n",traverse1->name);
fprintf(fp,"name: %s\n",traverse1->name);
printf("number %.0lf\n",traverse1->number);
fprintf(fp,"number:%.0lf\n ",traverse1->number);
traverse1=traverse1->next1;
}
}
void reserve2(int n)
{
    int i;
    for(i=0;i<n;i++)
    {

{
        double ele=0;
        char a[10];
        struct node *new2;
        new2=(struct node *)malloc(sizeof(struct node));
        printf("enter the name and contact number\n");
        scanf("%s",a);
        scanf("%lf",&ele);
        strcpy(new2->name,a);
        new2->number=ele;
if(head2==NULL)
 {
head2=tail2=new2;
tail2->next2=NULL;
 }
else
 {
new2->next2=head2;
head2=new2;
 }
}
}
}

void delete2()
{
char a[10];
printf("Enter the name to be deleted\n");
scanf("%s",a);
int flag=0;
struct node *traverse2;
traverse2=head2;
if(strcmp(head2->name,a)==0)
{
flag=1;
head2=head2->next2;

}
else
{
for(traverse2=head2;traverse2->next2!=NULL;traverse2=traverse2->next2)
{
if(strcmp(traverse2->next2->name,a)==0)
{
tail2=traverse2;
tail2->next2=NULL;
}
else
{
traverse2->next2=traverse2->next2->next2;
free(traverse2);
flag=1;
break;
}
}
}
if(flag==0)
printf("name not found\n");

}
void display2()
{
FILE *fp;
struct node *traverse2=head2;
fp=fopen("opp.txt","w");
while(traverse2!=NULL)
{
fprintf(fp,"YOU HAVE BOOKED SEAT FOR BANGLORE TO CHENNAI\n");
printf("name %s\n",traverse2->name);
fprintf(fp,"name:%s\n",traverse2->name);
printf("number %.0lf\n",traverse2->number);
fprintf(fp,"number %.0lf\n",traverse2->number);
traverse2=traverse2->next2;
}
}
int dijkstra1(int G[MAX][MAX],int startnode,int destnode,int u1,int d1)
{
    int fare,c=0;
int w[MAX][MAX],distance[MAX],pred[MAX];
int visited[MAX],count,mindistance,nextnode,i,j;


for(i=0;i<MAX;i++)
for(j=0;j<MAX;j++)
if(G[i][j]==0)
w[i][j]=INFINITY;
else
w[i][j]=G[i][j];


for(i=0;i<MAX;i++)
{
distance[i]=w[startnode][i];
pred[i]=startnode;
visited[i]=0;
}

distance[startnode]=0;
visited[startnode]=1;
count=1;

while(count<MAX-1)
{
mindistance=INFINITY;


for(i=0;i<MAX;i++)
if(distance[i]<mindistance&&!visited[i])
{
mindistance=distance[i];
nextnode=i;
}


visited[nextnode]=1;
for(i=0;i<MAX;i++)
if(!visited[i])
if(mindistance+w[nextnode][i]<distance[i])
{
distance[i]=mindistance+w[nextnode][i];
pred[i]=nextnode;
}
count++;
}


i=destnode;
if(i!=startnode )
{
j=i;
do
{
j=pred[j];
printf("<-%d",j);
                if(j==u1 || j==d1)
                c++;
}while(j!=startnode);

}return c;
}

void dijkstra(int G[MAX][MAX],int startnode,int destnode)
{
    int fare;
int w[MAX][MAX],distance[MAX],pred[MAX];
int visited[MAX],count,mindistance,nextnode,i,j;


for(i=0;i<MAX;i++)
for(j=0;j<MAX;j++)
if(G[i][j]==0)
w[i][j]=INFINITY;
else
w[i][j]=G[i][j];


for(i=0;i<MAX;i++)
{
distance[i]=w[startnode][i];
pred[i]=startnode;
visited[i]=0;
}

distance[startnode]=0;
visited[startnode]=1;
count=1;

while(count<MAX-1)
{
mindistance=INFINITY;


for(i=0;i<MAX;i++)
if(distance[i]<mindistance&&!visited[i])
{
mindistance=distance[i];
nextnode=i;
}


visited[nextnode]=1;
for(i=0;i<MAX;i++)
if(!visited[i])
if(mindistance+w[nextnode][i]<distance[i])
{
distance[i]=mindistance+w[nextnode][i];
pred[i]=nextnode;
}
count++;
}


i=destnode;
if(i!=startnode )
{
printf("\nDistance of %d=%d",i,distance[i]);

printf("\nPath=%d",i);


j=i;
do
{
j=pred[j];
printf("<-%d",j);
}while(j!=startnode);

        if(distance[i]<=50)
        printf("\nTotal fare is %d",distance[i]*15);

       else if(distance[i]>50 && distance[i]<=70)
            printf("\nTotal fare is %d",distance[i]*13);

        else
            printf("\nTotal fare is %d",distance[i]*11);
}
}
void dijkstra2(int G[MAX][MAX],int startnode,int destnode)
{
    int fare;
int w[MAX][MAX],distance[MAX],pred[MAX];
int visited[MAX],count,mindistance,nextnode,i,j;


for(i=0;i<MAX;i++)
for(j=0;j<MAX;j++)
if(G[i][j]==0)
w[i][j]=INFINITY;
else
w[i][j]=G[i][j];


for(i=0;i<MAX;i++)
{
distance[i]=w[startnode][i];
pred[i]=startnode;
visited[i]=0;
}

distance[startnode]=0;
visited[startnode]=1;
count=1;

while(count<MAX-1)
{
mindistance=INFINITY;


for(i=0;i<MAX;i++)
if(distance[i]<mindistance&&!visited[i])
{
mindistance=distance[i];
nextnode=i;
}


visited[nextnode]=1;
for(i=0;i<MAX;i++)
if(!visited[i])
if(mindistance+w[nextnode][i]<distance[i])
{
distance[i]=mindistance+w[nextnode][i];
pred[i]=nextnode;
}
count++;
}


i=destnode;
if(i!=startnode )
{
printf("\nDistance of node%d=%d",i,distance[i]);

printf("\nPath=%d",i);


j=i;
do
{
j=pred[j];
printf("<-%d",j);
}while(j!=startnode);

        if(distance[i]<=50)
        printf("\ntotal fare is %d",distance[i]*11);

       else if(distance[i]>50 && distance[i]<=70)
            printf("\ntotal fare is %d",distance[i]*9);

        else
            printf("\ntotal fare is %d",distance[i]*7);
}
}
//void dijkstra(int G[MAX][MAX],int startnode,int destnode);

int main()
{
    int i,j,u,d;
int ch,code,p,q;
    int u1,d1,c=0;
    FILE *fp;
int n=0;
int G[5][5]={ {0,50,60,0, 0},
                  {50, 0,40,45,0},
                  {60,40,0,40,50},
                  {0,45,40, 0, 0},
                  {0,0,50, 60, 0} };

     while(1){
    printf("_____________WELCOME TO BUS RESERVATION__________________");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t 1.TO VIEW AVAILABLE BUSES\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t 2.FOR TICKET RESERVATION\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t 3.TO CANCEL RESERVATION\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t 4.TO DISPLAY ALL RESERVATION\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t 5.TO CALCULATE SHORTEST PATH AND FARE\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t 6.EXIT\n");
printf("\n");
// scanf("%d",&d);
scanf("\n%d",&ch);

switch(ch)
{
    case 1:
            printf("****************BUS AVAILABLE*****************\n");
            printf("\t\t\t\tBUS CODE : 1200   Hubli to Banglore     Rs:1500\n\t\t\t\tBUS CODE : 1201   Banglore to Chennai   Rs:1800\n");
   fp=fopen("v.txt","w");
   fprintf(fp,"************information****************\n");
   fprintf(fp,"\t\t\t\tBUS CODE : 1200   Hubli to Banglore     Rs:1500\n\t\t\t\tBUS CODE : 1201   Banglore to Chennai   Rs:1800\n");
   printf("\n");
   fclose(fp);
            break;
case 2:
            printf("***************TICKET RESERVATION SYSTEM**************\n");
            printf("ENTER BUS CODE : \n");
            scanf("%d",&code);
            if(code==1200)
            {
                printf("Hubli to Banglore\n");
                printf("ENTER NUMBER OF SEATS TO BE RESERVED : \n");
                scanf("%d",&n);
                printf("TOTAL SEATS :30\n");
  k=30-(k+n);
                printf("AVAILABLE SEATS :%d\n",k);
if(k<=30)
                reserve1(n);
else
printf("================================================SORRY NO SEATS AVAILABLE==========================================\n");
                j=(1500*n);
                printf("total cost:%d\n",j);
                break;
            }
            else if(code==1201)
            {
                printf("Banglore to Hyderabad\n");
                printf("ENTER NUMBER OF SEATS TO BE RESERVED :\n");
                scanf("%d",&n);
                printf("TOTAL SEATS :30\n");
                t=30-(t+n);
                printf("AVAILABLE SEATS :%d\n",k);
if(t<=30)
reserve2(n);
else
printf("================================================SORRY NO SEATS AVAILABLE==========================================\n");
j=(1800*n);
                printf("TOTAL COST :%d\n",j);
                break;

            }

            else
            {

                printf("BUS NOT AVAILABLE\n");
            }
            break;
case 3: printf("ENTER BUS CODE FROM WHICH YOU WISH TO CANCEL RESERVATION\n");
scanf("%d",&q);
if(q==1200)
delete1();
else
delete2();
break;
case 4:
printf("Enter the code of the bus to display details\n");
scanf("%d",&p);
if(p==1200)
display1();
else
display2();
break;
/*case 5:dijkstra(G,u,d);
               break;*/

case 5:printf("**********The Hubli-Dharwad City********\n\n");
//printf("enter the details of customer 2\n");
printf("0:Railway Station     1:Gokul Road      2:Hosur       3:Dharwad        4:BVB\n\n");
           printf("\nEnter the source:");
      scanf("%d",&u1);
           printf("\nEnter the destination:");
      scanf("%d",&d1);
      int mode=1;
      printf("\nEnter mode of travelling:  1:Private  2:Sharing");
      scanf("%d",&mode);
      dijkstra(G,u1,d1);
        if(mode==2){
            printf("\nOops! Sharing service not available. Try again later.\n");
            break; }
            break;
        /*else{
              printf("Enter 1  To Book \n \t 2 To Exit");
              int choicein;
              scanf("%d",&choicein);
              if(choicein == 1)
              {
                 
              }
            //printf("The details of customer 2:\n");
            //dijkstra2(G,u1,d1);*/
        // }
        case 6:exit(0);
break;
default:printf("wrong choice\n");
    }
     }
    printf("\nThank You! Come again\n\n");
   return 0;

}