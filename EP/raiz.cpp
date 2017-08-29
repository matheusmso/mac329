#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
    int NUM;
    int div = 1;
    int quo;

    scanf("%d", &NUM);
    quo = NUM;

    while (quo - div - 1 > 0) {
        div++;
        quo = NUM / div;
    }

    printf("%d\n", div);

    return 0;
}
