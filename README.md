# ConsoleAnimation-tui-cpp
A TUI Library for Linux Consoles to make animation.Use this library,you can make a program just like `sl'.
# Documentation
## Structures
```
struct CASize
```
### Member Variable Values
```
width
```
The width of canva.
```
height
```
The height of canva.

### Initialize and Deinitialize Methods
None.

## Classes

```
class CACanvas
```

### Properties and methods
```
protected:
```
```
char** data
```
The data of a canva.
```
CASize size
```
The size of the canva,with character counts.
```
public:
```

```
CACanvas(int x,int y);
```
The initialize method.`x`is the width of canva,and `y` is the height of canva.

```
~CACanvas();
```
Deinitialize method.

```
void draw();
```
Draw the content of canva to the console.

```
CASize getSize();
```
Get the size of the canva.

```
char getContent(int x,int y);
```
Get content with a position.`x` is the x-value in position that start by left character,and `y` is the y-value in position that start by top character.

```
void setContent(char c,int x,int y);
```
Same as `getContent()`,just the method `get` is turn to `set`.`c` is the character that you want to set.
<!-- Update to there,I am gonna sleep.-->
