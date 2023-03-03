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

int score(vector<vector<int>> matrix, string target)
{
    string temp = str_rep(matrix);
    int score = 0;
    for (int i = 0; i < 9; i++)
    {
        if (temp[i] == target[i])
        {
            score++;
        }
    }
    return score;
}
int depth_counter = 0;

vector<vector<vector<int>>> decide(vector<vector<int>> matrix, string target)
{
    // pair<int,vector<vector<int>>>;
    priority_queue<pair<int, vector<vector<int>>>> pq;
    // unordered_map<int, vector<vector<int>>> map;
    int left = -1;
    int up = -1;
    int right = -1;
    int down = -1;
    if (!visited[str_rep(move_left(matrix))])
    {
        left = score(move_left(matrix), target);
        pq.push(make_pair(left, move_left(matrix)));
        // map[left] = move_left(matrix);
    }
    if (!visited[str_rep(move_up(matrix))])
    {
        up = score(move_up(matrix), target);
        pq.push(make_pair(up, move_up(matrix)));
        // map[up] = move_up(matrix);
    }
    if (!visited[str_rep(move_right(matrix))])
    {
        right = score(move_right(matrix), target);
        pq.push(make_pair(right, move_right(matrix)));
        // map[right] = move_right(matrix);
    }
    if (!visited[str_rep(move_down(matrix))])
    {
        down = score(move_down(matrix), target);
        pq.push(make_pair(down, move_down(matrix)));
        // map[down] = move_down(matrix);
    }
    // int min1 = min(left,right);
    // int min2 = min(up,down);
    // int min_final = min(min(left, right), min(up, down));
    cout << "left score : " << left << endl;
    cout << "up score : " << up << endl;
    cout << "right score : " << right << endl;
    cout << "down score : " << down << endl;
    vector<vector<vector<int>>> result;
    int temp = pq.top().first;
    result.push_back(pq.top().second);
    pq.pop();
    while (temp == pq.top().first)
    {
        if (pq.empty())
        {
            return result;
        }
        result.push_back(pq.top().second);
        pq.pop();
    }
    if (!result.empty())
    {
        depth_counter++;
    }
    return result;
}

vector<vector<vector<int>>> decide1(vector<vector<int>> matrix, string target)
{
    // pair<int,vector<vector<int>>>;
    priority_queue<pair<int, vector<vector<int>>>> pq;
    // unordered_map<int, vector<vector<int>>> map;
    int left = -1;
    int up = -1;
    int right = -1;
    int down = -1;

    left = score(move_left(matrix), target);
    pq.push(make_pair(left, move_left(matrix)));
    // map[left] = move_left(matrix);

    up = score(move_up(matrix), target);
    pq.push(make_pair(up, move_up(matrix)));
    // map[up] = move_up(matrix);

    right = score(move_right(matrix), target);
    pq.push(make_pair(right, move_right(matrix)));
    // map[right] = move_right(matrix);

    down = score(move_down(matrix), target);
    pq.push(make_pair(down, move_down(matrix)));
    // map[down] = move_down(matrix);

    // int min1 = min(left,right);
    // int min2 = min(up,down);
    // int min_final = min(min(left, right), min(up, down));
    cout << "left score : " << left << endl;
    cout << "up score : " << up << endl;
    cout << "right score : " << right << endl;
    cout << "down score : " << down << endl;
    vector<vector<vector<int>>> result;
    int temp = pq.top().first;
    result.push_back(pq.top().second);
    pq.pop();
    while (temp == pq.top().first)
    {
        if (pq.empty())
        {
            return result;
        }
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}
void BFS(vector<vector<int>> matrix, string target)
{

    queue<vector<vector<int>>> q;
    q.push(matrix);
    visited[str_rep(matrix)] = true;
    while (!q.empty())
    {
        vector<vector<int>> temp = q.front();
        // unordered_map<int,vector<vector<int>>>temp;
        q.pop();
        if (str_rep(temp) == target)
        {
            cout << "Puzzle is solved!! at count no : " << counter << endl;
            print(temp);
            return;
        }
        cout << endl;
        cout<<"Depth counter "<<depth_counter<<endl;
        cout << "count : " << ++counter << " : " << endl;
        print(temp);
        cout << endl;
        cout << endl;
        cout << endl;
        vector<vector<vector<int>>> children = decide(temp, target);
        int temp_counter = 0;
        while (temp_counter < children.size())
        {
            if (!visited[str_rep(children[temp_counter])])
            {
                q.push(children[temp_counter]);
                visited[str_rep(children[temp_counter])] = true;
            }
            temp_counter++;
        }
        children.clear();
        // q.push(decide(temp, target));
        // if(!visited[str_rep(move_left(temp))]){
        //     q.push(move_left(temp));
        //     visited[str_rep(move_left(temp))] = true;
        // }
        // if(!visited[str_rep(move_up(temp))]){
        //     q.push(move_up(temp));
        //     visited[str_rep(move_up(temp))] = true;
        // }
        // if(!visited[str_rep(move_right(temp))]){
        //     q.push(move_right(temp));
        //     visited[str_rep(move_right(temp))] = true;
        // }
        // if(!visited[str_rep(move_down(temp))]){
        //     q.push(move_down(temp));
        //     visited[str_rep(move_down(temp))] = true;
        // }
    }
}

// int check_inversion(string str_matrix){
//     int res = 0;

//     return res;
// }

// vector<vector<vector<int>>> decide_trial(vector<vector<int>> matrix, string target)
// {
//     // pair<int,vector<vector<int>>>;
//     priority_queue<pair<int, vector<vector<int>>>> pq;
//     // unordered_map<int, vector<vector<int>>> map;
//     int left = -1;
//     int up = -1;
//     int right = -1;
//     int down = -1;
//     if (!visited[str_rep(move_left(matrix))])
//     {
//         left = score(move_left(matrix), target);
//         pq.push(make_pair(left, move_left(matrix)));
//         // map[left] = move_left(matrix);
//     }
//     if (!visited[str_rep(move_up(matrix))])
//     {
//         up = score(move_up(matrix), target);
//         pq.push(make_pair(up, move_up(matrix)));
//         // map[up] = move_up(matrix);
//     }
//     if (!visited[str_rep(move_right(matrix))])
//     {
//         right = score(move_right(matrix), target);
//         pq.push(make_pair(right, move_right(matrix)));
//         // map[right] = move_right(matrix);
//     }
//     if (!visited[str_rep(move_down(matrix))])
//     {
//         down = score(move_down(matrix), target);
//         pq.push(make_pair(down, move_down(matrix)));
//         // map[down] = move_down(matrix);
//     }
//     // int min1 = min(left,right);
//     // int min2 = min(up,down);
//     // int min_final = min(min(left, right), min(up, down));
//     cout << left << endl;
//     cout << up << endl;
//     cout << right << endl;
//     cout << down << endl;
//     vector<vector<vector<int>>> result;
//     int temp = pq.top().first;
//     result.push_back(pq.top().second);
//     pq.pop();
//     while (temp == pq.top().first)
//     {
//         if (pq.empty())
//         {
//             return result;
//         }
//         result.push_back(pq.top().second);
//         pq.pop();
//     }
//     return result;
// }

int main()
{

    vector<vector<int>> matrix_initial = {{1, 2, 3}, {4, 0, 5}, {6, 7, 8}};
    // vector<vector<int>> matrix_final = {{1, 2, 3}, {4, 0, 5}, {6, 7, 8}};
    // vector<vector<int>> matrix_final = {{1, 2, 3}, {0, 4, 5}, {6, 7, 8}};
    // vector<vector<int>> matrix_final = {{8, 0, 3}, {1, 7, 5}, {4, 6, 2}};
    // vector<vector<int>> matrix_final = {{0, 2, 3}, {1, 4, 5}, {6, 7, 8}};
    vector<vector<int>> matrix_final = {{1, 2, 3}, {4, 5, 8}, {6, 7, 0}};// this input is solved at the 10 th count!, and is solved at the 2 nd count in best first search!
    // vector<vector<int>> matrix_final = {{8, 1, 3}, {7, 5, 2}, {0, 4, 6}};// this input is solved at the 96568 th count! Takes long!
    // for (int i = 0; i < matrix_final.size(); i++)
    // {
    //     for (int j = 0; j < matrix_final[0].size(); j++)
    //     {
    //         cout << matrix_final[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    string target = str_rep(matrix_final);
    BFS(matrix_initial, target);
    // print(matrix_final);
    // vector<vector<int>>result = decide_trial(matrix_initial,target);
    // print(result);
    // vector<vector<vector<int>>>res = decide(matrix_initial,target);
    // int temp_ctr = 0;
    // while(!res.empty()){
    //     print(res[temp_ctr]);
    //     res.pop_back();
    //     temp_ctr++;
    //     cout<<endl;
    //     cout<<endl;
    //     cout<<endl;
    // }
    return 0;
}