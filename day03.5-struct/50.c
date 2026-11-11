#include <stdio.h>

/* ============================================================
 * 一、定义结构体
 * ============================================================ */
typedef struct Point {
    int x;
    int y;
} Point;

/* ============================================================
 * 二、结构体当参数：三种方式
 * ============================================================ */

/* A. 传指针：改的是外面那个结构体本身 */
void move(Point *p, int dx, int dy)
{
    p->x += dx;         /* p->x 等价于 (*p).x */
    p->y += dy;
}

/* B. 传值：函数里拿到的是副本，改不到外面 */
void move_wrong(Point p, int dx, int dy)
{
    p.x += dx;          /* 用 . 因为 p 是变量不是指针 */
    p.y += dy;
}

/* C. 只读访问：加 const 承诺不改 */
void print_point(const Point *p)
{
    printf("(%d, %d)\n", p->x, p->y);
}

/* ============================================================
 * 三、自引用结构体 —— 链表节点的标准写法
 * ============================================================ */
typedef struct Node {
    int val;
    struct Node *next;      /* 必须写 struct Node */
} Node;

int main(void)
{
    /* ---------- 1. 三种访问方式 ---------- */
    Point p = {3, 4};
    Point *pp = &p;

    printf("p.x     = %d\n", p.x);        /* 3 */
    printf("pp->x   = %d\n", pp->x);      /* 3 */
    printf("(*pp).x = %d\n", (*pp).x);    /* 3 */

    p.x = 10;
    printf("改 p.x 后 pp->x = %d\n", pp->x);   /* 10，同一块内存 */

    Point q = p;          /* 整体复制 */
    q.x = 999;
    printf("q.x=%d, p.x=%d\n", q.x, p.x);      /* 999, 10 */

    /* ---------- 2. 传值 vs 传指针 ---------- */
    Point a = {1, 2};
    move_wrong(a, 100, 100);    /* 传值 */
    print_point(&a);            /* (1, 2) 没变 */

    move(&a, 100, 100);         /* 传指针 */
    print_point(&a);            /* (101, 102) 变了 */

    /* ---------- 3. 自引用：串成链表 ---------- */
    Node n1 = {1, NULL};
    Node n2 = {2, NULL};
    Node n3 = {3, NULL};
    n1.next = &n2;
    n2.next = &n3;

    printf("n1.val=%d, n1.next->val=%d\n", n1.val, n1.next->val);   /* 1, 2 */

    /* 遍历整条链 —— 链表遍历的原型 */
    Node *cur = &n1;
    while (cur != NULL) {
        printf("%d", cur->val);
        if (cur->next) printf("->");
        cur = cur->next;  
    }
    printf("\n");

    return 0;
}
