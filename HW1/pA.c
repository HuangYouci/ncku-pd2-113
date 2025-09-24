#include <stdio.h>
#include <string.h>

long long int prefix1[200005], prefix2[200005];

void preprocess(char s1[], char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    prefix1[0] = 0;
    for (int i = 1; i <= len1; i++) {
        prefix1[i] = prefix1[i - 1] + (s1[i - 1] - 'a'); 
    }

    prefix2[0] = 0;
    for (int i = 1; i <= len2; i++) {
        prefix2[i] = prefix2[i - 1] + (s2[i - 1] - 'a');
    }
}

int main() {
    char s1[200005], s2[200005];
    int q;

    scanf("%s %s", s1, s2);
    preprocess(s1, s2);

    scanf("%d", &q);
    for (int search = 0; search < q; search++) {
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);

        if ((r1 - l1) != (r2 - l2)) {
            printf("NO\n");
            continue;
        }

        long long sum1 = prefix1[r1] - prefix1[l1 - 1];
        long long sum2 = prefix2[r2] - prefix2[l2 - 1];

        if (sum1 == sum2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
