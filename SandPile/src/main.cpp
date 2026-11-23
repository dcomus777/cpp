// #include <iostream>

// int main()
// {
//     int n;
//     std::cin >> n;
//     int **grid = new int *[n];
//     for (int i = 0; i < n; i++)
//     {
//         grid[i] = new int[n]{};
//     }
//     int value = 1;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             grid[i][j] = value;
//             value++;
//         }
//     }

//     int add_top = 0;
//     int add_bottom = 0;
//     int add_left = 0;
//     int add_right = 0;

//     int new_rows = n + add_top + add_bottom;
//     int new_columns = n + add_left + add_right;

//     int **new_grid = new int *[new_rows]{};

//     for (int i = 0; i < new_rows; i++)
//     {
//         new_grid[i] = new int[new_columns]{};
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             new_grid[i + add_top][j + add_left] = grid[i][j];
//         }
//     }
//     for (int i = 0; i < new_rows; i++)
//     {
//         for (int j = 0; j < new_columns; j++)
//         {
//             std::cout << new_grid[i][j] << ' ';
//         }
//         std::cout << '\n';
//     }

//     for (int i = 0; i < new_rows; i++)
//     {
//         delete[] new_grid[i];
//     }
//     delete[] new_grid;

//     for (int i = 0; i < n; i++)
//     {
//         delete[] grid[i];
//     }
//     delete[] grid;
// }

#include <iostream>

void print_grid(int **grid, int rows, int columns);

int main()
{
    int rows = 3;
    int columns = 4;

    int **grid = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        grid[i] = new int[columns]{};
    }
    int value = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            grid[i][j] = value;
            value++;
        }
    }
    print_grid(grid, rows, columns);
}

void print_grid(int **grid, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << '\n';
    }
}