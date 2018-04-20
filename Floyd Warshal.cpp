/// God Help Me
/* Floyd Warshal Algorithm
   Indrojit Mondal,
   Computer Science and Engineering, University Of Barisal */
   #include<bits/stdc++.h>
   using namespace std;
   int strct=0;
   string str[100];
   int NEXT[100][100];
 int search_index(string node)
 {
  int ck=0;
   for(int I=1; I<=strct; I++)
   {
       if(str[I]==node)
       {
           ck=1;
           return I;
       }
   }
   if(ck==0)
   {
        strct=strct+1;
       str[strct]=node;
       return strct;
   }
 }

void  PathPrint(int U,int V)
 {
     int Path=U;
     cout<<str[U]<<" ";
     while(U!=V)
     {
         U=NEXT[U][V];
         //cout<<U<<" ";
          cout<<str[U]<<" ";
     }

 }
int main()
{
    int V,E,I,J,K,Cost,Inf=1e4,Node1,Node2;
   //freopen("Floyd Warshal.txt","r",stdin);
   freopen("Kruskal.txt","r",stdin);

    cin>>V>>E;
    int G[V+1][V+1];
    for(int I=1; I<=V; I++)
    {
        for(int J=1; J<=V; J++)
        {
             NEXT[I][J]=J;
            if(I==J) G[I][J]=0;
            else G[I][J]=Inf;
        }
    }
  string s1,s2;
   for(int I=1; I<=E; I++)
    {
        cin>>s1>>s2>>Cost;
        Node1=search_index(s1);
        Node2=search_index(s2);
        G[Node1][Node2]=Cost;
        G[Node2][Node1]=Cost;
    }



    for(int K=1; K<=V; K++)
    {
        for(int I=1; I<=V; I++)
        {
            for(int J=1; J<=V; J++)
            {

                if(G[I][J]>G[I][K]+G[K][J])
                {
                    G[I][J]=G[I][K]+G[K][J];
                    NEXT[I][J]=NEXT[I][K];

                }
            }
        }
    }
   /* for(int I=1; I<=V; I++)
    {
        for(int J=1; J<=V; J++)
        {
            cout<<str[I]<<" -> "<<str[J]<<" = "<<G[I][J]<<endl;
        }
    }*/
    PathPrint(search_index("a"),search_index("d"));

    return 0;
}
