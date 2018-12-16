// Helper functions for music program

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "helpers.h"


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numer = atoi(&fraction[0]);
    int denom = atoi(&fraction[2]);
    if (denom == 2)
    {
        numer = numer *4;
    }
    if (denom == 4)
    {
        numer = numer*2;
    }
    if (denom == 1)
    {
        numer = numer*8;
    }
    return numer;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int Note;
    int Octave;
    int SoF = 0;                    // default sharp or flat is 0
    int freq = 0;                   // initialize to zero for test compiling

    double fq=440.0;                  // starting at A4 = 440Hz
    double expon;

    if (strlen(note) == 3)
    {
        Octave = atoi(&note[2]);    // possible numbers in Octave are now 0 to 8
        SoF = (int)note[1];         // possible numbers in SoF are 35 if #(sharp) and 98 if b(flat)

        // adjust for sharp/flat notes between letter notes
        if (note[0] == 'A')         // Start A at 65 (int value of 'A')
            Note = 65;
        if (note[0] == 'B')         // move B to 67 due to semitone A# between A and B
            Note = 67;
        if (note[0] == 'C')         // move C to 56 due to -9 semitones between A and C in same octave
            Note = 56;
        if (note[0] == 'D')         // move D to 58 as above
            Note = 58;
        if (note[0] == 'E')         // move E to 60 as above
            Note = 60;
        if (note[0] == 'F')         // move F to 61 as above
            Note = 61;
        if (note[0] == 'G')         // move G to 63 as above
            Note = 63;
        if (SoF == 35)          // adjust for sharp or flat note
        {
            Note = Note + 1;
        }
        if (SoF == 98)
        {
            Note = Note -1;
        }
    }
    if (strlen(note) == 2)
    {
        Octave = atoi(&note[1]); // possible numbers in Octave are now 0 to 8
        // adjust for sharp/flat notes between letter notes
        if (note[0] == 'A')         // Start A at 65 (int value of 'A')
            Note = 65;
        if (note[0] == 'B')         // move B to 67 due to semitone A# between A and B
            Note = 67;
        if (note[0] == 'C')         // move C to 56 due to -9 semitones between A and C in same octave
            Note = 56;
        if (note[0] == 'D')         // move D to 58 as above
            Note = 58;
        if (note[0] == 'E')         // move E to 60 as above
            Note = 60;
        if (note[0] == 'F')         // move F to 61 as above
            Note = 61;
        if (note[0] == 'G')         // move G to 63 as above
            Note = 63;
    }

    expon = ((Note-65)%12);  // convert Notes to base 0 (A=0) rotating from 0 to 11
    fq = fq*pow(2,expon/12.0); // 2^n/12 * base A4 = 440 Hz
    fq = fq*pow(2,(double)Octave-4); // convert to octave, centered at 4

    freq = (int)(round(fq));  // round to nearest whole number, then cast to int
    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

