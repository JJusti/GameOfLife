#include <stdint.h>
#include <stdlib.h>

/**
    rule1: 一个细胞周围有3个细胞为生，则该细胞为生
    rule2: 一个细胞周围有2个细胞为生，则该细胞生死状态保持不变
    rule3: 其它情况下该细胞为死
*/
int main(int argc, char* argv[])
{
    const int32_t w = 32;
    const int32_t h = 32;

    int32_t word[w][h] = { 0 };
    int32_t temp[w][h] = { 0 };

    for (int32_t i = 0; i < w; i++)
    {
        for (int32_t j = 0; j < h; j++)
        {
            word[i][j] = rand() % 2;
        }
    }

    int32_t max = 10;
    for (int32_t t = 0; t < max; t++)
    {
        for (int32_t i = 0; i < w; i++)
        {
            for (int32_t j = 0; j < h; j++)
            {
                // (i - 1, j - 1) -> (i + 1, j + 1)
                int32_t c = 0;
                for (int32_t x = i - 1 >= 0 ? i - 1 : 0;
                    (x <= i + 1) && (x >= 0) && (x < w);
                    x++)
                {
                    for (int32_t y = j - 1 >= 0 ? j - 1 : 0;
                        (y <= j + 1) && (y >= 0) && (y < h);
                        y++)
                    {
                        if ((x == i) && (y == j))
                        {
                            continue;
                        }

                        if (word[x][y])
                        {
                            c += 1;
                        }
                    }
                }

                temp[i][j] = 0;
                if (c == 3)
                {
                    temp[i][j] = 1;
                }
                else if (c == 2)
                {
                    temp[i][j] = word[i][j];
                }
                else
                {
                    temp[i][j] = 0;
                }
            }
        }

        for (int32_t i = 0; i < w; i++)
        {
            for (int32_t j = 0; j < h; j++)
            {
                word[i][j] = temp[i][j];
            }
        }
    }

	return 0;
}
