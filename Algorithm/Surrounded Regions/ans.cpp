 class Solution {
    public:
        void solve(vector<vector<char> > &board) {
            int row = board.size();
            if(row == 0){
                return;
            }//if
            int col = board[0].size();
            // 都够不成围绕
            // 行
            for(int i = 0;i < col;++i){
                // 第一行
                BFS(board,0,i);
                // 最后一行
                BFS(board,row-1,i);
            }//for
            // 列
            for(int j = 0;j < row;++j){
                // 第一列
                BFS(board,j,0);
                // 最后一列
                BFS(board,j,col-1);
            }//for
            for(int i = 0;i < row;++i){
                for(int j = 0;j < col;j++){
                    // 不可以从外界走通的o
                    if(board[i][j] == 'O'){
                        board[i][j] = 'X';
                    }//if
                    // 可以从外界走通的o
                    else if(board[i][j] == '.'){
                        board[i][j] = 'O';
                    }
                }//for
            }//for
        }
    private:
        // row 行数 col 列数 x ,y 当前board位置
        void BFS(vector<vector<char> >& board, int x, int y){
            int row = board.size();
            int col = board[0].size();
            queue<pair<int,int> > q;
            Pass(board,row,col,x,y,q);
            while(!q.empty()){
                pair<int,int> point = q.front();
                q.pop();
                x = point.first;
                y = point.second;
                // left
                Pass(board,x,y+1,q);
                // right
                Pass(board,x,y-1,q);
                // up
                Pass(board,x-1,y,q);
                // down
                Pass(board,x+1,y,q);
            }//while
        }
        // 四边判断是否走通
        void Pass(vector<vector<char> >& board,int x,int y,queue<pair<int,int> > &q){
            int row = board.size();
            int col = board[0].size();
            // 边界条件以及遇到o才能走通
            if(x < 0 || x >= row || y < 0 || y >= col || board[x][y] != 'O'){
                return;
            }//if
            // 标记可从外界走通的o
            board[x][y] = '.';
            // 入队列
            q.push(make_pair(x,y));
        }
    };