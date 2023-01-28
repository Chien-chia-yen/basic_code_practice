#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define ROW 11
#define COLUMN 15
#define NUM 165
/////////ROW*COL=6*10=60///////////
int get_mine_count(int mine[ROW][COLUMN], int x, int y)/////record how many mine are there around mine[x][y] 
{

	int count=0;
	if((mine[x-1][y]==1 )& (x-1>=0)){
		count=count+1;
		
	}
	if((mine[x-1][y-1]==1)& (x-1>=0 & y-1>=0)){
		count=count+1;
		
	}
	if((mine[x][y-1]==1)& ( y-1>=0)){
		count=count+1;
	}
	if((mine[x+1][y-1]==1) & (x+1<ROW & y-1>=0)){
		count=count+1;
		
	}
	if((mine[x+1][y]==1)& (x+1<ROW )){
		count=count+1;
		
	}
	if((mine[x+1][y+1]==1)& (x+1<ROW & y+1<COLUMN)){
		count=count+1;
		
	}
	if((mine[x][y+1]==1)&(y+1<COLUMN)){
		count=count+1;
		
	}
	if((mine[x-1][y+1]==1)&(x-1>=0 & y+1<COLUMN)){
		count=count+1;
		
	}
	return count;
}

int group=2;
void SpreadMine(int32_t mine[ROW][COLUMN],int show[ROW][COLUMN],int check_board[ROW][COLUMN], int x, int y)////////spread mine map////////
{
	
	int count = get_mine_count(mine, x, y);
	
	if (count==0)////////////if there are no mine around mine[x][y], explore with recursive//////////// 
	{
		
		
		show[x][y] = group;
		//printf("group=%d\n",group);
		//printf("AAAAAAAAAAAgroup=%d\n",group);
		////////////Check whether it is a group that has been classified, if yes, join the node///////// 
		if (show[x][y + 1] != 0 & (y+1<COLUMN) )///right 
		{
			show[x][y] = show[x][y+1];
			//group=group-1;
			//group=show[x][y];
			//new_group=0;
		}
		if (y-1>=0 & show[x][y-1] != 0)///left
		{
		
			show[x][y] = show[x][y-1];
			//group=group-1;
			//group=show[x][y];
			//new_group=0;
			//printf("AAAAAAAA\n");
		}
		if (x-1>=0 &show[x-1][y] != 0)///up 
		{
			show[x][y] = show[x-1][y];
			//group=group-1;
			//group=show[x][y];
			///new_group=0;
			//printf("BBBBBBBBBB\n");
		}
		if ((x-1>=0 & y+1<COLUMN) &show[x-1][y+1] != 0)///right_up
		{
			show[x][y] = show[x-1][y+1];
			//group=group-1;
			//group=show[x][y];
			//new_group=0;
			//printf("CCCCCCCCC\n");
		}
		if (show[x+1][y+1] != 0& (y+1<COLUMN & x+1<ROW))////right_down
		{
			
			show[x][y] = show[x+1][y+1];
			//group=group-1;
			//group=show[x][y];
			//new_group=0;
			//show[x+1][y+1] = group;
		}
		if ((x-1>=0 & y-1>=0) &show[x-1][y-1] != 0)////left_up
		{
			show[x][y]=show[x-1][y-1];
			//group=group-1;
			//group=show[x][y];
			//new_group=0;
			//printf("DDDDDDDDD\n");
			
		}
		if (show[x+1][y-1] != 0& (y-1>=0 & x+1<ROW))////left_down
		{
			show[x][y]=show[x+1][y-1];
			//group=group-1;
			//group=show[x][y];
			//new_group=0;
			//show[x+1][y-1] = group;
		}
		if (show[x+1][y] != 0& (x+1<ROW))////down 
		{
			show[x][y]=show[x+1][y];
			//group=group-1;
			//group=show[x][y];
			//show[x+1][y] = group;
		}
		
		
	
		////////Class the surrounding nodes into groups////////// 
		if (show[x][y + 1] == 0 & (y+1<COLUMN) )///right 
		{
			SpreadMine(mine, show,check_board, x, y+1);
			//printf("show[x][y]=%d\n",show[x][y]);
			//show[x][y+1] = group;
		}
		if (show[x][y-1] == 0& (y-1>=0))///left 
		{
		
			SpreadMine(mine, show,check_board, x, y-1);
			//printf("show[x][y]=%d\n",show[x][y]);
			//show[x][y-1] = group;
		}
		if (show[x+1][y] == 0& (x+1<ROW))////down 
		{
			SpreadMine(mine, show,check_board, x+1, y);
			//printf("show[x][y]=%d\n",show[x][y]);
			//show[x+1][y] = group;
		}
		if (show[x+1][y-1] == 0& (y-1>=0 & x+1<ROW))////left_down
		{
			SpreadMine(mine, show,check_board, x+1, y-1);
			//printf("show[x][y]=%d\n",show[x][y]);
			//show[x+1][y-1] = group;
		}
		if (show[x+1][y+1] == 0& (y+1<COLUMN & x+1<ROW))////right_down
		{
			
			SpreadMine(mine, show,check_board, x+1, y+1);
			//printf("show[x][y]=%d\n",show[x][y]);
			//show[x+1][y+1] = group;
		}
		if (show[x-1][y] == 0& (x-1>=0))///up 
		{
			SpreadMine(mine, show,check_board, x-1, y);
			//printf("show[x][y]=%d\n",show[x][y]);
			//show[x-1][y] = group;
		}
		if (show[x-1][y+1] == 0& (y+1<COLUMN & x-1>=0))///right_up 
		{
			SpreadMine(mine, show,check_board, x-1, y+1);
			//printf("show[x][y]=%d\n",show[x][y]);
			//show[x-1][y+1] = group;
		}
		if (show[x-1][y-1] == 0& (y-1>=0 & x-1>=0))////left_up 
		{
			SpreadMine(mine, show,check_board, x-1, y-1);
			//printf("show[x][y]=%d\n",show[x][y]);
			//show[x-1][y-1] = group;
		}
		
	}
	
	
	
	
}

void BubbleSort(int row[],int col[], int len) ////////////Bubble sort and ascending///////////
{
	int i, j, temp1,temp2;
	for (i = 0; i < len - 1; ++i)          
		for (j = 0; j < len - 1 - i; ++j)  
			if (row[j] > row[j + 1])       
			{
				temp1 = row[j];
				row[j] = row[j + 1];
				row[j + 1] = temp1;
				temp2 = col[j];
				col[j] = col[j + 1];
				col[j + 1] = temp2;
			}
}
int check_surround_num(int show[ROW][COLUMN],int x,int y,int group,int check_map[NUM][ROW][COLUMN])
{
	int count_surround=0;
	
	check_map[group][x][y]=1;
	////////check the surrounding nodes into groups////////// 
	if (show[x][y + 1] == 0 & (y+1<COLUMN) &check_map[group][x][y+1]!=1)///right 
	{
		//printf("CCCCCCCCCCCCCCCCC\n");
		count_surround=count_surround+1; 
		check_map[group][x][y+1]=1;
	}
	if (show[x][y-1] == 0& (y-1>=0)&check_map[group][x][y-1]!=1)///left 
	{
		//printf("DDDDDDDDDDDDDDDDD\n");
		count_surround=count_surround+1;
		check_map[group][x][y-1]=1 ;
		
	}
	if (show[x+1][y] == 0& (x+1<ROW)&check_map[group][x+1][y]!=1)////down 
	{
		//printf("EEEEEEEEEEEEEEEEEEEE\n");
		count_surround=count_surround+1; 
		check_map[group][x+1][y]=1;
	}
	if (show[x+1][y-1] == 0& (y-1>=0 & x+1<ROW)&check_map[group][x+1][y-1]!=1)////left_down
	{
		count_surround=count_surround+1; 
		check_map[group][x+1][y-1]=1;
	}
	if (show[x+1][y+1] == 0& (y+1<COLUMN & x+1<ROW)&check_map[group][x+1][y+1]!=1)////right_down
	{
		count_surround=count_surround+1;
		check_map[group][x+1][y+1]=1 ;	
		
	}
	if (show[x-1][y] == 0& (x-1>=0)&check_map[group][x-1][y]!=1)///up 
	{
		count_surround=count_surround+1; 
		check_map[group][x-1][y]=1;
	}
	if (show[x-1][y+1] == 0& (y+1<COLUMN & x-1>=0)&check_map[group][x-1][y+1]!=1)///right_up 
	{
		count_surround=count_surround+1; 
		check_map[group][x-1][y+1]=1;
	}
	if (show[x-1][y-1] == 0& (y-1>=0 & x-1>=0)&check_map[group][x-1][y-1]!=1)////left_up 
	{
		check_map[group][x-1][y-1]=1;
		count_surround=count_surround+1; 
	}
	return count_surround;
}
int find_good_cells( const int32_t board[ROW][COLUMN],int32_t row[NUM],int32_t col[NUM] ){
	int i=0;
	int j=0;
	int u=0;
	int check_board[ROW][COLUMN];/////////help us to find node to recursive
	int show[ROW][COLUMN];//////////result mine map
	int original_map[ROW][COLUMN];/////original mine map

	for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
                	
            check_board[i][j]=board[i][j];
            show[i][j]=board[i][j];
            original_map[i][j]=board[i][j];
            //check_map[i][j]=0;
            
        }
        
    }
    
    
	for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
        	
                	
            if(board[i][j]==1)
            {
            	if((j+1<COLUMN )& (check_board[i][j+1]==0))////right 
            	{
            		check_board[i][j+1]=8;
            		
				}
				if((i+1<ROW )& (check_board[i+1][j]==0))/////down 
            	{
            		check_board[i+1][j]=8;
            		
				}
				if((i+1<ROW & j+1<COLUMN)& (check_board[i+1][j+1]==0))///////right_down 
            	{
            		check_board[i+1][j+1]=8;
            	
				}
				if((j-1>=0 )& (check_board[i][j-1]==0))////////left 
            	{
            		check_board[i][j-1]=8;
            		
				}
				if((i-1>=0 )& (check_board[i-1][j]==0))/////up 
            	{
            		check_board[i-1][j]=8;
            		
				}
				if((i+1<ROW & j-1>=0)& (check_board[i+1][j-1]==0))///left_down 
            	{
            		check_board[i+1][j-1]=8;
            		
				}
				if((i-1>=0 & j-1>=0)& (check_board[i-1][j-1]==0))///left_up 
            	{
            		check_board[i-1][j-1]=8;
            		
				}
				if((i-1>=0 & j+1<COLUMN)& (check_board[i-1][j+1]==0))///right_up 
            	{
            		check_board[i-1][j+1]=8;
            		
				}
			}
        }
        
    }
   
    ////////////record the coordinate that value is 0//////////// 
    int row_col[2][NUM]={{-1},{-1}};
    int num_zero=0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
                	
            if(check_board[i][j]==0)
            {
            	row_col[0][num_zero]=i;
            	row_col[1][num_zero]=j;
            	num_zero=num_zero+1;
			}
        }
        
    }
    
    
        
    ////////////////spread mine//////////////////////
    int go_row=0;
    int go_col=0;
    
    for(i=0;i<num_zero;i++)
    {
        go_row=row_col[0][i];
		go_col=row_col[1][i];        	
        SpreadMine(original_map, show,check_board, go_row, go_col);
        group=group+1;
    
    }
    printf("////////////original_map////////////////////////\n");    
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
                	
            printf("%d ",original_map[i][j]);
        }
        printf("\n");
    }
    printf("////////////check_board////////////////////////\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
                	
            printf("%d ",check_board[i][j]);
        }
        printf("\n");
    }
    
    printf("////////////Show////////////////////////\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
            if(show[i][j]<10)
			{
				printf(" %d ",show[i][j]);
					} 
			else
			{
				printf("%d ",show[i][j]);
				   }   	
            
        }
        printf("\n");
    }
    
    //////////////count size in each group//////////////
    int group_num=0;
	int count_group_num[2][NUM]={{0},{0}}; 
	int k=0;
	
	int check_map[NUM][ROW][COLUMN]={{0},{0},{0}};////check arround 0:uncount
	int count_surround=0;
	int rec_surround[NUM]={0}; 
	////////////count number that surround no mine and it surrounding/////////////
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
                	
            if(show[i][j]!=0 & show[i][j]!=1)
            {
            	
            	count_surround=check_surround_num(show,i,j,show[i][j],check_map);
            	rec_surround[show[i][j]]=rec_surround[show[i][j]]+count_surround;
            	
            	for(k=0;k<NUM;k++)
        		{
        			
                	//////////old group//////// 
            		if(count_group_num[0][k]==show[i][j])
            		{
            			count_group_num[1][k]=count_group_num[1][k]+1;
            			break;
            			
					}
					
					//////////new group//////// 
					if(count_group_num[0][k]==0)
					{
						group_num=group_num+1;
						count_group_num[0][k]=show[i][j];
						count_group_num[1][k]=count_group_num[1][k]+1;
						break;
					}
        
				}
        	}
        }
        
    }
   
    for(j=0;j<group_num;j++)
    {
                	
        count_group_num[1][j]=count_group_num[1][j]+rec_surround[count_group_num[0][j]];
        
    }   
    printf("group_num=%d\n\n",group_num);
    printf("diff group and its size\n");
    for(j=0;j<group_num;j++)
    {
                	
       
    	printf("group: %d ",count_group_num[0][j]);
    	printf("size=%d\n",count_group_num[1][j]);
       		
	   
    }   
    printf("\n");
    
    //////find biggest group and its size//////////////
    int biggest_group[NUM]={-1};
    int big_num=0;
    int count_big_group=0; 
    for(j=0;j<group_num;j++)
    {
       //printf("j=%d\n",j);         	
       if(count_group_num[1][j]>=big_num)
       {
       		big_num=count_group_num[1][j];
	   }
    } 
	int index_biggroup=0;   
    for(j=0;j<group_num;j++)
    {
       //printf("j=%d\n",j);         	
       if(count_group_num[1][j]==big_num)
       {
       		//printf("j=%d\n",j);
       		big_num=count_group_num[1][j];
       		biggest_group[index_biggroup]=count_group_num[0][j];
       		index_biggroup=index_biggroup+1;
       		count_big_group=count_big_group+1;
       		
	   }
    }    
    printf("big_num=%d\n",big_num);
    printf("count_big_group=%d\n",count_big_group);
    printf("biggest_group: ");
    for(j=0;j<count_big_group;j++)
    {
                	
       
       	printf("%d",biggest_group[j]);
       		
	   
    }   
    printf("\n");
    
    
    
    ///////////////Find the coordinates from the largest group where there are no mine around////////////
    int count_bomb=0;
    int go=0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
            count_bomb = get_mine_count(show, i, j);
			if(count_bomb==0)
			{
				for(k=0;k<group_num;k++)
				{
					if(show[i][j]==biggest_group[k])
					{
						printf("%d , %d\n",i,j);
						row[go]=i;
						col[go]=j;
						go=go+1;
					}
				}
				
			} 
        }
        
    }
    
    
    //////////sort row and col////////// 
    BubbleSort(row,col, go);
    
    //////////result////////////// 
    printf("row: [ ");
    for(i=0;i<NUM;i++)
    {
        if(row[i]!=-1)
        {
        	if(row[i]<10)
        	{
        		printf(" %d ",row[i]);
			}
			else
			{ 
        		printf("%d ",row[i]);
        	} 
		}
        
    }
    printf("] \n");
    printf("col: [ ");
    for(i=0;i<NUM;i++)
    {
        if(row[i]!=-1)
        {
        	if(col[i]<10)
        	{
        		printf(" %d ",col[i]);
			}
			else
			{
				printf("%d ",col[i]);
			}
        	
		}
        
    }
    printf("] ");
    
	return 0;
}
int  main(int argc,char** argv)
{
	
		///////////////read test file//////////////// 
        int board[ROW][COLUMN];
        int32_t row[NUM]={-1};
        int32_t col[NUM]={-1};
        
        int i,j;
        for(i=0;i<NUM;i++)
        {
        	row[i]=-1;
        	col[i]=-1;
		}
        FILE* fp=fopen("./test3.txt","r"); //open file
        if(fp==NULL)
        {
            printf("no file\n");
            return -1;
        }
        for(i=0;i<ROW;i++)
        {
                for(j=0;j<COLUMN;j++)
                {
                        fscanf(fp,"%d",&board[i][j]);/*read each number every time¡Afscanf if " " or \n end*/
                }
                fscanf(fp,"\n");
        }
        fclose(fp);
        
        
        
        int a=0;
        a=find_good_cells( board, row, col );
     return 0;	
}
