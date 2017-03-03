//
//  main.c
//  ReadWAVHeader
//
//  Created by Mathias Lyngklip Kjeldgaard on 03/03/2017.
//  Copyright © 2017 Mathias Lyngklip Kjeldgaard. All rights reserved.
//

#include <stdio.h>

// #define DEBUG_Mine 1

// #define WAVE_FILEN "kick.wav"
// const char WAVE_FILEN[] = "kick.txt";
#ifdef DEBUG_Mine
    const char WAVE_FILEN[] = "kick.wav";
#endif


int main(int argc, const char * argv[]) {
    printf("\n\n\n\n");
    
    
    
#ifdef DEBUG_Mine
    // insert code here...
    printf("argc: %d\n", argc);
    // printf("argv[%d]: %s\n", argv[argc]);
    for(int i = 0; i <= sizeof(&argv);i++){
        printf("%s\n", argv[i]);
    }
#endif
    
    FILE * wave_file = NULL;
#ifndef DEBUG_Mine
    if(argc > 1){
        // printf("Got a filename from parameter\n");
        wave_file = fopen(argv[1], "r");
        if(wave_file == NULL){
            // It failed opening the file
            return -1;
        }
    } else
    {
        printf("Okay, you did not specifi a filename.\nEnter one now\n");
        do{
            
            char tempName[101];
            scanf("%s", tempName);
            wave_file = fopen(tempName, "r");
            if(wave_file == NULL){
                printf("Oops, wrong name, try again.\n");
            }
        } while(wave_file == NULL);
    }// else
#endif
    
    
    
    
    
#if DEBUG_Mine == 1
    wave_file = fopen(WAVE_FILEN, "r");
    if(wave_file == NULL){
        printf("Something went wrong\n");
    } else { printf("Alt er godt!\n"); }
#endif
    
    
    
    // Okay, filen er åben!
    
    
    // fpos_t position;
    // fsetpos(wave_file, &position); // Nu står vi i starten af filen
    
    
    // char buffer[100];
    /* Read and display data */
    // fread(buffer, 2, 1, wave_file);
    
    
    
    // 20 = AudioFormat
    fseek(wave_file, 20, SEEK_SET); // Nu er vi i staren af det vi vil have!
    
    
    char *tempChar = NULL;
    
    
    
    // printf("tempChar: %X\n", tempChar);
    fread(&tempChar, 2, 1, wave_file); // AudioFormat
    int AudioFormat = 0;
    AudioFormat = (unsigned)(int)tempChar;
    printf("AudioFormat: %d\n", AudioFormat);
    
    
    
    // Number of channels
    fread(&tempChar, 2, 1, wave_file); // NumChannels
    int NumChannels = 0;
    NumChannels = (unsigned)(int)tempChar;
    printf("NumChannels: %d\n", NumChannels);
    tempChar = NULL;
    
    
    // Samplerate
    fread(&tempChar, 4, 1, wave_file); // SampleRate
    int SampleRate = 0;
    SampleRate = (unsigned)(int)tempChar;
    printf("SampleRate: %d\n", SampleRate);
    tempChar = NULL;
    
    
    // ByteRate
    fread(&tempChar, 4, 1, wave_file); // ByteRate
    int ByteRate = 0;
    ByteRate = (unsigned)(int)tempChar;
    printf("ByteRate: %d\n", ByteRate);
    tempChar = NULL;
    
    
    // BlockAlign
    fread(&tempChar, 2, 1, wave_file); // BlockAlign
    int BlockAlign = 0;
    BlockAlign = (unsigned)(int)tempChar;
    printf("BlockAlign: %x\n", BlockAlign);
    tempChar = NULL;
    
    
    // BitsPerSample
    // fseek(wave_file, 33, SEEK_SET);
    fread(&tempChar, 2, 1, wave_file); // BitsPerSample
    int BitsPerSample = 0;
    BitsPerSample = (unsigned)(int)tempChar;
    printf("BitsPerSample: %x\n", BitsPerSample);
    tempChar = NULL;
    
    
    return 0;
}




