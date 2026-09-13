#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// دالة الـ BFS
void bfs(int startNode, vector<int> adjList[], int totalNodes)
{
    // مصفوفة لتذكر العناصر التي زرناها من قبل لمنع اللوب اللانهائي
    vector<bool> visited(totalNodes, false);

    // الطابور الأساسي للخوارزمية
    queue<int> q;

    // زرنا النقطة الأولى وحطيناها بالطابور
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " "; // طباعة العنصر الحالي

        // اللف على كل جيران العنصر الحالي
        for (int neighbor : adjList[currentNode])
        {
            if (!visited[neighbor])
            { // إذا لم نزر هذا الجار من قبل
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main()
{
    int nodes = 5;
    vector<int> adjList[5];

    // بناء جراف بسيط (5 نقاط)
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1};
    adjList[4] = {1, 2};

    // تشغيل الخوارزمية ابتداءً من النقطة 0
    bfs(0, adjList, nodes);

    return 0;
}