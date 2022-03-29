#include <stdio.h>

void insertionSort(int array[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        int element = array[i];                 // for this element ...
        int j = i-1;
        while (j >= 0 && array[j] > element) {  // ... work down the ordered list
            array[j+1] = array[j];               // ... moving elements up
            j--;
        }
        array[j+1] = element;                   // and insert in correct position
    }
}

int main (void) {
    Edge e = {0, 0, 1};
    int nUsers;

    printf("Enter the number of users: ");
    scanf("%d", &nUsers);

    Graph g = newGraph(nUsers);

    printf("Enter a user (follower): ");
    while (scanf("%d", &e.v) == 1) {
        printf("Enter a user (followed by 0): ");
        scanf("%d", &e.w);
        insertEdge(g, e);
        printf("Enter a user (follower): ");
    }
    printf("Done.\n");

    //showGraph(g);

    int i;
    int j;
    int follow;
    int follows[numOfVertices(g)];
    int follower;
    int followers[numOfVertices(g)];
    int nV = numOfVertices(g);
    int vertices[numOfVertices(g)];
    printf("Ranking by follower base:\n");
    for (i = 0; i < nV; i++) {
        follow = 0;
        follower = 0;
        vertices[i] = i;
        printf("vertices[%d] = %d\n", i, vertices[i]);
        for (j = 0; j < nV; j++) {
            if (adjacent(g, i, j) != 0) {
                follow++;
            }

            if (adjacent(g, j, i) != 0) {
                follower++;
            }
        }
        followers[i] = follower;
        //printf("followers[%d] = %d\n", i, followers[i]);
        follows[i] = follow;
        //printf("follows[%d] = %d\n", i, follows[i]);
        //printf("%d has %d followers(s) and follows %d user(s)\n", i, follower, follow);
