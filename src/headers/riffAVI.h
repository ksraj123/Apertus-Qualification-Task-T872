#ifndef AVI_H
#define AVI_H

#include "functional.h"

struct MainAVIHeader
{
    uint32_t  MicroSecPerFrame {1000000};
    uint32_t  MaxBytesPerSec {max_height * max_width * 3 + 1000};
    uint32_t  PaddingGranularity {2048};
    uint32_t  Flags {0};
    uint32_t  TotalFrames {1};
    uint32_t  InitialFrames {0};
    uint32_t  Streams {1};
    uint32_t  SuggestedBufferSize {max_height * max_width * 3};
    uint32_t  Width {max_width};
    uint32_t  Height {max_height};
    uint32_t  Reserved[4] {0};
} ;

struct AVIStreamHeader
{
    char fccType[4] {'v', 'i', 'd', 's'};
    char fccHandler[4] {'R', 'A', 'W', ' '}; //optioanl
    uint32_t  Flags{0};
    uint16_t  Priority{0};
    uint16_t  Language{0};
    uint32_t  InitialFrames{0};
    uint32_t  Scale{1};
    uint32_t  Rate{1};
    uint32_t  Start{0};
    uint32_t  Length{1};
    uint32_t  SuggestedBufferSize{max_height * max_width * 3};
    int32_t   Quality{-1};
    uint32_t  SampleSize{0};
    struct
    {
        uint16_t left{0}; // x coordinate of upper left corner
        uint16_t top{0}; // y coordinate of upper left corner
        uint16_t right{max_width}; // x coodinate of lower right corner
        uint16_t bottom{max_height}; // y coordinate of lower right corner
    }  rcFrame;
};

struct AVIStreamFormat
{
    uint32_t headerSize {40};
    uint32_t width {max_width};
    uint32_t height {max_height};
    uint16_t planes {1};
    uint16_t bitsPerPixel {24};
    uint32_t compression {0};
    uint32_t dataSize {0};
    uint32_t horizontalResolution {2400};
    uint32_t verticalResolution {2400};
    uint32_t colours{0};
    uint32_t importantColors {0};
};

void WriteToAvi(uint8_t*, uint8_t*, uint8_t*);

#endif
