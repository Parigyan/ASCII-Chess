/*Copyright 2012 Parigyan Chandra Goyal & Sharat Shankar*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>

#define  mark 1000

typedef struct {
    int i, j, k, l, eval;
    char side;
    char ent1;
} list_elm;

typedef struct node {
    struct node *head;
    list_elm* elist;
    struct node* array[100];
    int dcntr;/*to know how many times our king can be killed{ d = defeat}*/
    int vcntr;
    int max_val;
    int min_val;
} node;

int compute(char ent1,int i1,int j1,int k1,int l1,int cond,char chess[2][8][8]);

void printing(char chp[2][8][8]);

void PawnAI(char swap[2][8][8], char side, int i,int j, node* root);
void KnightAI(char swap[2][8][8], char side, int i, int j, node* root);
void BishopAI(char swap[2][8][8],char side, int i, int j, node* root);
void RookAI(char swap[2][8][8], char side, int i, int j, node* root);
void QueenAI(char swap[2][8][8], char side, int i, int j, node* root);
void KingAI(char swap[2][8][8], char side, int i, int j, node* root);
void common_init(int i1, int j1, int k1, int l1, char swap[2][8][8], node *root,char play_side);


void assign_ent(char side, node* branch, char swap[2][8][8])
{
    int i,j=0;

/*    printf("\n\n\n\n");
    printing(swap);*/

    for(i;i<=7;i++)
    {
      j=0;
      for(j;j<=7;j++)
      {
         if(swap[1][i][j] == side)
         {
            char ent = swap[0][i][j];
            switch(ent)
            {
               case '1':
                        PawnAI(swap,side,i,j,branch);
			break;
               case '2':
                        KnightAI(swap,side,i,j,branch);
			break;
               case '4':
                        BishopAI(swap,side,i,j,branch);
			break;
               case '5':
                        RookAI(swap,side,i,j,branch);
			break;
               case '7':
			QueenAI(swap,side,i,j,branch);
			break;
               case '9':
                        KingAI(swap,side,i,j,branch);
			break;

               default: break;
            };
         }
      };
    };
}

void PawnAI(char swap[2][8][8], char side, int i,int j, node* root)
{
    printf("pawn %d %d %c\n",i,j,side);
    int outer;
    int inner;
    if(side== '1')
    {
       int moves[8]={i+1,j,i+2,j,i+1,j+1,i+1,j-1};
       outer=0;
       inner=1;
       for(outer;outer<=6; outer+=2)
       {
          if(moves[outer]>7 || moves[outer]<0)
          {
             moves[outer] = mark;
             moves[outer+1] = mark;
          }
          
          if(moves[inner]>7 || moves[inner]<0)
          {
             moves[outer] = mark;
             moves[inner] = mark;
          }

          if(moves[outer]!= mark)
          {
             int k,l;
             k = moves[outer];
             l = moves[inner];
           /*  printf("human pawn common_init k=%d l=%d\n",k,l);*/
             common_init(i,j,k,l,swap,root,side);
          }

          inner+=2;
       };


    }

    if(side == '2')
    {
       int moves[8] = {i-1,j,i-2,j,i-1,j+1,i-1,j-1};
       outer =0;
       inner =1;
       for(outer;outer<=6; outer+=2)
       {
          if(moves[outer]>7 || moves[outer]<0)
          {  
             moves[outer] = mark;
             moves[outer+1] = mark;
          }

          if(moves[inner]>7 || moves[inner]<0)
          {  
             moves[outer] = mark;
             moves[inner] = mark;
          }

          if(moves[outer]!= mark)
          {  
             int k,l;
             k = moves[outer];
             l = moves[inner];
/*             printf("computer pawn common_init k=%d l=%d\n",k,l);*/
             common_init(i,j,k,l,swap,root,side);
          }

          inner+=2;
       };

    }
}

void KnightAI(char swap[2][8][8], char side, int i, int j, node* root)
{
    printf("knight %d %d %c\n",i,j,side);
    int moves[16] = {i+2,j-1,i+2,j+1,i-2,j-1,i-2,j+1,i+1,j+2,i+1,j-2,i-1,j+2,i-1,j-2};
    int outer = 0;
    int inner =1;

    for(outer;outer<=14; outer+=2)
    {
      if(moves[outer]>7 || moves[outer]<0)
      {  
         moves[outer] = mark;
         moves[outer+1] = mark;
      }

      if(moves[inner]>7 || moves[inner]<0)
      {  
         moves[outer] = mark;
         moves[inner] = mark;
      }

      if(moves[outer]!= mark)
      {  
         int k,l;
         k = moves[outer];
         l = moves[inner];
         common_init(i,j,k,l,swap,root,side);
      }

      inner+=2;
    };
}

void BishopAI(char swap[2][8][8],char side, int i, int j, node* root)
{
    printf("bishop %d %d %c\n",i,j,side);
    int moves[56];
    int i1=i;
    int j1=j;
    int outer =0;
    int inner =1;

    for(outer; outer<=12; outer+=2)
    {
       moves[outer] = i1+1;
       moves[inner] = j1+1;
       i1++;
       j1++;
       inner+=2;
    };

    for(outer; outer<=26; outer+=2)
    {
       moves[outer] = i1+1;
       moves[inner] = j1-1;
       i1++;
       j1--;
       inner+=2;
    };

    for(outer;outer<=40; outer+=2)
    {
       moves[outer] = i1-1;
       moves[inner] = j1+1;
       i1--;
       j1++;
       inner+=2;
    };

    for(outer; outer<=54; outer+=2)
    {
       moves[outer] = i1-1;
       moves[inner] = j1-1;
       i1--;
       j1--;
       inner+=2;
    };

    outer=0;
    inner=1;
    for(outer;outer<=54; outer+=2)
    {
      if(moves[outer]>7 || moves[outer]<0)
      {
         moves[outer] = mark;
         moves[outer+1] = mark;
      }

      if(moves[inner]>7 || moves[inner]<0)
      {
         moves[outer] = mark;
         moves[inner] = mark;
      }

      if(moves[outer]!= mark)
      {
         int k,l;
         k = moves[outer];
         l = moves[inner];
         common_init(i,j,k,l,swap,root,side);
      }

      inner+=2;
    };            

}


void RookAI(char swap[2][8][8], char side, int i, int j, node* root)
{
    printf("rook %d %d %c\n",i,j,side);
    int moves[56];
    int i1,i2,i3,i4 = i;
    int j1,j2,j3,j4 = j;
    int outer = 0;
    int inner =1;

    for(outer; outer<=54; outer+=8)
    {
       moves[outer] = i1+1;
       moves[inner] = j1+1;
       i1++;
       j1++;

       moves[outer+2] = i2+1;
       moves[inner+2] = j2-1;
       i2++;
       j2--;
 
       moves[outer+4] = i3-1;
       moves[inner+4] = j3+1;
       i3--;
       j3++;

       moves[outer+6] = i4-1;
       moves[inner+6] = j4-1;
       i4--;
       j4--;

       inner+=8;
    };
   
    outer = 0;
    inner = 1;
    for(outer;outer<=54; outer+=2)
    {
      if(moves[outer]>7 || moves[outer]<0)
      {
         moves[outer] = mark;
         moves[outer+1] = mark;
      }

      if(moves[inner]>7 || moves[inner]<0)
      {
         moves[outer] = mark;
         moves[inner] = mark;
      }

      if(moves[outer]!= mark)
      {
         int k,l;
         k = moves[outer];
         l = moves[inner];
         common_init(i,j,k,l,swap,root,side);
      }

      inner+=2;
    };            
}

void QueenAI(char swap[2][8][8], char side, int i, int j, node *root)
{
    printf("queen %d %d %c\n",i,j,side);
    BishopAI(swap,side,i,j,root);
    RookAI(swap,side,i,j,root);
    printf("queen ends %d %d %c\n",i,j,side);
}

void KingAI(char swap[2][8][8],char side, int i, int j,node *root)
{
    printf("king %d %d %c\n",i,j,side);
    int moves[16] = {i+1,j,i+1,j+1,i+1,j-1,i,j-1,i,j+1,i-1,j,i-1,j-1,i-1,j+1};
    int outer = 0;
    int inner =1;

    for(outer;outer<=14; outer+=2)
    {   
      if(moves[outer]>7 || moves[outer]<0)
      {
         moves[outer] = mark;
         moves[outer+1] = mark;
      }

      if(moves[inner]>7 || moves[inner]<0)
      {
         moves[outer] = mark;
         moves[inner] = mark;
      }

      if(moves[outer]!= mark)
      {
         int k,l;
         k = moves[outer];
         l = moves[inner];
         common_init(i,j,k,l,swap,root,side);
      }

      inner+=2;
    };
 
}

void common_init(int i1, int j1, int k1, int l1, char swap[2][8][8], node *root,char play_side)
{
    char init_side = swap[1][i1][j1];
    char init_ent  = swap[0][i1][j1];
    char finl_side = swap[1][k1][l1];
    char finl_ent  = swap[0][k1][l1];

    int error = compute(init_ent, i1, j1, k1, l1, 1, swap);
    printf("error %d    ",error);

    if(error == 0)
    {
       list_elm* list = (list_elm*)malloc(sizeof(list_elm));
       list->i = i1;
       list->j = j1;
       list->k = k1;
       list->l = l1;

       node* branch = (node*)malloc(sizeof(node));
       branch->head = root;
       branch->elist = list;
       branch->dcntr = 0;
       branch->vcntr = 0;
       branch->max_val = 0;
       branch->min_val = 0;
       int z =0; int c= 0;
       for(z; z<=99; z++)
       {
          branch->array[z] =NULL;
          if(root->array[z] == NULL && c==0)
          {
             root->array[z] = branch; /*this is because we want the first NULL entry */
             c =1;
          }
       };

       int defeat =0;
       int victory=0;
       int val =0;
       char ent = '\0';
       char side ='\0';
       z=0 ;c= 0;
       for(c; c<=7; c++)
       {
         z=0;
         for(z;z<=7;z++)
         {
            ent  = swap[0][c][z];
            side = swap[1][c][z];

            switch(ent)
            {
              case'1':
                    {
                     if(side == '1')
                        val = val-1;
                     else if(side == '2')
                        val =val+1;
                     break;
                    }

              case'2':
                    {
                     if(side == '1')
                        val = val-2;
                     else if(side == '2')
                        val =val+2;
                     break;
                    }
              case'4':
                    {
                     if(side == '1')
                        val = val-4;
                     else if(side == '2')
                        val =val+4;
                     break;
                    }
              case'5':
                    {
                     if(side == '1')
                        val = val-5;
                     else if(side == '2')
                        val =val+5;
                     break;
                    }
              case'7':
                    {
                     if(side == '1')
                        val = val-7;
                     else if(side == '2')
                        val =val+7;
                     break;
                    }
              case'9':
                   {
                     if(side == '1')
                     {
                        val = val-9;
                        defeat = 1;
                     }
                     else if(side == '2')
                     {
                        val =val+9;
                        victory=1;
                     }
                     break;
                   }
              default:
                     break;

            };/*END OF SWITCH*/
         };/*End of FOR INNER LOOP*/
      };/*End of FOR OUTER LOOP*/

      if(defeat==0 && victory==1)
      {
         branch->vcntr+=1;
      }

      else if(defeat==1 && victory==0)
      {
         branch->dcntr+=1;
      }

      branch->elist->eval = val;
    /*  printf("eval=%d\n\n", branch->elist->eval);*/
      swap[0][i1][j1] = init_ent;      /* this is      */
      swap[1][i1][j1] = init_side;     /* for undoing  */
      swap[0][k1][l1] = finl_ent;      /* the changes  */
      swap[1][k1][l1] = finl_side;     /* in swap      */

    };
}

void FreeAll(node*);

void AIfunc(char origin[2][8][8])
{
 /*   printf("origin starts\n");
    printing(origin);
    printf("origin ends\n");*/
    char copy[2][8][8];
    char swap[2][8][8];

    int a,b =0;
    for(a; a<=7; a++)
    {
      b=0;
      for(b; b<=7; b++)
      {
          copy[0][a][b] = origin[0][a][b];
          copy[1][a][b] = origin[1][a][b];
          
          swap[0][a][b] = origin[0][a][b];
          swap[1][a][b] = origin[1][a][b];
      };
    };
/*    printing(swap);*/

    node *root;
    root = (node*)malloc(sizeof(node));
    root->head = NULL;
    root->elist = NULL;
    root->dcntr = 0;
    root->vcntr = 0;
    root->max_val = 0;
    root->min_val = 0;

    int z =0;
    for(z; z<=99; z++)
    {
       root->array[z] = NULL;
    };

/*    printing(swap);*/
    assign_ent('2',root, swap);

    z =0;
    int maxim_val = -100;
    node *shell = NULL;
    for(z; z<=99; z++)
    {
       shell =root->array[z];
       if(shell!=NULL)
          if(maxim_val < shell->elist->eval)
             maxim_val = shell->elist->eval;
    };

    maxim_val = 0.3*maxim_val;
    printf("maxim_val %d\n",maxim_val);
    z =0;

    for(z;z<=99; z++)
    {
       shell = root->array[z];
       if(shell!=NULL && shell->elist->eval < maxim_val)
       {
          free(shell->elist);
          free(shell);
          root->array[z] =NULL;
       }
    };

    char init_ent  = '\0';
    char init_side = '\0';
    char finl_ent  = '\0';
    char finl_side = '\0';

    z =0;
    int i1,j1,k1,l1;
    for(z;z<=99; z++)
    {
       if(root->array[z]!=NULL)
       {
         node* branch = root->array[z];
         i1 = branch->elist->i;
         j1 = branch->elist->j;
         k1 = branch->elist->k;
         l1 = branch->elist->l;

         init_ent  = swap[0][i1][j1];
         init_side = swap[1][i1][j1];
         finl_ent  = swap[0][k1][l1];
         finl_side = swap[1][k1][l1];

         int qw = compute(init_ent,i1,j1,k1,l1,1,swap);
         assign_ent('1',branch,swap);

         swap[0][i1][j1] = init_ent;
         swap[1][i1][j1] = init_side;
         swap[0][k1][l1] = finl_ent;
         swap[1][k1][l1] = finl_side;
       }
    };/*till here we have generated all the moves which are possible.*/

    node* subshell;
    node* ult_vic_shell ;
    node* vic_shell;
    ult_vic_shell = NULL;
    vic_shell = NULL;
    int min_dcntr = 100;

    int threat = 0; /*to know whether there is any imminent threat
                     *and this signifies a checkmate condition */
    z = 0;
    for(z ; z<=99;z++)
    {
       shell = root->array[z];
       if(shell!= NULL)
       {
          int ma_val= -100;
          int mi_val = 100;
          int c =0;
          for(c;c<=99; c++)
          {
             subshell = shell->array[c];
             if(subshell!=NULL)
             {
                if(ma_val < subshell->elist->eval)
                {
                   ma_val = subshell->elist->eval;
                }

                if(mi_val > subshell->elist->eval)
                {
                   mi_val = subshell->elist->eval;
                }

                if(subshell->dcntr > 0)
                {
                   shell->dcntr+=1;/*this is to tell us how many times dcntrs are high in subshells */
                }
             }
          };

          subshell = NULL;
          shell->max_val = ma_val;
          shell->min_val = mi_val;
       
          if(min_dcntr > shell->dcntr)
             min_dcntr = shell->dcntr;

          if(shell->dcntr > 0)
             threat =1;
       }
    };

    printf("min_dcntr = %d\n",min_dcntr);
    int ind_array[60];
    z =0;
    for(z; z<=59; z++)
       ind_array[z] = 200; /*this array is for storing the indices of root which have 
                            * lowest dcntr*/

    int c =0;
    z = 0;

    int safe_mode = 0;/*this is used so that we know that ult_vic_shell is
                       *stored with values which destroy the imminent threat
                       *FOR EXAMPLE: if a knight is going to kill our king
                       *             we are going to kill the knight if it
                       *             is possible.*/

    for(z;z<=99;z++)
    {  
       node* subshell = NULL;
       shell = root->array[z];
       if(shell!=NULL && shell->dcntr > 0 && safe_mode==0)/*dcntr can be > 1*/
       {
           int r=0;
           for(r;r<=99;r++)
           {
              subshell = shell->array[r];
              if(subshell!= NULL && subshell->dcntr > 0 && safe_mode==0)/*dcntr can be 0 or 1*/
              {  
                  int i = subshell->elist->i;  /* this 'i' & 'j' represent the position of the       */
                  int j = subshell->elist->j;  /* player 1 entity which can kill the king of the     */ 
                                               /* so we try to match its position with the           */ 
                                               /* position of a possible case back in the past       */ 
                                               /* where the computer is capable of killing the entity*/
                  node* inner_shell = NULL;
                  int c =0;
                  for(c;c<=99;c++)
                  {
                     inner_shell = root->array[c];
                     if(inner_shell!=NULL && i ==inner_shell->elist->k && j == inner_shell->elist->l && inner_shell->dcntr==0)
                     {
                         ult_vic_shell = inner_shell;
                         safe_mode =1;
                     }
                     
                  };
              }

           };
       }     
    };

    if(safe_mode==0 && threat==1)/*we have been unsuccessful in eliminating the entity*/
    {                            /*which is a threat.*/
       node* shell=NULL;
       int c=0;
       for(c;c<=99;c++)
       {
          shell = root->array[c];
          if(shell!=NULL && copy[0][shell->elist->i][shell->elist->j] == '9' && shell->dcntr==0)
          {
             ult_vic_shell = shell;/*here we seek for a possible move by computer in which */
             threat=0;             /* the king can change its position leading to no checkmate*/
          }   
       };

    }

    c=0;
    for(z=0; z<=99; z++)
    {
       shell = root->array[z];
       if(shell!= NULL)
       {
         if(shell->vcntr!= 0)
            ult_vic_shell = shell; /*this overwrites the value of ulti_vic_shell because*/
                                   /*we have finally got an instance where computer wins*/

         if(min_dcntr == shell->dcntr)
         {
            ind_array[c] = z;
            c++;
         } 
       }
    };

    z =0;
    int ma_val = -100;
    for(z;z<=c;z++)
    {
       if(ind_array[z]!= 200)
       {
          shell = root->array[ind_array[z]];
          shell->max_val = ((shell->max_val + shell->min_val)*10)/2; /*10 is multiplied so that we don't need float   */
          shell->max_val = shell->max_val + shell->elist->eval*100;  /*shell->elist->eval gives the value of grid of  */
                                                                     /*the node 1 and shell->max_val earlier containes*/
                                                                     /*the avg of the possible moves by the human      */

          if(ma_val < shell->max_val)
             ma_val = shell->max_val;
       }
    };

    int ind_rand[100];/*for storing those moves which have highest value*/
    z=0;
    for(z; z<100;z++)
    {
        ind_rand[z]=200;
    };

    int flag =0;
    int end_array=0;
    z =0;
    for(z; z<=c; z++)
    {
       if(ind_array[z]!= 200)
       {
          shell = root->array[ind_array[z]];
          if(ma_val == shell->max_val)
          {
             ind_rand[end_array] = ind_array[z];
             end_array++;
      /*       int i1 =shell->elist->i;
             int j1 =shell->elist->j;
             char ent = copy[0][i1][j1];

             if(ent=='1' && flag==0)
             {
                vic_shell = shell;
                flag=1;
             }

             if(ent=='2' && flag==0)
             {
                vic_shell = shell;
                flag=1;
             }

             if(ent=='4' && flag==0)
             {
                vic_shell = shell;
                flag=1;
             }

             if(ent=='5' && flag==0)
             {
                vic_shell = shell;
                flag=1;
             }

             if(ent=='7' && flag==0)
             {
                vic_shell = shell;
                flag=1;
             }

             if(ent=='9' && flag==0)
             {
                vic_shell = shell;
                flag=1;
             }*/
          }
       }
    };

    printf("i am here\n");                 /*produces a random number for selecting*/ 
    end_array--;                           /*a move amongst possible choices*/
    srand(time(NULL));
    z=0;
    z = rand()%(end_array+1);
    vic_shell=root->array[ind_rand[z]];
    printf("i am there\n");

    if(ult_vic_shell!=NULL)
    {
       shell = ult_vic_shell;
       i1 = shell->elist->i;
       j1 = shell->elist->j;
       k1 = shell->elist->k;
       l1 = shell->elist->l;
    }

    else if(ult_vic_shell==NULL && vic_shell!=NULL)
    {
       shell = vic_shell;
       i1 = shell->elist->i; 
       j1 = shell->elist->j;
       k1 = shell->elist->k;
       l1 = shell->elist->l;
    }

    init_ent = origin[0][i1][j1];
    printf("i1%d j1%d k1%d l1%d\n",i1,j1,k1,l1);
    z = compute(init_ent, i1, j1 ,k1, l1, 0, origin);

    FreeAll(root);    
return ;
}

void FreeAll(node* root)
{  
  if(root!= NULL)
  {
    int z,c =0;
    for(z; z<=99; z++)
    {
       if(root->array[z] != NULL)
        c++;
    };

    if(c!= 0)
    {
      z =0;
      for(z;z<=99;z++)
      {
         FreeAll(root->array[z]);
         root->array[z] = NULL;
      };  
    }

    else if(c == 0)
    {
       free(root->elist);
       free(root);
    }
  }
}
