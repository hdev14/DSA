#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct Node
{
    float value;
    int row;
    int column;
    Node *next;
} Node;

typedef struct Matrix
{
    Node **rows;
    int qty_rows;
    int qty_columns;
} Matrix;

void startMatrix(Matrix *matrix, int qty_rows, int qty_columns)
{
    matrix->rows = (Node **)malloc(qty_rows * sizeof(Node));
    matrix->qty_rows = qty_rows;
    matrix->qty_columns = qty_columns;

    for (int i = 0; i < qty_rows; i++)
    {
        matrix->rows[i] = NULL;
    }
}

bool isValidPosition(Matrix *matrix, int row, int column)
{
    return row >= 0 && row < matrix->qty_rows && column >= 0 && column < matrix->qty_columns;
}

bool editMatrix(Matrix *matrix, int row, int column, float value)
{
    if (!isValidPosition(matrix, row, column))
    {
        return false;
    }

    Node *previous = NULL;
    Node *current = matrix->rows[row];

    while (current != NULL && current->column < column)
    {
        previous = current;
        current = current->next;
    }

    if (current != NULL && current->column == column)
    {
        if (value == 0)
        {
            if (previous == NULL)
            {
                matrix->rows[row] = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return true;
        }

        current->value = value;
    }
    else
    {
        if (value != 0)
        {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->value = value;
            new_node->column = column;
            new_node->row = row;
            new_node->next = current;

            if (previous == NULL)
            {
                matrix->rows[row] = new_node;
            }
            else
            {
                previous->next = new_node;
            }
        }
    }

    return true;
}

void printMatrix(Matrix *matrix)
{
    for (int row = 0; row < matrix->qty_rows; row++)
    {
        Node *current = matrix->rows[row];
        printf("[ ");

        while (current != NULL)
        {

            printf(" %f ", current->value);
            current = current->next;
        }

        printf(" ]\n");
    }
}

float getValue(Matrix *matrix, int row, int column)
{
    if (isValidPosition(matrix, row, column))
    {
        Node *current = matrix->rows[row];

        while (current != NULL && current->column <= column)
        {
            if (current->column == column)
            {
                return current->value;
            }
            current = current->next;
        }
    }

    return 0;
}

int main()
{
    Matrix matrix;
    int rows = 3;
    int columns = 3;
    float number_matrix[rows][columns] = {{0, 1, 3.4}, {2.3, 4, 0}, {0, 0, 0}};

    startMatrix(&matrix, rows, columns);

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            editMatrix(&matrix, row, column, number_matrix[row][column]);
        }
    }

    printMatrix(&matrix);

    return 0;
}
