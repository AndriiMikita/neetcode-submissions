class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> count;

        for(vector<char>& row : board)
        {
            count.clear();
            for(char& cell : row)
            {
                if(cell >= '0' and cell <= '9')
                {
                    int number = cell - '0';

                    if(count.contains(number))
                        return false;

                    count[number] += 1;
                }
            }
        }

        for(int j = 0; j < board.size(); ++j)
        {
            count.clear();
            for(int i = 0; i < board.size(); ++i)
            {
                if(board[i][j] >= '0' and board[i][j] <= '9')
                {
                    int number = board[i][j] - '0';

                    if(count.contains(number))
                        return false;

                    count[number] += 1;
                }

            }
        }

        for(int i = 0; i < board.size() / 3; ++i)
        {
            for(int j = 0; j < board.size() / 3; ++j)
            {
                count.clear();
                for(int ii = 0; ii < 3; ++ii)
                {
                    for(int jj = 0; jj < 3; ++jj)
                    {
                        char ch = board[i * 3 + ii][j * 3 + jj];
                        if(ch >= '0' and ch <= '9')
                        {
                            int number = ch - '0';

                            if(count.contains(number))
                                return false;

                            count[number] += 1;
                        }
                    }
                }
            }
        }

        return true;
    }
};
