#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MIN_CHAR 'a'
#define MAX_CHAR '{'
#define COUNT_AR_LEN (MAX_CHAR - MIN_CHAR + 1)

struct located_char
{
    char c;
    int i, j;
    bool operator < (const located_char& ano) const 
    {
        if (i == ano.i) return j < ano.j; return i < ano.i;
    }
};

struct suffix_array_t
{
    located_char* origin;
    int length;
    int* sa;
    int* rank;

    int* h;
    int* height;

    void get_new_rank(int key1[], int key2[], int result[])
    {
        vector<int> piles[length + 1];
        for (int i = 0; i < length; i++) piles[key1[i]].push_back(i);
        int currank = 1;
        for (int i = 0; i <= length; i++)
        {
            if (piles[i].empty()) continue;

            int pre = -1;
            int inrank = -1;
            sort(piles[i].begin(), piles[i].end(), [=](int a, int b){ return key2[a] < key2[b]; });

            for (int k = 0; k < (int)piles[i].size(); k++) 
            {
                if (key2[piles[i][k]] != pre) 
                {
                    pre = key2[piles[i][k]];
                    inrank++;
                }
                result[piles[i][k]] = currank + inrank;
            }
            currank += inrank + 1;
        }
    }

    void fill_init_rank()
    {
        int count[COUNT_AR_LEN];
        for (int i = 0; i < COUNT_AR_LEN; i++) count[i] = 0;
        for (int i = 0; i < length; i++) count[origin[i].c - MIN_CHAR]++;
        int rankmatch[COUNT_AR_LEN];
        int currank = 1;
        for (int i = 0; i < COUNT_AR_LEN; i++)
        {
            if (count[i] > 0)
            {
                rankmatch[i] = currank;
                currank++;
            }
        }
        for (int i = 0; i < length; i++) rank[i] = rankmatch[origin[i].c - MIN_CHAR];
    }

    void build_rank()
    {
        fill_init_rank();
        int sorted_length = 1;
        int tmp[length];
        while (sorted_length < length)
        {
            for (int i = 0; i + sorted_length < length; i++) tmp[i] = rank[i + sorted_length];
            for (int i = length - sorted_length; i < length; i++) tmp[i] = 0;
            get_new_rank(rank, tmp, rank);
            sorted_length *= 2;
        }
        for (int i = 0; i < length; i++) rank[i]--;
    }

    void build_sa()
    {
        for (int i = 0; i < length; i++) sa[rank[i]] = i;
    }

    suffix_array_t(located_char* str, int len)
    {
        origin = str;
        length = len;
        sa = new int[length];
        rank = new int[length];
        build_rank();
        build_sa();
    }
};

int lesscmp(located_char* ar, string& str, int i)
{
    if (str.empty()) return 0;
    int j = 0;
    while (ar[i].c == str[j]) { i++; j++; if (j == str.length()) return 0; }
    return ar[i].c - str[j];
}

int main()
{
    int test; cin >> test;
    for (int t = 0; t < test; t++)
    {
        int row, col;
        cin >> row >> col; 
        located_char ar[row][col];
        for (int i = 0; i < row; i++)
        {
            string str; cin >> str;
            for (int j = 0; j < col; j++)
            {
                char c = str[j];
                if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
                ar[i][j].c = c;
                ar[i][j].i = i + 1;
                ar[i][j].j = j + 1;
            }
        }
        located_char del; del.c = '{'; 
        located_char lstr[row * col * 32];
        int lid = 0;
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j < col; j++) lstr[lid++] = ar[i][j]; lstr[lid++] = del;
            for (int j = col - 1; j >= 0; j--) lstr[lid++] = ar[i][j]; lstr[lid++] = del;
            for (int ii = i, jj = 0; ii < row && jj < col; ii++, jj++) lstr[lid++] = ar[ii][jj]; lstr[lid++] = del;
            for (int ii = i, jj = 0; ii >= 0 && jj < col; ii--, jj++) lstr[lid++] = ar[ii][jj]; lstr[lid++] = del;
            for (int ii = i, jj = col - 1; ii >= 0 && jj >= 0; ii--, jj--) lstr[lid++] = ar[ii][jj]; lstr[lid++] = del;
            for (int ii = i, jj = col - 1; ii < row && jj >= 0; ii++, jj--) lstr[lid++] = ar[ii][jj]; lstr[lid++] = del;
        }
        for (int j = 0; j < col; j++) 
        {
            for (int i = 0; i < row; i++) lstr[lid++] = ar[i][j]; lstr[lid++] = del;
            for (int i = row - 1; i >= 0; i--) lstr[lid++] = ar[i][j]; lstr[lid++] = del;
            for (int ii = 0, jj = j; ii < row && jj < col; ii++, jj++) lstr[lid++] = ar[ii][jj]; lstr[lid++] = del;
            for (int ii = 0, jj = j; ii < row && jj >= 0; ii++, jj--) lstr[lid++] = ar[ii][jj]; lstr[lid++] = del;
            for (int ii = row - 1, jj = j; ii >= 0 && jj >= 0; ii--, jj--) lstr[lid++] = ar[ii][jj]; lstr[lid++] = del;
            for (int ii = row - 1, jj = j; ii >= 0 && jj < col; ii--, jj++) lstr[lid++] = ar[ii][jj]; lstr[lid++] = del;
        }
       
        suffix_array_t sa(lstr, lid);
        int* re = sa.sa;
        
        int nquery; cin >> nquery;
        for (int q = 0; q < nquery; q++)
        {
            string query; cin >> query;
            std::transform(query.begin(), query.end(), query.begin(), ::tolower);

            int left = 0, right = lid - 1;
            while (left < right)
            {
                int sum = left + right;
                int mid = sum / 2;
                if (lesscmp(lstr, query, re[mid]) < 0) left = mid + 1;
                else right = mid;
            }
            int lbound = right;
            left = 0, right = lid - 1;
            while (left < right)
            {
                int sum = left + right;
                int mid = sum / 2 + sum % 2;
                if (lesscmp(lstr, query, re[mid]) > 0) right = mid - 1;
                else left = mid;
            }
            int rbound = left;
            located_char minpos = lstr[re[lbound]];
            for (int i = lbound + 1; i <= rbound; i++)
            {
                if (lstr[re[i]] < minpos) minpos = lstr[re[i]];
            }
            cout << minpos.i << " " << minpos.j << endl;
        }
        if (t != test - 1) cout << endl;
    }
}
