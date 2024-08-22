#include<stdio.h>
int create(int n,int m,int t[][3])
{
    int k=0,e;
    t[0][0]=m;
    t[0][1]=n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter Element For [%d ,%d] Element :",i,j);
            scanf("%d",&e);
            if(e!=0)
             {
                k+=1;
                t[k][0]=i;
                t[k][1]=j;
                t[k][2]=e;
             }

        }
    }
t[0][2]=k;
return k;

}

void display(int k,int t[][3]){
    printf("\n");
    for(int i=0;i<=k;i++)
    {
        printf("%d %d %d \n",t[i][0],t[i][1],t[i][2]);
    }
}

void transpose(int k,int t[][3],int t1[][3])
{
    int l=1;
     t1[0][0]=t[0][1];
     t1[0][1]=t[0][0];
     t1[0][2]=t[0][2];
    for(int i=0;i<t[0][1];i++)
    {
      for(int j=0;j<=t[0][2];j++)
      {
         if(t[j][1]==i)
         {
            t1[l][0]=t[j][1];
            t1[l][1]=t[j][0];
            t1[l][2]=t[j][2];
            l++;

         }
      }
    }

}
int main(){
    int m1,n1,m2,n2,k1,k2,k3;
    printf("Enter Order of The Matrix 1:");
    scanf("%d%d",&m1,&n1);
    int t[50][3],t1[50][3];
    printf("Enter  The Matrix 1:\n");
    k1=create(m1,n1,t);
    printf("The Matrix 1:");
    display(k1,t);
    printf("The Transpose Of Sparse Matrix is : \n");
    transpose(k1,t,t1);
    display(k1,t1);


    return 0;
    }
    


