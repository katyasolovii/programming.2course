#include <stdio.h>

typedef struct Point{
    double x, y, z;
} Point;

typedef struct RectParallelepiped{
    Point vertices[8]; 
} RectParallelepiped;

void inputPoint(Point *p) {
    printf("Enter pointers (x y z): ");
    scanf("%lf %lf %lf", &p->x, &p->y, &p->z);
}

void Vertices(RectParallelepiped *rp, Point A, Point B) {
    rp->vertices[0] = A;
    rp->vertices[7] = B;
    rp->vertices[1] = (Point){B.x, A.y, A.z};
    rp->vertices[2] = (Point){B.x, B.y, A.z};
    rp->vertices[3] = (Point){A.x, B.y, A.z};
    rp->vertices[4] = (Point){A.x, A.y, B.z};
    rp->vertices[5] = (Point){B.x, A.y, B.z};
    rp->vertices[6] = (Point){A.x, B.y, B.z};
}

void outputPoint(Point p) {
    printf("(%.2lf, %.2lf, %.2lf)", p.x, p.y, p.z);
}

void outputRectParallelepiped(RectParallelepiped rp) {
    printf("Coordinates of the vertices: \n");
    for (int i = 0; i < 8; i++) {
        printf("The point %d: ", i + 1);
        outputPoint(rp.vertices[i]);
        printf("\n");
    }
}

int main() {
    Point A, B;
    RectParallelepiped rp;
    inputPoint(&A);
    inputPoint(&B);
    Vertices(&rp, A, B);
    outputRectParallelepiped(rp);
}
