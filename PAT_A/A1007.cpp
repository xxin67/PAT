#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int K;
    scanf("%d", &K);
    int AllNegative = 1;
    vector<int> num(K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &num[i]);
    }

    int max = -1;
    int max_seqi = -1, max_seqj = -1;
    int current = 0;
    int subseq = 0;

    int max_temp = 0;
    int seqi = -1, seqj = -1;
    for (current; current < num.size(); current++)
    {
        if (num[current] >= 0)
        {
            if (subseq == 0)
            {
                AllNegative = 0;
                subseq = 1;
                seqi = current;
                seqj = current;
                max_temp += num[current];
            }
            else
            {
                seqj = current;
                max_temp += num[current];
            }
        }
        else
        {
            if (subseq == 0)
            {
                continue;
            }
            else
            {
                subseq = 0;
                if (max_temp > max)
                {
                    max = max_temp;
                    max_temp = 0;
                    max_seqi = seqi;
                    max_seqj = seqj;
                }
                continue;
            }
        }
        if (current == num.size() - 1 && subseq == 1)
        {
            if (max_temp > max)
            {
                max = max_temp;
                max_temp = 0;
                max_seqi = seqi;
                max_seqj = seqj;
            }
        }
    }

    if (AllNegative == 1)
    {
        printf("0 %d %d\n", num[0], num[num.size() - 1]);
    }
    else
    {
        printf("%d %d %d\n", max, num[max_seqi], num[max_seqj]);
    }
}