class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();  //行数

        if(rows == 0)
            return false;

        int columns = array[0].size();   //列数

        //从矩阵的右上角开始查找
        int row = 0;
        int column = columns - 1;

        //开始查找，保证比较的数始终位于剩余矩阵的右上角
        while(row < rows && column >= 0)   //保证不越过矩阵边界
        {
            if(array[row][column] == target)
                return true;
            else if(array[row][column] > target)   //若矩阵右上角的数大于要查找的数，则排除该列
                column--;
            else                                   //若矩阵右上角的数小于要查找的数，则排除该行
                row++;
        }

        return false;   //没找到则返回false
    }
};
