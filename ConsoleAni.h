#ifndef CONSOLE_ANIMAION
#define CONSOLE_ANIMAION

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef LIB_DEBUG
#define DEFAULT_PADDING_CHAR ' '
#else
#define DEFAULT_PADDING_CHAR '*'
#endif

struct CASize {
    int width;
    int height;
};
class CACanvas {
    protected:
    char **data;
    CASize size;
    public:
    CACanvas(int x,int y);
    ~CACanvas();
    void draw();
    CASize getSize();
    char getContent(int x,int y);
    void setContent(char c,int x,int y);
};
class CAFlashAnimation {
    protected:
    CACanvas** flashes;    // Should End By NULL
    long useconds;
    public:
    CAFlashAnimation(CACanvas **data,long t);
    void setGapTime(long us);
    CACanvas *getFlash(int index);   // index Start from 0
    void start();
};
#endif
