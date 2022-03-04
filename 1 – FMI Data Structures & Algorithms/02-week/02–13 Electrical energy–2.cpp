// https://www.hackerrank.com/contests/practice-2-sda/challenges/electrical-energy
// Electrical Energy

#include <cstdio>
#include <memory>
#include <cstring>

using namespace std;

static_assert(sizeof(long long) >= 8);

const int mxN = 1e5 + 5;

int n, A[mxN];
long long inversions;

void merge(int *arr, int l, int mid, int r) {
    unique_ptr<int[]> l_arr(new int[mid - l + 1]);
    unique_ptr<int[]> r_arr(new int[r - mid]);

    memcpy(l_arr.get(), arr + l, sizeof(int) * (mid - l + 1));
    memcpy(r_arr.get(), arr + mid + 1, sizeof(int) * (r - mid));

    int l_ind = 0, r_ind = 0;

    for (int i = l; i <= r; ++i) {
        if (r_ind == r - mid || (l_ind != mid - l + 1 && l_arr[l_ind] <= r_arr[r_ind])) {
            inversions += r_ind;
            arr[i] = l_arr[l_ind++];
        } else {
            arr[i] = r_arr[r_ind++];
        }
    }
}

void ms(int *arr, int l, int r) {
    if (l == r) {
        return;
    }

    int mid = (l + r) / 2;

    ms(arr, l, mid);
    ms(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }

    ms(A, 0, n - 1);

    return printf("%lld", inversions), 0;
}
