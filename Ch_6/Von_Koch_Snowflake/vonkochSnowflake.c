#include <graphics.h>
#include <stdio.h>
#include <math.h>

#define max_stack 100
int grboard = DETECT, grmode, grresult;
double angle, ang_stack[max_stack], tmp_stack[max_stack];

void initialize(double stack[]) {
    stack[0] = 0.0;
}

void empty(double stack[]) {
    return stack[0] == 0.0;
}

void full(double stack[]) {
    return (int)stack[0] == max_stack - 1;
}

double pop(double stack[]) {
    return stack[(int)stack[0]--];
}

void push(double angle, double stack[]) {
    if (!full(stack)) { stack[(int) ++stack[0]] = angle; }
    else { outtext("Stack overflow"); }
}

void forward(float distance) {
    /*arguements to sin() have to be in radians, hence the pi/180*/
    linerel((int) (cos(angle * M_PI/180) * distance), (int) (sin(angle * M_PI/180) * distance));
}

void three_pushes(double stack[]) {
    push(-60.0, stack);
    push(120.0, stack);
    push(-60.0, stack);
}

void side(float size, int level) {
    char i;
    three_pushes(ang_stack);
    size /= 3;
    initialize(tmp_stack);
    for(i = 2; i <= level ; i++) {
        size /= 3;
        while (!empty(ang_stack)) {
            three_pushes(tmp_stack);
            push(pop(ang_stack), tmp_stack);
        }
        three_pushes(tmp_stack);
        while (!empty(tmp_stack)) {
            push(pop(tmp_stack), ang_stack);
        }
    }
    forward(size);
    while (!empty(ang_stack)) {
        angle += pop(ang_stack);
        forward(size);
    }
}

void snowflake(float size, int level) {
    for (int i = 1; level > 0 && i <= 3; i++) {
        initialize(ang_stack);
        side(size, level);
        angle += 120;
    }
}

int main() {
    detectgraph(&grboard, &grmode);
    switch(grboard) {
        case EGA:       grmode = EGAHI; break;
        case EGA64:     grmode = EGA64LO; break;
        case VGA:       grmode = VGAHI; break;
        default:        fprintf(stderr, "Needs EGA compatible board\n"); return 1;
    }
    initgraph(&grboard, &grmode, "");
    if ((grresult = graphresult()) < 0) {
        fprintf(stderr, "%s\n", grapherrormsg(grresult));
    }
    setcolor(WHITE);
    setbkcolor(BLUE);
    moveto(200, 150);
    angle = 0.0;
    snowflake(300, 2);
    return 0;
}