/* This is the sample sparse.c file that implements functions defined in the 
	sparse.h file. You should implement the other functions in this file.
   You can also define new functions and structures here, but they will not be
	"seen" or used outside this file (e.g. you cannot use them in p2.c). 

								Gang Qu
								April 12, 2025
April 20: code is cleaned (most of printf() and fprintf()).
          show_list() has been modified to show the position of each entry
          in the show_list(), do-while loop is replaced by while() loop for
                the case of an empty list (non-NULL ROOT)

*/

#include<stdio.h>
#include<stdlib.h>
#include "sparse.h"

ENTRY * make_node (int r, int c, int v)
{ ENTRY *temp;
  if (r<0 || c<0 || v==0)		// verify input values 
    return NULL;
  temp = NEW(ENTRY);
  if (temp != NULL)
  { temp->val = v;
    temp->row = r;
    temp->col = c;

    temp->left = NULL;
    temp->right = NULL;
    temp->up = NULL;
    temp->down = NULL;
    temp->info = NULL;
    temp->next = NULL;
  }
  return temp;
}

ROOT * make_root (void)
{ ROOT  *temp;
  temp = NEW(ROOT);
  if (temp != NULL)
  { temp->head = NULL;
    temp->num = 0;
    temp->info = NULL;
  }
  return temp; 
}

void insert_at_tail (ROOT *M, ENTRY *e)
{ ENTRY *tmp;

  if (M == NULL) return;
  if (M->head == NULL) 
  { M->head = e;
    M->num = 1;
    return;
  } 
  
  tmp = M->head;
  while (tmp->next != NULL) 
    tmp = tmp->next;
  tmp->next = e;
  e->next = NULL;
  M->num++;
}


void show_list (ROOT *M, FILE *F)
{ ENTRY *temp;
  int i=0;				// 5 values per line

  if (M != NULL)
  { 
    fprintf(F, "matrix at %p ...\n", M);
    temp = M->head;
    while (temp != NULL) 
    { fprintf(F, "%5d (%d,%d) ", temp->val, temp->row, temp->col);
       temp = temp->next;
      i++;
      if (i == 5)
      {	fprintf(F, "\n");
        i = 0;
      }
    } // while (temp != NULL);
// the previous do-while loop seg fault when the list is empty
  }
  if (i!=0) 
    fprintf(F, "\n");
}


void  read_input(FILE *F, ROOT *M, FILE *G)
{ ENTRY *tmp;
  int r, c, v;
  
  if (M == NULL)
  { M = make_root();
    if (M == NULL)
    { printf("No space left. Fail to store data.\n");
      exit(0);
    }
  }

  fprintf(G, "Reading entry from %p ... \n", F);
  while(fscanf(F, "%d %d %d", &r, &c, &v) != EOF)
  { tmp = make_node(r, c, v);
    if (tmp != NULL)			// check whether node is made or not
      insert_at_tail (M, tmp);
  }
  fprintf(G, "%ld entries stored in matrix at %p.\n", M->num, M);
}

/*search function is used to find the value k in M and then it is written to file F
 this is accomplished my iterating through the linked list untill the NULL pointer is reached
starting at root M, if the value of k is found, it is writen to the output file .*/
void search (ROOT *M, int k, FILE *F){
  fprintf(F, "search %d in matrix at %p ...\n",k, M);
  ENTRY *temp;
  temp = M -> head;
  while (temp -> next){
    if ((temp -> val) == k){
      fprintf(F, "%d %d\n",temp -> row,temp->col);
    }
    temp = temp -> next;
    if ((temp -> next) == NULL){
      if ((temp -> val) == k){
        fprintf(F, "%d %d\n",temp -> row,temp->col);
      }
      break;
    }
  }
  return;
}
/*finds the maximum value in the linked list,by iterating through the entire list 
until it reaches the null value */
void find_max(ROOT *M, FILE *F){
  int max_val;
  fprintf(F, "find max in matrix %p ...\n",M);
  ENTRY *temp;
  temp = M -> head;
  max_val = temp ->val;
  int max_row = 0, max_col = 0;
  if (temp == NULL) {  //checks if the matrix is empty 
    fprintf(F, "Matrix is empty.\n");
    return;
  }
  while (temp != NULL){
    if((temp -> val) > max_val){
      max_val = temp -> val;
      max_row = temp ->row;
      max_col = temp ->col;
    } 
    temp = temp -> next;
    if (temp == NULL){
      break;
    }
  }
  fprintf(F,"maximum %d at position (%d,%d)",max_val,max_row,max_col);
  return;
}
/*this is a helper function that iterates through the second list in the addition function
to find if the corresponding value exists in the other linked list it returns a zero if the sum is zero other 
wise it returns a NULL value
*/
ENTRY * find_add_val(int r, int c,int value, ROOT *M){
  ENTRY *node,* temp, *zero_node;
  int flag = 0; //using flag variables to check if the value is zero 
  temp = M -> head;
  while (temp != NULL){
    if ((temp -> col == c) && (temp -> row == r)){ //checks if the corresponding valiue exists 
       if (((temp -> val) + value) != 0){// makes sure it is not zero
        flag = 1;
        node = make_node(r,c,((temp -> val)+value));
        break;
       } 
       if (((temp -> val) + value) == 0){
        zero_node = NEW(ENTRY);
        if (zero_node != NULL)
            { zero_node->val = 0;
              zero_node->row = r;
              zero_node->col = c;

              zero_node->left = NULL;
              zero_node->right = NULL;
              zero_node->up = NULL;
              zero_node->down = NULL;
              zero_node->info = NULL;
              zero_node->next = NULL;
            }
            return zero_node;

      }
    }
    temp = temp -> next;
  }
  if (flag == 0){
    return NULL;
  } 
  return node;
}
/*this is just a helper function used to display the matrix on the terminal*/
void show_matrix(ROOT* M){
  ENTRY *temp;
  temp = M -> head;
  printf("matrix\n");
  while (temp != NULL){
    
    printf("%d(%d,%d)\n",temp->val, temp->row, temp ->col);
    if (temp ->up != NULL){
      printf("up: %d,",temp ->up->val);
    }if (temp ->down != NULL){
      printf("down: %d,", temp -> down->val);
    } if (temp ->right != NULL){
      printf("right: %d,", temp -> right->val);
    }if (temp ->left != NULL){
      printf("left: %d,", temp-> left->val);
    }
    printf("\n");
    temp = temp ->next;
  }
}
/* takes the first linked list and checks if there is a corresponding value in the second linked list by calling 
find_add_val, if there is a value it is added and either the value or null or a zero value is returned.
after checking for the corresponding values the function considers the nodes which are not common and treats it 
as zero so that the two matrices can be added with the correct dimensions.
*/
ROOT * addition (ROOT *M1, ROOT *M2, FILE *F){
  ROOT *add_matrix;
  ENTRY *temp, *temp_in, *node, *zero_node;
  add_matrix = make_root();
  if (M1 == NULL || M2 == NULL){
    return NULL;
  }
  temp = M1 -> head;
  if (temp == NULL){
    if ((M2 -> head) != NULL){
      return M2;
    }
    else{
      return NULL;
    }
  }
  
  if (add_matrix != NULL){
    while (temp != NULL){
      //this checks if node is zero not sum is zer -- so check for that
      temp_in = find_add_val(temp -> row,temp -> col,temp->val,M2);
      if (temp_in == NULL){ //means there is no corresponding value
        if ((temp ->val) != 0){
          zero_node = make_node(temp -> row,temp -> col,temp->val);
          if (add_matrix ->head == NULL){
            node = zero_node;
            add_matrix ->head = node;
          }else{
            node ->next = zero_node;
            node = node ->next;
          } 
        }
        add_matrix -> num = add_matrix -> num + 1;
      }
      if (temp_in != NULL){  //corresponding value exists
        if (temp_in -> val == 0){
          temp = temp -> next;
          continue;
        }
        if (add_matrix ->head == NULL){
          node = temp_in;
          add_matrix ->head = node;
        } else{
          node ->next = temp_in;
          node = node ->next;
        } 
      }
      temp = temp -> next;
    }
  }
  node -> next = NULL;
  ENTRY *temp_check,*temp_check_1,*new_nodes_in_m2,*check_zero;
  temp_check = M2 -> head;
  temp_check_1 = M1 -> head;
  int flag = 0;
  while (temp_check != NULL) {
    flag = 0;
    temp_check_1 = M1->head;

    while (temp_check_1 != NULL) {
      
        if ((temp_check->row == temp_check_1->row) && (temp_check->col == temp_check_1->col)) { //
           flag = 1;
        }
        temp_check_1 = temp_check_1->next;
    }

    if (flag == 0) {
        new_nodes_in_m2 = make_node(temp_check->row, temp_check->col, temp_check->val);
        insert_at_tail(add_matrix, new_nodes_in_m2);
    }

    temp_check = temp_check->next;
  }

  return add_matrix;
}
/*first -1 is multipled to M2 and a new linked list is made. this liked list is passed through the addition 
function so that the two are subtracted, since A - B = A +(-B)*/
ROOT * subtraction (ROOT *M1, ROOT *M2, FILE *F){
  ROOT *sub,*negative_m2;
  ENTRY *temp,*negative_m2_node;
  sub = make_root();
  negative_m2 = make_root();
  temp = M2 -> head;
  if (M1 == NULL || M2 == NULL){
    return NULL;
  }
  while (temp != NULL){
    negative_m2_node= make_node(temp->row, temp->col, (-1*(temp->val))); 
    insert_at_tail(negative_m2,negative_m2_node);
    temp = temp->next;
  }
  sub = addition(M1,negative_m2,F);
  return sub;
}

int check_row(ROW_HEAD * R,int row_val){ //checks if the row node is there in the matrix
    ROW * temp;
    if (R -> head == NULL){
      return -1;
    }
    temp = R -> head;
    while (temp != NULL){
      if (temp ->val == row_val){
        return 1;
      }
      temp = temp -> next;
    }
    return 0;
}
int check_col(COL_HEAD * C,int col_val){ //checks if the row node is there in the matrix
  COL * temp;
  if (C -> head == NULL){
    return -1;
  }
  temp = C -> head;
  while (temp != NULL){
    if (temp ->val == col_val){
      return 1;
    }
    temp = temp -> next;
  }
  return 0;
}
ROW * create_row_node(){
    ROW * new_row;
    new_row = NEW(ROW);
    new_row ->head = NULL;
    new_row ->next = NULL;
    new_row -> val = 0;
    return new_row;
}

void insert_left_right(ROW_HEAD* r_head,ENTRY *node){ //functions to update the values of left and right
   int node_col_val = node -> col;
   int node_row_val = node -> row;
   int r_check = check_row(r_head,node_row_val);
   ROW *temp_row;
   if (r_check == -1){ //head is null
      temp_row = create_row_node();
      temp_row -> head = node;
      temp_row -> val = node_row_val;
      r_head -> head = temp_row;
      r_head -> val = 1;
      // printf("created a node!\n");
      return;
   }
   temp_row = r_head -> head; //temp_row points to the first row node
   if (r_check == 0){ //row node is not there in the row head linked list 
    while(temp_row != NULL){
      if (temp_row -> next == NULL){
        ROW *tail_node;
        tail_node = create_row_node();
        tail_node -> head = node;
        tail_node -> val = node_row_val;
        temp_row -> next = tail_node;
        r_head -> val = r_head -> val + 1;
        // printf("added row node at the end of the row node link!\n");
        return;
      }
      temp_row = temp_row -> next;
    }
   }
   if (r_check == 1){
    while (temp_row != NULL){
      if (temp_row -> val == node_row_val){ //first find the same row as the value 
        ENTRY *temp_entry;
        temp_entry = temp_row -> head;
        if ((temp_entry -> col) > (node -> col)){ //check if the column is less than the first value
          temp_row -> head = node;
          node -> right = temp_entry;
          temp_entry -> left = node;
          return;
        }
        while (temp_entry != NULL){
          if (temp_entry -> right != NULL){ //there is a next value so that we can compare 
            if (((temp_entry -> col) < (node -> col)) && ((temp_entry -> right -> col) > (node -> col))){ //lies in between values
              ENTRY *next_right;
              next_right = temp_entry -> right;
              temp_entry -> right = node;
              node -> left = temp_entry;
              node -> right = next_right;
              next_right -> left = node;
              return;
            }
          }
          if (temp_entry -> right == NULL){
            temp_entry -> right = node;
            node -> left = temp_entry;
            return;
          }
          temp_entry = temp_entry -> right;
        }
      }
      temp_row = temp_row -> next;
    }
    return;
   }
}
COL * create_col_node(){
  COL * new_col;
  new_col = NEW(COL);
  new_col ->head = NULL;
  new_col ->next = NULL;
  new_col -> val = 0;
  return new_col;
}

void insert_up_down(COL_HEAD* c_head,ENTRY *node){ //functions to update the values of left and right
  int node_col_val = node -> col;
  int node_row_val = node -> row;
  int c_check = check_col(c_head,node_col_val);
  COL *temp_col;
  if (c_check == -1){ //head is null
     temp_col = create_col_node();
     temp_col -> head = node;
     temp_col -> val = node_row_val;
     c_head -> head = temp_col;
     c_head -> val = 1;
    //  printf("created a node!\n");
     return;
  }
  temp_col = c_head -> head; //temp_row points to the first row node
  if (c_check == 0){ //row node is not there in the row head linked list 
   while(temp_col != NULL){
     if (temp_col -> next == NULL){
       COL *tail_node;
       tail_node = create_col_node();
       tail_node -> head = node;
       tail_node -> val = node_col_val;
       temp_col -> next = tail_node;
       c_head -> val = c_head -> val + 1;
       return;
     }
     temp_col = temp_col -> next;
   }
  }
  if (c_check == 1){
   while (temp_col != NULL){
     if (temp_col -> val == node_col_val){ //first find the same row as the value //checked till here 
       ENTRY *temp_entry;
       temp_entry = temp_col -> head;
       if ((temp_entry -> row) > (node -> row)){ //check if the column is less than the first value
         temp_col -> head = node;
         node -> down = temp_entry;
         temp_entry -> up = node;
         return;
       }
       while (temp_entry != NULL){
         if (temp_entry -> down != NULL){ //there is a next value so that we can compare 
           if (((temp_entry -> row) < (node -> row)) && ((temp_entry -> down -> row) > (node -> row))){ //lies in between values
             ENTRY *next_down;
             next_down = temp_entry -> down;
             temp_entry -> down = node;
             node -> up = temp_entry;
             node -> down = next_down;
             next_down -> up = node;
             return;
           }
         }
         if (temp_entry -> down == NULL){
           temp_entry -> down = node;
           node -> up = temp_entry;
           return;
         }
         temp_entry = temp_entry -> down;
       }
     }
     temp_col = temp_col -> next;
   }
   return;
  }
}
ROOT * form_matrix(ROOT *M){
    MATRIX_HEAD *mat_head;
    ROW_HEAD *r_head; //create row head 
    COL_HEAD *c_head; //create column head
    mat_head = NEW(MATRIX_HEAD);
    r_head = NEW(ROW_HEAD);
    r_head ->head = NULL;
    r_head ->val = 0;
    c_head = NEW(COL_HEAD);
    c_head -> head = NULL;
    c_head -> val = 0;
    mat_head -> row_head = r_head;
    mat_head -> col_head = c_head;
    ENTRY *temp;
    temp = M -> head;
    
    while (temp != NULL){
      insert_left_right(r_head,temp);
      insert_up_down(c_head,temp);
      temp = temp -> next;
    } 
    show_matrix(M);
    return M;
}

ROOT * multiplication (ROOT *M1, ROOT *M2, FILE *F){
  M1 = form_matrix(M1);
  M2 = form_matrix(M2);
  if (M1 == NULL || M2 == NULL){

  }
}