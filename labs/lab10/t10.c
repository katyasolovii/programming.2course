#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#define LEN 255

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

void outputDate(Date d){
    printf("%02d/%02d/%04d\n", d.day, d.month, d.year);
}

int inputDate(Date* d){
    printf("Input year, month, day: ");
    return scanf("%d %d %d", &d->year, &d->month, &d->day);
}

void task1_a() {
    Date today;
    
    if (inputDate(&today) == 3) { 
        outputDate(today);
    } else {
        printf("Invalid input. \n");
    }
}

typedef struct Chess_board{
    unsigned char horisontal;
    char vertical;
} Chess_board; 

void output_cell(Chess_board c){
    printf("Cell: %c%d\n", c.vertical, c.horisontal);
}

int input_cell(Chess_board* c){
    printf("Enter vertical (a-h or A-H): ");
    scanf(" %c", &c->vertical);
    printf("Enter horisontal (1-8): ");
    scanf("%hhu", &c->horisontal);
    if ((c->vertical >= 'a' && c->vertical <= 'h' || c->vertical >= 'A' && c->vertical <= 'H') &&
        (c->horisontal >= 1 && c->horisontal <= 8)) {
        return 0; 
    }
    return 1;
}

void task1_b(){
    Chess_board cell;
    if (input_cell(&cell) == 0) {
        output_cell(cell); 
    } else {
        printf("Invalid input. \n");
    }
}

typedef struct Vertex{
    long double x;
    long double y;
} Vertex;

void output_vectex(Vertex v){
    printf("%Lg %Lg", v.x, v.y);
};

Vertex inputvertex(){
    Vertex res;
    printf("x, y = ");
    scanf("%Lg %Lg", &res.x, &res.y);
    return res;
}

typedef struct Rectangle{
    Vertex v1;
    Vertex v2;
} Rectangle;

void outputRectangle(const Rectangle* r){
    output_vectex(r->v1);
    printf("\t");
    output_vectex(r->v2);
    printf("\n");
}

int inputRectangle(Rectangle* r){
    r->v1 = inputvertex();
    r->v2 = inputvertex();
    return 0;
}

void task1_c(){
    Rectangle rect;
    inputRectangle(&rect); 
    outputRectangle(&rect);
}

typedef struct Poly
{
    unsigned n;
    double *a;
} Poly;

void output_pol(Poly p) {
    for (int i = 0; i < p.n; i++) {
        printf("%lf * x^%d + ", p.a[i], i);
    }
    printf("%lf * x^%d \n", p.a[p.n], p.n);
}

int inputPoly(Poly* p) {
    printf("Enter n: ");
    scanf("%d", &(p->n));
    p->a = (double*)calloc(p->n + 1, sizeof(*(p->a)));

    for (int i = 0; i <= p->n; i++) {
        printf("Enter x^%d: ", i);
        scanf("%lf", &(p->a[i]));
    }
    return 0;
}

void deletePoly(Poly* p) {
    if (p->a) {
        free(p->a);
    }
}

void task1_g() {
    Poly p;
    inputPoly(&p);
    output_pol(p);
    deletePoly(&p);
}

bool hitQueen(Chess_board f1, Chess_board f2) {
    return (f1.horisontal == f2.horisontal) ||
           (f1.vertical == f2.vertical) ||
           (abs(f1.vertical - f2.vertical) == abs(f1.horisontal - f2.horisontal));
}

void task2(){
    Chess_board cell1, cell2;
    printf("Input the first cell:\n");
    input_cell(&cell1);
    printf("Input the second cell:\n");
    input_cell(&cell2);
    output_cell(cell1);
    output_cell(cell2);
    if (hitQueen(cell1, cell2)) {
        printf("The queen can move in one move. \n");
    } else {
        printf("The queen cannot move in one move. \n");
    }
}


int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year){
    int MONTHDAY[] = {31, 28, 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31};
    if (month == 2 && isLeapYear(year)){
        return 29;
    }
    return MONTHDAY[month-1];
}

Date tomorrow(Date d){
    d.day++;
    // якщо день перевищує к-сть днів у поточному місяці
    if (d.day > days_in_month(d.month, d.year)){
        d.day = 1;
        d.month++;
        // якщо грудень, рік++
        if (d.month > 12){
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

// Алгоритм обчислення дня тижня - формула з вікіпедії
int day_of_week(Date d) {
    int day = d.day;
    int m = d.month;
    int y = d.year % 100;
    int c = d.year / 100;
    int a = (14 - m) / 12;
    int b = y - a;
    int f = m + 12 * a - 2;

    int day_of_week = (day + b + (b / 4) - (b / 100) + (b / 400) + (31 * f) / 12) % 7;
    return day_of_week;
}

void task3() {
    Date d;
    if (inputDate(&d) == 3) {
        printf("Current date: ");
        outputDate(d);

        Date t = tomorrow(d);
        printf("Tomorrow's date: ");
        outputDate(t);

        int dow = day_of_week(d);
        const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        printf("Day of the week: %s\n", days[dow]);
    } 
    else {
        printf("Invalid input.\n");
    }
}

typedef struct Mount
{
    char Name[LEN];
    int height;
} Mount;

void input_Mount(Mount* m){
    printf("Enter the name of the mountain: ");
    scanf("%s", m->Name);
    printf("Enter the height of the mountain: ");
    scanf("%d", &m->height);
}

void output_Mount(Mount* m){
    printf("Mountain: %s, Height: %d\n", m->Name, m->height);
}

Mount find_highest(const Mount* m, int n){
    Mount highest = m[0];
    for (int i=0; i < n; i++){
        if (m[i].height > highest.height){
            highest = m[i];
        }
    }
    return highest;
}

int find_height_by_name(const Mount* m, const char* name, int n){
    for (int i=0; i < n; i++){
        if (strcmp(m[i].Name, name) == 0) {
            return m[i].height;
        }
    }
    return 1;
}

void task5(){
    int N;
    printf("N = ");
    scanf("%d", &N);
    Mount* mut = (Mount*)calloc(N, sizeof(Mount));
    for (int i=0; i < N; i++){
        input_Mount(&mut[i]);
    }
    Mount highest = find_highest(mut, N);
    printf("The highest mountain is: %s , height of %d\n", highest.Name, highest.height);

    char title[LEN];
    printf("Enter the name of the mountain: ");
    scanf("%s", title);
    int height = find_height_by_name(mut, title, N);
    
    if (height != 1) {
        printf("The height of mountain %s is: %d\n", title, height);
    } else {
        printf("Mountain with name '%s' not found.\n", title);
    }
    free(mut);
}

int main(){
    int task;
    printf("task = ");
    scanf("%d", &task);

    if (task == 1){
        task1_a();
        task1_b();
        task1_c();
        task1_g();
    }
    else if (task == 2)
    {
        task2();
    }
    else if (task == 3)
    {
        task3();
    }
    else if (task == 5)
    {
        task5();
    }
    
}
