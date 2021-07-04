#include<stdio.h>
int main()
{
    float L[20][20]= {0}, U[20][20];
    float  X[20]= {0},Y[20]= {0};
    int i,j,k,n=4;
    
    //square matrix
    float A[20][20]= {{1.19, 2.11,-100.0, 1.0},
                          {14.2, -0.122, 12.2, -1},
                          {0.0, 100, 99.9, 1},
                          {15.3,0.11,-13.1,-1}
                         };
    
    //coonstant matrix
    float B[20]= {1.12,3.44,2.15,4.16};
    
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i<=j)
            {
                U[i][j]=A[i][j];
                for(k=0; k<i-1; k++)
                    U[i][j]-=L[i][k]*U[k][j];
                printf("****%f",L[i][k]);
                if(i==j)
                    L[i][j]=1;
                else
                    L[i][j]=0;
            }
            else
            {
                L[i][j]=A[i][j];
                for(k=0; k<=j-1; k++)
                    L[i][j]-=L[i][k]*U[k][j];
                L[i][j]/=U[j][j];
                U[i][j]=0;
            }
        }
    }
    printf("[L]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",L[i][j]);
        printf("\n");
    }
    printf("\n\n[U]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",U[i][j]);
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        
        Y[i]=B[i];
        if(i==0)
        continue;
        for(j=0; j<i; j++)
        {
            printf("##%f",Y[j]);
            Y[i]-=L[i][j]*Y[j];
        }
    }
    printf("\n\n[B]: \n");
    for(i=0;i<4;i++)
        printf("%9.3f",B[i]);
    printf("\n\n[Y]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",Y[i]);
    }
    for(i=n-1; i>=0; i--)
    {
        X[i]= Y[i];
        for(j=i+1; j<n; j++)
        {
            X[i]-=U[i][j]*X[j];
        }
        X[i]/=U[i][i];
    }
    printf("\n\n[X]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",X[i]);
    }
    return 0;
}
