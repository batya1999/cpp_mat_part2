#include "mat.hpp"
double const half = 0.5;

namespace ariel
{
    string mat(int col, int row, char c1, char c2)
    {
        if (col < 0 || row < 0){
        
            throw invalid_argument("inputs should be positive");
        }
        if (col % 2 == 0 || row % 2 == 0){
            throw invalid_argument("both inputs should be odd");

        }
                
        vector<char> vec2(col, ' ');//insider vector
        vector< vector<char> > tmatrix(row, vec2); //the complete vector
        int lim = prefx(col, row);
        char temp = c1;
        int tempcol = 0;
        int temprow = 0;
        int i = 0;

        while (i <= lim){ /*each iteration has prefix of [size(prefix)+1] 
                            untill [size(prefix)]=lim*/

            for (int k = i; k < row - i; k++){
                //filling the row with current char
                tempcol = col-1-i;
                tmatrix[k][i] = temp;
                tmatrix[k][tempcol] = temp;
            }

            for (int l = i; l < col - i; l++){
                //filling the col with current char
                temprow = row-1-i;
                tmatrix[i][l] = temp;
                tmatrix[temprow][l] = temp;
            }
            //char replacement after each frame filling iteration
            if(temp==c1){
                temp = c2;
            }           
            else{
                temp = c1;
            }             
            i++;
        }
        string ret = convertS(row, col, tmatrix);
        return ret;
    }

    int prefx(int n1, int n2){
        if(n1>n2){
            return int(n2*half);
        }
        if(n2>n1){
            return int(n1*half);
        }
        
        return int(n1*half);//if n1 = n2 then return n1 (case of n*n matrix)
    }

    string convertS(int row, int col, vector< vector<char>> finalmat){
        //converts a vector variable to a string variable
        string ans = string("");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)  {
                
                ans += finalmat[i][j];  
                }        
            ans += '\n';
        }
        return ans;
    }
        
}