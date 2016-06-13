/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    FILE* file = fopen("card.raw", "r");
    
    // file verification
        if (file == NULL)
        {
            printf("File couldn't be opened.\n");
            return 1;
        }
    
    // buffer size of 512 bytes
    uint8_t buffer[512];
    
    // number of jpg files
    int fcount = 0;
    
    //size of file name
    char filename[8];
    
    FILE *output;
    output = NULL;
    
    fread(&buffer, sizeof(buffer), 1, file);
    
    while(!feof(file))
    {
        fread(&buffer, sizeof(buffer), 1, file);
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            if (output == NULL)
            {
                sprintf(filename,"%03d.jpg",fcount);
                output = fopen(filename,"w");
                fwrite(buffer,sizeof(buffer),1,output);
                fcount++;
            }  
            else
            {
                fclose(output);
                sprintf(filename,"%03d.jpg",fcount);
                output = fopen(filename,"w");
                fwrite(buffer,sizeof(buffer),1,output);
                fcount++;
            }
        } else
        {
            if (fcount == 0)
            {
                continue;
            }
            fwrite(buffer, sizeof(buffer), 1, output);
        }
    }
    fclose(file);
}
