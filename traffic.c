#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct vehicle{
	int vehicle_number;
	struct vehicle* next_vehicle;
};
void append ( struct vehicle**, int ) ;
void display ( struct vehicle* ) ;
void reverse (struct vehicle**);

int main() {
	struct vehicle*p;
	p=NULL;
	int n,x=0;            
	do {
	printf("1.Insert\n2.Display\n3.Reverse\n4.Exit\n");
                	printf("Enter your choice :\n");
                	scanf("%d",&x);
	switch(x)
                 	{
                		case 1:
			printf("Enter the vehicle number\n");
			scanf("%d",&n);
			append(&p,n);
                			break;
                		case 2:
			if(p==NULL)
			{

				printf("Route is clear");
			}
			else
			{
				printf("The vehicles in the route are \n");
				display(p);
			}
                			printf("\n");
			break;	
                		case 3:
                
			if(p==NULL)
			{
				printf("There are no vehicle to redirect");
			}
			else
			{
				printf("The vehicles in the route after redirecting\n");
				reverse(&p);
				display(p);
			}
			printf("\n");
			break;
		case 4:
               			printf("Task accomplished\n");
			break;

	}} while(x!=4);

	return 0;
}


void append ( struct vehicle**q, int num ) {
// Fill in the code here
struct vehicle *nn=(struct vehicle*)malloc(sizeof(struct vehicle));
nn->vehicle_number=num;
nn->next_vehicle=NULL;
if(*q==NULL)
*q=nn;
else
{
    struct vehicle *temp=*q;
    while(temp->next_vehicle!=NULL)
    {
        temp=temp->next_vehicle;
    }
    temp->next_vehicle=nn;
}
}

void display ( struct vehicle *q ) {

while(q!=NULL)
{
    printf("%d ",q->vehicle_number);
    q=q->next_vehicle;
}
}
void reverse ( struct vehicle**x ) {
    
struct vehicle *temp=*x,*next=NULL,*prev=NULL;
while(temp!=NULL)
{
  next=temp->next_vehicle;
  temp->next_vehicle=prev;
  prev=temp;
  temp=next;
    
}
*x=prev;

}
