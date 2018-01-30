class Solution {
public:
    struct Node {
        int x;
        int y;
        int step;
        Node(int x1, int y1, int step1): x(x1), y(y1), step(step1) {}  //≥ı ºªØ
    };
    
    /*
    
    3
    0 0 0
    0 1 0
    1 1 1
    
    5
    1 1 0 1 0
    0 0 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    
    */
    
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        int dis[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) continue;
    
    //            int vis[10005][10005];
    //            memset(vis, 0, sizeof(vis));
    
                Node node(i, j, 0);
                queue<Node> q;
                while(!q.empty()) q.pop();
    
                q.push(node);
                int step = 1;
                while(!q.empty()) {
                    node = q.front();
                    q.pop();
                    if(matrix[node.x][node.y] == 0) {
                        step = node.step;
                        break;
                    }
    //                vis[node.x][node.y] = 1;
                    for(int k = 0; k < 4; k++) {
                        int x = node.x + dis[k][0];
                        int y = node.y + dis[k][1];
                        if(x >= 0 && y >= 0 && x < matrix.size() && y < matrix[i].size()) {
                            Node next(x, y, node.step + 1);
                            q.push(next);
                        }
                    }
                }
                matrix[i][j] = step;
            }
        }
        return matrix;
    }
};