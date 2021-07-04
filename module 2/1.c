#include <stdio.h>
#include <stdlib.h>
#define N 4 //Number of Unknowns

void swap_row(double mat[N][N+1], int i, int j)
{
    for (int k=0; k<=N; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

int forwardElim(double mat[N][N+1])
{
    for (int k=0; k<N; k++)
    {
        //first value of row is pivot, and its index is saved.
        int i_max = k;
        int v_max = mat[i_max][k];

        //find greater amplitude for pivot if any
        for (int i = k+1; i < N; i++)
            if (abs(mat[i][k]) > v_max)
                v_max = mat[i][k], i_max = i;

        //Swap the greatest value row with current row
        if (i_max != k)
            swap_row(mat, k, i_max);

        for (int i=k+1; i<N; i++)
        {
            double f = mat[i][k]/mat[k][k];

            for (int j=k+1; j<=N; j++)
                mat[i][j] -= mat[k][j]*f;

            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0;
        }
    }
    return -1;
}

void backSub(double mat[N][N+1])
{
    double x[N];

    /* Start calculating from last equation up to the
       first */
    for (int i = N-1; i >= 0; i--)
    {
        /* start with the RHS of the equation */
        x[i] = mat[i][N];

        for (int j=i+1; j<N; j++)
        {
            x[i] -= mat[i][j]*x[j];
        }

        /* divide the RHS by the coefficient of the
           unknown being calculated */
        x[i] = x[i]/mat[i][i];
    }

    printf("\nSolution for the system:\n");
    for (int i=0; i<N; i++)
        printf("x%d = %6.3lf\n", (i+1), x[i]);
}

void gaussianElimination(double mat[N][N+1])
{
    /* reduction into r.e.f. */
    int singular_flag = forwardElim(mat);

    /* if matrix is singular */
    if (singular_flag != -1)
    {
        printf("Singular Matrix.\n");

        if (mat[singular_flag][N])
            printf("Inconsistent System.");
        else
            printf("May have infinitely many "
                   "solutions.");

        return;
    }

    /* get solution to system and print it using
       backward substitution */
    backSub(mat);
}

int main()
{
    double mat[N][N+1] = {{1.19, 2.11,-100.0, 1.0, 1.12},
                          {14.2, -0.122, 12.2, -1, 3.44},
                          {0.0, 100, 99.9, 1, 2.15},
                          {15.3,0.11,-13.1,-1,4.16}
                         };

    gaussianElimination(mat);

    return 0;
}
