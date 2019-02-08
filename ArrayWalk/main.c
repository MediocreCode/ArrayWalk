//
//  main.c
//  ArrayWalk
//
//  Created by Raleigh Dial on 2/8/19.
//  Copyright © 2019 Raleigh Dial. All rights reserved.
//  Xcode just puts this here whenever you start a new project. I'm keeping it :)
//
//  Program looks pretty cool all things considered. Works with a million coin flips.
//  Didn't put a cap on flipNum wanted to see how far it could go, feel free to break
//  does as intended though.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    char array[11]="     *    \0";//'\0' so I don't get a random character when printing string.
    char go='y';//go yes or no
    int flipNum;// self explanitory
    srand((int)time(0));// wanted it to be random
    int r = rand()%2;
    int i=0;//this seemed better than for loop
    int starIndex=5;//used to reset string
    
    while(go!='n'){
        printf("Enter number of coin flips:\n");
        scanf(" %d",&flipNum);
        while(i<flipNum) {
            switch (r) {//wanted to just move the star instead of placing a star where it moved,
                        //so you can see if it went back on itself... just seems better to look at.
                case 0:
                    if (starIndex==9) {//Fixes out of bounds problem, just maintains wall position.
                        starIndex=8;
                    }
                    array[starIndex]=' ';
                    starIndex+=1;       //coin flip to move right
                    array[starIndex]='*';
                    i++;
                    printf("%s\n",array);
                    r = rand()%2;
                    break;
                    
                case 1:
                    if (starIndex==0) {//Fixes out of bounds problem, just maintains wall position.
                        starIndex=1;
                    }
                    array[starIndex]=' ';
                    starIndex-=1;       //coin flip to move left
                    array[starIndex]='*';
                    i++;
                    printf("%s\n",array);
                    r = rand()%2;
                    break;
            }
        }
        starIndex=5;
        for (int j=0; j<11; j++) {//puts string back together
            if(j==5){
                array[j]='*';
            }else if(j==10){
                array[j]='\0';
            }else{
                array[j]=' ';
            }
        }
        i=0;
        printf("Would you like to go again? ('y' or 'n')\n");
        scanf(" %c",&go);
    }
    return 0;
}
