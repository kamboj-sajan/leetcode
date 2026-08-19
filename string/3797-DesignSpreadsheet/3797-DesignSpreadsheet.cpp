// Last updated: 19/08/2026, 15:25:16
class Spreadsheet {
private:
    int rows;
    vector<vector<int>> grid;  // rows x 26 (columns A-Z)

    // Helper: parse cell like "B12" into (row, col)
    pair<int,int> parseCell(const string &cell) {
        char colChar = cell[0];
        int col = colChar - 'A';
        int row = stoi(cell.substr(1)) - 1;  // convert to 0-index
        return {row, col};
    }

    // Helper: get value from either integer or cell reference
    int getOperandValue(const string &s) {
        if (isdigit(s[0])) {
            return stoi(s);
        } else {
            auto [r, c] = parseCell(s);
            if (r >= 0 && r < rows && c >= 0 && c < 26)
                return grid[r][c];
            return 0; // out of bounds treated as 0
        }
    }

public:
    Spreadsheet(int rows) : rows(rows) {
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        if (r >= 0 && r < rows && c >= 0 && c < 26)
            grid[r][c] = value;
    }

    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        if (r >= 0 && r < rows && c >= 0 && c < 26)
            grid[r][c] = 0;
    }

    int getValue(string formula) {
        // Formula looks like "=X+Y"
        formula = formula.substr(1); // remove '='
        size_t plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        int val1 = getOperandValue(left);
        int val2 = getOperandValue(right);

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */