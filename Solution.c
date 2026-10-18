#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    char t[10001];

    printf("Enter Video_Stream:\n");
    scanf("%200000s", s);

    printf("Enter Evidence_Pattern:\n");
    scanf("%10000s", t);

    int n = strlen(s);
    int m = strlen(t);

    int required[128] = {0};
    int window[128] = {0};

    for (int i = 0; i < m; i++) {
        required[(unsigned char)t[i]]++;
    }

    int missing = m;
    int left = 0;

    int bestStart = 0;
    int bestLength = n + 1;

    for (int right = 0; right < n; right++) {
        unsigned char ch = (unsigned char)s[right];

        window[ch]++;

        if (window[ch] <= required[ch]) {
            missing--;
        }

        while (missing == 0) {
            int length = right - left + 1;

            if (length < bestLength) {
                bestLength = length;
                bestStart = left;
            }

            unsigned char leftChar =
                (unsigned char)s[left];

            window[leftChar]--;

            if (window[leftChar] < required[leftChar]) {
                missing++;
            }

            left++;
        }
    }

    if (bestLength == n + 1) {
        printf("Incident Incomplete\n");
    } else {
        printf("Shortest substring: ");

        for (int i = bestStart;
             i < bestStart + bestLength; i++) {
            printf("%c", s[i]);
        }

        printf("\n");
        printf("Start frame: %d\n", bestStart);
        printf("End frame: %d\n",
               bestStart + bestLength - 1);
        printf("Duration: %d\n", bestLength);
    }

    return 0;
}