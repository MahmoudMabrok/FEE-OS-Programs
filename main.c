#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

/*

C Program to copy file to another one
steps ::

 * first open source files
 * read content of it
 * create another file
 * loop to write read bytes int new file

i use open() with O_CREAT  to create a new file instead of use creat() call

*/

int main( )
{
    int  fd1  , fd2  , n_read , n_write  ;
    char buffer  [2048]  ;


    fd1 = open("f.txt" , O_RDWR , 0666) ; // open with create if not exist
    if (fd1 == -1 )
    {
        perror("Program") ; //display message with error description
        exit(1);
    }

    fd2 = open("f_copy.txt"  , O_CREAT | O_RDWR  , 0666) ; // copied file creation
    if (fd2 == -1 )
    {
        perror("Program") ;
        exit(1);
    }

    while( (n_read = read( fd1,buffer,2048)) > 0  ) // continue in read operation as bytes of read is greater than 0
    {
        printf("n of read bytes %d \n" , n_read ) ; // display count of bytes read

        n_write =  write(fd2 , buffer , n_read) ; // write in fd2 , with data in buffer , length of n_read

        if ( n_write != n_read) // check count of bytes written with count of bytes read
        {
            printf("error in writing \n") ;
            exit(1) ;
        }
        printf("success write %d \n " , n_write ) ; //display count of bytes written
    }

    printf("finish  copying \n") ;
}
