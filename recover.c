#include <stdio.h>
#include <stdlib.h>

//declare function that will test buffer
int buffertest (unsigned char buffer[]);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename.raw\n");
        return 1;
    }

    // read in file
    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // store 512 bytes in array called buffer
    unsigned char buffer[512];
    fread(&buffer, sizeof(unsigned char),512,inptr);
    //int catch4test = 0; - done for testing
    int JPGct = 0;
    int test = 512;
    while (test == 512) //&& catch4test < 60)
    {
            if (buffertest(buffer) == 0)                                    // if at start of jpeg file (first 3 bytes meet condition)
            {
                char filename2[sizeof("XXX.jpg")];                          // create filename
                sprintf(filename2, "%03d.jpg",JPGct);                       // determine and store file name
                JPGct +=1;                                                  // increment picture number
                FILE *outptr2 = fopen(filename2, "w");                      // open output file
                if (outptr2 == NULL)
                    {
                        fclose(inptr);
                        fprintf(stderr, "Could not create %s.\n", filename2);
                        return 3;
                    }
                    fwrite(&buffer,sizeof(unsigned char), 512,outptr2);     // write to jpeg file
                    test = fread(&buffer, sizeof(unsigned char),512,inptr); // store next 512 bytes, test if fread got a whole 512 bytes, if not it is at end of file
                    while (buffertest(buffer)!=0 && test == 512)            // while not at start of new jpeg and while fread got 512 bytes
                        {
                                fwrite(&buffer,sizeof(unsigned char), 512,outptr2);         // keep writing to same jpeg file
                                test = fread(&buffer, sizeof(unsigned char),512,inptr);     // get next 512 bytes
                        }
                        fclose(outptr2);
            }
            else
            {
                fread(&buffer, sizeof(unsigned char),512,inptr);            // keep reading 512 bytes until find first start of jpeg
            }
        //catch4test++;
    }

    // close infile
    fclose(inptr);

return 0;
}

int buffertest (unsigned char buffer[]) //function that returns 0 if at start of jpeg file and 1 otherwise - made function because the if statements were so long
{
    if ((buffer[0]==0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] <= 0xef && buffer[3]>=0xe0 )) //conditions for bytes at start of jpeg
        return 0;
    else
        return 1;
}
