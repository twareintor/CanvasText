//Permanent link: https://rextester.com/CCAB72954
//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64
//two-dim array of chars canvas to draw in
//Code by Twareintor - Copyright (c) 2018 Claudiu Ciutacu #lt:mliato:ciutacu/0[gma!1?cOm#gt:

#include "canvas.h"

int main(void)
{
    printf("Hello, world!\n");
    char** canvas;
    int dims[] = {100, 100};
    makeCanvas(&canvas, dims[0], dims[1]);
    // test_draw(&canvas);
    test_draw2(&canvas);
    printCanvas(canvas, dims[0], dims[1]);
    deleteCanvas(&canvas, dims[0], dims[1]);
    printf("Game Over\n");
    return 0;
}

void makeCanvas(char*** ppcanvas, int width, int height)
{
    int i; /* rows */
    *ppcanvas = (char**)malloc(height*sizeof(char*));
    for(i=0; i<height; i++)
    {
        (*ppcanvas)[i] = (char*)malloc((width+1)*sizeof(char));
        memset((*ppcanvas)[i], ' ', width);
        (*ppcanvas)[i][width] = 0;
    }
}

void printCanvas(char** pcanvas, int width, int height)
{
    int i; 
    printf("/");
    for(i=0; i<width; i++) printf("-");
    printf("\\\n");
    for(i=0; i<height; i++)
    {
        printf("|%s|\n", pcanvas[i]);
    }
    printf("\\");
    for(i=0; i<width; i++) printf("-");
    printf("/\n");
}

void deleteCanvas(char*** ppcanvas, int width, int height)
{
    int i;
    for(i=0; i<height; i++)
    {
        free((*ppcanvas)[i]);
    }
    free(*ppcanvas);
}

void test_draw2(char*** ppcanvas)
{
    (*ppcanvas)[3][4] = 'A';
    (*ppcanvas)[3][5] = 'B';
    (*ppcanvas)[4][6] = 'C';
    (*ppcanvas)[5][7] = 'D';
    (*ppcanvas)[12][11] = 'X';
    (*ppcanvas)[13][10] = 'Y';
    (*ppcanvas)[14][9] = 'Z';
    (*ppcanvas)[8][12] = '#';
}

void test_draw(char*** ppcanvas)
{
    int i, j;
    for(i=8; i<32; i++)
    {
        for(j=4; j<36; j++)
        {
            if(i==8 || i==31)
                (*ppcanvas)[i][j] = '#';
            else
                if(j==4 || j==35)
                    (*ppcanvas)[i][j] = '#';
        }
    }
}

