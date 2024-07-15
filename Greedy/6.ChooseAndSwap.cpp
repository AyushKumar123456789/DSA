// https://www.geeksforgeeks.org/problems/choose-and-swap0531/1

/*
Easy Question
*/

string chooseandswap(string str)
{
    int n = str.size();
    vector<int> temp(26, 0);
    for (int i = 0; i < n; i++)
    {
        temp[str[i] - 'a'] = 1;
    }
    char a, b;
    for (int i = 0; i < n; i++)
    {
        bool flag = 0;
        temp[str[i] - 'a'] = -1;
        for (int j = 0; j <= str[i] - 'a'; j++)
        {
            if (temp[j] == 1)
            {
                a = str[i];
                b = 'a' + j;
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == a)
        {
            str[i] = b;
        }
        else if (str[i] == b)
        {
            str[i] = a;
        }
    }
    return str;
}