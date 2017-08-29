#include <cstdio>

using namespace std;

int main() {
    int NUM;
    int div;
    int Rnum;

    scanf("%d", &NUM);
    Rnum = raiz(NUM);

    div = 2;
    while (div <= Rnum) {
        if (NUM % div == 0) break;
        div++;
    }

    printf("%d\n", div > Rnum?1:0);

    return 0;
}
