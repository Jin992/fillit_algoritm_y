#include <stdio.h>

#include <string.h>
#include <stdlib.h>

int algoritm_y(char **res, char *matrix)
{
    size_t i;
    char *m_start;

    i = 0;
    if (*(res) == NULL)
        return (1);
    m_start = matrix;
    while (matrix[i] != '\0')
    {
      
        if ((*res)[i] == '#' && matrix[i] != '#')
        {
            matrix[i] = (*res)[i];
            i++;
        }
        else if (matrix[i] == '#' && (*res)[i] == '#')
        {
            matrix++;
            i = 0;
        }
        else
        i++;
        if ((*res)[i + 1] == '\0')
            algoritm_y(res + 1, m_start);
    }
    return (0);
}

int main() {
  char matrix[25] = "#...#...#...#...";
  char **res = (char **)malloc(sizeof(char *) * 3);
  res[2] = 0;
  
  res[0] = strdup("#...#...#...#...");
  res[1] = strdup("##..#...#.......");
  
  algoritm_y(res, matrix);
  printf("%s\n", matrix);
  return 0;
}