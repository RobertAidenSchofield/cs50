/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{   
    
    FILE* file = fopen("card.raw", "r");
    
 
    if (file == NULL)
    {
        fclose(file); 
        printf("unable to recover file from card.raw \n");
        return 1;
    }

    // counter
    int counter = 0; 
   
    //buffer of 512 bytes
    BYTE buffer[512];
   
    // three-digit decimal number from 000 on up
    char lname[10]; 
   
    // temp file output
    FILE* temp = NULL; 

    while (!feof(file))
    {
       
        // check first couple of sequence of the jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // if already exist, then close file
            if (temp != NULL)
            {
                fclose(temp);
                
            }
            
            // label the files with three digits
            sprintf(lname, "%03d.jpg", counter);
            
            // next file in line
            temp = fopen(lname, "w");
            
            // add to counter
            counter++;
            
            // new file with buffer
            fwrite(buffer, sizeof(buffer), 1, temp);
        }
        else if (counter > 0)
        {
            // put jpg into temp
            fwrite(buffer, sizeof(buffer), 1, temp);            
            
        }
      
        fread(buffer, sizeof(buffer), 1, file);
        
    }
  
    
    // close the file
    fclose(file);

    // that's all folks
    return 0;
}