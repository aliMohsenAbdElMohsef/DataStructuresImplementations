
#include "mergeSort.cpp"
using namespace std;

class SuffixArray
{
    char *base;
    int *SuffArray;
    int size;

    int my_strlen(const char *str)
    {
        int length = 0;
        while (str[length] != '\0')
        {
            length++;
        }
        return length;
    }
    void my_memcpy(char *dest, const char *src, int n)
    {
        for (int i = 0; i < n; i++)
        {
            dest[i] = src[i];
        }
    }

public:
    SuffixArray(const char *input)
    {
        size = my_strlen(input);
        base = new char[size + 1];
        my_memcpy(base, input, size + 1);
        SuffArray = new int[size];
    }

    ~SuffixArray()
    {
        delete[] base;
        delete[] SuffArray;
    }

    void ConstructUsingPrefixDoubling()
    {
        int n = size;
        auto zeroTransitionArray = new pair<pair<int, int>, int>[n];
        auto suffixArrayTransitionZero = new int[n];
        for (int i = 0; i < n; i++)
        {
            zeroTransitionArray[i].first.first = (int)base[i];
            zeroTransitionArray[i].second = i;
            zeroTransitionArray[i].first.second = 0;
        }
        mergeSort(zeroTransitionArray, 0, n - 1);

        suffixArrayTransitionZero[zeroTransitionArray[0].second] = 0;
        for (int i = 1; i < n; i++)
        {
            if (zeroTransitionArray[i].first.first == zeroTransitionArray[i - 1].first.first)
                suffixArrayTransitionZero[zeroTransitionArray[i].second] = suffixArrayTransitionZero[zeroTransitionArray[i - 1].second];
            else
                suffixArrayTransitionZero[zeroTransitionArray[i].second] = suffixArrayTransitionZero[zeroTransitionArray[i - 1].second] + 1;
        }

        auto suffixArray = new pair<pair<int, int>, int>[n];
        int transition = 0;

        while ((1 << transition) < n)
        {
            for (int i = 0; i < n; i++)
            {
                suffixArray[i] = {{suffixArrayTransitionZero[i], suffixArrayTransitionZero[(i + (1 << transition)) % n]}, i};
            }

            mergeSort(suffixArray, 0, n - 1);

            suffixArrayTransitionZero[suffixArray[0].second] = 0;
            int cnt = 0;

            for (int i = 1; i < n; i++)
            {
                if (suffixArray[i].first.first != suffixArray[i - 1].first.first || suffixArray[i].first.second != suffixArray[i - 1].first.second)
                {
                    suffixArrayTransitionZero[suffixArray[i].second] = suffixArrayTransitionZero[suffixArray[i - 1].second] + 1;
                    cnt++;
                }
                else
                {
                    suffixArrayTransitionZero[suffixArray[i].second] = suffixArrayTransitionZero[suffixArray[i - 1].second];
                }
            }
            if (cnt == n - 1)
                break;
            transition++;
        }

        for (int i = 0; i < n; i++)
        {
            SuffArray[i] = suffixArray[i].second;
        }

        delete[] suffixArray;
        delete[] zeroTransitionArray;
        delete[] suffixArrayTransitionZero;
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << SuffArray[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    SuffixArray t("ACGACTACGATAAC$");
    t.ConstructUsingPrefixDoubling();
    t.Print(); // Prints: 14 11 12 0 6 3 9 13 1 7 4 2 8 10 5
    return 0;
}