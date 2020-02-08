#define M 11
#define N 301

int max_from_index(int* jobDifficulty, int jobDifficultySize, int index) {
    int max_val = -1;
    for(int i = index; i < jobDifficultySize; i++) {
        if(jobDifficulty[i] > max_val) {
            max_val = jobDifficulty[i];
        }
    }
    return max_val;
}

void solve(int* jobDifficulty, int jobDifficultySize, int d, int start_index, int memo[M][N]) {
    //printf("%d %d\n", d, jobDifficultySize-start_index);
    if(d > jobDifficultySize-start_index || memo[d][start_index] != -1) return;
    if(d == 1) {
        memo[d][start_index] = max_from_index(jobDifficulty, jobDifficultySize, start_index);
        //printf("%d %d %d\n", d, start_index, memo[d][start_index]);
    } else {
        int min_val = 9999999, max_val = jobDifficulty[start_index];
        for(int i = 1; start_index + i < jobDifficultySize && jobDifficultySize - start_index - i >= d - 1; i++) {
            if(max_val < jobDifficulty[start_index+i-1]) {
                max_val = jobDifficulty[start_index+i-1];
            }
            solve(jobDifficulty, jobDifficultySize, d-1, start_index+i, memo);
            if(min_val > memo[d-1][start_index+i] + max_val) {
                min_val = memo[d-1][start_index+i] + max_val;
            }
        }
        memo[d][start_index] = min_val;
    }
    //printf("%d %d %d\n", d, start_index, memo[d][start_index]);
}

int minDifficulty(int* jobDifficulty, int jobDifficultySize, int d){
    int memo[M][N];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            memo[i][j] = -1;
        }
    }
    solve(jobDifficulty, jobDifficultySize, d, 0, memo);
    return memo[d][0];
}