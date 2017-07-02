#include<stdio.h>
#include<stdlib.h>

typedef struct node_type
{
  int data;
   
  int level;
  struct node_type *right_link;

  struct node_typed *left_link;


}node;

typedef node *tree;
 
char*  getInput(char *ch)
{
 
 
 ch=(char*)malloc(sizeof(char)*5);
 

 scanf("%s",ch);
 
return ch;
 
 
}

tree insert_node(tree Tree, int data)
{    int level =1;
    
     //node *pointer,*parent;  
     tree temp,pointer,parent;
   if( Tree == NULL)
     {
           Tree = (tree)malloc(sizeof(node));
           Tree->data = data;
           Tree->left_link=NULL;
           Tree->right_link=NULL;
           level = 1;
          
     }
     else
     { 
         pointer = Tree;
         parent = Tree;
        while(pointer != NULL)        
        {
          if(pointer->data > data)
          { 
           level++;
           parent=pointer;
           pointer=(tree) pointer->left_link;
          }
          else
          {
            level++;
          parent = pointer;
          pointer=(tree) pointer->right_link;
          
          }
       }
       
       temp = (tree)malloc(sizeof(node));
       if(parent->data > data)
        {
           (*parent).left_link = (struct node_type*)temp;
           temp->data=data;
            temp->level = level;
             temp->left_link = NULL;
              temp->right_link = NULL;
       
        }
       else
        {
          (*parent).right_link = temp;
           temp->data=data;
            temp->level = level;
             temp->left_link = NULL;
              temp->right_link = NULL;
       
        }
       

     }
      return Tree;
}

void display_tree(tree Tree)
{       if(Tree != NULL)
       {
       display_tree((node*)Tree->left_link);
       printf("DATA = %d : LEVEL = %d \n", Tree->data,Tree->level);
       display_tree((node*)Tree->right_link);
       }



} 





int main()
{

tree root = NULL;
char *ch;
int input;

 ch= NULL;

 while(1)
{
    printf("do you want to enter data? \n");
 
    ch=getInput(ch);
    if(*ch == 'y'|| *ch == 'Y')
    { printf("you selected yes\n");
      free(ch);
      printf("input the data value");
      scanf("%d",&input);
      root=insert_node(root,input);    
     }
     else if(*ch == 'N'|| *ch == 'n')
      {  free(ch);
         if(root != NULL)
         {
          printf("starting to display\n");
         display_tree(root);
         break;
         }
      }      
           
 
}


 //root = (tree)malloc(sizeof(node));
 
 //root->data = 5;

 //printf("data = %x \n",(int)(root->data));



exit(0);
}
