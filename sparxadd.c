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
int add(int m,int n,int k1,int k2,int t1[][3],int t2[][3],int t3[][3])
{
    int i=1;
    int j=1; 
    int k=0;
    t3[0][0]=m;
    t3[0][1]=n;
   while(i<=k1&&j<=k2)
    {
          if(t1[i][0]==t2[j][0])
          {
            if(t1[i][1]==t2[j][1])
             {
                k+=1;
                t3[k][0]=t1[i][0];
                t3[k][1]=t1[i][1];
                t3[k][2]=t1[i][2]+t2[j][2];
                i+=1;
                j+=1;
             }
            else if(t1[i][1]<t2[j][1])
             {
                k+=1;
                t3[k][0]=t1[i][0];
                t3[k][1]=t1[i][1];
                t3[k][2]=t1[i][2];
                i+=1;
             }
            else
             {
                k+=1;
                t3[k][0]=t2[j][0];
                t3[k][1]=t2[j][1];
                t3[k][2]=t2[j][2];
                j+=1;
             }
          }
        else if(t1[i][0]<t2[j][0])
        {
             k+=1;
            t3[k][0]=t1[i][0];
            t3[k][1]=t1[i][1];
            t3[k][2]=t1[i][2];
            i+=1;

        }
       else
       {
        k+=1;
        t3[k][0]=t2[j][0];
        t3[k][1]=t2[j][1];
        t3[k][2]=t2[j][2];
        j+=1;

       }

    }
   while(i<=k1)
    {
     k+=1;
    t3[k][0]=t1[i][0];
    t3[k][1]=t1[i][1];
    t3[k][2]=t1[i][2];
    i+=1;
   }
  while(j<=k2)
   {
     k+=1;
    t3[k][0]=t2[i][0];
    t3[k][1]=t2[i][1];
    t3[k][2]=t2[i][2];
    j+=1;
   }
return k;



}

int main()
{
    int m1,n1,m2,n2,k1,k2,k3;
    printf("Enter Order of The Matrix 1:");
    scanf("%d%d",&m1,&n1);
    printf("Enter Order of The Matrix 2:");
    scanf("%d%d",&m2,&n2);
    int t1[50][3],t2[50][3],t3[50][3];
    if((m1!=m2 )||(n1!=n2))
    {
        printf("Matrix Addition Not Possible ");
    }
    else{
    printf("Enter  The Matrix 1:\n");
    k1=create(m1,n1,t1);
    printf("Enter The Matrix 2:\n");
    k2=create(m2,n2,t2);
    printf("The Matrix 1:");
    display(k1,t1);
    printf("The Matrix 2:");
    display(k2,t2);
    printf("The Sum Of Sparse Matrix is : \n");
    k3=add(n1,m1,k1,k2,t1,t2,t3);
    t3[0][2]=k3;
    display(k3,t3);
    }
    return 0;




}

























