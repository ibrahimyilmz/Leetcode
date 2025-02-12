class Solution {
private:
    void helper(int j, int n, vector<vector<string>>& res, vector<bool>& pos, vector<bool>& neg,
     vector<string>& board, vector<bool>& rows)
    {
        if (j > n) {
            res.push_back(board);
            return;
        }
        for (int i = 1 ; i <= n ; i++) {
            if (!rows[i] && !pos[i + j] && !neg[i - j + n])  {
                string str (n, '.');
                str[i - 1] = 'Q';
                board.push_back(str);

                pos[i + j] = true;
                neg[i - j + n] = true;
                rows[i] = true;

                helper(j + 1, n, res, pos, neg, board, rows);

                board.pop_back();
                pos[i + j] = false;
                neg[i - j + n] = false;
                rows[i] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<bool> pos(n * 2);
        vector<bool> neg(n * 2);
        vector<string> board;
        vector<bool> rows(n);

        helper(1, n ,res, pos, neg, board, rows);

        return res;
    }
};