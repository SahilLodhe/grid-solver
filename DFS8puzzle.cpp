#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> visited;
string str_rep(vector<vector<int>> matrix)
{
    string res = "";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            res += to_string(matrix[i][j]);
        }
    }
    return res;
}

vector<vector<int>> move_left(vector<vector<int>> matrix)
{
    int x = -1;
    int y = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }
    if (matrix[x][y] == 0)
    {
        if (y != 0)
        {
            swap(matrix[x][y], matrix[x][y - 1]);
        }
    }

    return matrix;
}
bool is_left(vector<vector<int>> matrix)
{
    int x = -1;
    int y = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }
    if (y == 0)
    {
        return false;
    }
    return true;
}
vector<vector<int>> move_right(vector<vector<int>> matrix)
{
    int x = -1;
    int y = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }
    if (matrix[x][y] == 0)
    {
        if (y != 2)
        {
            swap(matrix[x][y], matrix[x][y + 1]);
        }
    }

    return matrix;
}
bool is_right(vector<vector<int>> matrix)
{
    int x = -1;
    int y = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }
    if (y == 2)
    {
        return false;
    }
    return true;
}
vector<vector<int>> move_down(vector<vector<int>> matrix)
{
    int x = -1;
    int y = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }
    if (matrix[x][y] == 0)
    {
        if (x != 2)
        {
            swap(matrix[x][y], matrix[x + 1][y]);
        }
    }

    return matrix;
}
bool is_down(vector<vector<int>> matrix)
{
    int x = -1;
    int y = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }
    if (x == 2)
    {
        return false;
    }
    return true;
}
vector<vector<int>> move_up(vector<vector<int>> matrix)
{
    int x = -1;
    int y = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }
    if (matrix[x][y] == 0)
    {
        if (x != 0)
        {
            swap(matrix[x][y], matrix[x - 1][y]);
        }
    }

    return matrix;
}
bool is_up(vector<vector<int>> matrix)
{
    int x = -1;
    int y = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }
    if (x == 0)
    {
        return false;
    }
    return true;
}

int counter = 0;
void print(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(vector<vector<int>>matrix,string target,int countIDS){
    if(counter == 10){
        return;
    }
    if(str_rep(matrix) == target){
        cout<<"Solution found at count : "<<++counter<<endl;
        print(matrix);
        return;
    }
    cout<<endl;
    cout<<endl;
    cout<<"COUNT NUMBER : "<<++counter<<endl;
    cout<<endl;
    print(matrix);
    cout<<endl;
    cout<<endl;
    visited[str_rep(matrix)] = true;
    if(!visited[str_rep(move_left(matrix))]){
        return DFS(move_left(matrix),target,countIDS + 1);
    }
    if(!visited[str_rep(move_up(matrix))]){
        return DFS(move_up(matrix),target,countIDS + 1);
    }
    if(!visited[str_rep(move_right(matrix))]){
        return DFS(move_right(matrix),target,countIDS + 1);
    }
    if(!visited[str_rep(move_down(matrix))]){
        return DFS(move_down(matrix),target,countIDS + 1);
    }

}

// void DFS(vector<vector<int>> &matrix, string target)
// {
//     if (visited[str_rep(matrix)])
//     {
//         return;
//     }
//     if (str_rep(matrix) == target)
//     {
//         visited[str_rep(matrix)] = true;
//         cout << "Solution found!";
//         print(matrix);
//         return;
//     }
//     cout << endl;
//     cout << endl;
//     cout << ++counter << endl;
//     print(matrix);
//     cout << endl;
//     cout << endl;
//     if (!visited[str_rep(move_left(matrix))])
//     {
//         if (is_left(matrix))
//         {
//             vector<vector<int>> matrix_left = move_left(matrix);
//             visited[str_rep(matrix_left)] = true;
//             DFS(matrix_left, target);
//         }
//     }
//     if (!visited[str_rep(move_up(matrix))])
//     {
//         if (is_up(matrix))
//         {
//             vector<vector<int>> matrix_up = move_up(matrix);
//             visited[str_rep(matrix_up)] = true;
//             DFS(matrix_up, target);
//         }
//     }
//     if (!visited[str_rep(move_right(matrix))])
//     {
//         if (is_right(matrix))
//         {
//             vector<vector<int>> matrix_right = move_right(matrix);
//             visited[str_rep(matrix_right)] = true;
//             DFS(matrix_right, target);
//         }
//     }
//     if (!visited[str_rep(move_down(matrix))])
//     {
//         if (is_down(matrix))
//         {
//             vector<vector<int>> matrix_down = move_down(matrix);
//             visited[str_rep(matrix_down)] = true;
//             DFS(matrix_down, target);
//         }
//     }
// }
int main()
{
    vector<vector<int>> matrix_initial = {{1, 2, 3}, {4, 0, 5}, {6, 7, 8}};
    vector<vector<int>> matrix_final = {{1, 2, 3}, {4, 5, 0}, {6, 7, 8}};
    // vector<vector<int>> matrix_final = {{0, 2, 3}, {1, 4, 5}, {6, 7, 8}};
    // vector<vector<int>> matrix_final = {{2, 0, 3}, {1, 7, 5}, {4, 6, 8}};
    // vector<vector<int>> matrix_final = {{8, 0, 3}, {1, 7, 5}, {4, 6, 2}};
    // vector<vector<int>> matrix_final = {{1, 2, 3}, {4, 5, 8}, {6, 7, 0}};// this input is solved at the 10 th count!
    // vector<vector<int>> matrix_final = {{8, 1, 3}, {7, 5, 2}, {0, 4, 6}};// this input is solved at the 96568 th count! Takes long!

    for (int i = 0; i < matrix_final.size(); i++)
    {
        for (int j = 0; j < matrix_final[0].size(); j++)
        {
            cout << matrix_final[i][j] << " ";
        }
        cout << endl;
    }
    string target = str_rep(matrix_final);
    DFS(matrix_initial, target,0);
    return 0;
}