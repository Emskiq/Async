#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define CHAR_SIZE 256

using namespace std;

/* Ex.1 - with Hash Table */
bool check_repeatable_um(string str)
{
    unordered_map<char, int> words_um;
    for (int i = 0; i < str.size(); ++i) {
        words_um[str[i]]++;
        if (words_um[str[i]] > 1)
            return true;
    }
    return false;
}

/* Ex. 1 - without Hash Table */
bool check_repeatable_array(string str)
{
    int hash_table[CHAR_SIZE] = {};
    for (int i = 0; i < str.size(); ++i) {
        hash_table[str[i]]++;

        if (hash_table[str[i]] > 1)
            return true;
    }
    return false;
}

/* Ex. 2 (in C++) */
void reverse(char* str)
{
    if (str)
    {
        // Get the string length
        int str_len = 0;
        char* end = str;
        while (*end != '\0')
        {
            str_len++;
            end++;
        }
        for (int i = 0; i < str_len/2; i++)
        {
            char temp = str[i];
            str[i] = str[str_len-i-1];
            str[str_len-i-1] = temp;
        }
    }
}
void print(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        std::cout << str[i];
        ++i;
    }
}

/* Ex.3 */
bool is_permutation(string source_str, string check_str)
{
    if (source_str.size() != check_str.size()) return false;

    unordered_map<char, int> um_chars;

    for (char s : source_str)
    {
        um_chars[s]++;
    }

    for (char s : check_str)
    {
        um_chars[s]++;
        if (um_chars[s]==1)
            return false;
    }
    return true;
}

/* Ex.4 */
void shift_string_by_2(string &str, int position)
{
    if(position + 3 >= str.length()) return;

    char prev = str[position+1], prev1;
    for (int i = position+2; i < str.size(); i++)
    {
        prev1 = str[i];
        str[i] = prev;
        prev = prev1;
    }
    prev = str[position+2];
    for (int i = position+3; i < str.size(); i++)
    {
        prev1=str[i];
        str[i]=prev;
        prev=prev1;
    }
    str[position] = '%';
    str[position+1] = '2';
    str[position+2] = '0';
}
void replace_spaces(string &str)
{
    for (int i = 0; i < str.size();i++)
    {
        if(str[i] == ' ')
        {
            shift_string_by_2(str, i);
        }
    }
}

/* Ex.5 Not In place */
void reverse_matrix(int** m, int N)
{
    vector<vector<int>> m2(N, vector<int>(N));

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m2[j][N-i-1] = m[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout<<"\n";
        for (int j = 0; j < N; ++j) {
            cout <<m[i][j]<<" ";
        }
    }
    cout<<"\n";
    for (int i = 0; i < N; i++)
    {
        cout<<"\n";
        for (int j = 0; j < N; ++j) {
            cout <<m2[i][j]<<" ";
        }
    }
}

/* In place */
// Преписана от книгата, ако може я разбери напълно как се swap-ват индексите...
void reverse_matrix_in_place(int **m, int N)
{
    int temp;

    for (int i = 0; i < N; i++)
    {
        cout<<"\n";
        for (int j = 0; j < N; ++j) {
            cout <<m[i][j]<<" ";
        }
    }
    cout<<'\n';
    for (int layer = 0; layer < N/2; layer++)
    {
        int first = layer;
        int last = N - 1 - layer;
        for (int j = first; j < last; ++j) {
            int offset = j - first;
            temp = m[first][j];

            // left -> top
            m[first][j] = m[last-offset][first];

            // bottom -> left
            m[last-offset][first] = m[last][last-offset];

            // right -> bottom
            m[last][last-offset] = m[j][last];

            m[j][last] = temp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout<<"\n";
        for (int j = 0; j < N; ++j) {
            cout <<m[i][j]<<" ";
        }
    }
}