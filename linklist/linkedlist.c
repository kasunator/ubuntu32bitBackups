#include <stdio.h>
#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>

typedef struct node_type
             {
                int data;
                struct node_type *link;
             
             }node;  

typedef node *list;


/*========================================================*/
/* this function prints all the nodes of the linked list */

void show_list(list head)
{
  int i =0;
   while(1)
      {  
       printf(" Node %d DATA = %d  : link= %x \n", i, (*head).data , (int)(*head).link);
       i++;
       head=(*head).link;
       if((*head).link == NULL)
        {

        printf(" Node %d DATA = %d  : link= %x \n", i, (*head).data , (int)(*head).link);
    
          break;
         }
      }
     
}






int main()
{
 int input =0;
 char *command;
  list head,tail;
  
  list temp;
/*initialize the head*/
 head = (list) malloc(sizeof(node));
 
 (*head).data = 5;

 (*head).link = NULL;
 
  tail=head;
  
 printf( "the HEAD data = %d : and lin = %x \n ", (*head).data ,(int)((*head).link));
 
 
while(1)
 {  
   command=(char*) malloc(20*sizeof(char));

   printf("do you want to add a node \n");

 scanf("%s",command);
  if(*command == 'y'|| *command == 'Y')
   { 
     printf("you said yes\n");
     printf("insert in head or tail\n");
     
      scanf("%s",command);
     if(*command == 'H' || *command == 'h')
     {
     free(command);
     temp=(list) malloc(sizeof(node));
     
     printf("input the new node value\n");
     scanf("%d",&input); 
     (*temp).data = input;
     (*temp).link=head;
     head=temp; 
     }
     else if(*command == 'T' || *command == 't')
     {
      free(command);
     temp=(list) malloc(sizeof(node));
     
     printf("input the new node value\n");
     scanf("%d",&input);
     (*tail).link=temp; 
     (*temp).data = input;
     (*temp).link=NULL;
     tail=temp;
      

     }
  
   }
   else if( *command == 'N'|| *command == 'n')
   {   
        show_list(head);
       break;

   }
 }




 

/*


 printf("enter the new data\n");
 scanf("%d", &input);
 
  temp = (node*)malloc(sizeof(node));
 
 (*temp).data = input;
 (*temp).link = &head;
 head= temp;
*/
 
 







exit(0);
}
