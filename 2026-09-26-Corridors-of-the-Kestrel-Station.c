#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, cost;
} Edge;

typedef struct {
    int a, b, budget, id;
} Query;

int parent[100005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b)
        parent[b] = a;
}

int compareEdge(const void *p1, const void *p2) {
    Edge *a = (Edge *)p1;
    Edge *b = (Edge *)p2;

    return a->cost - b->cost;
}

int compareQuery(const void *p1, const void *p2) {
    Query *a = (Query *)p1;
    Query *b = (Query *)p2;

    return a->budget - b->budget;
}

int main() {
    int n, m, q;

    scanf("%d %d %d", &n, &m, &q);

    Edge *edges = (Edge *)malloc(m * sizeof(Edge));
    Query *queries = (Query *)malloc(q * sizeof(Query));

    int i;

    for (i = 0; i < m; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].cost);
    }

    for (i = 0; i < q; i++) {
        scanf("%d %d %d",
              &queries[i].a,
              &queries[i].b,
              &queries[i].budget);

        queries[i].id = i;
    }

    qsort(edges, m, sizeof(Edge), compareEdge);
    qsort(queries, q, sizeof(Query), compareQuery);

    for (i = 1; i <= n; i++)
        parent[i] = i;

    char *answer = (char *)malloc(q * sizeof(char));

    int edgeIndex = 0;

    for (i = 0; i < q; i++) {
        while (edgeIndex < m &&
               edges[edgeIndex].cost <= queries[i].budget) {

            unite(edges[edgeIndex].u,
                  edges[edgeIndex].v);

            edgeIndex++;
        }

        if (find(queries[i].a) == find(queries[i].b))
            answer[queries[i].id] = 'Y';
        else
            answer[queries[i].id] = 'N';
    }

    for (i = 0; i < q; i++) {
        if (answer[i] == 'Y')
            printf("YES\n");
        else
            printf("NO\n");
    }

    free(edges);
    free(queries);
    free(answer);

    return 0;
}
