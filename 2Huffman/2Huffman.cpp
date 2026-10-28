#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void printCodes(Node *root, string code)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffmanEncoding(vector<char> &chars, vector<int> &freq)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (int i = 0; i < chars.size(); i++)
        pq.push(new Node(chars[i], freq[i]));

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *newNode = new Node('-', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node *root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Enter a positive number of characters.";
        return 0;
    }

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++)
        cin >> chars[i];

    cout << "Enter corresponding frequencies: ";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    huffmanEncoding(chars, freq);

    return 0;
}

/*Enter number of characters: 5
Enter characters: A B C D E
Enter corresponding frequencies: 5 9 12 13 16*/