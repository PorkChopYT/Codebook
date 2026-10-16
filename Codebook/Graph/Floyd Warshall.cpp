ll dp[max_n][max_n];
ll graph[max_n][max_n];
void Floyd_Warshall(){
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n; j++){
            if(i == j) dp[i][j]=0;
            else if(graph[i][j] != llmx) dp[i][j]=graph[i][j];
            else dp[i][j]=llmx;
        }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
}