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
void BFS(vector<vector<int>> &matrix, string target)
{

    queue<vector<vector<int>>> q;
    q.push(matrix); // use early goal test
    visited[str_rep(matrix)] = true;
    while (!q.empty())
    {
        vector<vector<int>> temp = q.front();
        q.pop();
        if (str_rep(temp) == target)
        {
            cout << "Puzzle is solved!! at count no : " << counter << endl;
            print(temp);
            return;
        }
        cout << endl;
        cout << "count : " << ++counter << " : " << endl;
        print(temp);
        cout << endl;
        cout << endl;
        cout << endl;
        if (!visited[str_rep(move_left(temp))])
        {
            cout<<"yes"<<endl;
            q.push(move_left(temp));
            visited[str_rep(move_left(temp))] = true;
        }
        if (!visited[str_rep(move_up(temp))])
        {
            cout<<"yes"<<endl;
            q.push(move_up(temp));
            visited[str_rep(move_up(temp))] = true;
        }
        if (!visited[str_rep(move_right(temp))])
        {
            cout<<"yes"<<endl;
            q.push(move_right(temp));
            visited[str_rep(move_right(temp))] = true;
        }
        if (!visited[str_rep(move_down(temp))])
        {
            cout<<"yes"<<endl;
            q.push(move_down(temp));
            visited[str_rep(move_down(temp))] = true;
        }
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// //blank represented by 0

// int main() {
//     vector<int> init(9), goal(9);
//     int x = 0, y = 0, inv = 0;
//     for(int i = 0; i < 9; i++){
//         cin>>init[i];
//     }
//     for(int i = 0; i < 9; i++){
//         int temp;
//         cin>>temp;
//         goal[temp] = i;
//     }
//     for(int i = 0; i < 9; i++){
//         for(int j = i + 1; j < 9; j++){
//             if(init[i] && init[j]){
//                 x = goal[init[i]];
//                 y = goal[init[j]];
//                 if(x > y) inv++;
//             }
//         }
//     }
//     if(inv & 1) cout<<"Unsolvable"<<endl;
//     else cout<<"Solvable"<<endl;
// 	return 0;
// }

bool inversion(vector<int> check_inversion)
{
    int inv_count = 0;
    for (int i = 0; i < check_inversion.size(); i++)
    {
        for (int j = i + 1; j < check_inversion.size(); j++)
        {
            if ((check_inversion[i] && check_inversion[j]) && check_inversion[i] > check_inversion[j])
            {
                inv_count++;
            }
        }
    }
    return inv_count % 2 == 0;
}
int main()
{

    vector<vector<int>> matrix_initial = {{1, 2, 3}, {4, 0, 5}, {6, 7, 8}};
    // vector<vector<int>> matrix_initial = {{1, 2, 3}, {4, 0, 5}, {6, 8, 7}};
    // vector<vector<int>> matrix_final = {{0, 2, 3}, {1, 4, 5}, {6, 7, 8}};
    // vector<vector<int>> matrix_final = {{2, 0, 3}, {1, 7, 5}, {4, 6, 8}};
    // vector<vector<int>> matrix_final = {{8, 0, 3}, {1, 7, 5}, {4, 6, 2}};
    // vector<vector<int>> matrix_final = {{1, 2, 3}, {4, 5, 8}, {6, 7, 0}};// this input is solved at the 10 th count!
    vector<vector<int>> matrix_final = {{8, 1, 3}, {7, 5, 2}, {0, 4, 6}}; // this input is solved at the 96568 th count! Takes long!
    for (int i = 0; i < matrix_final.size(); i++)
    {
        for (int j = 0; j < matrix_final[0].size(); j++)
        {
            cout << matrix_final[i][j] << " ";
        }
        cout << endl;
    }
    string target = str_rep(matrix_final);
    vector<int> check_inversion;
    for (int i = 0; i < matrix_initial.size(); i++)
    {
        for (int j = 0; j < matrix_initial[i].size(); j++)
        {
            if (matrix_initial[i][j])
            {
                check_inversion.push_back(matrix_initial[i][j]);
            }
        }
    }
    // cout<<check_inversion.size()<<endl;
    if (inversion(check_inversion))
    {
        BFS(matrix_initial, target);
    }
    else{
        cout<<"The matrix isn't solvable!"<<endl;
    }
    return 0;
}