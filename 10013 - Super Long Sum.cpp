#include <iostream>

using namespace std;

int main() {
    int nbcase, M, *V, a, i, j;
    V = new int[1000001];

    cin >> nbcase;
    nbcase -= 1;

    for (i = 0; i <= nbcase; i++) {
        cin >> M;
        for (j = 0; j <= M; j++) V[j] = 0;
        for (j = 1; j <= M; j++) {
            cin >> V[j];
            cin >> a;
            V[j] += a;
            a = j;
            while (V[a] >= 10) {
                V[a] = V[a] % 10;
                V[a - 1] += 1;
                a--;
            }
        }
        if (V[0] != 0) cout << V[0];
        for (j = 1; j <= M; j++) cout << V[j];
        cout << endl;
        if (i != nbcase) cout << endl;
    }
    return 0;
}