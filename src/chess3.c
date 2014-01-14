/*Copyright 2012 Parigyan Chandra Goyal & Sharat Shankar*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include <unistd.h>
#include "AI.c"

/* 1 = PAWN
 * 2 = KNIGHT
 * 4 = BISHOP
 * 5 = ROOK
 * 7 = QUEEN
 * 9 = KING*/

int compute(char ent1,int i1,int j1,int k1,int l1, int cond, char chess[2][8][8]);
void printing(char chp [2][8][8]);


int main()
{
    char chess[2][8][8]={
                        {
                        {'5','4','2','9','7','2','4','5'},
                        {'1','1','1','1','1','1','1','1'},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {'1','1','1','1','1','1','1','1'},
                        {'5','4','2','7','9','2','4','5'},
                      },

                        {
                        {'1','1','1','1','1','1','1','1'},
                        {'1','1','1','1','1','1','1','1'},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {'2','2','2','2','2','2','2','2'},
                        {'2','2','2','2','2','2','2','2'},
                      }
                       };


     const char *ind[8][8]=
                        {                         
                        {"A1","A2","A3","A4","A5","A6","A7","A8"},
                        {"B1","B2","B3","B4","B5","B6","B7","B8"},
                        {"C1","C2","C3","C4","C5","C6","C7","C8"},
                        {"D1","D2","D3","D4","D5","D6","D7","D8"},
                        {"E1","E2","E3","E4","E5","E6","E7","E8"},
                        {"F1","F2","F3","F4","F5","F6","F7","F8"},
                        {"G1","G2","G3","G4","G5","G6","G7","G8"},
                        {"H1","H2","H3","H4","H5","H6","H7","H8"},
                        };

    int checker=1;
    int run = 108;
    while(run > 0)
    {

       printing(chess);
       char ent='0';


/***************************************TAKING THE INPUT**********************************************/
    if(checker%2 ==0)
    { 
       int loop =0;						/********Delay Loop********/
       for(loop;loop<=1000000000;loop++)	/******To enhance the gameplay and make it look more real******/
       {
          ;
       };
       AIfunc(chess);
       checker++;
     }
   
    else if(checker%2 !=0)
     {
      printf("PLAYER 1 TYPE IN YOUR MOVE: ");
       

      int whitesp = 0;
      int n =0;
      int ck =0;
      int ik = 0;
      int fk =0;
      char d = '\0';
      char lin1[100];
      char initv[100], finlv[100],help[100];
      
      int par = 0;
      for(par = 0; par<100; par++)
      {  
          lin1[par] = '\0'; 
          initv[par] = '\0';
          help[par] = '\0';
          finlv[par] = '\0';
      }

      scanf(" %[^\n]s", lin1);
      int low=0;
      int len =strlen(lin1) - 1;

      for(low;low<=len;low++)
      {
        lin1[low]=toupper(lin1[low]);
      }

      for(n =0; n <=len ; n++)
      {
           if(lin1[n] == ' ' && n==0)
           continue;

           if(lin1[n] == ' ' && ((lin1[n-1] != ' ') && n!=0)){
                whitesp++;
           }

           if( whitesp == 0 && (n == 0 || lin1[n-1] == ' ') && lin1[n] != ' ')
                d = lin1[n];

           if(whitesp == 0 && lin1[n] != ' '){
                    help[ck] = lin1[n];
                    ck++;
           }

           if(whitesp == 1 && lin1[n] != ' '){
                    initv[ik] = lin1[n];
                    ik++;
            }

           if(whitesp == 2 && lin1[n] != ' '){
                    finlv[fk] = lin1[n];
                    fk++;
           }

      }

/*
      printf("\n");                            The comments have been left
      printf("%c \n", d);                      as such because people who are new
      printf("%s \n", lin1 );                  to the source code can uncomment the
      printf("%sa\n", help);                   statements and understand the significance
      printf("%s \n", initv);                  and working of the variables.
      printf("%s \n", finlv);

*/



/*************************************CALCULATING THE INDICES******************************************/       
       char *quit = "QUIT";
       int dep = 30;
       dep = strcmp(help,quit);
     /*  printf("dep%d",dep) */;

       char *display = "HELP";
       int ped =40;
       ped = strcmp(help, display);

       if(ped == 0)
       {
            printf("\n\n\n\n\n");
            printf("\t1 = PAWN\n\t2 = KNIGHT\n\t4 = BISHOP\n\t5 = ROOK\n\t7 = QUEEN\n\t9 = KING\n\n\n\n\n");

            printf("PRESS ENTER TO ESCAPE HELP:");
            char esc;

            if( (esc = getchar() ) == 'h' || (esc = getchar() )== 'H')
            continue;

       }

       if(dep == 0)
       { 
            printf("ENTER Y TO QUIT:");
            char y;
    
            if( (y = getchar() ) == 'y' || (y = getchar() )== 'Y')
            break;
       }


       ent = d;
       int error=0;       
       int i,j,k,l=0;
       int check;

       for (i=0;i<=7;i++)
        { check = 100;
          
          for (j=0;j<=7;j++)
           {  check = strcmp(ind[i][j],initv);
             if (check==0)
             break;
           };
	 
         if(check==0)
         break;       
       }    


       if(check!=0)
       {
          error++;
          printf("THERE IS NO INITIAL POSITION AS \"%s\"\n", initv);/*************ERROR ERROR*************/
       } 
      
        
       for (k=0;k<=7;k++)
        { check = 100;

          for (l=0;l<=7;l++)
           { check = strcmp(ind[k][l],finlv);
             if (check==0)
             break;
           };
         
         if(check==0)
         break;            
       }

      if(check!=0)
      {
         error++;
         printf("THERE IS NO FINAL POSITION AS \"%s\"\n", finlv);/*************ERROR ERROR*************/
      }
 
       char king = chess[0][k][l];

       if(checker%2 !=0 && chess[1][i][j]=='2')
       { 
         error=1;
         printf("PLAYER 1 YOU CANNOT ACCESS ARMY OF PLAYER 2\n");
       }  

       else if(checker%2 ==0 && chess[1][i][j]== '1')
       {
         error=1;
         printf("PLAYER 2 YOU CANNOT ACCESS ARMY OF PLAYER 1\n");
       }


 /*  system("clear");*/
     
       if(error ==0)
       {
        error =  compute(ent,i,j,k,l,0,chess);
       }

       if(error==0)
       { 
         checker++;  
       /*  printf("checker:%d  error a:%d\n",checker,error);*/
        }  

       else if( error !=0)
       {
       /*  printf("checker:%d  error b:%d\n",checker,error);*/ 
       }  

       if(king=='9' && error ==0 && checker%2 == 0)
       {printf("PLAYER 1 HAS WON THE GAME\n");
        break;
       }
    
       if(king=='9' && error ==0 && checker%2 != 0)
       {printf("PLAYER 2 HAS WON THE GAME\n");
        break;
       }  
     
      /*  printf("checker:%d  error c:%d\n",checker,error);*/
      
  }

 }

   return 0;
}






int compute(char ent1,int i1,int j1,int k1,int l1, int cond, char chess[2][8][8])
/*cond means condition for stopping printf statements
 *when cond ==1 do not print  */
{     
     int q=0;
     switch(ent1)
      {
       case '1':/************************************* RULES FOR PAWN************************************************/ 
             switch(chess[0][i1][j1])
             { 
        	case'1': /*CHECKS WHETHER PAWN IS AVAILABLE OR NOT*/
                {
                  if (chess[1][i1][j1]=='1')/*FOR UPPER PLAYER*/
                  {
                       if( (chess[1][k1][l1]== '1' && l1==j1) || (i1 == 1 && chess[1][2][j1] == '1' && j1==l1 ) ) 
                        {
                         q=1;
                         if(cond == 0)  
                           printf("PLAYER 1 YOU CAN NOT OVERRUN YOUR ARMY\n");/************ERROR ERROR***************/
                        }

                       else if (chess[1][2][j1] == '2')
                        {
                         q=1;
                         if(cond == 0)
                           printf("PLAYER 1 PAWN CAN'T JUMP OVER THE ENEMY\n");/************ERROR ERROR***************/
                        }

                    
                       else
                       {
                           if ( i1==1 && (k1==i1+1 || k1==i1+2) && l1==j1 )/*WHEN THE PAWN IS AT ITS INITIAL POSITION*/
                           {                                               
                                if(chess[1][k1][l1] == ' ')
                                   {
                                   chess[0][k1][l1]=chess[0][i1][j1];
                                   chess[1][k1][l1]=chess[1][i1][j1];
                                   chess[0][i1][j1]=chess[1][i1][j1]=' ';
                                   }

                                 else
                                   {
                                     q=1;
                                     if(cond == 0)
                                       printf("ILLEGAL MOVE\n");/************ERROR ERROR***************/

                                   }

                           }
               
                       
		           else if (k1==i1+1 && l1==j1)/*WHEN PAWN IS ANYWHERE ELSE*/
		 	   {
                                if(chess[1][k1][l1] == ' ')
                                   {
                                   chess[0][k1][l1]=chess[0][i1][j1];
                                   chess[1][k1][l1]=chess[1][i1][j1];
                                   chess[0][i1][j1]=chess[1][i1][j1]=' ';
                                   }
 
                                 else
                                   {
                                    q=1;
                                    if(cond == 0)
                                      printf("ILLEGAL MOVE\n");/************ERROR ERROR***************/
                                   }

                           }

                           else if (k1 == i1+1 && ( l1==j1-1 || l1==j1+1))/*WHEN PAWN IS ANYWHERE ELSE*/
                           { 
                                if(chess[1][k1][l1] == '2')
                                   {
                                   chess[0][k1][l1]=chess[0][i1][j1];
                                   chess[1][k1][l1]=chess[1][i1][j1];   
                                   chess[0][i1][j1]=chess[1][i1][j1]=' ';
                                   }
               
                                else
                                   {
                                     q=1;
                                     if(cond == 0)
                                       printf("ILLEGAL MOVE\n");/************ERROR ERROR***************/

                                   }
                           }


                            else
                            {    q=1;
                                 if(cond == 0)
                                   printf("PLAYER 1 ILLEGAL MOVE\n");/************ERROR ERROR***************/

                            }

      		       }

                  }

		  else if (chess[1][i1][j1]=='2')/*FOR LOWER PLAYER*/
                  {
                        if( (chess[1][k1][l1]== '2' && l1 == j1) || (i1==6 && chess[1][5][j1] == '2' && j1==l1 ) )
                        {
                         q=1;
                         if(cond == 0)  
                           printf("PLAYER 2 YOU CAN NOT OVERRUN YOUR ARMY\n");/************ERROR ERROR***************/
                        }
 
                        else if (chess[1][5][j1] == '1')
                        {
                         q=1;
                         if(cond == 0)
                           printf("PLAYER 2 PAWN CAN'T JUMP OVER THE ENEMY\n");/************ERROR ERROR***************/
                        }


                       else
                       {
                           if ( i1==6 && (k1==i1-1 || k1==i1-2) && l1==j1 )/*WHEN THE PAWN IS AT ITS INITIAL POSITION*/
                           {
                                if(chess[1][k1][l1] == ' ')
                                   {
                                   chess[0][k1][l1]=chess[0][i1][j1];
                                   chess[1][k1][l1]=chess[1][i1][j1];
                                   chess[0][i1][j1]=chess[1][i1][j1]=' ';
                                   }

                                 else
                                   {
                                    q=1;
                                    if(cond == 0)
                                      printf("ILLEGAL MOVE\n");/************ERROR ERROR***************/

                                   }

                           }

                           else if (k1==i1-1 && l1==j1)/*WHEN PAWN IS ANYWHERE ELSE*/
                           {
                                if(chess[1][k1][l1] == ' ')
                                   {
                                   chess[0][k1][l1]=chess[0][i1][j1];
                                   chess[1][k1][l1]=chess[1][i1][j1];
                                   chess[0][i1][j1]=chess[1][i1][j1]=' ';
                                   }

                                 else
                                   {
                                    q=1;
                                    if(cond == 0)
                                      printf("ILLEGAL MOVE\n");/************ERROR ERROR***************/
                                   }

                           }

                           else if (k1 == i1-1 && ( l1==j1-1 || l1==j1+1))/*WHEN PAWN IS ANYWHERE ELSE*/
                           {
                                if(chess[1][k1][l1] == '1')
                                   {
                                   chess[0][k1][l1]=chess[0][i1][j1];
                                   chess[1][k1][l1]=chess[1][i1][j1];
                                   chess[0][i1][j1]=chess[1][i1][j1]=' ';
                                   }

                                else
                                   {
                                    q=1;
                                    if(cond == 0)
                                      printf("ILLEGAL MOVE\n");/************ERROR ERROR***************/
                                   }
                           }
	
                  
		           else
                           {        q=1;   
                                    if(cond == 0)
                                      printf("YOUR MOVE IS ILLEGAL\n");/************ERROR ERROR***************/
                           }
    
		        }
                  }

                break;}/*BREAK OF CASE 1*/	

	 

                default:
                       {  q=1;
                          if(cond == 0)
                            printf("PAWN IS NOT AT THE SPECIFIED POSITION\n");/************ERROR ERROR***************/
                       }

             }break;/**********************************************END OF PAWN***********************************/
 


       case '2' : /******************************************RULES FOR KNIGHT*********************************/
             switch(chess[0][i1][j1])    
             { case '2':/***CHECKS WHETHER KNIGHT IS THERE OR NOT******/
                       {     
                             if( (k1 == i1+2 || k1 == i1-2) && (k1>=0 && k1<=7) && (l1 == j1+1 || l1 == j1-1) && (l1>=0 && l1<=7) )
                             {/*******FOR VERTICAL MOVEMENT*************/
                                        if(chess[1][i1][j1] == chess[1][k1][l1] )
                                        {
                                            q =1;
                                            if(cond == 0)
                                              printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
                                        }
                                    

                                        else
                                        {
                                             chess[0][k1][l1]=chess[0][i1][j1];
                                             chess[1][k1][l1]=chess[1][i1][j1];
                                             chess[0][i1][j1]=chess[1][i1][j1]=' ';

                                        }
                                 
                             }
                          
                       
                            else if( (k1 == i1+1 || k1 == i1-1) && (k1>=0 && k1<=7) && (l1 == j1+2 || l1== j1-2) && (l1>=0 && l1<=7) )
                             {/*********FOR HORIZONTAL MOVEMENT***********/
                                        if(chess[1][i1][j1] == chess[1][k1][l1] )
                                        {
                                            q =1;
                                            if(cond == 0)
                                              printf("YOU CANNOT OVERRUN YOUR ARMY\n");/************ERROR ERROR***************/
                                        }


                                        else
                                        {
                                             chess[0][k1][l1]=chess[0][i1][j1];
                                             chess[1][k1][l1]=chess[1][i1][j1];
                                             chess[0][i1][j1]=chess[1][i1][j1]=' ';

                                        }

                             }

                             else
                             {
                                        q =1;
                                        if(cond == 0)
                                          printf("YOUR KNIGHT MOVE IS ILLEGAL\n");/************ERROR ERROR***************/
                             }
                             
               break;}/*BREAK OF CASE 2*/


               default:
                      {
                        q =1;
                        if(cond == 0)
                          printf("KNIGHT IS NOT AT THE SPECIFIED POSITION\n");/************ERROR ERROR***************/
                      }               

             }break;/***********************************END OF KNIGHT********************************************/
        

 
       case'3':/***************************************RULE OF NO-ENTITY 3 ****************************************/
             {
                   q =1;
                   if(cond == 0)
                     printf("THERE IS NO ENTITY 3\n");/************ERROR ERROR***************/

             }break;/***********************************END OF NO-ENTITY 3 ****************************************/



       case'4':/****************************************RULES OF BISHOP****************************************/
              switch(chess[0][i1][j1])
                     { case '4': /***CHECKS WHETHER BISHOP IS THERE OR NOT******/
                              {    int bis;
                                   bis = k1 - i1;                                     
                                /*   printf("%d\n",bis);*/

                                   if(l1 == bis + j1 || l1 == (-1)*bis + j1)
                                   {      int var = bis - 1;
                                           

                                          if(bis < 0){
                                               var = (-1)*bis -1;
                                           }
                                     
                                          for(var; var >0; var--)
                                          {    
                                               if(bis > 0 && l1 > j1)
                                               { 
                                                   if(chess[1][i1+var][j1+var] == ' ')
                                                   continue;     

                                                   else
                                                   {
                                                       q =1;
                                                       if(cond == 0)
                                                         printf("BISHOP CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                       break;
                                                   }
                                               }

                                               else if(bis > 0 && l1 < j1)
                                               {
                                                   if(chess[1][i1+var][j1-var] == ' ')
                                                   continue;

                                                   else
                                                   {
                                                       q =1;
                                                       if(cond == 0)
                                                         printf("BISHOP CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                       break;
                                                   }
                                               }

                                               else if(bis < 0 && l1 > j1)
                                               {
                                                   if(chess[1][i1-var][j1+var] == ' ')
                                                   continue;

                                                   else
                                                   {
                                                       q =1;
                                                       if(cond == 0)
                                                         printf("BISHOP CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                       break;

                                                   }
                                               }

                                               if(bis < 0 && l1 < j1)
                                               {
                                                   if(chess[1][i1-var][j1-var] == ' ')
                                                   continue;

                                                   else
                                                   {
                                                       q =1;
                                                       if(cond == 0)
                                                         printf("BISHOP CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                       break;

                                                   }
                                               }

                                          }


                                          if(chess[1][i1][j1] == chess[1][k1][l1])
                                          {
                                              q =1;
                                              var = 1;
                                              if(cond == 0)
                                                printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
                                          }


                                          if(var == 0)
                                          {
                                              chess[0][k1][l1]=chess[0][i1][j1];
                                              chess[1][k1][l1]=chess[1][i1][j1];
                                              chess[0][i1][j1]=chess[1][i1][j1]=' ';

                                          }

                                   }

                                   else
                                   {
                                         q =1;
                                         if(cond == 0)
                                           printf("INVALID MOVE OF BISHOP\n"); /************ERROR ERROR***************/
                                   }
                              




                 break;}/***END OF CASE 4 ***********/

                 default:
                        {   q =1;
                            if(cond == 0)
                              printf("BISHOP IS NOT AT THE SPECIFIED POSITION\n"); /************ERROR ERROR***************/
                        }


              }break; /*********************************END OF BISHOP**************************************/



       case '5' : /******************************************RULES FOR ROOK*********************************/
             switch(chess[0][i1][j1])
             { case '5':/***CHECKS WHETHER ROOK IS THERE OR NOT******/
                       {
                             if(l1==j1)
                             {/*******FOR VERTICAL MOVEMENT*************/
                                        int rip;
                                        rip = k1 - i1;
                                        int vap = rip-1;           

                                        if(rip <0)
                                        {
                                           vap = (-1)*rip-1;
                                        }

                                        for(vap; vap>0; vap--)
                                        { 
                                             if(rip>0)
                                             {   
                                                  if(chess[1][i1 + vap][j1] == ' ')
                                                  continue;

                                                  else
                                                  {  
                                                      q =1; 
                                                      if(cond == 0)
                                                        printf("ROOK CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                      break;
                                                  }
                                             }

                                             else if(rip<0)
                                             {
                                                  if(chess[1][i1 - vap][j1] == ' ')
                                                  continue;
                        
                                                  else
                                                  {
                                                      q =1;
                                                      if(cond == 0)
                                                        printf("ROOK CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                      break;
                                                  }
                                             }

                                        }

                                        if(chess[1][i1][j1] == chess[1][k1][l1] )
                                        {
                                            q =1;
                                            vap = 1;
                                            if(cond == 0)
                                              printf("YOU CANNOT OVERRUN YOUR ARMY\n");/************ERROR ERROR***************/
                                        }


                                        if(vap ==0)
                                        {
                                             chess[0][k1][l1]=chess[0][i1][j1];
                                             chess[1][k1][l1]=chess[1][i1][j1];
                                             chess[0][i1][j1]=chess[1][i1][j1]=' ';

                                        }

                             }

                             else if(k1==i1)
                             {/******FOR HORIZONTAL MOVEMENT*************/
                                        int rhip;
                                        rhip = l1 - j1;
                                        int vhap = rhip -1 ;

                                        if(rhip <0)
                                        {  
                                           vhap = (-1)*rhip-1;
                                        }

                                        for(vhap; vhap>0; vhap--)
                                        {
                                             if(rhip>0)
                                             {
                                                  if(chess[1][i1][j1 + vhap] == ' ')
                                                  continue;

                                                  else
                                                  {   
                                                      q =1;
                                                      if(cond == 0)
                                                        printf("ROOK CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                      break;
                                                  }
                                             }

                                             else if(rhip<0)
                                             {
                                                  if(chess[1][i1][j1 - vhap] == ' ')
                                                  continue;

                                                  else
                                                  {
                                                      q =1;
                                                      if(cond == 0)
                                                        printf("ROOK CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                      break;
                                                  }
                                             }


                                        }

                                        if(chess[1][i1][j1] == chess[1][k1][l1] )
                                        {   
                                            q =1;
                                            vhap = 1;
                                            if(cond == 0)
                                              printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
                                        }


                                        if(vhap ==0)
                                        {
                                             chess[0][k1][l1]=chess[0][i1][j1];
                                             chess[1][k1][l1]=chess[1][i1][j1];
                                             chess[0][i1][j1]=chess[1][i1][j1]=' ';

                                        }

                              }
                        
                           else
                              {
                                 q =1;
                                 if(cond == 0)
                                   printf("INVALID MOVE FOR ROOK\n"); /*******ERROR ERROR*********/
                               
                              }


                   break;}/***END OF CASE 5 ***********/


               default:
                      { 
                        q =1;
                        if(cond == 0)
                          printf("ROOK IS NOT AT THE SPECIFIED POSITION\n");/***********ERROR ERROR**************/
                      }

              }break; /*******************************END OF ROOK**************************************/




       case'6':/***************************************RULE OF NO-ENTITY 6 ****************************************/
             {
                   q =1;
                   if(cond == 0)
                     printf("THERE IS NO ENTITY 6\n");/************ERROR ERROR***************/

             }break;/***********************************END OF NO-ENTITY 6 ****************************************/





       case'7':/***************************************RULE OF QUEEN ****************************************/
             switch(chess[0][i1][j1])/***CHECKS WHETHER QUEEN IS THERE OR NOT******/
                 { case'7':
                           {
                         
                            if(l1==j1)
                             {/*******FOR VERTICAL MOVEMENT*************/
                                        int rip;
                                        rip = k1 - i1;
                                        int vap = rip-1;

                                        if(rip <0)
                                        {  
                                           vap = (-1)*rip-1;
                                        }

                                        for(vap; vap>0; vap--)
                                        {
                                             if(rip>0)
                                             {
                                                  if(chess[1][i1 + vap][j1] == ' ')
                                                  continue;

                                                  else
                                                  {   
                                                      q =1;
                                                      if(cond == 0)
                                                        printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                      break;
                                                  }
                                             }

                                             else if(rip<0)
                                             {
                                                  if(chess[1][i1 - vap][j1] == ' ')
                                                  continue;

                                                  else
                                                  {
                                                      q =1;
                                                      if(cond == 0)
                                                        printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                      break;
                                                  }
                                             }

                                        }

                                        if(chess[1][i1][j1] == chess[1][k1][l1] )
                                        {
                                            q =1;
                                            vap = 1;
                                            if(cond == 0)
                                              printf("YOU CANNOT OVERRUN YOUR ARMY\n");/************ERROR ERROR***************/
                                        }


                                        if(vap ==0)
                                        {
                                             chess[0][k1][l1]=chess[0][i1][j1];
                                             chess[1][k1][l1]=chess[1][i1][j1];
                                             chess[0][i1][j1]=chess[1][i1][j1]=' ';

                                        }

                             }

                             else if(k1==i1)
                             {/******FOR HORIZONTAL MOVEMENT*************/
                                        int rhip;
                                        rhip = l1 - j1;
                                        int vhap = rhip -1 ;

                                        if(rhip <0)
                                        {
                                           vhap = (-1)*rhip-1;
                                        }

                                        for(vhap; vhap>0; vhap--)
                                        {
                                             if(rhip>0)
                                             {
                                                  if(chess[1][i1][j1 + vhap] == ' ')
                                                  continue;

                                                  else
                                                  {
                                                      q =1;
                                                      if(cond == 0)
                                                        printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                      break;
                                                  }
                                             }

                                             else if(rhip<0)
                                             {
                                                  if(chess[1][i1][j1 - vhap] == ' ')
                                                  continue;

                                                  else
                                                  {
                                                      q =1;
                                                      if(cond == 0)
                                                        printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                      break;
                                                  }
                                             }


                                        }

                                        if(chess[1][i1][j1] == chess[1][k1][l1] )
                                        {
                                            q =1;
                                            vhap = 1;
                                            if(cond == 0)
                                              printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
                                        }


                                        if(vhap ==0)
                                        {
                                             chess[0][k1][l1]=chess[0][i1][j1];
                                             chess[1][k1][l1]=chess[1][i1][j1];
                                             chess[0][i1][j1]=chess[1][i1][j1]=' ';

                                        }

                              }
                         
 
                              else
                              {    int bis;
                                   bis = k1 - i1;
                                   /*printf("%d\n",bis);*/

                                   if(l1 == bis + j1 || l1 == (-1)*bis + j1)
                                   {      int var = bis - 1;


                                          if(bis < 0){
                                               var = (-1)*bis -1;
                                           }

                                          for(var; var >0; var--)
                                          {
                                               if(bis > 0 && l1 > j1)
                                               {
                                                   if(chess[1][i1+var][j1+var] == ' ')
                                                   continue;

                                                   else
                                                   {
                                                       q =1;
                                                       if(cond == 0)
                                                         printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                       break;
                                                   }
                                               }

                                               else if(bis > 0 && l1 < j1)
                                               {
                                                   if(chess[1][i1+var][j1-var] == ' ')
                                                   continue;

                                                   else
                                                   {
						       q =1;
                                                       if(cond == 0)
                                                         printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                       break;
                                                   }
                                               }

                                               else if(bis < 0 && l1 > j1)
                                               {   
                                                   if(chess[1][i1-var][j1+var] == ' ')
                                                   continue;

                                                   else
                                                   {   
                                                       q =1;
                                                       if(cond == 0)
                                                         printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                       break;

                                                   }
                                               }

                                               if(bis < 0 && l1 < j1)
                                               {   
                                                   if(chess[1][i1-var][j1-var] == ' ')
                                                   continue;

                                                   else
                                                   {   
                                                       q =1;
                                                       if(cond == 0)
                                                         printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                                                       break;

                                                   }
                                               }

                                          }


                                          if(chess[1][i1][j1] == chess[1][k1][l1])
                                          {
                                              q =1;
                                              var = 1;
                                              if(cond == 0)
                                                printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
                                          }


                                          if(var == 0)
                                          {
                                              chess[0][k1][l1]=chess[0][i1][j1];
                                              chess[1][k1][l1]=chess[1][i1][j1];
                                              chess[0][i1][j1]=chess[1][i1][j1]=' ';

                                          }

                                   }

                                   else
                                   {
                                            q =1;
                                            if(cond == 0)
                                              printf("INVALID MOVE FOR QUEEN\n");/*******ERROR ERROR*********/
                                   }

                              }


                  break;}/********END OF CASE 7 ************/



                default:
                      {
                        q =1;
                        if(cond == 0)
                          printf("QUEEN IS NOT AT THE SPECIFIED POSITION\n");/***********ERROR ERROR**************/
                      }
                 
              }break;/***********************************END OF QUEEN ****************************************/




       case'9':/***************************************RULE OF KING ****************************************/
             switch(chess[0][i1][j1])/***CHECKS WHETHER QUEEN IS THERE OR NOT******/
             {case'9':
                     {
                       
                        if( (k1 == i1 + 1 || k1 == i1-1) && (l1 == j1 || l1==j1-1 || l1 == j1+1) )
                        {

                              if(chess[1][i1][j1] == chess[1][k1][l1])
                              {  
                                  q =1; 
                                  if(cond == 0)
                                    printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
                              }


                              else
                              {
                                  chess[0][k1][l1]=chess[0][i1][j1];
                                  chess[1][k1][l1]=chess[1][i1][j1];
                                  chess[0][i1][j1]=chess[1][i1][j1]=' ';

                               }


                        }  

                        else if( (k1 == i1) && (l1==j1-1 || l1 == j1+1) )
                        {

                              if(chess[1][i1][j1] == chess[1][k1][l1])
                              {
                                  q =1;
                                  if(cond == 0)
                                    printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
                              }


                              else                                  
                              {
                                  chess[0][k1][l1]=chess[0][i1][j1];
                                  chess[1][k1][l1]=chess[1][i1][j1];
                                  chess[0][i1][j1]=chess[1][i1][j1]=' ';

                               }


                        }

                   
                        else
                        {
                               q =1;
                               if(cond == 0)
                                 printf("ILLEGAL MOVE FOR KING\n"); /************ERROR ERROR***************/
                        }
                    


               break;}/********END OF CASE 9 ************/


                default:
                      { 
                        q =1;
                        if(cond == 0)
                          printf("KING IS NOT AT THE SPECIFIED POSITION\n");/***********ERROR ERROR**************/
                      }


             }break;/***********************************END OF KING **************************************/


       default:{ 
                if(cond == 0)
                  printf("OTHER THAN THE ALLOWED NUMBERS , CHARACTERS NOT ALLOWED AS ENTITY\nLOOK INTO HELP\n");/************ERROR ERROR***************/
               }

     }/*****************END OF SWITCH(ENTITY)************************/
   
    return q;    

}/*END OF COMPUTE*/



void printing(char chp [2][8][8])
{     
     int a,b;
     a =b =0;
     int  len, brd, buffer;   /*len = length & brd = breadth*/
     brd = len = 8;
     printf("\n\n\n\n\n");

     printf("                             \x1b[31m PLAYER \x1b[0m                            \n");
     printf("           1      2      3      4      5      6      7      8    \n");
     buffer = len;
     printf("       --");

      for(len; len>0; len--){
       printf("-------");
      }

      printf("\n");
      len = buffer;

      int i;
      char alpha = 'A';
      int vert = 0;
      for(brd; brd>0; brd--)
      {
          a = 8 - brd;
          i = 3;
          if(i==3)
          {
              len = buffer;
              int hor =0;

              printf("       |");
              for(len; len>0; len--)
              {
                  if( (hor+vert)%2 == 0 )
                  {
                    printf("       ");
                  }

                  else if( (hor+vert)%2 != 0 )
                  {
                    printf("\u2588\u2588\u2588\u2588\u2588\u2588\u2588");     /* the characters inside the print statement*/
                  }                                                           /* are unicodes used for printing the chess grid*/
                  hor++;
              }

              printf("|");
              printf("\n");
              i--;
         }

         if(i==2)
         {
              len = buffer;
              int hor =0;
              printf("     %c |",alpha);

              for(len; len>0; len--)
              {
                  b = 8 - len;
                  if( (hor+vert)%2 == 0 )
                  {
                      if(chp[1][a][b] == '1')
                      {
                       printf("   \x1b[31m%c\x1b[0m   ", chp[0][a][b]);                   /*unicode*/
                      }

                      if(chp[1][a][b] == ' ')
                      {
                       printf("       ");
                      }

                      if(chp[1][a][b] == '2')
                      {
                       printf("   \x1b[32m%c\x1b[0m   ", chp[0][a][b]);                   /*unicode*/
                      }
                  }

                  else if( (hor+vert)%2 != 0 )
                  {
                      if(chp[1][a][b] =='1')
                      {
                       printf("\u2588\u2588\u258C\x1b[31m%c\x1b[0m\u2590\u2588\u2588", chp[0][a][b]);
                      }

                      if(chp[1][a][b] =='2')
                      {
                       printf("\u2588\u2588\u258C\x1b[32m%c\x1b[0m\u2590\u2588\u2588", chp[0][a][b]);
                      }

                      if(chp[1][a][b] ==' ')
                      {
                       printf("\u2588\u2588\u2588\u2588\u2588\u2588\u2588", chp[0][a][b]);
                      }

                  }
                  hor++;

             }

              printf("| %c", alpha);
              printf("\n");
              i--;
         }

         if(i==1)
         {
              len = buffer;
              printf("       |");
              int hor =0;

               for(len; len>0; len--)
               {
                  if( (hor+vert)%2 == 0 )
                  {
                    printf("       ");
                  }

                  else if( (hor+vert)%2 != 0 )
                  {
                    printf("\u2588\u2588\u2588\u2588\u2588\u2588\u2588");
                  }
                  hor++;

               }

             printf("|");
             printf("\n");
             i--;
         }

          alpha++;
          vert++;
     }


     len = buffer;
     printf("       --");

      for(len; len>0; len--){
       printf("-------");
      }
             printf("\n");

     printf("           1      2      3      4      5      6      7      8    \n");
     printf("                             \x1b[32mCOMPUTER\x1b[0m                            \n\n");
     printf("       '1'=>PAWN        '2'=>KNIGHT          '4'=>BISHOP\n       '5'=>ROOK        '7'=>QUEEN           '9'=>KING");
     printf("\n\n");


}
