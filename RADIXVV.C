#include <stdio.h>
#include <conio.h>

#define SIZE 12
#define COLOR YELLOW
#define color WHITE
#define NO_GETCH 0
#define GETCH 1
//#define PASS_PRINT

int arr[] = {123,784,345,275,987,457,271,125,825,331,284,701};
int buckets[SIZE];
int h1[10];
int temp,getch_flag = GETCH,key,delay_Value = 100;


int whoIsMax() {
   int ctr;
   int max = 0;
   for( ctr = 0 ; ctr < SIZE ; ctr++ ) {
      if( arr[ ctr ] > max )
	 max = arr[ ctr ];
   }
   return max;
}

int howManyDigits( int num ) {
   int ctr;
   for( ctr = 0 ; num ; ctr++ ) {
      num = num / 10;
   }
   return ctr;
}

void initializeHelpers() {
   int ctr;
   for( ctr = 0 ; ctr < 10 ; ctr++ ) {
      h1[ ctr ] = 0;

   }
}

void drawDabba()
{
  int row = 2 , col , ctr,ctr1;
    col = (80 - 61 ) / 2;
   gotoxy(col,row);
   cprintf("%c",218);
   for( ctr1 = 0 ; ctr1 < SIZE ; ctr1 ++)  {
   for( ctr = 0 ; ctr < 4 ; ctr ++)
     cprintf( "%c", 196 );
   cprintf( "%c", 194 );
   }
   cprintf("\b%c",191);
   gotoxy(col,++row);
   for( ctr = 0 ; ctr < SIZE + 1 ; ctr ++ ) {
   cprintf( "%c", 179 );
   cprintf( "    " );
   }
   gotoxy(col ,++row);
   cprintf("%c",192 );
   for( ctr1 = 0 ; ctr1 < SIZE ; ctr1++ )  {
   for(ctr =  0 ; ctr < 4 ; ctr ++)
     cprintf( "%c", 196 );
   cprintf( "%c", 193);

   }
   cprintf( "\b%c",217 );
}
void fillDabba()
{
  int row = 3, col = 10, ctr;
  char str[10];
  for( ctr = 0 ; ctr < SIZE ; ctr ++)  {
     gotoxy( col + ctr * 5, row );
    // cprintf( "%d", arr[ctr] );
      sprintf(str,"%4d",arr[ctr]);
      textcolor(COLOR);
      cprintf("%s",str);
  }
}
void drawBucket() {
   int row = 21, col = 6, ctr,ctr1 ;
    //base
   gotoxy(col,row);
   for( ctr1 = 0 ; ctr1 < 10 ; ctr1 ++ )  {
   cprintf( "%c", 192 );
   for( ctr = 0  ; ctr < 4 ; ctr++ )
      cprintf( "%c", 196 );
   cprintf( "%c", 217 );
   cprintf( " ");

   }
   for(ctr=0;ctr<10;ctr++){
   gotoxy( 8 + ctr* 7 , 22 );
  cprintf( "%d", ctr);
}
}

void buildBucket(int size, int index , int row_pos)
{
   int col=6,ctr;
   for(ctr = 0 ; ctr<size;ctr++)
   {
      gotoxy(col+index*7,row_pos--);
      cprintf("%c",179);
      cprintf("    ");
      cprintf("%c",179);
   }
}
void fillBucket(int value , int index , int row_pos)
{
   char str[10];
   int col=7;
   gotoxy( col+index*7 , row_pos);
   sprintf(str,"%4d",value);
   textcolor(COLOR);
   cprintf("%s",str);

}

void EraseDabbaValue(int ctr)
{
  int row = 3, col = 10;
     gotoxy( col + ctr * 5, row );
     cprintf( "    " );
}
void fillArray(int value, int ctr)
{
   char str[10];
   int col = 10;
   int row = 3;
   gotoxy( col+ctr*5 , row);
   sprintf(str,"%4d",value);
   textcolor(COLOR);
   cprintf("%s",str);
}
void eraseBucketValue(int index,int row_pos)
{
   int col = 7;
   gotoxy(col+index*7,row_pos);
   cprintf("    ");
}
void stepDown(int index)
{
   char str[10];
   int col = 10;
   EraseDabbaValue(index);

   delay(delay_Value);
   gotoxy( col+index*5 , 5);
   sprintf(str,"%4d",arr[index]);
   textcolor(COLOR);
   cprintf("%s",str);
   delay(delay_Value);
   key = bioskey(1);
if(key!=0)
{
key = bioskey(0);
if(key==16896) getch_flag = NO_GETCH;
else if(key==19712)
delay_Value=(delay_Value<10)?10:delay_Value-10;
else if(key==19200)
delay_Value=(delay_Value>200)? 200:delay_Value+10;
//else if(key==15104) sorthelp();
}


   gotoxy(col+index*5,5);
   cprintf("    ");

}
void stepDownAndMove(int index,int bucket_index,int bucket_row)
{
   char str[10];
   int col = 10;
   int bucket_col =7;
    int diff_col,diff_row,ctr,c_if,c_else,i;
    sprintf(str,"%4d",arr[index]);
  gotoxy(col+index*5,5);
  cprintf("    ");
  delay(delay_Value);
  if((col+index*5)>(bucket_col+bucket_index*7))
  {

     diff_col = (col+index*5)-(bucket_col+bucket_index*7);

     for( ctr =0; ctr<diff_col;ctr++)
     {   c_if=(col+index*5)-(ctr+1)  ;
	 gotoxy(c_if,5);
	 textcolor(COLOR);
	 cprintf("%s",str);
	 delay(delay_Value);
	 gotoxy(c_if,5);
	 cprintf("    ");
	 key = bioskey(1);
if(key!=0)
{
key = bioskey(0);
if(key==16896) getch_flag = NO_GETCH;
else if(key==19712)
delay_Value=(delay_Value<10)?10:delay_Value-10;
else if(key==19200)
delay_Value=(delay_Value>200)? 200:delay_Value+10;
//else if(key==15104) sorthelp();

}}
     diff_row=bucket_row-6  ;
     for(i = 0; i < diff_row ;i++)
     {
	gotoxy(c_if,6+i);
	//cprintf("%d",arr[index]);
	textcolor(COLOR);
	 cprintf("%s",str);
	delay(delay_Value);
	gotoxy(c_if,6+i);
	cprintf("    ");
	key = bioskey(1);
if(key!=0)
{
key = bioskey(0);
if(key==16896) getch_flag = NO_GETCH;
else if(key==19712)
delay_Value=(delay_Value<10)?10:delay_Value-10;
else if(key==19200)
delay_Value=(delay_Value>200)? 200:delay_Value+10;

//else if(key==15104) sorthelp();
}
}

     }

   else
   {
       diff_col=(bucket_col+bucket_index*7)-(col+index*5);
       for(ctr=0;ctr<diff_col;ctr++)
       {
	  c_else= (col+index*5)+(ctr+1)  ;
	  gotoxy(c_else,5);
	 //cprintf("%d",arr[index]);
	 textcolor(COLOR);
	 cprintf("%s",str);
	 delay(delay_Value);
	 gotoxy( c_else,5);
	 cprintf("    ");
	 key = bioskey(1);
if(key!=0)
{
key = bioskey(0);
if(key==16896) getch_flag = NO_GETCH;
else if(key==19712)
delay_Value=(delay_Value<10)?10:delay_Value-10;
else if(key==19200)
delay_Value=(delay_Value>200)? 200:delay_Value+10;

//else if(key==15104) sorthelp();
}
 }
     diff_row=bucket_row-6  ;
     for(i = 0; i < diff_row ;i++)
     {
	gotoxy(c_else,6+i);
       //	cprintf("%d",arr[index]);
	textcolor(COLOR);
	 cprintf("%s",str);
	delay(delay_Value);
	gotoxy(c_else,6+i);
	cprintf("    ");
	key = bioskey(1);
if(key!=0)
{
key = bioskey(0);
if(key==16896) getch_flag = NO_GETCH;
else if(key==19712)
delay_Value=delay_Value<10?delay_Value:delay_Value-10;
else if(key==19200)
delay_Value=delay_Value>200?delay_Value:delay_Value+10;
//else if(key==15104) sorthelp();

}

     }
   }
/*gotoxy(bucket_col+bucket_index*7,5);
  cprintf("%d",arr[index]);
  delay(500);
  gotoxy(bucket_col+bucket_index*7,5);
  cprintf("    ");*/
}
void blinker(int value,int pos,int row,int col,int color)
{
   int ctr;
   char str[10];
   sprintf(str,"%4d",value);


for(ctr=0;str[ctr];ctr++)
{
gotoxy(col++,row);
if(pos==1)
{
textcolor(color+BLINK);
cprintf("%c",str[ctr]);
textcolor(COLOR);
}
else
{
textcolor(COLOR);
cprintf("%c",str[ctr]);
}
pos--;
}
}

void printmessages()
{
gotoxy(6,24);
textcolor(YELLOW);
cprintf("%c Press ",1);
textcolor(RED);
cprintf("F8 ");
textcolor(YELLOW);
cprintf("to Disable getch() %c",1);
textcolor(CYAN);
cprintf(" - Press %c to increase && %c to Reduce",0x1a,0x1b);
}

void main() {
   int ctr1,ctr2;
   int ctr;
   int max;
   int digits;
   int divisor = 1;
   clrscr();

   max = whoIsMax();
   digits = howManyDigits(max);
   printmessages();
   drawDabba();
   fillDabba();

   for( ctr1 = 0 ; ctr1 < digits ; ctr1++ ) {
       int row_pos[10] = {20,20,20,20,20,20,20,20,20,20};
       int row_pos1[10] = {20,20,20,20,20,20,20,20,20,20};
      initializeHelpers();
      for(ctr=0;ctr<SIZE;ctr++)
      {
	  blinker(arr[ctr],(4-(ctr1)),3,10+ctr*5,color);
      }
      for( ctr = 0 ; ctr < SIZE ; ctr++ ) {

	 h1[ (arr[ ctr ] / divisor) % 10 ]++;    //  h1[0]++;
	 drawBucket();
      }
       for( ctr = 0 ; ctr < 10  ; ctr++) {
	  buildBucket(h1[ctr],ctr,row_pos[ctr]);
       }
      temp = 0;
      for( ctr = 0 ; ctr < 10 ; ctr++ ) {
	 temp = temp + h1[ctr];
	 h1[ctr] = temp - h1[ctr];
      }


      for( ctr = 0 ; ctr < SIZE ; ctr++ ) {
	 buckets[ h1[( arr[ ctr ] / divisor ) % 10 ] ] = arr[ ctr ];          // buckets[0]
	 h1[ (arr[ ctr ] / divisor) % 10  ]++;
	 if(getch_flag==GETCH)
	 getch();
	 stepDown( ctr );
	 delay(delay_Value);
	 stepDownAndMove(ctr,(arr[ctr]/divisor)%10,row_pos[(arr[ctr]/divisor)%10]);
	 delay(delay_Value);
	 fillBucket(arr[ctr] , (arr[ctr]/divisor)%10 , row_pos[(arr[ctr]/divisor)%10 ]--);

	 EraseDabbaValue(ctr);

      }

      for( ctr = 0 ; ctr < SIZE ; ctr++ ) {
	 arr[ ctr ] = buckets[ ctr ];
	  fillArray(buckets[ctr],ctr);
	  delay(delay_Value);
	eraseBucketValue((buckets[ctr]/divisor)%10 ,row_pos1[(buckets[ctr]/divisor)%10]-- );

      }
       //to erase the buckets
       for(ctr = 8 ; ctr < 24 ;ctr++ )
       {
       gotoxy(1,ctr);
       clreol();
       }
      divisor = divisor * 10;

   }
   getch();
}

