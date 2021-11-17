#include<stdio.h>
#include<stdlib.h>
#define MAX 777
 struct node
               {
                int u;
		int d;
                struct node *next;
               };
  struct node *start=NULL,*ptr,*pos;
int n;

void insert(int u, int d)
 {
 
   ptr=(struct node *) malloc(sizeof(struct node));
   ptr->u= u;
   ptr->d= d;
  if(start==NULL)
                {
                 ptr->next=start;
                 start=ptr;
                } 
   else
       {
        
        ptr->next=start;
        start=ptr;
       } 
 }

void delete(int u)
  {
  int i,j=1;
  
  ptr=start;
  

  if(ptr->u==u)

	{
	  
	  start= start->next;
	  
	}
 else{
       
  	while(ptr->u != u && ptr != NULL)
                             {
                              pos=ptr; 
                              ptr=ptr->next;
                              
                             }
        if(ptr->next==NULL)
		{
		  
		  pos->next= ptr->next;
		}
        else{ 
  		pos->next=ptr->next;
  		ptr=ptr->next;
  		
   	    } 
    }

}

void modify(int u, int v) 

		{
		
		  
                  ptr=start;
		  int flag=1;
		while(flag != 0)
			{
				
			  if((ptr->u == u)) 
			   {	
			
				ptr->d=v;
				
				flag = 0;
				break;
			   }
			 ptr=ptr->next;
			}
		}


int minimum() {

		ptr= start;
		int u;
		int min=MAX;
	
		while(ptr !=NULL)
			{
				if(ptr->d < min)
					{
					  min= ptr->d;
					  u=ptr->u; 
					}
				ptr=ptr->next;
			}
		return u;
	}

void dijkstra(int G[][10],int distance[])

	{
		int u,new;		
		while(start != NULL)

			{
				u= minimum();
				delete(u);
				for (int i=0; i<n; i++)
					{
					new = G[u][i]+ distance[u];
					if(distance[i] > new)
						{
							distance[i]=new;
							modify(i,new);
						}					
					 	
			
					}
						
			 	
			}   
	}

int main()

	{
		int i,j;
		int G[10][10];
		int distance[10];

		printf("Please enter the number of vertices in the graph: ");
		scanf("%d",&n);

		printf(" KIndly enter the graph in adjacency matrix format: ");

		for(i=0;i<n;i++)
			
			{
			 printf("\n");
       			  for(j=0;j<n;j++)
				scanf("%d",&G[i][j]);
			}


		insert(0,0);
		distance[0]=0;
		for(i=1; i<n; i++)
			{
				distance[i]=MAX;
				insert(i, MAX);
			}

		dijkstra(G,distance);

		for(i=0; i<n; i++)
			{
				printf(" %d ", distance[i]);
			}

		
				


	}
