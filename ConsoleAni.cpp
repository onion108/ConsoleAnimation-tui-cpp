#include "ConsoleAni.h"

// CACanvas
CACanvas::CACanvas(int x,int y) {
    data = new char*[y];
    for(int i = 0;i < y;i++) {
        data[i] = new char[x];
    }
    size = CASize();
    size.width = x;
    size.height = y;
    for(int i = 0;i < y;i++) {
        for(int j = 0;j < x;j++) {
            data[i][j] = DEFAULT_PADDING_CHAR;
        }
    }
}
CACanvas::~CACanvas() {
    for(int i = 0;i < size.height;i++) {
        delete data[i];
    }
}
void CACanvas::draw() {
    for(int i = 0;i < size.height;i++) {
        for(int j = 0;j < size.width;j++) {
            putchar(data[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
CASize CACanvas::getSize() {
    return this -> size;
}
char CACanvas::getContent(int x,int y) {
    return data[y][x];
}
// Position:
// [0][0] [0][1] [0][2] ...
// [1][0] [1][1] [1][2] ...
// ...
// -> [y][x]
void CACanvas::setContent(char c,int x,int y) {
    data[y][x] = c;
}

/**********************************************************************************************************/
/**
 * CAFlashAnimation(CACanvas **data,long t);
 * void setGapTime(long us);
 * CACanvas *getFlash(int index);   // index Start from 0
 * void start();
 * that's all that I should to implement.
 * I write it here because my IDE is OnlineGDB.
 * WOWIE! ^_^
 */
CAFlashAnimation::CAFlashAnimation(CACanvas **data,long t) {
    this -> flashes = data;             // I enjoy add a "this ->" before calling,getting or setting a property or a method
    this -> useconds = t;               // This habit let me feeling very cool! B-D
    // Oh,it looks like there's nothing.This is the simplest initalize method my wrote!
}
void CAFlashAnimation::setGapTime(long us) {
    this -> useconds = us;
}
// When I wrote there and check it by compile it,IDE found some bugs.
// I found that sometime when you resolve a bug,the other bugs will be auto resolved,too.
CACanvas* CAFlashAnimation::getFlash(int index) {
    return this -> flashes[index];
}
// Well I never write a method like this,so B-
// I don't sure what will happen.
void CAFlashAnimation::start(void) {
    int tIdx;
    while(this -> flashes[tIdx]) {
        system("clear");
        this -> flashes[tIdx] -> draw();
        usleep(this -> useconds);
        tIdx++;
    }
}