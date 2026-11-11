/* ============================================================
 * Day 4 · 动态内存 · 完整示例
 *
 * 目标：写出一个能自动扩容的数组（动态数组 Vec）
 *
 * 编译：gcc -O2 -Wall -Wextra -o vec_demo vec_demo.c
 * ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* ============================================================
 * 第一部分：内存账本
 *
 * Windows 上没有 valgrind，用它来检查"有没有忘记 free"：
 * 分配次数 == 释放次数  →  没有泄漏
 * ============================================================ */
static long g_alloc = 0;
static long g_free  = 0;
static void *ck_malloc(size_t n)
{
    void *p = malloc(n);
    if (p) g_alloc++;
    return p;
}
static void ck_free(void *p)
{
    if (p) { g_free++; free(p); }
}
/* ============================================================
 * 第二部分：动态数组
 *
 *   data : 指向堆上那块内存（真正的数组）
 *   size : 已经装了几个
 *   cap  : 现在最多能装几个
 * ============================================================ */
typedef struct {
    int *data;
    int  size;
    int  cap;
} Vec;
/* 扩容策略：0 = 容量翻倍（推荐），1 = 每次 +1（用来对比） */
static int g_grow_mode = 0;
/* 统计扩容器做了多少"搬运工作" */
static long g_grow_calls = 0;    /* 扩容了几次 */
static long g_grow_copies = 0;   /* 最坏情况下累计要搬多少个元素 */
/* ---------- 初始化：要一块能装 4 个 int 的内存 ---------- */
static int vec_init(Vec *v)
{
    v->cap  = 4;
    v->size = 0;
    v->data = (int *)ck_malloc(sizeof(int) * (size_t)v->cap);
    return v->data != NULL;
}
/* ---------- 扩容 ----------
 * 用 realloc：它可能把数据搬到另一块更大的内存
 * 必须用返回值，失败时原内存仍有效
 */
static int vec_grow(Vec *v)
{
    int newcap = (g_grow_mode == 0) ? v->cap * 2 : v->cap + 1;
    g_grow_calls++;
    g_grow_copies += v->size;        /* 最坏情况：整个数组都要搬一遍 */
    int *nd = (int *)realloc(v->data, sizeof(int) * (size_t)newcap);
    if (nd == NULL) return 0;        /* 失败：原数据还在 */
    v->data = nd;
    v->cap  = newcap;
    return 1;
}
/* ---------- 放一个元素 ---------- */
static int vec_push(Vec *v, int x)
{
    if (v->size == v->cap) {
        if (!vec_grow(v)) return 0;
    }
    v->data[v->size] = x;
    v->size++;
    return 1;
}
/* ---------- 释放 ---------- */
static void vec_free(Vec *v)
{
    if (v->data) {
        ck_free(v->data);
        v->data = NULL;              /* 置空，防止悬空指针 */
    }
    v->size = 0;
    v->cap  = 0;
}
/* ---------- 打印 ---------- */
static void vec_print(const Vec *v, int n)
{
    int lim = (n < v->size) ? n : v->size;
    int i;
    for (i = 0; i < lim; i++) {
        printf("%d", v->data[i]);
        if (i != lim - 1) printf(" ");
    }
    printf("\n");
}
static void reset_grow_stat(void) { g_grow_calls = 0; g_grow_copies = 0; }
int main(void)
{
    /* ============================================================
     * 1. 基本操作：观察 size 和 cap 的变化
     * ============================================================ */
    printf("========== 1. 基本操作与扩容 ==========\n");
    Vec v;
    if (!vec_init(&v)) { printf("初始化失败\n"); return 1; }
    printf("  初始化: size=%d cap=%d\n", v.size, v.cap);
    int i;
    for (i = 1; i <= 9; i++) {
        int oldcap = v.cap;
        vec_push(&v, i * 10);
        printf("  push %2d -> size=%d cap=%d%s\n",
               i * 10, v.size, v.cap,
               (v.cap != oldcap) ? "   <- 扩容了" : "");
    }
    printf("  内容: ");
    vec_print(&v, 100);
    vec_free(&v);
    /* ============================================================
     * 2. 压力测试：100 万次 push
     * ============================================================ */
    printf("\n========== 2. 100 万次 push（翻倍扩容）==========\n");
    g_grow_mode = 0;
    Vec big;
    vec_init(&big);
    clock_t t0 = clock();
    for (i = 0; i < 1000000; i++) vec_push(&big, i);
    clock_t t1 = clock();
    printf("  size = %d, cap = %d\n", big.size, big.cap);
    printf("  耗时 = %.4f 秒\n", (double)(t1 - t0) / CLOCKS_PER_SEC);
    printf("  扩容次数 = %ld，累计搬运元素 = %ld\n", g_grow_calls, g_grow_copies);
    vec_free(&big);
    /* ============================================================
     * 3. 核心对比：翻倍 vs 每次 +1
     *
     * 看"扩容次数"和"累计搬运元素数"，这才是复杂度差异的真相
     *   翻倍：扩容 log2(n) 次，累计搬运 ≈ 2n
     *   +1  ：扩容 n 次，     累计搬运 ≈ n2/2
     * ============================================================ */
    printf("\n========== 3. 对比：同样 %d 次 push ==========\n", 100000);
    const int N = 100000;
    g_grow_mode = 0; reset_grow_stat();
    Vec vd; vec_init(&vd);
    clock_t d0 = clock();
    for (i = 0; i < N; i++) vec_push(&vd, i);
    clock_t d1 = clock();
    printf("  翻倍扩容: 扩容 %ld 次，累计搬运 %ld 个元素，耗时 %.4f 秒\n",
           g_grow_calls, g_grow_copies, (double)(d1 - d0) / CLOCKS_PER_SEC);
    vec_free(&vd);
    g_grow_mode = 1; reset_grow_stat();
    Vec vp; vec_init(&vp);
    clock_t p0 = clock();
    for (i = 0; i < N; i++) vec_push(&vp, i);
    clock_t p1 = clock();
    printf("  每次 +1 : 扩容 %ld 次，累计搬运 %ld 个元素，耗时 %.4f 秒\n",
           g_grow_calls, g_grow_copies, (double)(p1 - p0) / CLOCKS_PER_SEC);
    vec_free(&vp);
    printf("  >> 搬运量差了上百倍，这就是 O(n) 和 O(n2) 的区别\n");
    /* ============================================================
     * 4. 内存账本
     * ============================================================ */
    printf("\n========== 4. 内存账本 ==========\n");
    printf("  alloc = %ld, free = %ld\n", g_alloc, g_free);
    printf("  %s\n", (g_alloc == g_free) ? "无泄漏 ?" : "有泄漏 ?");
    return 0;
}
