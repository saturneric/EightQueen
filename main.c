//
//  main.c
//  Eight Queen
//
//  Created by Eric on 15-7-19.
//  Copyright (c) 2015年 Eric Bakantu. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#define T_MAX 8
int T_count;

int queen(int count, int table[8][8]);

int main() {
    int start = clock();
    int table[8][8];
    for (int x = 0; x < 8; x++)
        for ( int y = 0; y < 8 ; y++)
            table[x][y] = 1;
    
    queen(0,table);
    printf("OK! T_count = %d \n",T_count);
    int end = clock();
    int total = end - start;
    printf("TOTAL TIME: %d",total);
    return 0;
}

int queen(int count, int table[8][8]){
    
        int m_table[8][8],x,y,k,i;
        //复制棋盘
        for (x = 0; x < 8; x++)
            for ( int y = 0; y < 8 ; y++)
                m_table[x][y] = table[x][y];
        //检查列
        for (i = 0; i < T_MAX; i++){
            //如果可以放置
            if (m_table[count][i] == 1) {
                //竖直禁用
                for (k = 0; k < 8; k++){
                    m_table [k][i] = 0;
                    m_table [count][k] = 0;
                }
                
                x=count;
                y=i;
                //左斜禁用
                while(x<8 && y<8){
                    
                    m_table[x++][y++] = 0;
                    
                }
                
                x=count;
                y=i;
                //右斜禁用
                while(x<8 && y>=0){
                    
                    m_table[x++][y--] = 0;
                    
                }
                //放棋
                m_table[count][i] = 9;
                
                //判断行
                if (count < 7) {
                    queen(count+1, m_table);
                }
                else{
                    //如果底行输出
                    /*for (x = 0; x < 8; x++){
                        for ( int y = 0; y < 8 ; y++)
                            printf("%d ",m_table[x][y]);
                        printf("\n");
                    }
                    printf("The %d Answer\n\n",T_count);*/
                    T_count++;
                }
                //恢复棋盘
                for (x = 0; x < 8; x++)
                    for (y = 0; y < 8 ; y++)
                        m_table[x][y] = table[x][y];
                
            }
            
        }
    
    return 0;
    
}